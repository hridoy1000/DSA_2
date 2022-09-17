#include<iostream>
using namespace std;

void Merge(int* nums, int left, int mid, int right) {
    int* temp = new int[right - left + 1];
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j]) {
            temp[k] = nums[i];
            i++;
        } else {
            temp[k] = nums[j];
            j++;
        }
        k++;
    }
    while (i <= mid) {
        temp[k] = nums[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = nums[j];
        j++;
        k++;
    }
    for (int m = 0; m < k; m++) {
        nums[left + m] = temp[m];
    }
    delete[] temp;
}

void mergeSort(int* nums, int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        Merge(nums, left, mid, right);
    }
}

void removeDuplicates(int* nums, int numsSize) {
    int i = 0;
    for (int j = 1; j < numsSize; j++) {
        if (nums[i] != nums[j]) {
            i++;
            nums[i] = nums[j];
        }
    }
    numsSize = i + 1;
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    removeDuplicates(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    mergeSort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}
