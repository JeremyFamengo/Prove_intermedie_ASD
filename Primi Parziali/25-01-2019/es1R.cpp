#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

void altezzaNodiAux(PNode u, int k, int count_k, int& tot){
    if(!u)return;
    if(count_k==k){
        tot++;
    }
    altezzaNodiAux(u->left,k,count_k+1,tot);
    altezzaNodiAux(u->right,k,count_k+1,tot);
}

int altezzaNodi(PNode u, int k){
    int count_k=0;
    int tot=0;
    altezzaNodiAux(u,k,count_k,tot);
    return tot;
}


int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"altezza_nodi? "<< altezzaNodi(root,1);

    return 0;
}