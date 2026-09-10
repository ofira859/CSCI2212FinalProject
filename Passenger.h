// Passenger.h
// holds all the info about the person booking the ticket
// instead of passing a bunch of loose bools everywhere, we just pass one Passenger object

#ifndef CPLUSPLUSFINALPROJECT_PASSENGER_H
#define CPLUSPLUSFINALPROJECT_PASSENGER_H


#include <string>
using namespace std;

class Passenger {
private:
    string name;
    bool isOnline;
    bool isStudent;
    bool isMilitary;
    bool isClubMember;

public:
    Passenger();
    Passenger(string n, bool online, bool student, bool military, bool club);

    /*gets all passenger discounts eligibility in boolean*/
    string getName() const;
    bool getIsOnline() const;
    bool getIsStudent() const;
    bool getIsMilitary() const;
    bool getIsClubMember() const;

    /* setters to set a name with their corresponding eligibility */
    void setName(string n);
    void setIsOnline(bool online);
    void setIsStudent(bool student);
    void setIsMilitary(bool military);
    void setIsClubMember(bool club);

    /** prints passenger info and which discounts they qualify for
     * (To be used for testing pyrposes)
     */
    void displayPassenger() const;
};

#endif //CPLUSPLUSFINALPROJECT_PASSENGER_H