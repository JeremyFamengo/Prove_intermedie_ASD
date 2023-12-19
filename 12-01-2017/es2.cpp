#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

void is_bst_Aux(PNode u, bool& res){
    if(!u)return;

    if((u->right && u->key>u->right->key) || (u->left && u->key<u->left->key)){
        res=false;
    }

    is_bst_Aux(u->left,res);
    is_bst_Aux(u->right,res);
}


bool is_bst(PNode u){
    bool res=true;
    is_bst_Aux(u,res);
    return res;
}

int main(){
    PNode root = new Node{2, new Node{1, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"is_bst? "<< is_bst(root);

    return 0;
}