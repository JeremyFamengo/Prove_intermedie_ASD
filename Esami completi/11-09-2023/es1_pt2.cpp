#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left_child;
    Node* right_sibling;
};

typedef Node* PNodeG;

bool isNonDec_aux(PNodeG r, int pred){ //T(n)= theta di n per il metodo di sostituzione
    if(!r) return true;
    if(pred>r->key)return false;
    return isNonDec_aux(r->right_sibling, r->key) && isNonDec_aux(r->left_child, r->key);
}

bool isNonDec(PNodeG r){//T(n)=theta di n causato da isNonDec_aux
    if(!r) return true;
    return isNonDec_aux(r,r->key);
}

int main(){
    // Creazione dei nodi
    Node node1 = {1, nullptr, nullptr};
    Node node2 = {2, nullptr, nullptr};
    Node node3 = {3, nullptr, nullptr};
    Node node4 = {4, nullptr, nullptr};
    Node node5 = {5, nullptr, nullptr};
    Node node6 = {6, nullptr, nullptr};
    Node node7 = {7, nullptr, nullptr};
    Node node8 = {8, nullptr, nullptr};

    // Collegamento dei nodi
    node1.left_child = &node2; // node1 ha come figlio sinistro node2

    node2.right_sibling = &node3; // node2 ha come fratello destro node3
    node3.right_sibling = &node4; // node3 ha come fratello destro node4

    node2.left_child = &node5; // node2 ha come figlio sinistro node5
    node5.right_sibling = &node6; // node5 ha come fratello destro node6

    node4.left_child = &node7; // node4 ha come figlio sinistro node7
    node7.right_sibling = &node8; // node7 ha come fratello destro node8

    PNodeG root = &node1;

    // Verifica se l'albero soddisfa la proprietà non decrescente
    if (isNonDec(root)) {
        cout << "L'albero soddisfa la proprietà non decrescente." << endl;
    } else {
        cout << "L'albero NON soddisfa la proprietà non decrescente." << endl;
    }

    return 0;
}

