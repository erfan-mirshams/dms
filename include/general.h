#ifndef GENERAL_H_
#define GENERAL_H_

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>
#include <sstream>
using namespace std;
typedef long long int ll;

const string DUPLICATE_MISSION_MSG = "DUPLICATE_MISSION_ID";
const string INVALID_ARGUMENTS_MSG = "INVALID_ARGUMENTS";
const string MISSION_NOT_FOUND_MSG = "MISSION_NOT_FOUND";
const string DUPLICATE_DRIVER_MSG = "DUPLICATE_DRIVER_MISSION";
const string DRIVER_MISSION_NOT_FOUND = "DRIVER_MISSION_NOT_FOUND";

const string OK_STR = "OK";

const int NA = -1;
const int CMD_CNT = 6;
const string CMD_STRING[CMD_CNT] = {"add_time_mission", "add_distance_mission", "add_count_mission", "assign_mission", "record_ride", "show_missions_status"};
const int CMD_LEN[CMD_CNT] = {5, 5, 5, 2, 4, 1};
enum CMD_TYPE{ADD_TIME_MISSION, ADD_DISTANCE_MISSION, ADD_COUNT_MISSION, ASSIGN_MISSION, RECORD_RIDE, SHOW_MISSIONS_STATUS};

bool isTimeSegmentValid(ll a, ll b);
bool isValidCommand(vector<string> cmd, int ind);
bool isInTimeSegment(ll st, ll fn, ll st2, ll fn2);
#endif // GENERAL_H_
