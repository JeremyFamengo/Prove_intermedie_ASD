#include "iostream"

using namespace std;

struct T {
    int key;
    T *left;
    T *right;
};

typedef T *PNode;

int is_alberoBinarioAux(PNode u, bool& res){
    if(!u)return 0;
    int hsx= 1+is_alberoBinarioAux(u->left,res);
    int hdx= 1+is_alberoBinarioAux(u->right,res);
    if(hsx!=hdx)res=false;
    return hsx;
}

bool is_alberoBinario(PNode u){
    bool res=true;
    is_alberoBinarioAux(u,res);
    return res;
}

int main() {
    PNode root = new T{1, new T{2, nullptr, nullptr}, new T{3, nullptr, nullptr}};
    int k = 5;
    bool is_k_compreso = is_alberoBinario(root);
    std::cout << "è albero binario completo? " << is_k_compreso;
    return 0;
}
