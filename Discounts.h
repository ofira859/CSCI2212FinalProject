// Discounts.h
// handles discount logic and price calculations
// only applies the best discount, not multiple

#ifndef CPLUSPLUSFINALPROJECT_DISCOUNTS_H
#define CPLUSPLUSFINALPROJECT_DISCOUNTS_H

using namespace std;

class Discounts {
private:
    bool isOnline;
    bool isStudent;
    bool isMilitary;
    bool isClubMember;
    double basePrice;

public:
    /*constructors*/
    Discounts();
    Discounts(bool online, bool student, bool military, bool club, double price);

    /* functions to find and apply best discount eligibility*/
    double getBestDiscount() const;
    double getPriceBeforeDiscount() const;
    double getPriceAfterDiscount() const;
};

#endif //CPLUSPLUSFINALPROJECT_DISCOUNTS_H