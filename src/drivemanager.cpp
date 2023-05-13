#include "../include/drivemanager.h"

string DriveManager::handleCommand(vector<string> cmd){
    if(isValidCommand(cmd, ADD_TIME_MISSION)){
        addTimeMission(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]), stoi(cmd[5]));
        return OK_STR;
    }
    if(isValidCommand(cmd, ADD_DISTANCE_MISSION)){
        addDistanceMission(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]), stoi(cmd[5]));
        return OK_STR;
    }
    if(isValidCommand(cmd, ADD_COUNT_MISSION)){
        addCountMission(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]), stoi(cmd[5]));
        return OK_STR;
    }
    if(isValidCommand(cmd, ASSIGN_MISSION)){
        assignMission(stoi(cmd[1]), stoi(cmd[2]));
        return OK_STR;
    }
    if(isValidCommand(cmd, RECORD_RIDE)){
        recordRide(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]));
        return newCompletedMissionsReport(stoi(cmd[3]));
    }
    if(isValidCommand(cmd, SHOW_MISSIONS_STATUS)){
        return missionsStatus(stoi(cmd[1]));
    }
    throw logic_error(INVALID_ARGUMENTS_MSG);
}

void DriveManager::addTimeMission(int _id, ll _start, ll _finish, int _timeInMins, int _reward){
    if(!isTimeSegmentValid(_start, _finish) || _timeInMins < 0 || _reward < 0){
        throw logic_error(INVALID_ARGUMENTS_MSG);
    }
    if(findMissionById(_id) == NULL){
        missions.push_back(new TimeMission(_id, _start, _finish, _timeInMins, _reward));
    }
    else{
        throw logic_error(DUPLICATE_MISSION_MSG);
    }
}

void DriveManager::addDistanceMission(int _id, ll _start, ll _finish, int _distance, int _reward){
    if(!isTimeSegmentValid(_start, _finish) || _distance < 0 || _reward < 0){
        throw logic_error(INVALID_ARGUMENTS_MSG);
    }
    if(findMissionById(_id) == NULL){
        missions.push_back(new DistanceMission(_id, _start, _finish, _distance, _reward));
    }
    else{
        throw logic_error(DUPLICATE_MISSION_MSG);
    }
}

void DriveManager::addCountMission(int _id, ll _start, ll _finish, int _count, int _reward){
    if(!isTimeSegmentValid(_start, _finish) || _count < 0 || _reward < 0){
        throw logic_error(INVALID_ARGUMENTS_MSG);
    }
    if(findMissionById(_id) == NULL){
        missions.push_back(new CountMission(_id, _start, _finish, _count, _reward));
    }
    else{
        throw logic_error(DUPLICATE_MISSION_MSG);
    }
}

Mission* DriveManager::findMissionById(int _id){
    for(auto m : missions){
        if(m -> getId() == _id){
            return m;
        }
    }
    return NULL;
}

Driver* DriveManager::findDriverById(int _id){
    for(auto d : drivers){
        if(d -> getId() == _id){
            return d;
        }
    }
    return NULL;
}

void DriveManager::assignMission(int missionId, int driverId){
    Mission* mission = findMissionById(missionId);
    if(mission == NULL){
        throw logic_error(MISSION_NOT_FOUND_MSG);
    }
    Driver* driver = findDriverById(driverId);
    if(driver == NULL){
        driver = new Driver(driverId);
        drivers.push_back(driver);
    }
    driver -> assignMission(mission);
}

void DriveManager::recordRide(ll start, ll finish, int driverId, int distance){
    Driver* driver = findDriverById(driverId);
    if(driver == NULL){
        return;
    }
    if(!isTimeSegmentValid(start, finish)){
        throw logic_error(INVALID_ARGUMENTS_MSG);
    }
    driver -> addRide(start, finish, distance);
}

string DriveManager::newCompletedMissionsReport(int driverId){
    Driver* driver = findDriverById(driverId);
    ostringstream output;
    output << "completed missions for driver " << driverId << ":" << endl;
    if(driver == NULL){
        return output.str();
    }
    output << driver -> newCompletedMissionsReport();
    return output.str();
}

DriveManager::~DriveManager(){
    for(auto m : missions){
        delete m;
    }
    for(auto d : drivers){
        delete d;
    }
}

string DriveManager::missionsStatus(int driverId){
    ostringstream output;
    Driver* driver = findDriverById(driverId);
    if(driver == NULL){
        throw logic_error(DRIVER_MISSION_NOT_FOUND);
    }
    output << "missions status for driver " << driverId << ": " << endl;
    output << driver -> getMissionsStatus();
    return output.str();
}
