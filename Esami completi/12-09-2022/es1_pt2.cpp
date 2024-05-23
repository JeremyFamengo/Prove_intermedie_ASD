#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node(int k){
        key=k;
        left=right=nullptr;
    }
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree;

void count_foglie_aux(PNode n, int& sum){
    if(!n) return;
    if(!n->left && !n->right) sum++;
    count_foglie_aux(n->left, sum);
    count_foglie_aux(n->right, sum);
}

int count_foglie(PTree t){
    if(!t)return 0;
    if(!t->root) return 0;
    int sum=0;
    count_foglie_aux(t->root, sum);
    return sum;
}

int main() {
    PNode root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    PTree t = new Tree{root};

    cout<<"conta: "<<count_foglie(t)<<endl;

    return 0;
}