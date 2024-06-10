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

typedef Node* PTNode;

int set_fruitful_aux(PTNode r, int k){ // T(n)=O(n) perchè scorro tutti i nodi dell'albero
    if(!r)return 0;

    int sum=set_fruitful_aux(r->left,k)+ set_fruitful_aux(r->center,k)+set_fruitful_aux(r->right,k);

    if(sum>k){
        r->fruitful=true;
    }else{
        r->fruitful=false;
    }
    return sum+r->key;
}

void set_fruitful(PTNode r, int k){ // T(n)=O(n) per la funzione set_fruitful_aux
    if(!r)return;
    set_fruitful_aux(r,k);
}

void print_tree(PTNode node) {
    if (node == nullptr) return;
    std::cout << "Node key: " << node->key << ", fruitful: " << (node->fruitful ? "True" : "False") << std::endl;
    print_tree(node->left);
    print_tree(node->center);
    print_tree(node->right);
}


int main() {
    // Creazione di un albero ternario di esempio
    PTNode root = new Node(5);
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

    set_fruitful(root, k);

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