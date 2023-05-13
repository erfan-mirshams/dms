#include "../include/mission.h"

Mission::Mission(int _id, ll _start, ll _finish, int _reward){
    id = _id;
    start = _start;
    finish = _finish;
    reward = _reward;
}

TimeMission::TimeMission(int _id, ll _start, ll _finish, int _timeInMins, int _reward) : Mission(_id, _start, _finish, _reward){
    timeInMins = _timeInMins;
}

CountMission::CountMission(int _id, ll _start, ll _finish, int _count, int _reward) : Mission(_id, _start, _finish, _reward){
    count = _count;
}

DistanceMission::DistanceMission(int _id, ll _start, ll _finish, int _distance, int _reward) : Mission(_id, _start, _finish, _reward){
    distance = _distance;
}
