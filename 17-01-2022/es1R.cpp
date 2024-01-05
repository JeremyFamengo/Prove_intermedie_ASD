#include "utility"
#include "iostream"

using namespace std;

struct Node{
    int key;
    Node* left;
    Node* right;
    char col; //B o R
};

typedef Node* PNode;

//pair<black,red>
int blackHeight(PNode u){
    if(!u)return 0;
    int rsx=blackHeight(u->left);
    int rdx=blackHeight(u->right);

    int res=0;
    if(u->left!=nullptr)res=rsx;
    else res=rdx;

    if(u->col=='B')res++;

    if(rsx==-1 || rdx==-1 ||  u->right && u->left && rsx != rdx)return -1;

    return res;
}



int main(){
    PNode root = new Node{1,  new Node{3, nullptr, new Node{4, nullptr, nullptr, 'B'}, 'B'},nullptr, 'B'};
    cout<<blackHeight(root);

    return 0;
}