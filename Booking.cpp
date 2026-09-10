//
// Created by Uwas on 02.04.26.
// Booking.cpp

#include "Booking.h"
#include <iostream>
using namespace std;

Booking::Booking() {
    isCancelled = false;
}

/* passenger already has the discount flags, so we just pull them out and pass the price
*/
Booking::Booking(Passenger p, Trips t) {
    passenger = p;
    trip = t;
/* This is where we pull the discount flags*/
    discounts = Discounts(p.getIsOnline(), p.getIsStudent(), p.getIsMilitary(), p.getIsClubMember(), t.calculatePrice());
    isCancelled = false;
}

// getters

/*Gets passenger object info through the passenger class*/
Passenger Booking::getPassenger() const {
    return passenger;
}
/*Gets trip object info through the trips class*/
Trips Booking::getTrip() const {
    return trip;
}
/*returns if a trip is stored as cancelled(true) or not(false)*/
bool Booking::getIsCancelled() const {
    return isCancelled;
}
/*changes status of booking to cancelled by calling isCancelled and setting to true*/
void Booking::cancelBooking() {
    isCancelled = true;
    /*confirmation message that trip got cancelled*/
    cout << "Booking for " << passenger.getName() << " on trip from "
         << trip.getSource() << " to " << trip.getDestination()
         << " has been cancelled." << endl;
}
/*Displays all bookings stored and their status*/
void Booking::displayBooking() const {
    cout << "-----------------------------" << endl;
    cout << "Passenger: " << passenger.getName() << endl;
    cout << "Trip: " << trip.getSource() << " -> " << trip.getDestination() << endl;
    cout << "Distance: " << trip.getDistance() << " miles" << endl;

    /** pull discount flags from passenger since they are stored there now*
     * prints all discounts a passenger qualifies for
     */
    cout << "Discounts: ";
    if (!passenger.getIsMilitary() && !passenger.getIsClubMember()
        && !passenger.getIsStudent() && !passenger.getIsOnline()) {
        cout << "None";
        } else {
            if (passenger.getIsMilitary()) {
                cout << "[Military 20%] ";
            }
            if (passenger.getIsClubMember()) {
                cout << "[Club 10%] ";
            }
            if (passenger.getIsStudent()) {
                cout << "[Student 5%] ";
            }
            if (passenger.getIsOnline()) {
                cout << "[Online 5%] ";
            }
        }
    cout << endl;
    /* Prints out the final best discount the customer gets applied to trip, and price
     * before and after its applied
     */
    cout << "Applied Discount: " << (discounts.getBestDiscount() * 100) << "%" << endl;
    cout << "Price Before Discount: $" << discounts.getPriceBeforeDiscount() << endl;
    cout << "Price After Discount:  $" << discounts.getPriceAfterDiscount() << endl;

    if (isCancelled) {
        cout << "Status: CANCELLED" << endl;
    } else {
        cout << "Status: CONFIRMED" << endl;
    }
    cout << "-----------------------------" << endl;
}