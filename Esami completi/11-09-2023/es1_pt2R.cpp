#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left_child;
    Node* right_sib;
    Node(int k) : key(k), left_child(nullptr), right_sib(nullptr) {}
};

struct Tree{
    Node* root;
};

typedef Node* PNodeG;
typedef Tree* PTree;

void isNonDec_aux(PNodeG r, bool& is_nonDec){
    if(!r) return;
    if(r->right_sib && r->key>r->right_sib->key){
        is_nonDec=false;
        isNonDec_aux(r->right_sib,is_nonDec);
    }
    isNonDec_aux(r->left_child,is_nonDec);
}

bool isNonDec(PNodeG r){
    bool is_nonDec=true;
    isNonDec_aux(r,is_nonDec);
    return is_nonDec;
}

int main(){
    // Creazione dei nodi
    PNodeG node1 = new Node(1);
    PNodeG node2 =  new Node(2);
    PNodeG node3 =  new Node(3);
    PNodeG node4 =  new Node(4);
    PNodeG node5 =  new Node(5);
    PNodeG node6 =  new Node(6);
    PNodeG node7 =  new Node(7);
    PNodeG node8 =  new Node(8);

    // Collegamento dei nodi
    node1->left_child = node2; // node1 ha come figlio sinistro node2

    node2->right_sib = node3; // node2 ha come fratello destro node3
    node3->right_sib = node4; // node3 ha come fratello destro node4

    node2->left_child = node5; // node2 ha come figlio sinistro node5
    node5->right_sib = node6; // node5 ha come fratello destro node6

    node4->left_child = node7; // node4 ha come figlio sinistro node7
    node7->right_sib = node8; // node7 ha come fratello destro node8

    PNodeG root = node1;

    // Verifica se l'albero soddisfa la proprietà non decrescente
    if (isNonDec(root)) {
        cout << "L'albero soddisfa la proprietà non decrescente." << endl;
    } else {
        cout << "L'albero NON soddisfa la proprietà non decrescente." << endl;
    }

    return 0;
}
