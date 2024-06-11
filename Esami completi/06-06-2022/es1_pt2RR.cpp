#include "iostream"
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

int print_aux(PNode n){ //T(n)=theta(n) per il teorema della sostituzione
    if(!n)return 0;
    int sumsx= print_aux(n->left);
    int sumdx= print_aux(n->right);
    if(sumsx>sumdx){
        cout<<n->key<<" ";
    }
    return sumsx+sumdx+1;
}

void print(PTree t){ //T(n)=theta(n) per print_aux
    print_aux(t->root);
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

    printBT(t);

    print(t);

    return 0;
}