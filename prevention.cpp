#include "prevention.h"
#include<iostream>
#include<fstream>
#include<string>
#include "prevention.h"

//prints the whole linkedlist to the screen line by line
void print(Node* hp)
{
  Node* n = hp;
  while(n != nullptr)
    {
      std::cout << n->data << " ";
      n = n->next;

      std::cout << std::endl;
    }
}

// this function will construct the nodes.
void buildList(std::string d, Node* &hp, Node* &tp)
{
  Node* temp = new Node;
  temp->data = d;//initialize new node with data from parameter
  if (hp == nullptr)
    {
      tp = temp;
      hp = temp;
    }
  tp->next = temp;
  tp = temp;
}

// read the txt file and put each lines into the linkedlist
void fileToNode()
{
  std::ifstream infile;
  std::string info;
  Node* hp = nullptr;
  Node* tp = nullptr;

  infile.open("prevention.txt");

  if(infile.fail())
    {
      std::cout << "Cannot open file\n";
    }
  else
    {
      while(!infile.eof())
        {
            std::getline(infile, info);
            buildList(info, hp, tp);
        }
    }

  print(hp);
}
