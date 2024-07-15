#include "iostream"
using namespace std;

struct Node{
    int key;
    bool fruitful;
    Node* left;
    Node* center;
    Node* right;
    Node(int k) : key(k), fruitful(false), left(nullptr), center(nullptr), right(nullptr) {}
};

struct Tree{
    Node* root;
};

typedef Node* PNode;
typedef Tree* PTNode;

int set_fruitful_aux(PNode n, int k){
    if(!n) return 0;
    int sumsx=set_fruitful_aux(n->left,k);
    int sumcenter=set_fruitful_aux(n->center,k);
    int sumrx=set_fruitful_aux(n->right,k);

    int sum=sumsx+sumcenter+sumrx;

    if(sum>k)n->fruitful=true;
    else n->fruitful=false;
    return n->key+sum;
}

void set_fruitful(PTNode r, int k){
    set_fruitful_aux(r->root,k);
}


void print_tree(PNode node) {
    if (node == nullptr) return;
    std::cout << "Node key: " << node->key << ", fruitful: " << (node->fruitful ? "True" : "False") << std::endl;
    print_tree(node->left);
    print_tree(node->center);
    print_tree(node->right);
}


int main() {
    // Creazione di un albero ternario di esempio
    PNode root = new Node(5);
    root->left = new Node(3);
    root->center = new Node(2);
    root->right = new Node(8);

    root->left->left = new Node(1);
    root->left->center = new Node(0);
    root->left->right = new Node(4);

    root->center->left = new Node(6);
    root->center->center = new Node(7);
    root->center->right = new Node(9);

    int k = 4;

    PTNode tree = new Tree();
    tree->root=root;

    set_fruitful(tree, k);

    // Stampa dell'albero
    print_tree(root);

    // Pulizia della memoria allocata dinamicamente
    delete root->left->left;
    delete root->left->center;
    delete root->left->right;
    delete root->center->left;
    delete root->center->center;
    delete root->center->right;
    delete root->left;
    delete root->center;
    delete root->right;
    delete root;

    return 0;
}