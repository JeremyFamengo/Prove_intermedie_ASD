
#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

void simmetrica_aux(PNode u, bool& res){
    if(!u)return;

    if((u->left && !u->right) || (!u->left && u->right) || (u->left && u->right && u->left->key!=u->right->key)){
        res=false;
    }

    simmetrica_aux(u->left,res);
    simmetrica_aux(u->right,res);
}

bool simmetrica(PNode u){
    bool res=true;
    simmetrica_aux(u,res);
    return res;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"k_limitato? "<< simmetrica(root);

    return 0;
}