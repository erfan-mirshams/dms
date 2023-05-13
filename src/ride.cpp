#include "../include/ride.h"

Ride::Ride(){
    start = finish = distance = 0;
}

Ride::Ride(ll _start, ll _finish, int _distance){
    start = _start;
    finish = _finish;
    distance = _distance;
}
