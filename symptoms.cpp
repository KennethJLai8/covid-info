#include "symptoms.h"
#include "functions.h"
#include<iostream>
#include<fstream>
#include<string>
#include <vector>

void Symptoms::add_entry(std::string key, std::string description){
    data[key] = description;
}

void Symptoms::printMap(){

    int choice;
    std::vector<std::string> keyvec;
    int quit = 0;
    while(quit != 2)
    {
        divisionLine();
        int counter = 1;
        for (std::unordered_map<std::string, std::string>::iterator pos = data.begin(); pos != data.end(); pos++)
       {
          std::cout << counter << ". " << pos->first << std::endl;
           counter++;
           keyvec.push_back(pos->first);
       }
        divisionLine();
        std::cout << "Which symptom would you like to read about?" << std::endl;
        choice = validatedInt(1, counter-1);
        divisionLine();
        std::cout << keyvec[choice-1] << ":" << std::endl << std::endl;
        std::cout << data[keyvec[choice-1]] << std::endl;
        divisionLine();
        std::cout << "Would you like to look at another symptom?" << std::endl;
        std::cout << "1. Yes I want to read another one\n2. No I'm done looking at symptoms." << std::endl;
        quit = validatedInt(1, 2);
    }
}

void fileToMap(){//puts file in a map
    std::ifstream infile;
    std::string line;
    std::string keyWord;
    std::string Description;
    const char sc = '|';
    Symptoms a;

    infile.open("/Users/kennethlai/Documents/CS-124/finalproject/symptoms.txt");

  if(infile.fail())
    {
      std::cout << "Cannot open file\n";
    }
  else
    {
      std::getline(infile, line);
      while(!infile.eof())
        {
            Description = "";
            if(line[0]== sc){
                keyWord = line.substr(1);
                std::getline(infile, line);
            }

            while(line[0]!= sc && !infile.eof()){
                Description += line;
                std::getline(infile, line);
            }
            a.add_entry(keyWord, Description);
        }
    }
    a.printMap();
}

std::unordered_map<std::string, std::string> Symptoms::returnMap()
{
    return data;
}
