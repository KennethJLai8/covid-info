#ifndef symptoms_hpp
#define symptoms_hpp
#include <unordered_map>
#include <string>

class Symptoms{
public:
    void printMap();
    void add_entry(std::string key,std::string description);
    std::unordered_map<std::string, std::string> returnMap();
private:
    std::unordered_map<std::string, std::string> data;
};

void fileToMap();



#endif

