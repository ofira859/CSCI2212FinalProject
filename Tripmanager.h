//
// Created by Uwas on 23.04.26.
//

#ifndef CPLUSPLUSFINALPROJECT_TRIPMANAGER_H
#define CPLUSPLUSFINALPROJECT_TRIPMANAGER_H

#include <fstream>
#include <string>
#include "Trips.h"
#include "Booking.h"
#include "Passenger.h"
using namespace std;

const int MAX_TRIPS    = 50;
const int MAX_BOOKINGS = 50;

class TripManager {
private:
    Trips trips[MAX_TRIPS];
    int tripCount;

    Booking bookings[MAX_BOOKINGS];
    int bookingCount;

    /* helpers to find an index, return -1 if not found */
    int findTripIndex(string source, string destination) const;
    int findBookingIndex(string passengerName, string destination) const;

public:
    TripManager();

    /* trip management */
    void addTrip(Trips t);
    void removeTrip(string source, string destination);
    void displayAllTrips() const;

    /* booking management */
    void bookTicket(Passenger p, string source, string destination);
    void cancelTicket(string passengerName, string destination);
    void displayAllBookings() const;

    /* writing trips into file and reading from file */
    void saveTripsToFile(string filename) const;
    void loadTripsFromFile(string filename);

    /* writing bookings into file and reading from file */
    void saveBookingsToFile(string filename) const;
    void loadBookingsFromFile(string filename);
};


#endif //CPLUSPLUSFINALPROJECT_TRIPMANAGER_H