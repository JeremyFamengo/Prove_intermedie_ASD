
#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;
};

struct Tree{
    Node* root;
};

typedef Node* PNode;

void tree_insert(Tree t, PNode z){
    PNode y=nullptr;
    PNode x= t.root;
    while(x!=nullptr){
        y=x;
        if(z->key<x->key){ //minore è a sinistra
            x=x->left;
        }else{
            x=x->right;
        }
    }
    z->p=y;
    if(y==nullptr){
        t.root=z;
    }else{
        if(z->key<y->key){
            y->left=z;
        }else{
            y->right=z;
        }
    }

}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"k_limitato? "<< simmetrica(root);

    return 0;
}