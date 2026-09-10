// links a passenger to a trip and handles the discount display

#ifndef CPLUSPLUSFINALPROJECT_BOOKING_H
#define CPLUSPLUSFINALPROJECT_BOOKING_H


#include <string>
#include "Trips.h"
#include "Discounts.h"
#include "Passenger.h"
using namespace std;

class Booking {
private:
    Passenger passenger;
    Trips trip;
    Discounts discounts;
    bool isCancelled;

public:
    /*constructor*/
    Booking();
    Booking(Passenger p, Trips t);

    /* getters for trips and passengers*/
    Passenger getPassenger() const;
    Trips getTrip() const;
    bool getIsCancelled() const;

    /*cancels a booking*/
    void cancelBooking();

    /*displays all bookings*/
    void displayBooking() const;
};

#endif //CPLUSPLUSFINALPROJECT_BOOKING_H