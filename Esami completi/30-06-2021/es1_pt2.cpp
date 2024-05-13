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

int somma(PNode u){
    if(!u)return 0;
    int sumsx = u->key+somma(u->left);
    int sumdx = u->key+somma(u->right);

    int sum=sumsx+sumdx;

    if(u && !u->left && !u->right){
        if(sum>0){
            u->left=new Node(sum, u);
        }else{
            u->right=new Node(sum, u);
        }
    }
}

void aggiungiFigli(PNode u){
    somma(u);
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

    return 0;
}

