#ifndef tree_h
#define tree_h

class Node1{
public:
    std::string getWord() const;
private:
    std::string word;
    Node1* left = nullptr;
    Node1* right = nullptr;
    friend class BST;
};

class BST
{

public:

    BST();
    void insert1(std::string data);
    int count1(std::string data) const;
    std::string getRoot() const;
private:
    void add_node(Node1* parent, Node1* new_node) const;
    Node1* root;
};

void fileToTree();

#endif /* tree_h */
