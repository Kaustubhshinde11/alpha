#include <iostream>
#include <omp.h>

using namespace std;

void Merge(int* arr, int s, int e) {
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    int k = s;

    for (int i = 0; i < len1; i++) {
        left[i] = arr[k++];
    }

    k = mid + 1;
    for (int j = 0; j < len2; j++) {
        right[j] = arr[k++];
    }

    k = s;
    int index1 = 0;
    int index2 = 0;

    while (index1 < len1 && index2 < len2) {
        if (left[index1] < right[index2]) {
            arr[k++] = left[index1++];
        } else {
            arr[k++] = right[index2++];
        }
    }

    while (index1 < len1) {
        arr[k++] = left[index1++];
    }

    while (index2 < len2) {
        arr[k++] = right[index2++];
    }

    delete[] left;
    delete[] right;
}

void mergesort(int* arr, int s, int e) {
    if (s >= e) {
        return;
    }

    int mid = (s + e) / 2;

    #pragma omp parallel sections
    {
        #pragma omp section
        {
            mergesort(arr, s, mid);
        }
        #pragma omp section
        {
            mergesort(arr, mid + 1, e);
        }
    }

    Merge(arr, s, e);
}

int main() {
    int m;
    cout << "Enter the size of array: ";
    cin >> m;

    int* arr = new int[m];

    cout << "Enter the array values:\n";
    for (int j = 0; j < m; j++) {
        cin >> arr[j];
    }
    double start = omp_get_wtime();

    #pragma omp parallel
    {
        #pragma omp single
        {
            mergesort(arr, 0, m - 1);
        }
    }
    double end = omp_get_wtime();

    cout << "Sorted array:\n";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Time Taken by Parallel Merge Sort: " << end-start << endl;

    delete[] arr;
    return 0;
}
