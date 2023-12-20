#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int key, Node* padre);
};
Node::Node(int key, Node* padre) : key(key), left(nullptr), right(nullptr), p(padre) {}
typedef Node* PTree;

struct T{
    PTree root;
};

void printBT(const std::string& prefix,  PTree node, bool isLeft)
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

void printBT(const PTree node)
{
    printBT("", node, false);
}

void tree_insert(T t, PTree z){
    PTree y=nullptr;
    PTree x= t.root;
    while(x!=nullptr){
        y=x;
        if(z->key<x->key){ //minore è a sinistra
            x=x->left;
        }else{
            x=x->right;
        }
    }
    z->p=y;
    if(y==nullptr){
        t.root=z;
    }else{
        if(z->key<y->key){
            y->left=z;
        }else{
            y->right=z;
        }
    }

}

PTree tree_min(PTree x){
    while(x->left != nullptr){
        x = x->left;
    }
    return x;
}

PTree tree_successor(PTree x){
    if(x->right != nullptr){
        return tree_min(x->right);
    } else {
        PTree y = x->p;
        while(y != nullptr && y->right){
            x=y;
            y=y->p;
        }
        return y;
    }
}

PTree creaBSTInterval(PTree t, int k){
    if(!t)return nullptr;
    T res;
    res.root=nullptr;
    PTree pc{t};
    while(pc){
        //if(pc->key<k){
            tree_insert(res, pc);
            printBT(res.root);
        //}
        pc= tree_successor(pc);
    }
    return res.root;
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

    printBT(creaBSTInterval(u.root,20));

    return 0;
}