#ifndef MISSION_H_
#define MISSION_H_

#include "general.h"
#include "ride.h"

class Mission{
protected:
    int id;
    ll start;
    ll finish;
    map<int, ll> endTimeStamp;
    map<int, int> startRideIndex;
    int reward;
public:
    Mission(int _id, ll _start, ll _finish, int _reward);
    inline int getId(){return id;}
    inline void setEndTimeStamp(int driverId, ll t) {endTimeStamp[driverId] = t;}
    inline void setStartRideIndex(int driverId, int ind) {startRideIndex[driverId] = ind;}
    bool isBefore(Mission* b);
    string getInfo(int driverId);
    virtual bool isCompleted(int driverId, const vector<Ride> &vec) = 0;
    virtual ~Mission(){}
};

class TimeMission : public Mission{
private:
    int timeInMins;
public:
    TimeMission(int _id, ll _start, ll _finish, int _timeInMins, int _reward);
    virtual bool isCompleted(int driverId, const vector<Ride> &vec) override;
};

class CountMission : public Mission{
private:
    int count;
public:
    CountMission(int _id, ll _start, ll _finish, int _count, int _reward);
    virtual bool isCompleted(int driverId, const vector<Ride> &vec) override;
};

class DistanceMission : public Mission{
private:
    int distance;
public:
    DistanceMission(int _id, ll _start, ll _finish, int _distance, int _reward);
    virtual bool isCompleted(int driverId, const vector<Ride> &vec) override;
};
#endif // MISSION_H_
