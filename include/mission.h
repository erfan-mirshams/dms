#ifndef MISSION_H_
#define MISSION_H_

#include "general.h"

class Mission{
protected:
    int id;
    ll start;
    ll finish;
    int reward;
public:
    Mission(int _id, ll _start, ll _finish, int _reward);
    inline int getId(){return id;}
};

class TimeMission : public Mission{
private:
    int timeInMins;
public:
    TimeMission(int _id, ll _start, ll _finish, int _timeInMins, int _reward);
};

class CountMission : public Mission{
private:
    int count;
public:
    CountMission(int _id, ll _start, ll _finish, int _count, int _reward);
};

class DistanceMission : public Mission{
private:
    int distance;
public:
    DistanceMission(int _id, ll _start, ll _finish, int _distance, int _reward);
};
#endif // MISSION_H_
