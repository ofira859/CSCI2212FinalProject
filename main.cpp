//
// Created by Ofir
//

#include <iostream>
#include "Trips.h"
#include "Passenger.h"
#include "Tripmanager.h"
using namespace std;



int main() {

    TripManager manager;
    int roleChoice;

    /* loading all bookings and trips from files */
    manager.loadTripsFromFile("/Users/test/CLionProjects/cplusplusfinalproject/Trips.txt");
    manager.loadBookingsFromFile("/Users/test/CLionProjects/cplusplusfinalproject/Bookings.txt");

    /* initial bus ticketing system menu */
    do {
        cout << "\n==== BUS TICKETING SYSTEM ====" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Passenger" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your role: ";
        cin >> roleChoice;

        switch (roleChoice) {

            case 1: {
                int adminChoice;
                /* admin menu options */
                do {
                    cout << "\n==== ADMIN MENU ====" << endl;
                    cout << "1. Add Trip" << endl;
                    cout << "2. Remove Trip" << endl;
                    cout << "3. Display All Trips" << endl;
                    cout << "4. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> adminChoice;

                    switch (adminChoice) {
                        /* adding a new trip */
                        case 1: {
                            string source, destination, driver;
                            int distance, maxTravelers;

                            cin.ignore();
                            /* adding a new trip with everything it needs */
                            cout << "Enter source: ";
                            getline(cin, source);

                            cout << "Enter destination: ";
                            getline(cin, destination);

                            cout << "Enter distance in miles: ";
                            cin >> distance;

                            cin.ignore();

                            cout << "Enter driver name: ";
                            getline(cin, driver);

                            cout << "Enter max travelers: ";
                            cin >> maxTravelers;
                            /*stores in the constructor and adds trip to array of trips*/

                            Trips trip(source, destination, distance, driver, maxTravelers);
                            manager.addTrip(trip);
                            break;
                        }
                        /* removing a trip via the source and destination*/
                        case 2: {
                            string source, destination;

                            cin.ignore();

                            cout << "Enter source of trip to remove: ";
                            getline(cin, source);

                            cout << "Enter destination of trip to remove: ";
                            getline(cin, destination);
                            /*function call to remove trip*/
                            manager.removeTrip(source, destination);
                            break;
                        }
                        /* displaying all trips */
                        case 3:
                            manager.displayAllTrips();
                            break;
                            /*returns to main menu*/
                        case 4:
                            cout << "Returning to main menu." << endl;
                            break;
                        /* invalid input, try again (data validation)*/
                        default:
                            cout << "Invalid admin choice." << endl;
                    }

                } while (adminChoice != 4);

                break;
            }

            case 2: {
                int passengerChoice;
                /* passenger menu options */
                do {
                    cout << "\n==== PASSENGER MENU ====" << endl;
                    cout << "1. Book Ticket" << endl;
                    cout << "2. Cancel Ticket" << endl;
                    cout << "3. Display All Bookings" << endl;
                    cout << "4. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    cin >> passengerChoice;

                    switch (passengerChoice) {
                        /* booking a ticket prompting user for details*/
                        case 1: {
                            string name, source, destination;
                            char answer;
                            bool online, student, military, club;

                            cin.ignore();

                            cout << "Enter passenger name: ";
                            getline(cin, name);

                            cout << "Enter trip source: ";
                            getline(cin, source);

                            cout << "Enter trip destination: ";
                            getline(cin, destination);

                            cout << "Was this booked online? (y/n): ";
                            cin >> answer;
                            online = (answer == 'y' || answer == 'Y');

                            cout << "Is the passenger a student? (y/n): ";
                            cin >> answer;
                            student = (answer == 'y' || answer == 'Y');

                            cout << "Is the passenger military/veteran? (y/n): ";
                            cin >> answer;
                            military = (answer == 'y' || answer == 'Y');

                            cout << "Is the passenger a BUS_TRIPS club member? (y/n): ";
                            cin >> answer;
                            club = (answer == 'y' || answer == 'Y');
                            /* makes new Passenger object so functions may be implemented*/
                            Passenger passenger(name, online, student, military, club);
                            manager.bookTicket(passenger, source, destination);
                            break;
                        }
                        /* canceling a ticket based on passenger name and destination */
                        case 2: {
                            string passengerName, destination;

                            cin.ignore();

                            cout << "Enter passenger name: ";
                            getline(cin, passengerName);

                            cout << "Enter trip destination: ";
                            getline(cin, destination);

                            manager.cancelTicket(passengerName, destination);
                            break;
                        }
                        /* display all bookings */
                        case 3:
                            manager.displayAllBookings();
                            break;

                        case 4:
                            cout << "Returning to main menu." << endl;
                            break;
                        /* invalid input, try again (input validation)*/
                        default:
                            cout << "Invalid passenger choice." << endl;
                    }

                } while (passengerChoice != 4);

                break;
            }
            /* saving new bookings and trips into the files and exiting the program */
            case 3:
                manager.saveTripsToFile ("/Users/test/CLionProjects/cplusplusfinalproject/Trips.txt");
                manager.saveBookingsToFile("/Users/test/CLionProjects/cplusplusfinalproject/Bookings.txt");
                cout << "Exiting program. Goodbye!" << endl;
                break;
            /* invalid input, try again */
            default:
                cout << "Invalid role choice." << endl;
        }

    } while (roleChoice != 3); /*exits program after new data stored*/

    return 0;
}
