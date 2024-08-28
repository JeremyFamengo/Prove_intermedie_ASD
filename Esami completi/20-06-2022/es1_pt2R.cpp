#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int key, Node* p){
        this->key=key;
        this->p=p;
        left=right=nullptr;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree;

void transplant(PTree t, PNode u, PNode v){
    if(!u->p){
        t->root=v;
    }else{
        if(u==u->p->left){
            u->p->left=v;
        }else{
            u->p->right=v;
        }
    }
    if(v) v->p=u->p;
}

void del_min_k_aux(PTree t, PNode n, int k){
    if(!n)return;
    del_min_k_aux(t,n->left,k);
    del_min_k_aux(t,n->right,k);
    if(n->key<=k){
        PNode tmp=n;
        transplant(t,n,n->right);
        delete tmp;
    }
}

void del_min_k(PTree t, int k){
    if(!t)return;
    del_min_k_aux(t, t->root, k);
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
    PNode root = new Node(4, nullptr);
    root->left = new Node(2, root);
    root->right = new Node(5, root);
    root->left->left = new Node(1,root->left);
    root->left->right = new Node(3,root->left);

    PTree t = new Tree{root};

    printBT(t);

    del_min_k(t,2);

    printBT(t);

    return 0;
}