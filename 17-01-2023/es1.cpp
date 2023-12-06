#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    char col; // B black, R rosso
};

typedef Node* PNode;

int blackHeight(PNode u){

    return 0;
}

int main(){
    PNode root = new Node{1, new Node{2, nullptr, nullptr, 'R'}, new Node{3, nullptr, nullptr, 'B'}, 'B'};
    cout<<blackHeight(root);

    return 0;
}