#include "iostream"
#include "vector"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int key, Node* padre);
};
Node::Node(int key, Node* padre) : key(key), left(nullptr), right(nullptr), p(padre) {}
typedef Node* PNode;

struct T{
    PNode root;
};

void printBT(const std::string& prefix,  PNode node, bool isLeft)
{
    if( node != nullptr )
    {
        std::cout << prefix;

        std::cout << (isLeft ? "├──" : "└──" );

        // print the value of the node
        std::cout << node->key << std::endl;

        // enter the next tree level - left and right branch
        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
    }
}

void printBT(const PNode node)
{
    printBT("", node, false);
}

PNode build_treeAux(vector<int> tree, int inizio, int fine){
    if(inizio<fine){
        int mezzo=(inizio+fine)/2;
        PNode u = new Node(tree.at(mezzo),nullptr);
        u->left=build_treeAux(tree, inizio, mezzo-1);
        u->right=build_treeAux(tree, mezzo, fine);
        return u;

    }else{
        return nullptr;
    }
}

//T build_tree(vector<int>& tree){
//    T t;
//    t.root= build_treeAux(tree,0, tree.size());
//    return t;
//
//}

void visita_albero(PNode u, vector<int>& vector_tree, int k, int value_root){
    if(u){
        visita_albero(u->left, vector_tree,k,value_root);
        if(u->key>=value_root && u->key<=k){
            vector_tree.push_back(u->key);
        }
        visita_albero(u->right, vector_tree,k,value_root);
    }
}

T creaBSTInterval(T t, int k){
    vector<int> vector_tree;
    visita_albero(t.root, vector_tree,k,t.root->key);
    //return build_tree(vector_tree);
    build_treeAux(vector_tree,0, vector_tree.size());
    return t;
}

int main(){
    T u;
    u.root = new Node(10,nullptr);
    u.root->left = new Node(5,u.root);
    u.root->right = new Node(20,u.root);
    u.root->left->left = new Node(1,u.root->left);
    u.root->left->right = new Node(8,u.root->left);
    u.root->right->left = new Node(15,u.root->right);
    u.root->right->right = new Node(25,u.root->right);
    u.root->right->left->left = new Node(13, u.root->right->left);
    u.root->right->left->right = new Node(18, u.root->right->left);
    u.root->right->right->left = new Node(22,u.root->right->right);
    u.root->right->right->right = new Node(30,u.root->right->right);

    printBT(creaBSTInterval(u,20).root);

    return 0;
}