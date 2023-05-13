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
