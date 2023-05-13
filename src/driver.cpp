#include "../include/driver.h"

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
        missions.push_back(mission);
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
        if(isInCompletedIndexes(i)){
            continue;
        }
        if(missions[i] -> isCompleted(rides)){
            output << missions[i] -> getInfo() << endl;
            completedIndexes.push_back(i);
        }
    }
    return output.str();
}

string Driver::getMissionsStatus(){
    ostringstream output;
    for(int i = 0; i < (int)missions.size(); i++){
        output << missions[i] -> getInfo() << "status: "<< (isInCompletedIndexes(i) ? "completed" : "ongoing") << endl;
    }
    return output.str();
}
