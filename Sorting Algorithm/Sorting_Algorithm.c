#include <stdio.h>

void merge(int arr[], int left[], int right[], int left_size, int right_size) {
    int i = 0, j = 0, k = 0;
    while (i < left_size && j < right_size) {
        if (left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int size, int k) {
    if (size > k) {
        int mid = size / 2;
        int left[mid], right[size-mid];

        for (int i = 0; i < mid; i++) {
            left[i] = arr[i];
        }
        for (int i = mid; i < size; i++) {
            right[i-mid] = arr[i];
        }

        merge_sort(left, mid, k);
        merge_sort(right, size-mid, k);
        merge(arr, left, right, mid, size-mid);
    } else {
        for (int i = 1; i < size; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }
}

int main() {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int k = 2;
    int size = sizeof(arr) / sizeof(arr[0]);

    merge_sort(arr, size, k);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
