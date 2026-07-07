#include <bits/stdc++.h>
using namespace std;
/*
Problem Statement: Given an integer array sorted in non-decreasing order, remove the duplicates in place such that 
each unique element appears only once. The relative order of the elements should be kept the same.
If there are k elements after removing the duplicates, then the first k elements of the array should hold the final result. 
It does not matter what you leave beyond the first k elements.*/

/*
Time Complexity: O(N), We traverse the entire original array only once.
Space Complexity: O(1), constant additional space is used to check unique elements.
*/
int removeDuplicates(vector<int> &arr, int n) {
    if (n == 0)
        return 0;

    int i = 0;

    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1; // count of unique elements
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3};
    int n = arr.size();
    int k = removeDuplicates(arr, n);

    cout << "Length of array after removing duplicates: " << k << endl;

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < k; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}