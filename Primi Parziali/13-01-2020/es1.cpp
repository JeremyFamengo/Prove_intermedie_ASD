#include "iostream"
using namespace std;

struct Node{
    int k;
    Node* left;
    Node* right;
};

struct Tree{
    Node* root;
};


bool antenato(Tree antenato, int k1, int k2){
    bool find_k1=false, find_k2=false;
    Node* u=antenato.root;
    while(u && !find_k2){
        if(!find_k1){
            if(u->k==k1)find_k1=true;
            else if (k1<u->k)u=u->left;
            else u=u->right;
        }else{
            if(u->k==k2)find_k2=true;
            else if (k2<u->k)u=u->left;
            else u=u->right;
        }
    }
    return find_k2;
}

int main(){
    Tree radice;
    radice.root = new Node{5, new Node{2, nullptr, nullptr}, new Node{6, nullptr, nullptr}};

    cout<<"antenato? "<< antenato(radice,6,5);


    return 0;
}