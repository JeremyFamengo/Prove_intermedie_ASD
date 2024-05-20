#include "iostream"

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

int k_compresoAux(PNode u, bool& res, int k){
    if(!u)return 0;
    int sumsx=k_compresoAux(u->left,res,k);
    int sumdx=k_compresoAux(u->right,res,k);

    int sum=u->key+sumsx+sumdx;

    if(!(-k<sum && sum<k))res=false;

    return sum;
}

bool k_compreso(PNode u, int k){
    bool res=true;
    k_compresoAux(u,res,k);
    return res;
}

int main() {
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};
    int k = 5;
    bool is_k_compreso = k_compreso(root, k);
    std::cout << "k_compreso? " << is_k_compreso;
    return 0;
}
