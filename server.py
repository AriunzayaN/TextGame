
import subprocess
import os
import sqlite3
from bottle import route, run, template, post, request

conn = sqlite3.connect('var/server.sqlite3')


def executeCpp(filename, command):
    # create a pipe to a child process
    data, temp = os.pipe()

    # store output of the program as a byte string in s
    s = subprocess.check_output("./server.exe {} '{}'"
                                .format(filename, command),
                                stdin=data, shell=True)

    # decode s to a normal string
    return s.decode("utf-8")


@route('/')
def root():
    return template('''
        <form action="/hello" method="post">
            Nickname: <input type="text" name="name"><br>
                    <input type="hidden" name="command" value="">
            <input type="submit" value="Submit">
        </form>
    ''')


@post('/hello')
def index():
    c = conn.cursor()
    postdata = request.body.read()
    name = request.forms.get("name")
    command = request.forms.get("command")
    print(name, command)
    query = 'SELECT EXISTS(SELECT 1 FROM users WHERE username="{}");'.format(
                name)
    print(query)
    c.execute(query)
    exists = c.fetchone()[0]
    message = 'Game continuing...'
    if exists == 0:
        message = 'New Game'
        with open('designs/example.txt', 'r') as content_file:
            state = content_file.read()
            print(state)
            c.execute('INSERT INTO users (username, state) VALUES("{}","{}");'
                      .format(name, state))
    state = c.execute('SELECT state FROM users WHERE username="{}"'
                      .format(name)).fetchone()[0]
    tempfilename = name + ".temp.text"
    if os.path.exists(tempfilename):
        os.remove(tempfilename)
    with open(tempfilename, 'w') as temp_file:
        temp_file.write(state)
    gameOutput = ''
    if command != '':
        gameOutput = executeCpp(tempfilename, command)
    with open(tempfilename, 'r') as temp_file:
        state = temp_file.read()
        c.execute('UPDATE users SET state="{}" WHERE username="{}"'
                  .format(state, name))
    if os.path.exists(tempfilename):
        os.remove(tempfilename)
    return template('''
        <b>{{name}} {{message}}</b><br>
        <p>{{gameOutput}}</p><br>
        <form action="/hello" method="post">
            Command: <input type="text" name="command" value=""><br>
            <input type="hidden" name="name" value="{{name}}">
        <input type="submit" value="Submit">
        </form>
    ''', message=message, name=name, gameOutput=gameOutput)


run(host='localhost', port=8080)
