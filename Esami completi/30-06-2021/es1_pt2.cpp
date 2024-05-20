#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;//padre
    Node(int data, Node* padre) {
        this->key = data;
        left = right = NULL;
        p=padre;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree;

void somma(PNode u, int sum){
    if(!u)return;
    int sum_tot=sum+u->key;

    somma(u->left, sum_tot);
    somma(u->right, sum_tot);

    if(u && !u->left && !u->right){
        if(sum_tot>0){
            u->left=new Node(sum_tot, u);
        }else{
            u->right=new Node(sum_tot, u);
        }
    }
}

void aggiungiFigli(PNode u){
    somma(u,0);
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

void printBT(const PNode node)
{
    printBT("", node, false);
}

int main() {
    PNode root = new Node(15,nullptr);
    root->left = new Node(7,root);
    root->right = new Node(20,root);
//    root->left->left = new Node(3,root->left);
//    root->right->left = new Node(17,root->right);
//    root->right->right = new Node(25,root->right);
//    root->right->right->left = new Node(21,root->right->right);

    //PTree t = new Tree{root};

    aggiungiFigli(root);
    printBT(root);
    return 0;
}

