cmake_minimum_required(VERSION 4.1)
project(cplusplusfinalproject)

set(CMAKE_CXX_STANDARD 14)

add_executable(cplusplusfinalproject
        main.cpp
        Trips.cpp
        Trips.h
        Discounts.cpp
        Discounts.h
        Booking.cpp
        Booking.h
        Passenger.cpp
        Passenger.h
        Tripmanager.cpp
        Tripmanager.h
)
