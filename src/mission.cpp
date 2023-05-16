#include "../include/mission.h"

Mission::Mission(int _id, ll _start, ll _finish, int _reward){
    id = _id;
    start = _start;
    finish = _finish;
    reward = _reward;
}

bool Mission::isBefore(Mission *b){
    return (this -> start < b -> start) || (this -> start == b -> start && this -> finish < b -> finish);
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

bool TimeMission::isCompleted(int driverId, const vector<Ride> &vec){
    int curTime = 0;
    for(int i = startRideIndex[driverId]; i < (int)vec.size(); i++){
        auto r = vec[i];
        if(isInTimeSegment(start, finish, r.getStart(), r.getFinish())){
            curTime += r.getFinish() - r.getStart() + 1;
        }
    }
    return curTime / SECONDS_IN_MIN >= timeInMins;
}

bool CountMission::isCompleted(int driverId, const vector<Ride> &vec){
    int curCount = 0;
    for(int i = startRideIndex[driverId]; i < (int)vec.size(); i++){
        auto r = vec[i];
        if(isInTimeSegment(start, finish, r.getStart(), r.getFinish())){
            curCount++;
        }
    }
    return curCount >= count;
}

bool DistanceMission::isCompleted(int driverId, const vector<Ride> &vec){
    int curDis = 0;
    for(int i = startRideIndex[driverId]; i < (int)vec.size(); i++){
        auto r = vec[i];
        if(isInTimeSegment(start, finish, r.getStart(), r.getFinish())){
            curDis += r.getDistance();
        }
    }
    return curDis >= distance;
}

string Mission::getInfo(int driverId){
    ostringstream output;
    output << "mission: " << id << endl
           << "start timestamp: " << start << endl
           << "end timestamp: " << endTimeStamp[driverId] - 1 << endl
           << "reward: " << reward << endl;
    return output.str();
}
