#include "iostream"
#include "utility"
using namespace std;

typedef struct node{
    char  colore;
    struct node * left;
    struct node * right;
} * Node;


struct Tree{
    Node root;
};

pair<int,int> bilanciato_aux(Node u, int& count){
    if(u){
        pair<int,int> res_sx= bilanciato_aux(u->left,count);
        pair<int,int> res_dx= bilanciato_aux(u->right,count);
        int b=res_sx.first+res_dx.first;
        int n=res_dx.second+res_sx.second;
        if(u->colore=='B'){
            if(b+1==n)count++;
            return {b+1,n};
        }else{
            if(n+1==b)count++;
            return {b,n+1};
        }
    }else{
        return {0,0};
    }
}

int bilanciato(Tree t){
    int res=0;
    bilanciato_aux(t.root,res);
    return res;
}

int main() {
    Node root = new node{'B', new node{'N', nullptr, nullptr}, new node{'N', new node{'B', nullptr, nullptr}, nullptr}};
    Tree t ;
    t.root=root;
    int k = 5;
    bool is_k_compreso = bilanciato(t);
    std::cout << "è bilanciato? " << is_k_compreso;
    return 0;
}
