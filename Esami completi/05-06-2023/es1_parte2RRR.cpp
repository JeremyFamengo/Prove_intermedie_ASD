#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int key){
        this->key=key;
        this->p=nullptr;
        this->left=nullptr;
        this->right=nullptr;
    }
    Node(int key, Node* p){
        this->key=key;
        this->p=p;
        this->left=nullptr;
        this->right=nullptr;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree ;

void tree_insert(PTree T, PNode z){ //O(h), h altezza dell'albero nel caso medio e nel caso peggiore O(n), n numero di nodi
    PNode y = nullptr;
    PNode x= T->root;
    while(x!=nullptr){
        y=x;
        if(z->key < x->key){
            x=x->left;
        }else{
            x=x->right;
        }
    }
    z->p;
    if(y==nullptr){
        T->root=z;
    }else{
        if(z->key<y->key){
            y->left=z;
        }else{
            y->right=z;
        }
    }
}

void creaBSTInterval_aux(PNode n, PTree& resT, int from, int to){ // con il teorema master T(n)=2T(n/2)+O(n) nel caso peggiore, T(n)=2T(n/2)+O(h) (O(log n))
    if(!n) return;
    if(from<=n->key && n->key<=to) {
        tree_insert(resT,new Node(n->key));
    }
    creaBSTInterval_aux(n->left,resT,from,to);
    creaBSTInterval_aux(n->right,resT,from,to);
}

PTree creaBSTInterval(PTree t, int k){ // con il teorema master T(n)=2T(n/2)+O(n) nel caso peggiore, T(n)=2T(n/2)+O(h) (O(log n))
    PTree tres= new Tree();
    creaBSTInterval_aux(t->root,tres,t->root->key,k);
    return tres;
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