#include<iostream>
using namespace std;

int reversePair(int* nums, int numsSize) {
    int count = 0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] > 2 * nums[j]) {
                count++;
            }
        }
    }
    return count;
}

int main() {
   int nums;
    cin >> nums;
    for(int i = 1; i<=nums; i++)
    {
        cin >> arr[i];
    }
    int result = reversePair(arr,nums);
    cout << result;
}