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
        this->left=nullptr;
        this->right=nullptr;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree ;

void tree_insert(PTree T, PNode z){ //O(h), h altezza dell'albero.
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


/**
 * caso medio: O(log n * h)
 * caso peggiore: O(nlog n)
 * n numero nodi
 * h altezza dell'albero
 * */
void scorri(PNode n, int from, int to, PTree res){
    if(!n)return;
    if(from<=n->key && n->key<=to){
        tree_insert(res, new Node(n->key,nullptr));
    }
    if(n->left && from<=n->left->key && n->left->key<=to){
        scorri(n->left, from,to,res);
    }
    if(n->right && from<=n->right->key && n->right->key<=to){
        scorri(n->right, from,to,res);
    }
}


/**
 * caso medio: O(log n * h)
 * caso peggiore: O(nlog n)
 *
 * dovuto alla funzione scorri
 * n numero nodi
 * h altezza dell'albero
 * */
PTree creaBSTInterval(PTree t, int k){
    PTree res=new Tree();
    scorri(t->root,t->root->key,k,res);
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