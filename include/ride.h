#ifndef RIDE_H_
#define RIDE_H_

#include "general.h"

class Ride{
private:
    ll start;
    ll finish;
    int distance;
public:
    Ride();
    Ride(ll _start, ll _finish, int _distance);
    ll getStart() { return start; }
    ll getFinish() { return finish; }
    int getDistance() { return distance; }
};

#endif // RIDE_H_
