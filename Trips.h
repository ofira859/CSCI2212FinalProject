//
// Created by Ofir
//

#ifndef CPLUSPLUSFINALPROJECT_TRIPS_H
#define CPLUSPLUSFINALPROJECT_TRIPS_H

#include <string>
using namespace std;

    class Trips {
    private:
        // these are the variables we'll use to store the trip information
        string source;
        string destination;
        int distance;
        string driver;
        int maxTravelers;

    public:
        Trips();
        Trips(string s, string d, int dist, string dr, int maxT);
        /* these will be the "getter" functions that will allow us to access the data of the trip*/
        string getSource() const;
        string getDestination() const;
        int getDistance() const;
        string getDriver() const;
        int getMaxTravelers() const;

        /* these will be the "setter" functions that we're gonna use to make changes in the values of the trip data*/
        void setSource(string s);
        void setDestination(string d);
        void setDistance(int dist);
        void setDriver(string dr);
        void setMaxTravelers(int maxT);

        /* this function will be used to calculate the price of the trip per mile*/
        double calculatePrice() const;

        /* this function will display all the trip information*/
        void displayTrip() const;
    };




#endif //CPLUSPLUSFINALPROJECT_TRIPS_H