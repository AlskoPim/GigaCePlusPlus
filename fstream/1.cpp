#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void write(){
    fstream file("testfile.txt");
    string text = "";
    getline(cin, text);
    file << text << endl;
}

void read(){
    fstream file("testfile.txt");
    string line = "";
    while(getline(file, line)) cout << line << endl;
}

int main(){

    fstream file("testfile.txt");
    if(!file.is_open()){
        cout << "File not automatically opened, opening file now..." << endl;
        file.open("testfile.txt");
    }

    string choice = "";
    int intchoice = 0;
    string line = "";
    bool flag = false;

    cout << "What do you want to do?" << endl;
    while(!flag){
        cout << "|| 1 - Write to file || 2 - Read from file || E - Exit Program || Your choice - ";
        getline(cin, choice);
        cout << endl;
        if(choice == "E" || choice == "e"){
            cout << "Exiting program" << endl;
            flag = true;
            break;
        }
        if(choice == " " || choice == "") {
            intchoice = 0;
        }else{
            intchoice = stoi(choice);
        }
        switch(intchoice){
            case 1:
                write();
                break;
            case 2:
                read();
                break;
            default:
                cout << "bru its not that hard of a choice" << endl;
                break;
        }
        intchoice = 0;
        cout << endl;
    }


}

