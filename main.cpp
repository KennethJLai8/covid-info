#include <iostream>
#include "testLocation.h"
#include "functions.h"
#include "prevention.h"
#include "symptoms.h"
#include "tree.h"
#include <vector>
#include <string>
#include <fstream>
#include <stack>


int main() {
    std::string menu =//string that contains the whole menu.
       "Welcome to our COVID-19 WIKI about the COVID-19 virus( ´ ▽ ` )ﾉ"
       "\nWHAT WOULD YOU LIKE TO DO(´･ω･`)?\n"
       "HERE ARE OUR OPTIONS:\n"
       "1.List of Test Areas of Bay Area\n"
       "2.List of Symptoms\n"
       "3.Prevention Methods\n"
    "4.Search for symptoms\n"
    "5.Source Page\n";


    int choice = 0; // variable that holds the user's choice in main menu
    int quit = 0; // variable that holds the user's choice for action after viewing a page

    // this is the stack that keeps track of the pages that the user viewed
    std::stack<int> pages;//for backtracking

    while(quit != 1)
    {
        // if the user choose to look at the main menu again, show them the main menu again and ask for option
        if(quit != 3)
        {
            divisionLine();
            std::cout << menu;
            choice = validatedInt(1,7);
            pages.push(choice);
        }
         // show user the message if the pages stack is empty
        else if(quit == 3 && pages.empty())
        {
            std::cout << "You are currently at the first page you viewed, can't go back anymore.(´∀｀ゞ)" << std::endl;
            choice = 0;
        }
        else if(quit == 3 && !pages.empty()) // go back to the previous page, pop the first element from the stack
        {
            // otherwise, set the chocie to the previous page's number and pop that num from the page stack
            choice = pages.top();
            pages.pop();
        }

        // the following is the operation for each choice in the main menu
        if(choice == 1)//menu option 1.
        {
            divisionLine();
            std::cout << "                          Test Locations In the Bay Area: " << std::endl << std::endl;
            std::string filename  = "locations.txt";
            int numOfLines = countLines(filename);

            testLocation* arr = new testLocation[numOfLines];//an array of TestLocation objects
            readFileLocToArr(filename, arr);//Where the array is actually made
            std::cout << std::setw(30) << std::left << "     Name" << std::setw(30) << std::left << "     Address" << std::setw(30) << std::left << "     City" << std::endl;
            divisionLine();
            for(int i = 0; i < numOfLines; i++)
            {
                arr[i].printAll();
            }
        }
        else if (choice == 2)
        {
            std::cout << "This is the list of symptoms page." << std::endl;
            fileToMap();
        }
        else if (choice == 3) {
            divisionLine();
            std::cout << "                          Prevention Methods: " << std::endl << std::endl;
            fileToNode();
        }
        else if (choice == 4)
        {
            // search for symptoms
            divisionLine();
            fileToTree();
        }
        else if (choice == 5)
        {
            std::cout << "Sources Pages" << std::endl;
        }
        // end of main menu operations

        // ask user for the next step after viewing one page
        divisionLine();
        std::cout << "\nYou are currently at the main menu. Would you like to quit the program(´･ω･`)?\n";
        std::cout << "1. Yes I want to quit(╯°Д°)╯ ┻━┻\n2. I want to look at something else( σ'ω')σ\n3. I want to go back to the last page I viewed ('ω' )\n";
        quit = validatedInt(1, 3);
    }
    divisionLine();
    std::cout << "\n                          Thanks for using this program! (￣▽￣)ノBye!\n\n";
    divisionLine();
    return 0;
}
