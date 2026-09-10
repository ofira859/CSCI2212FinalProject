//
// Created by Uwas on 02.04.26.
//

// Discounts.cpp

#include "Discounts.h"
using namespace std;

Discounts::Discounts() {
    isOnline = false;
    isStudent = false;
    isMilitary = false;
    isClubMember = false;
    basePrice = 0.0;
}

/*constructor to store the values, calculations happen in the functions below*/
Discounts::Discounts(bool online, bool student, bool military, bool club, double price) {
    isOnline = online;
    isStudent = student;
    isMilitary = military;
    isClubMember = club;
    basePrice = price;
}

/* checks all discounts and returns the best one as a decimal*/
double Discounts::getBestDiscount() const {
    double best = 0.0;

    /*starts checking eligibility and sets initial discount to 0 then filters through if
     * statement to find best discount
     */
    if (isMilitary && 0.20 > best) {
        best = 0.20;
    }
    if (isClubMember && 0.10 > best) {
        best = 0.10;
    }
    if ((isOnline || isStudent) && 0.05 > best) {
        best = 0.05;
    }
    return best;
}

/*returns price without discount*/
double Discounts::getPriceBeforeDiscount() const {
    return basePrice;
}

/*calculates price with discount*/
double Discounts::getPriceAfterDiscount() const {
    return basePrice * (1.0 - getBestDiscount());
}