#include "iostream"

using namespace std;

struct T {
    int key;
    T *left;
    T *right;
};

typedef T *PNode;

// versione ufficile della prof

bool k_compresoAux(PNode u, int k, int &sum) { // T(n) = θ(n)
    int sumsx = 0, sumdx = 0;  // θ(1)
    bool rissx, risdx; // θ(1)

    if (!u) { // θ(1)
        sum = 0; // θ(1)
        return true;
    }

    rissx = k_compresoAux(u->left, k, sumsx); // T(n/2)
    risdx = k_compresoAux(u->right, k, sumdx); // T(n/2)

    sum = sumsx + sumdx + u->key; // θ(1)
    return rissx && risdx && -k <= sum && sum <= k; // θ(1)
}

bool k_compreso(PNode u, int k) {
    int sum; // θ(1)
    return k_compresoAux(u, k, sum); // θ(n)
}


int main() {
    PNode root = new T{1, new T{2, nullptr, nullptr}, new T{3, nullptr, nullptr}};
    int k = 5;
    bool is_k_compreso = k_compreso(root, k);
    std::cout << "k_compreso? " << is_k_compreso;
    return 0;
}
