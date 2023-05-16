#include "../include/general.h"
#include "../include/input.h"
#include "../include/drivemanager.h"

int main() {
    string line;
    DriveManager driveMan;
    while(getline(cin, line)){
        line = trimBoth(line);
        try{
            string printedLine = driveMan.handleCommand(splitIntoWords(line));
            if(printedLine.size()){
                while(printedLine[printedLine.size() - 1] == '\n'){
                    printedLine = printedLine.substr(0, printedLine.size() - 1);
                }
                cout << printedLine << endl;
            }
        }
        catch(logic_error &le){
            cout << le.what() << endl;
        }
    }
    return 0;
}
