
#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

int conta_riccorrenze(PNode T, int k){
    int sum=0;
    if(!T)return sum;
    if(T->key==k)sum++;
    sum += conta_riccorrenze(T->left,k);
    sum += conta_riccorrenze(T->right,k);

    return sum;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr}, new Node{2, nullptr, nullptr}};

    cout<<"conta_riccorrenze? "<< conta_riccorrenze(root,2);

    return 0;
}