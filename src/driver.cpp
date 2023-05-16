#include "../include/driver.h"


bool missionCmp(Mission* a, Mission* b){
    return a -> isBefore(b);
}

Driver::Driver(int _id){
    id = _id;
}

Mission* Driver::findMissionById(int id){
    for(auto m : missions){
        if(m -> getId() == id){
            return m;
        }
    }
    return NULL;
}

void Driver::assignMission(Mission *mission){
    if(findMissionById(mission -> getId()) == NULL){
        mission -> setStartRideIndex(id, (int)rides.size());
        missions.push_back(mission);
        sort(missions.begin(), missions.end(), missionCmp);
    }
    else{
        throw logic_error(DUPLICATE_DRIVER_MSG);
    }
}

void Driver::addRide(ll start, ll finish, int distance){
    rides.push_back(Ride(start, finish, distance));
}

bool Driver::isInCompletedIndexes(int ind){
    for(auto x : completedIndexes){
        if(ind == x){
            return true;
        }
    }
    return false;
}

string Driver::newCompletedMissionsReport(){
    ostringstream output;
    for(int i = 0; i < (int)missions.size(); i++){
        if(isInCompletedIndexes(missions[i] -> getId())){
            continue;
        }
        if(missions[i] -> isCompleted(id, rides)){
            missions[i] -> setEndTimeStamp(id, rides[(int)rides.size() - 1].getFinish() + 1);
            output << missions[i] -> getInfo(id) << endl;
            completedIndexes.push_back(missions[i] -> getId());
        }
    }
    return output.str();
}

string Driver::getMissionsStatus(){
    ostringstream output;
    for(int i = 0; i < (int)missions.size(); i++){
        output << missions[i] -> getInfo(id) << "status: "<< (isInCompletedIndexes(missions[i] -> getId()) ? "completed" : "ongoing") << endl;
    }
    return output.str();
}
