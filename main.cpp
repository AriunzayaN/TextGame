#include "manager.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(){
    string testFileName = "designs/lab_scenario.txt";
    loadTheGame(testFileName);
    
    for (string line; getline(cin, line);){
        vector<string> v = split(line);

        if(valid_input(v)){
            cout << playerCommand(v) << endl;
        }else{
            cout << "Input not valid" << endl;
        }
    }

    return 0;
}