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

void transplant(PTree t, PNode u, PNode v){
    if(u->p==nullptr){
        t->root=v;
    }else{
        if(u==u->p->left){
            u->p->left=v;
        }else{
            u->p->right=v;
        }
    }
    if(v!=nullptr){
        v->p=u->p;
    }
}

void rimuovi(PNode u){
    if(u){
        rimuovi(u->left);
        rimuovi(u->right);
        delete u;
    }
}

void eliminaMaggioriK(PTree t, int k){
    PNode iter, temp;
    iter=t->root;
    while(iter->key!=k){
        if(iter->key>k){
            rimuovi(iter->right);
            iter->right=nullptr;
            temp=iter;
            transplant(t,iter,iter->left);
            iter=iter->left;
            delete temp;
        }else{
            iter=iter->right;
        }
    }
    rimuovi(iter->right);
    iter->right=nullptr;
}

int main() {
    PNode root = new Node(15,nullptr);
    root->left = new Node(7,root);
    root->right = new Node(20,root);
//    root->left->left = new Node(3,root->left);
//    root->right->left = new Node(17,root->right);
//    root->right->right = new Node(25,root->right);
//    root->right->right->left = new Node(21,root->right->right);

    PTree t = new Tree{root};

    eliminaMaggioriK(t,7);

    return 0;
}

