#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

struct T{
    PNode root;
};

typedef T* Tree;

void antenatoAux(PNode u, int k1, bool& tk1, int k2, bool& tk2, bool& res){
    if(!u)return;

    if(k1==u->key)tk1=true;
    if(k2==u->key)tk2=true;

    if(!tk1 && tk2){
        res=false;
        return;
    }

    if(k1<u->key)antenatoAux(u->left,k1,tk1,k2,tk2,res);
    if(u->key<k2)antenatoAux(u->right,k1,tk1,k2,tk2,res);
}


bool antenato(Tree t, int k1, int k2){
    bool tk1=false;
    bool tk2=false;
    bool res=true;

    antenatoAux(t->root,k1,tk1,k2,tk2,res);

    return res;
}

int main(){
    Tree radice=new T;
    radice->root = new Node{5, new Node{2, nullptr, nullptr}, new Node{6, nullptr, nullptr}};

    cout<<"antenato? "<< antenato(radice,5,6);


    return 0;
}