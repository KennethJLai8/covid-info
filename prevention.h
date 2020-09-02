#ifndef prevention_hpp
#define prevention_hpp
#include <string>

struct Node
{
  std::string data;
  Node* next = nullptr;
};

void print(Node*);
void buildList(std::string, Node*&, Node*&);
void fileToNode();


#endif /* prevention_h */
