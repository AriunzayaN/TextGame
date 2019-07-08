#include <iostream>
#include <fstream>
#include "manager.h"

using namespace std;

int main(int argc, char **argv){
    string filename = argv[1];
    string command = argv[2];
    loadTheGame(filename);
    vector<string> v = split(command);
    if(valid_input(v)){
        cout << playerCommand(v) << endl;
    }else{
        cout << "Input not valid" << endl;
    }
    ofstream os;
    os.open(filename);
    os << saveTheGame();
    os.close();
    return 0;
}