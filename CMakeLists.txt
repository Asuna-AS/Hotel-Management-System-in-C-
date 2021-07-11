cmake_minimum_required(VERSION 3.18)
project(Hotel_Management_System_in_C_)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Hotel_Management_System_in_C_
        app.cpp
        user.h
        user.cpp
        customer.h
        customer.cpp
       admin.h
        hotel.h
        hotel.cpp
       acroom.h
     nonac.h
        room.h
        room.cpp)
