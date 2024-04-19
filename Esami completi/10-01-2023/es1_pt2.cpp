#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

struct Tree{
    Node* root;
};

typedef Node* PNode;
typedef Tree* PTree;

int k_compreso_aux(PNode u, bool& k_compreso, int k){
    if(!u)return 0;
    int sumsx= k_compreso_aux(u->left,k_compreso,k);
    int sumdx= k_compreso_aux(u->right,k_compreso,k);
    int sum=sumsx+sumdx+u->key;
    if(!((sumsx<=k && sumsx<=k) && (sumdx<=k && sumdx<=k) && (sum<=k && sum<=k)))k_compreso=false;
    return sum;

}

bool k_compreso(PNode u, int k){
    bool k_compreso=true;
    k_compreso_aux(u, k_compreso, k);
    return k_compreso;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout<<"k_compreso? "<< k_compreso(root,6);

    return 0;
}