//
// Created by Uwas on 23.04.26.
//

#include "Tripmanager.h"
#include <iostream>
using namespace std;

/*the constructor initializes the counts to 0*/
TripManager::TripManager() {
    tripCount = 0;
    bookingCount = 0;
}

/*searches for a trip based on source and destination
if found it returns the index of that trip in the array
if not found it returns -1 */
int TripManager::findTripIndex(string source, string destination) const {
    for (int i = 0; i < tripCount; i++) {
        if (trips[i].getSource() == source &&
            trips[i].getDestination() == destination) {
            return i;
        }
    }
    return -1;
}

/*searches for an existing booking using the passenger name and the destination
also makes sure the booking is not cancelled */
int TripManager::findBookingIndex(string passengerName, string destination) const {
    for (int i = 0; i < bookingCount; i++) {
        if (bookings[i].getPassenger().getName() == passengerName &&
            bookings[i].getTrip().getDestination() == destination &&
            !bookings[i].getIsCancelled()) {
            return i;
        }
    }
    return -1;
}

/*adds a new trip to the trips array*/
void TripManager::addTrip(Trips t) {
    if (tripCount >= MAX_TRIPS) {
        cout << "Cannot add trip. Trip list is full." << endl;
        return;
    }
    trips[tripCount] = t;
    tripCount++;
    cout << "Trip added successfully." << endl;
}

/*removes a trip based on the source and destination*/
void TripManager::removeTrip(string source, string destination) {
    int index = findTripIndex(source, destination);
    if (index == -1) {
        cout << "Trip not found." << endl;
        return;
    }
    for (int i = index; i < tripCount - 1; i++) {
        trips[i] = trips[i + 1];
    }
    tripCount--;
    cout << "Trip removed successfully." << endl;
}

/*displays all trips in the array*/
void TripManager::displayAllTrips() const {
    cout << endl;
    if (tripCount == 0) {
        cout << "No trips available." << endl;
        return;
    }
    for (int i = 0; i < tripCount; i++) {
        cout << "Trip #" << i + 1 << endl;
        trips[i].displayTrip();

        /* Count active bookings for this trip*/
        int activeBookings = 0;
        for (int j = 0; j < bookingCount; j++) {
            if (bookings[j].getTrip().getSource() == trips[i].getSource() &&
                bookings[j].getTrip().getDestination() == trips[i].getDestination() &&
                !bookings[j].getIsCancelled()) {
                activeBookings++;
                }
        }
        cout << "Passengers: " << activeBookings << "/" << trips[i].getMaxTravelers() << endl;

        if (i < tripCount - 1) {
            cout << endl;
        }
    }
}

/*books a ticket for a passenger to a specific trip*/
void TripManager::bookTicket(Passenger p, string source, string destination) {
    /* find the trip by source and destination*/
    int tripIndex = findTripIndex(source, destination);
    if (tripIndex == -1) {
        cout << "Trip not found." << endl;
        return;
    }
    /*check if booking list is full*/
    if (bookingCount >= MAX_BOOKINGS) {
        cout << "Cannot book ticket. Booking list is full." << endl;
        return;
    }
    int currentBookings = 0;
    for (int i = 0; i < bookingCount; i++) {
        /*count active bookings for this trip*/
        if (bookings[i].getTrip().getSource() == source &&
            bookings[i].getTrip().getDestination() == destination &&
            !bookings[i].getIsCancelled()) {
            currentBookings++;
        }
    }
    /*check if trip is full*/
    if (currentBookings >= trips[tripIndex].getMaxTravelers()) {
        cout << "cannot book Ticket. This trip is full." << endl;
        return;
    }
    /*create and store the booking*/
    bookings[bookingCount] = Booking(p, trips[tripIndex]);
    bookingCount++;
    cout << "Ticket booked successfully." << endl;
    bookings[bookingCount - 1].displayBooking();
}

/*cancels a booking based on passenger name and destination*/
void TripManager::cancelTicket(string passengerName, string destination) {
    int index = findBookingIndex(passengerName, destination);
    if (index == -1) {
        cout << "Booking not found." << endl;
        return;
    }
    bookings[index].cancelBooking();
}

/* displays all bookings (including cancelled ones) */
void TripManager::displayAllBookings() const {
    if (bookingCount == 0) {
        cout << "No bookings found." << endl;
        return;
    }
    for (int i = 0; i < bookingCount; i++) {
        bookings[i].displayBooking();
    }
}

/* saves new trips into Trips.txt file */
void TripManager::saveTripsToFile(string filename) const {
    ofstream file(filename);

    for (int i = 0; i < tripCount; i++) {
        file << trips[i].getSource() << ","
             << trips[i].getDestination() << ","
             << trips[i].getDistance() << ","
             << trips[i].getDriver() << ","
             << trips[i].getMaxTravelers() << endl;
    }

    file.close();
}

/* loading trips from the Trips.txt file into the system */
void TripManager::loadTripsFromFile(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "No trips file found yet." << endl;
        return;
    }

    tripCount = 0;

    string source, destination, distanceStr, driver, maxStr;

    while (getline(file, source, ',') &&
           getline(file, destination, ',') &&
           getline(file, distanceStr, ',') &&
           getline(file, driver, ',') &&
           getline(file, maxStr)) {
        int distance = stoi(distanceStr);
        int maxTravelers = stoi(maxStr);

        trips[tripCount] = Trips(source, destination, distance, driver, maxTravelers);
        tripCount++;
           }

    file.close();
}

/* saves new bookings into Bookings.txt file */
void TripManager::saveBookingsToFile(string filename) const {
    ofstream file(filename);

    for (int i = 0; i < bookingCount; i++) {

        Passenger p = bookings[i].getPassenger();
        Trips t = bookings[i].getTrip();

        file << p.getName() << ","
             << p.getIsOnline() << ","
             << p.getIsStudent() << ","
             << p.getIsMilitary() << ","
             << p.getIsClubMember() << ","
             << t.getSource() << ","
             << t.getDestination() << ","
             << t.getDistance() << ","
             << t.getDriver() << ","
             << t.getMaxTravelers() << ","
             << bookings[i].getIsCancelled()
             << endl;
    }

    file.close();
}

/* loads bookings from Bookings.txt file */
void TripManager::loadBookingsFromFile(string filename) {
    ifstream file(filename);

    if (!file) {
        cout << "No bookings file found yet." << endl;
        return;
    }

    bookingCount = 0;

    string name, onlineStr, studentStr, militaryStr, clubStr;
    string source, destination, distanceStr, driver, maxStr, cancelStr;

    while (getline(file, name, ',') &&
           getline(file, onlineStr, ',') &&
           getline(file, studentStr, ',') &&
           getline(file, militaryStr, ',') &&
           getline(file, clubStr, ',') &&
           getline(file, source, ',') &&
           getline(file, destination, ',') &&
           getline(file, distanceStr, ',') &&
           getline(file, driver, ',') &&
           getline(file, maxStr, ',') &&
           getline(file, cancelStr)) {

        bool online = stoi(onlineStr);
        bool student = stoi(studentStr);
        bool military = stoi(militaryStr);
        bool club = stoi(clubStr);

        int distance = stoi(distanceStr);
        int maxTravelers = stoi(maxStr);
        bool isCancelled = stoi(cancelStr);

        Passenger p(name, online, student, military, club);
        Trips t(source, destination, distance, driver, maxTravelers);

        bookings[bookingCount] = Booking(p, t);

        if (isCancelled) {
            bookings[bookingCount].cancelBooking();
        }

        bookingCount++;
           }

    file.close();
}