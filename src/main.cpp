#include "../include/general.h"
#include "../include/input.h"
#include "../include/drivemanager.h"

int main() {
    string line;
    DriveManager driveMan;
    while(getline(cin, line)){
        line = trimBoth(line);
        try{
            cout << driveMan.handleCommand(splitIntoWords(line)) << endl;
        }
        catch(logic_error &le){
            cout << le.what() << endl;
        }
    }
    return 0;
}
