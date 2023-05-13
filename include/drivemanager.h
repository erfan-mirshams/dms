#ifndef DRIVEMANAGER_H_
#define DRIVEMANAGER_H_

#include "general.h"
#include "driver.h"
#include "mission.h"

class DriveManager{
private:
    vector<Driver*> drivers;
    vector<Mission*> missions;
public:
    string handleCommand(vector<string> cmd);
    void addTimeMission(int _id, ll _start, ll _finish, int _timeInMins, int reward);
    void addDistanceMission(int _id, ll _start, ll _finish, int _distance, int reward);
    void addCountMission(int _id, ll _start, ll _finish, int _count, int reward);
    Mission* findMissionById(int _id);
    Driver* findDriverById(int _id);
    void assignMission(int missionId, int driverId);
    void recordRide(ll start, ll finish, int driverId, int distance);
    string newCompletedMissionsReport(int driverId);
    string missionsStatus(int driverId);
    virtual ~DriveManager();
};

#endif // DRIVEMANAGER_H_
