#include "iostream"
using namespace std;

struct Tree{
    int k;
    Tree* left;
    Tree* right;
};

typedef Tree* PTree;

void antenato_aux(PTree antenato, int k1, int k2, bool& bk1, bool& bk2, bool& res){
    if(antenato)return;
    if(antenato->k==k1)bk1=true;
    else if(antenato->k==k2)bk2=true;

    if(!bk1 && bk2){
        res=false;
        return;
    }

    antenato_aux(antenato->left,k1, k2, bk1, bk2, res);
    antenato_aux(antenato->right,k1, k2, bk1, bk2, res);

}

bool antenato(PTree antenato, int k1, int k2){
    bool bk1=false, bk2=false,  res=true;

    antenato_aux(antenato,k1, k2, bk1, bk2, res);

    return res;
}

int main(){
    PTree root = new Tree{1, new Tree{2, nullptr, nullptr}, new Tree{3, nullptr, nullptr}};

    cout<<"antenato? "<< antenato(root,1234567890,76);


    return 0;
}