#include "../include/general.h"

bool isTimeSegmentValid(ll a, ll b){
    return a <= b;
}

bool isValidCommand(vector<string> cmd, int ind){
    return (cmd[0] == CMD_STRING[ind] && (int)cmd.size() - 1 == CMD_LEN[ind]);
}
