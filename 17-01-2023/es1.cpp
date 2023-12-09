#include "iostream"
using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    char col; // B black, R rosso
};

typedef Node* PNode;


//int aux(PNode u){
//    if(u==nullptr){
//        return 0;
//    }
//
//    else{
//        int rissx,risdx;
//        rissx=aux(u->left);
//        risdx=aux(u->right);
//        if((rissx==-1 || risdx!=-1)&& u->right!=nullptr && u->left!=nullptr && rissx!=risdx) {
//            return -1;
//        }
//
//        int ris;
//        if(u->left == nullptr){
//            ris=risdx;
//        }
//        else{
//            ris=rissx;
//        }
//
//        if(u->key=='B');
//        return ris;
//
//
//    }
//}
/**
 *
 *
 * */
int blackHeight(PNode u){
    if(u==nullptr){
        return 0;
    }

    else{
        int rissx,risdx;
        rissx=blackHeight(u->left);
        risdx=blackHeight(u->right);
        if(rissx==-1 || risdx==-1 || u->right!=nullptr && u->left!=nullptr && rissx!=risdx) {
            return -1;
        }

        int ris;
        if(u->left == nullptr){
            ris=risdx;
        }
        else{
            ris=rissx;
        }

        if(u->col=='B')ris++;
        return ris;
    }
}

int main(){
    PNode root = new Node{1,  new Node{3, nullptr, new Node{4, nullptr, nullptr, 'B'}, 'B'},nullptr, 'B'};
    cout<<blackHeight(root);

    return 0;
}