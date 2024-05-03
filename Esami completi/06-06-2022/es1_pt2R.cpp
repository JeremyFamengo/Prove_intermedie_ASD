#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
};

typedef Node* PNode;

struct Tree{
    PNode root;
};

typedef Tree* PTree;

int printTreeAux(PNode n){
    if(!n)return 0;
    int sumNsx = printTreeAux(n->left);
    int sumNdx = printTreeAux(n->right);
    int tot=1+sumNsx+sumNdx;

    if(sumNsx>sumNdx)cout<<n->key<<endl;

    return tot;
}

void printTree(PTree t){
    printTreeAux(t->root);
}

//void printBT(const std::string& prefix,  PNode node, bool isLeft)
//{
//    if( node != nullptr )
//    {
//        std::cout << prefix;
//
//        std::cout << (isLeft ? "├──" : "└──" );
//
//        // print the value of the node
//        std::cout << node->key << std::endl;
//
//        // enter the next tree level - left and right branch
//        printBT( prefix + (isLeft ? "│   " : "    "), node->left, true);
//        printBT( prefix + (isLeft ? "│   " : "    "), node->right, false);
//    }
//}
//
//void printBT(const PNode node)
//{
//    printBT("", node, false);
//}

int main(){
    PNode root = new Node{30, new Node{25, new Node{21, nullptr, nullptr}, new Node{26, nullptr, nullptr}}, new Node{40, new Node{35, nullptr, nullptr}, new Node{45, nullptr, new Node{50,  nullptr, new Node{100, new Node{26, nullptr, nullptr}, nullptr}}}}};
    PTree t = new Tree{root};
//    printBT(t->root);
    printTree(t);

    return 0;
}