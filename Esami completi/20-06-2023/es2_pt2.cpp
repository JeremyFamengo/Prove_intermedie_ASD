#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

void merge1(std::vector<pair<int, string>>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<pair<int, string>> L(n1 + 1), R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = A[q + 1 + j];
    }

    L[n1] = {INT_MAX, ""};  // Use a large value to represent infinity
    R[n2] = {INT_MAX, ""};  // Use a large value to represent infinity

    int i = 0, j = 0;

    for (int k = p; k <= r; ++k) {
        if (L[i].second.compare(R[j].second)<0) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}

void mergeSort1(std::vector<pair<int, string>>& A, int p, int r) {
    if (p < r) {
        int med = (p + r) / 2;
        mergeSort1(A, p, med);
        mergeSort1(A, med + 1, r);
        merge1(A, p, med, r);
    }
}

void merge2(std::vector<pair<int, string>>& A, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<pair<int, string>> L(n1 + 1), R(n2 + 1);

    for (int i = 0; i < n1; ++i) {
        L[i] = A[p + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = A[q + 1 + j];
    }

    L[n1] = {INT_MAX, ""};  // Use a large value to represent infinity
    R[n2] = {INT_MAX, ""};  // Use a large value to represent infinity

    int i = 0, j = 0;

    for (int k = p; k <= r; ++k) {
        if (L[i].first <= R[j].first) {
            A[k] = L[i];
            ++i;
        } else {
            A[k] = R[j];
            ++j;
        }
    }
}

void mergeSort2(std::vector<pair<int, string>>& A, int p, int r) {
    if (p < r) {
        int med = (p + r) / 2;
        mergeSort2(A, p, med);
        mergeSort2(A, med + 1, r);
        merge2(A, p, med, r);
    }
}

void es_2_a(vector<pair<int, string>>& A) {
    mergeSort1(A, 0, A.size() - 1);
    mergeSort2(A, 0, A.size() - 1);
}

int main() {
    std::vector<pair<int, string>> A = {{38, "BIANCO"}, {27, "BIANCO"}, {8, "NERO"}, {7, "BIANCO"}, {8, "BIANCO"}, {27, "NERO"},{338, "BIANCO"}, {24, "NERO"}}; // Example array
    int n = A.size();

    es_2_a(A);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        std::cout << A[i].second << "-" << A[i].first << " ";
    }
    std::cout << std::endl;

    return 0;
}
