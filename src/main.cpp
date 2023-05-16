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
                if(printedLine[printedLine.size() - 1] == '\n'){
                    cout << printedLine;
                }
                else{
                    cout << printedLine << endl;
                }
            }
        }
        catch(logic_error &le){
            cout << le.what() << endl;
        }
    }
    return 0;
}
