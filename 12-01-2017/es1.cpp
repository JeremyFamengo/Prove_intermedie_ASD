#include "iostream"

using namespace std;

struct Cella {
    int info;
    Cella *next;
};

typedef Cella *Lista;


void append(Lista &l, int elem) {
    if (l == nullptr) {
        l = new Cella{elem, nullptr};
    } else
        append(l->next, elem);
}

Lista intersezione(Lista &l1, Lista &l2) {
    Lista res = nullptr;
    Lista p{l1};
    while (p) {
        append(res, p->info);
        p = p->next;
    }

    p = l2;
    while (p) {
        p = p->next;
        append(res, p->info);

    }


    return res;
}


void readlist(Lista& l) {
    int q, e;

    std::cin>>q;

    while (q>0) {
        std::cin>>e;
        append(l, e);
        q--;
    }
}

int main() {
    PNode root = new Node{2, new Node{1, nullptr, nullptr}, new Node{3, nullptr, nullptr}};

    cout << "is_bst? " << is_bst(root);

    return 0;
}