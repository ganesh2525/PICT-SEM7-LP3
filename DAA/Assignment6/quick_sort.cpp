#include <bits/stdc++.h>
#include <ctime>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int deterministicPartition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low-1;
    for (int j=low; j<high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void deterministicQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pi - 1);
        deterministicQuickSort(arr, pi + 1, high);
    }
}

int randomizedPartition(vector<int> &arr, int low, int high) {
    int randomIndex = low + rand() % (high-low+1);
    swap(arr[randomIndex], arr[high]);
    return deterministicPartition(arr, low, high);
}

void randomizedQuickSort(vector<int> &arr, int low, int high) {
    if (low < high) {
        int pi = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pi - 1);
        randomizedQuickSort(arr, pi + 1, high);
    }
}

void displayArray(const vector<int> &arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));  // Seed for random number generator

    vector<int> arr1 = {34, 7, 23, 32, 5, 62, 32};
    vector<int> arr2 = arr1; 

    cout << "Original Array: ";
    displayArray(arr1);

    deterministicQuickSort(arr1, 0, arr1.size()-1);
    cout << "Sorted by Deterministic Quick Sort: ";
    displayArray(arr1);

    randomizedQuickSort(arr2, 0, arr2.size()-1);
    cout << "Sorted by Randomized Quick Sort: ";
    displayArray(arr2);

    return 0;
}

/*
Deterministic Quick Sort:
Time: 1) Best and Average Case: 𝑂(𝑛logn)
      2) Worst Case: 𝑂(𝑛^2)
Space: O(logn)

Randomized Quick Sort:
Time: 1) Best and Average Case: 𝑂(𝑛logn), 
        randomization reduces the likelihood of consistently poor pivot choices
      2) Worst Case: 𝑂(𝑛^2)
Space: 𝑂(logn)
*/