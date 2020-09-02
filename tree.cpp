#include<iostream>
#include<string>
#include <fstream>
#include <vector>
#include "tree.h"
#include "symptoms.h"
#include "functions.h"

std::string Node1::getWord() const
{
    return word;
}

std::string BST::getRoot() const
{
    return root->getWord();
}

BST::BST() { root = nullptr; }//default constructor

void BST::insert1(std::string data){//insert 1 node?
   Node1* new_node = new Node1;//create the new node and initialize the data in the parameter.
   new_node->word = data;
   if (root == nullptr) { root = new_node; }//IF there is NO ROOT, the new node is the root.
   else { add_node(root, new_node); }//else add the node to the tree
}

int BST::count1(std::string data) const{//to see if word is in the set
    Node1* current = root;
   while (current != nullptr)
   {
      if (data < current->word)
      {
         current = current->left;//IF data is less than the current node then go to the left side which is the lesser side
      }
      else if (data > current->word)
      {
         current = current->right;//go to the side where there's more
      }
      else return 1;
   }
   return 0;//if it reaches nullptr, return 0 which means not found
}

//parent is probably root node initially passed in. new_node is the node with the value to be inserted.
void BST::add_node(Node1* parent, Node1* new_node) const{//add node to the tree. it's possible for parent to be root. if it is, just branch from there
    if (new_node->word < parent->word)
   {
      if (parent->left == nullptr) { parent->left = new_node; }//if there's no left child, put the new node there
      else { add_node(parent->left, new_node); }//if the value via unicode is less than current node, recursively add to the left. keep traversing
   }
   else if (new_node->word > parent->word)//same process as above except on the right side.
   {
      if (parent->right == nullptr) { parent->right = new_node; }
      else { add_node(parent->right, new_node); }
   }

}


void fileToTree()
{
    std::ifstream infile;
    std::string line;
    std::string keyWord;
    std::string Description;
    const char sc = '|';//special delimiter read all the stuff up to it per subject.
    BST BSTarr[12];//binary search tree array for the 12 subjects
    int counter = 0;//used to keep track of array slots.
    std::string str[12];
    infile.open("symptoms.txt");

    if(infile.fail())
      {
        std::cout << "Cannot open file\n";
      }
    else
      {
          std::getline(infile, line);
          // std::vector<std::string> wordVec;
          while(!infile.eof())
          {
                Description = "";//initialize description with empty string
                if(line[0]== sc){
                    keyWord = line.substr(1);/
                    BSTarr[counter].insert1(keyWord);//keyWord is the root for each of the 12 BST in the BST array.
                }
                while(line[0]!= sc && !infile.eof())
                {
                    Description += line;//keep concatenating lines into one big string
                    std::getline(infile, line);//get the next line

                }

              str[counter++] = Description;//put the big ass strings in here.
          }
          std::vector<std::string> vec;
          std::string word;
          for(int i = 0; i < 12; i++)
          {
              vec = splite(str[i]);
              for(auto x : vec)
              {
                BSTarr[i].insert1(x);
              }
          }
          std::cout << "Please enter the word that is relative to any symptoms(For example: cough): " << std::endl;
          std::string input;
          std::cin >> input;
          int index = 1;
          std::vector<int> indexArr;
          std::string menu = "";
          for(int i = 0; i < 12; i++)
          {
              if(BSTarr[i].count1(input) == 1)
              {
                  indexArr.push_back(i);
                  menu += std::to_string(index++) + ". " + BSTarr[i].getRoot() + "\n";
              }
          }
          divisionLine();
          if(indexArr.size() != 0)
          {
              std::cout << "Here are the symptoms that contains your word: " << std::endl;
              std::cout << menu << std::endl;
              std::cout << "Which page would you like to read about?" << std::endl;
              int toRead = validatedInt(1, index-1);
              divisionLine();
              std::cout << str[indexArr[toRead-1]] << std::endl;
          }
          else
          {
              divisionLine();
              std::cout << "None of the symptoms contains this word." << std::endl;
          }
      }
}
