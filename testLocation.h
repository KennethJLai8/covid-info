#ifndef TestLocation_H
#define TestLocation_H

#include <string>
#include <iomanip>
#include <iostream>

class testLocation
{
private:
    std::string address;
    std::string city;
    std::string name;
public:
    testLocation();
    testLocation(std::string,std::string,std::string);
    std::string getAdd() const;
    std::string getCity() const;
    std::string getName() const;
    void setData(std::string,std::string,std::string);//Sets data that is read in from test location file.
    void printAll();
};

#endif
