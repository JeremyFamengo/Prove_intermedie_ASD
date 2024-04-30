#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

typedef Node* PNode;


int k_compreso_aux(PNode u, int k, bool& res){
    if(!u)return 0;
    int sumsx= k_compreso_aux(u->left,k,res);
    int sumdx= k_compreso_aux(u->right,k,res);
    int sum=u->key+sumsx+sumdx;
    if(!(-k<sum && sum<k))res=false;
    return sum;
}

bool k_compreso(PNode u, int k){
    bool res=true;
    k_compreso_aux(u,k,res);
    return res;
}

int main() {
    // Esempio di utilizzo
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 10;
    if (k_compreso(root, k))
        std::cout << "L'albero e' " << k << "-compreso." << std::endl;
    else
        std::cout << "L'albero non e' " << k << "-compreso." << std::endl;

    // Deallocazione della memoria
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}

//int main(){
//    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{3, nullptr, nullptr}};
//
//    cout<<"k_compreso? "<< k_compreso(root,7);
//
//    return 0;
//}