#ifndef DRIVER_H_
#define DRIVER_H_

#include "general.h"
#include "ride.h"
#include "mission.h"

class Driver{
private:
    int id;
    vector<Mission*> missions;
    vector<Ride> rides;
    vector<int> completedIndexes;
public:
    Driver(int _id);
    void assignMission(Mission* mission);
    Mission* findMissionById(int id);
    int getId(){ return id;}
    void addRide(ll start, ll finish, int distance);
    bool isInCompletedIndexes(int ind);
    string newCompletedMissionsReport();
    string getMissionsStatus();
};

#endif // DRIVER_H_
