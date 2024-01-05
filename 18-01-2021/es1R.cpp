#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

int k_limitatoAux(PNode u, int k, bool& res){
    if(!u)return 0;
    int sumsx=k_limitatoAux(u->left,k,res);
    int sumdx=k_limitatoAux(u->right,k,res);
    int sum=u->key+sumsx+sumdx;
    if(sum>k)res=false;
    return sum;
}

bool k_limitato(PNode u, int k){
    bool res=true;
    k_limitatoAux(u,k,res);
    return res;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"k_limitato? "<< k_limitato(root,5);

    return 0;
}