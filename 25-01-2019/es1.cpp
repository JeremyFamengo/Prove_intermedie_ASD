#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

int altezzaNodi(PNode u, int k){
    static int res=0;
    if(!u)return res;
    if(k==0)res++;

    altezzaNodi(u->left,k-1);
    altezzaNodi(u->right,k-1);

    return res;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"altezza_nodi? "<< altezzaNodi(root,1);

    return 0;
}