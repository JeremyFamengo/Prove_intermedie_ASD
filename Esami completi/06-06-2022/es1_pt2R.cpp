#include "iostream"
#include <climits>
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int data) {
        this->key = data;
        left = right = NULL;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree;

// Function to check if the given tree is a BST
bool isBSTUtil(PNode n, int min, int max) {
    if (n == NULL)
        return true;
    if (n->key <= min || n->key >= max)
        return false;
    return isBSTUtil(n->left, min, n->key) && isBSTUtil(n->right, n->key, max);
}

bool isBST(PNode root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

PTree Modify_key(PTree t, PNode x, int key){
    if(x){
        x->key=key;
    }
    if(isBST(t->root)){
        return t;
    }else{
        return nullptr;
    }
}

void printBT(const std::string& prefix,  PNode node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const PTree t)
{
    printBT("", t->root, false);
}


int main() {
    PNode root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    PTree t = new Tree{root};

    printBT(Modify_key(t,t->root->right,6));

    return 0;
}