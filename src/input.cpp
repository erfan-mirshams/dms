#include "../include/input.h"

string wordFromPosition(string::iterator &it, string::iterator fn){
    while (isspace(*(it++)))
        ;
    --it;
    string::iterator i = it;
    string res = "";
    for (; i != fn; ++i) {
        if (isspace(*i)) {
            break;
        }
        res.push_back(*i);
    }
    swap(i, it);
    return res;
}

vector<string> splitIntoWords(string str){
    vector<string> elements;
    string::iterator it = str.begin();
    while(it != str.end()){
        elements.push_back(wordFromPosition(it, str.end()));
    }
    return elements;
}

string trimBoth(string str){
    int stPos = 0, fnPos = (int)str.size();
    for(int i = 0; i < (int)str.size(); i++){
        if(!isspace(str[i])){
            stPos = i;
            break;
        }
    }
    for(int i = (int)str.size() - 1; ~i; i--){
        if(!isspace(str[i])){
            fnPos = i + 1;
            break;
        }
    }
    return str.substr(stPos, fnPos - stPos);
}
