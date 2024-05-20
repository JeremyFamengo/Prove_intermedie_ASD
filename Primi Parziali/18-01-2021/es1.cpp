#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

int k_limitatoAux(PNode u, int k, bool& k_limit){
    if(!u)return 0;

    int sumsx=0;
    int sumdx=0;

    if(u->left)sumsx = k_limitatoAux(u->left,k,k_limit);
    if(u->right)sumdx = k_limitatoAux(u->right,k,k_limit);

    int sum=sumsx+sumdx+u->key;

    if(sum>k)k_limit=false;
    return sum;
}


bool k_limitato(PNode u, int k){
    bool k_limit=true;
    k_limitatoAux(u,k,k_limit);
    return k_limit;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"k_limitato? "<< k_limitato(root,6);

    return 0;
}