#include "Trips.h"
#include <iostream>
using namespace std;

/* initializing all the variables to empty them out */
Trips::Trips() {
    source = "";
    destination = "";
    distance = 0;
    driver = "";
    maxTravelers = 0;
}
/*the constructor sets all the values when an object is created*/
Trips::Trips(string s, string d, int dist, string dr, int maxT) {
    source = s;
    destination = d;
    distance = dist;
    driver = dr;
    maxTravelers = maxT;
}
/*getter function for the trip source*/
string Trips::getSource() const {
    return source;
}

/*getter function for the trip destination*/
string Trips::getDestination() const {
    return destination;
}

/*getter function for the trip distance*/
int Trips::getDistance() const {
    return distance;
}

/*getter functions for the trip driver*/
string Trips::getDriver() const {
    return driver;
}

/*getter function for the trip max travelers*/
int Trips::getMaxTravelers() const {
    return maxTravelers;
}

/*setter function for the trip source*/
void Trips::setSource(string s) {
    source = s;
}

/*setter function for the trip destination*/
void Trips::setDestination(string d) {
    destination = d;
}

/*setter function for the trip distance*/
void Trips::setDistance(int dist) {
    distance = dist;
}

/*setter function for the trip driver*/
void Trips::setDriver(string dr) {
    driver = dr;
}

/*setter function for the trip max travelers*/
void Trips::setMaxTravelers(int maxT) {
    maxTravelers = maxT;
}

/*the function that calculates the price per mile*/
double Trips::calculatePrice() const {
    return distance * 1.25;
}

/*printing all trip information*/
void Trips::displayTrip() const {
    cout << "Source: " << source << endl;
    cout << "Destination: " << destination << endl;
    cout << "Distance: " << distance << " miles" << endl;
    cout << "Driver: " << driver << endl;
    cout << "Max Travelers: " << maxTravelers << endl;
    cout << "Base Ticket Price: $" << calculatePrice() << endl;
}