#include "functions.h"
#include "testLocation.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <chrono>
#include <algorithm>

using std::ifstream;
using std::ofstream;


//Function that counts the number of lines in the file
int countLines(std::string filename)
{
    int numOfLines = 0;
    ifstream infile;//file stream

    infile.open(filename);
    if(!infile.is_open()) { std::cout << "file not found" << std::endl; }
    else
    {
        std::string line;

        while(!infile.eof())
        {
            getline(infile, line);
            numOfLines++;
        }
        infile.close();
        return numOfLines;//return counter
    }
    return 0;
}

void readFileLocToArr(std::string filename, testLocation arr[])
    ifstream infile;

    infile.open(filename);
    if(!infile.is_open()) { std::cout << "file not found" << std::endl; }
    else
    {
        std::string address,city,name;//variables to hold location components
        int counter = 0;//used to count commas
        int arrCount = 0;
        std::string line;
        std::string cut;//cuts out a portion of line to place in appropriate variables (i.e adress, city, name)
        int cur = 0;//left bound of substring. initially set to 0 which is the first character in the string
        while(!infile.eof()) //Do all the stuff from line 63 to line 77 over and over again until it reaches end of file
        {
            getline(infile, line);//get the current line.
            for(int i = 0; i < line.length(); i++)//traverse through the chars of the line
            {
                if (line[i] == ',')//when iterator encounters a comma, that's when we do our work.
                {
                    cut = line.substr(cur, i - cur);//takes the portion of the line. from cur to i - cur. i - cur is right bound of substring
                    if(counter == 0) { name = cut; counter++; cur = i+1;}//if counter is zero, the cut is stored in the "name" variable.
                    else if(counter == 1) { address = cut; counter++; cur = i+1;}//on the next iteration of the for loop on line 59, the counter was incremented to one, so it goes to this block of the if else statement.
                    else if(counter == 2) { city = cut; counter = 0; cur = 0;}//reset counter and reset cur to prepare for next line.
                }//remember for if else statements, only ONE of these blocks executes per iteration.
            }
            arr[arrCount++].setData(address,city,name);//arrCount increments with each iteration of while loop on line 56.

        }
        infile.close();
    }
}

int validatedInt(int a, int b)//validate if the number is between a and b.
{
    int input;
    std::cin >> input;
    while(input < a || input > b || std::cin.fail())// while input less than a OR input more than b OR there's no input.
    {
        std::cout << "Invalid option, please enter a number from " << a << " to " << b << ": " << std::endl;
        std::cin.clear();
        std::cin.ignore(999999, '\n');//ignore newline so that the second cin below is not ignored.
        std::cin >> input;
    }
    return input;
}

// this function will print a division line on the screen to separate contents
void divisionLine() { std::cout << "------------------------------------------------------------------------------------------" << std::endl; }

// This is a function that checks if the letter is one of the 26 letters, upper or lower case
bool isLetter(char c) { return((c >= 65 && c <= 90) || (c >= 97 && c <= 122)); }//unicode values

int countWord(std::string filename)
{
    int numOfWords = 0;
    ifstream infile;
    bool have_word;

    infile.open(filename);
    if(!infile.is_open()) { std::cout << "file not found" << std::endl; }
    else
    {
        std::cout << "file opened" << std::endl;
        std::string line;

        while(!infile.eof())
        {
            getline(infile, line);
            for(int i = 0; i < line.length(); i++)
            {
                have_word = false;
                while(!isLetter(line[i])){ i++; }//while iterator is not a letter. line[i] is position of iterator. i++ = go to next letter
                while(i < line.length() && (isLetter(line[i]) || line[i] == '\'' || (line[i] == '-' && line[i+1] != '-'))) { i++; have_word = true;}
                if(have_word){ numOfWords++; }//^ line above is basically: while(i < line length AND (isLetter returns true OR the iterator in "line" is a backspace OR (a dash AND the character after is NOT a dash))) then increment the iterator and have_word = true
            }//if have_word is true, increment the number of words counter. So while it's not at the end of the line
        }   //important note about line 116. line[i] == '\'' is checking for a single quote aka apostrophe. We need the backslash to distinguish it. Related to escape sequence.
        infile.close();
        std::cout << "Number of words: " << numOfWords << std::endl;
        return numOfWords;
    }
    return 0;
}

std::vector<std::string> splite(std::string str)//vector of string. use for FileToTree function
{

    std::vector<std::string> res;
    std::string word;
    for(int i = 0; i < str.length(); i++)//eliminate punctuation
    {
        if(ispunct(str[i]))
        {
            str.erase(i--, 1);//.erase() means begin at i-- and span the length of 1. so start at previous character and erase the next one.
        }
    }
    for (auto x : str)//a for loop that goes through entire string. str is the parameter. x is at the beginning
        {
            if (!isalpha(x))
            {
                res.push_back(word);
                word = "";
            }
            else
            {
                word = word + x;
            }
        }
        res.push_back(word);
    return res;
}
