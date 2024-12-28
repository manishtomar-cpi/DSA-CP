#include <vector>
#include <iostream>
using namespace std;

void display(vector<int> &vec) {
    cout << "[ ";
    for (auto &i : vec)
        cout << i << " ";
    cout << "]" << endl;
}

void merge(vector<int> &vec, int start, int mid, int end) {
    vector<int> merged(end - start + 1); // Temporary array for merging
    int i = start;  // Pointer for the left subarray
    int j = mid + 1; // Pointer for the right subarray
    int k = 0;      // Pointer for the merged array

    // Merge the two subarrays
    while (i <= mid && j <= end) {
        if (vec[i] <= vec[j]) {
            merged[k++] = vec[i++];
        } else {
            merged[k++] = vec[j++];
        }
    }

    // Copy any remaining elements from the left subarray
    while (i <= mid) {
        merged[k++] = vec[i++];
    }

    // Copy any remaining elements from the right subarray
    while (j <= end) {
        merged[k++] = vec[j++];
    }

    // Copy the merged elements back to the original array
    for (int i = 0; i < merged.size(); i++) {
        vec[start + i] = merged[i];
    }
}

void mergeSort(vector<int> &arr) {
    int n = arr.size();

    for (int size = 1; size < n; size *= 2) {
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);

            // Merge two subarrays: [left, mid] and [mid + 1, right]
            merge(arr, left, mid, right);
        }
    }
}

int main() {
    vector<int> vec = {3, 1, 5, 2, 8, 7, 6, 9, 10, 14, 13};

    cout << "Original array: ";
    display(vec);

    mergeSort(vec);

    cout << "Sorted array: ";
    display(vec);

    return 0;
}
