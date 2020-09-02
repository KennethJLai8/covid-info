//main functions declarations


#ifndef functions_hpp
#define functions_hpp
#include <stdio.h>
#include "testLocation.h"
#include <string>
#include <set>


void readFileLocToArr(std::string, testLocation[]);
int countLines(std::string);
int validatedInt(int, int);
void divisionLine();
void toWordsSet(std::string, std::string[]);
void setToArray(std::set<std::string>, std::string[]);
int countWord(std::string);
bool isLetter(char);
std::vector<std::string> splite(std::string);



#endif
