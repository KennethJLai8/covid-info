#include <string>
#include <iostream>
#include <iomanip>
#include "testLocation.h"

// default constructor
testLocation::testLocation()
{
    address = "N/A";
    city = address;
    name = address;
}

// constructor
testLocation::testLocation(std::string cit,std::string add,std::string nam)
{
    address = add;
    city = cit;
    name = nam;
}

// function that returns the address of the test location
std::string testLocation::getAdd() const
{
    return address;
}

// function that returns the address of the test location
std::string testLocation::getCity() const
{
    return address;
}

// function that returns the name of the test location
std::string testLocation::getName() const
{
    return address;
}

// function that prints out all the information about the test location
void testLocation::printAll()
{
    std::cout << std::setw(30) << std::left << name << std::setw(30) << std::left << address << std::setw(30) << std::left << city << std::endl;
}
//initializes data for sorting purposes
void testLocation::setData(std::string add,std::string cit,std::string nam)
{
    address = add;
    city = cit;
    name = nam;
}
