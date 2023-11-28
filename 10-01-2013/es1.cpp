#include "iostream"
using namespace std;

struct T{
    int key;
    T* left;
    T* right;
};

typedef T* PNode;

int isK_compreso(PNode u, int k, bool& k_compresa){
        if (!u) return 0; // θ(1)
        if (!k_compresa) return 0; // θ(1) // attenzione a questa istruzione nel calcolo della complessità, perchè ferma la ricorsione

        int sumsx=0,sumdx=0;
        if(u->left){
            sumsx+=u->left->key+isK_compreso(u->left, k,k_compresa); // T(n/2)

        }

        if(u->right){
            sumdx+=u->right->key+isK_compreso(u->right, k,k_compresa); // T(n/2)
        }

        int tot=sumsx+sumdx;

//        cout << -k<<"<"<<tot <<" && "<< tot<<"<"<<k<<endl;
//        cout << "complex: "<<(-k<tot && tot<k)<<endl;
        if (!(-k<tot && tot<k) && k_compresa){
            k_compresa=false;
        }
        return tot;
}


/**
 *  L’albero si dice k-compreso, per un certo numero naturale k, se per ogni nodo x la somma delle chiavi dei nodi dell’albero radicato in x è compresa tra -k e k.
 * @return true se l'albero è k-compreso, false altrimenti
 */
bool k_compreso(PNode u, int k){
    bool k_compreso_b=true;
    isK_compreso(u, k,k_compreso_b);
    return k_compreso_b;
}

int main(){
    PNode root = new T{1, new T{2, nullptr, nullptr}, new T{3, nullptr, nullptr}};
    int k =0;
    bool is_k_compreso = k_compreso(root, k);
    std::cout<<"k_compreso? "<<is_k_compreso;
//    std::cout << "L'albero è " << (is_k_compreso ? "" : "non ") << "k-compreso" << std::endl;
    return 0;
}
