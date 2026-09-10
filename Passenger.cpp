#include "Passenger.h"
#include <iostream>
using namespace std;

Passenger::Passenger() {
    name = "";
    isOnline = false;
    isStudent = false;
    isMilitary = false;
    isClubMember = false;
}

Passenger::Passenger(string n, bool online, bool student, bool military, bool club) {
    name = n;
    isOnline = online;
    isStudent = student;
    isMilitary = military;
    isClubMember = club;
}

// getters
string Passenger::getName() const {
    return name;
}

bool Passenger::getIsOnline() const {
    return isOnline;
}

bool Passenger::getIsStudent() const {
    return isStudent;
}

bool Passenger::getIsMilitary() const {
    return isMilitary;
}

bool Passenger::getIsClubMember() const {
    return isClubMember;
}

// setters
void Passenger::setName(string n) {
    name = n;
}

void Passenger::setIsOnline(bool online) {
    isOnline = online;
}

void Passenger::setIsStudent(bool student) {
    isStudent = student;
}

void Passenger::setIsMilitary(bool military) {
    isMilitary = military;
}

void Passenger::setIsClubMember(bool club) {
    isClubMember = club;
}

// shows the passenger and which discounts they qualify for
void Passenger::displayPassenger() const {
    cout << "Passenger: " << name << endl;
    cout << "Discount Eligibility: ";
    if (!isOnline && !isStudent && !isMilitary && !isClubMember) {
        cout << "None";
    } else {
        if (isMilitary)   cout << "[Military] ";
        if (isClubMember) cout << "[Club Member] ";
        if (isStudent)    cout << "[Student] ";
        if (isOnline)     cout << "[Online] ";
    }
    cout << endl;
}