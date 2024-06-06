#include <iostream>
#include <vector>

using namespace std;

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}

void min_heapify(vector<int>& A, int heap_size, int i) {
    int l = left(i);
    int r = right(i);
    int minimo = i;

    if (l < heap_size && A[l] < A[i]) {
        minimo = l;
    }

    if (r < heap_size && A[r] < A[minimo]) {
        minimo = r;
    }

    if (minimo != i) {
        swap(A[i], A[minimo]);
        min_heapify(A, heap_size, minimo);
    }
}

void build_min_heap(vector<int>& A) {
    int heap_size = A.size();
    for (int i = heap_size / 2 - 1; i >= 0; i--) {
        min_heapify(A, heap_size, i);
    }
}

int main() {
    vector<int> A = {35,42,2,-1,27}; // Example array

    build_min_heap(A);

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }

    return 0;
}
