#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int k, Node* p){
        key=k;
        this->p=p;
        left=right=nullptr;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree;

void tree_insert(PTree t, PNode z){
    PNode y=nullptr;
    PNode x = t->root;
    while(x!=nullptr){
        y=x;
        if(z->key<x->key){
            x=x->left;
        }else{
            x=x->right;
        }
    }
    z->p=y;
    if(y==nullptr){
        t->root=z;
    }else{
        if(z->key<y->key){
            y->left=z;
        }else{
            y->right=z;
        }
    }
}

void getInterval(PNode n, int from, int to, PTree res){
    if(!n) return;
    if(from<=n->key && n->key<=to){
        PNode tmp = new Node(n->key,nullptr);
        tree_insert(res, tmp);
    }
    getInterval(n->left,from,to, res);
    getInterval(n->right,from,to, res);
}

PTree creaBSTInterval(PTree t, int k){
    PTree res=new Tree();
    getInterval(t->root,t->root->key,k,res);
    return res;
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

int main(){
    PNode root = new Node(15,nullptr);
    root->left = new Node(7,root);
    root->right = new Node(20,root);
    root->left->left = new Node(3,root->left);
    root->right->left = new Node(17,root->right);
    root->right->right = new Node(25,root->right);
    root->right->right->left = new Node(21,root->right->right);

    PTree t = new Tree{root};

    printBT(t);
    PTree res = creaBSTInterval(t,25);
    printBT(res);
    return 0;
}