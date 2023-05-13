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

bool TimeMission::isCompleted(const vector<Ride> &vec){
    int curTime = 0;
    for(auto r : vec){
        if(isInTimeSegment(start, finish, r.getStart(), r.getFinish())){
            curTime += r.getFinish() - r.getStart() + 1;
        }
    }
    return curTime >= timeInMins;
}

bool CountMission::isCompleted(const vector<Ride> &vec){
    int curCount = 0;
    for(auto r : vec){
        if(isInTimeSegment(start, finish, r.getStart(), r.getFinish())){
            curCount++;
        }
    }
    return curCount >= count;
}

bool DistanceMission::isCompleted(const vector<Ride> &vec){
    int curDis = 0;
    for(auto r : vec){
        if(isInTimeSegment(start, finish, r.getStart(), r.getFinish())){
            curDis += r.getDistance();
        }
    }
    return curDis >= distance;
}

string Mission::getInfo(){
    ostringstream output;
    output << "mission: " << id << endl
           << "start timestamp: " << start << endl
           << "end timestamp: " << finish << endl
           << "reward: " << reward << endl;
    return output.str();
}
