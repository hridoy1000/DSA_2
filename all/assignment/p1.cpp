#include<iostream>
using namespace std;

int maxSubArray(int* nums, int numsSize) {
    int max_sum =nums[0];
    int cur_sum =nums[0];
    for(int i = 1; i < numsSize; i++) {
        cur_sum =max(nums[i],cur_sum + nums[i]);
        max_sum =max(max_sum,cur_sum);
    }
    return max_sum;
}
int main() {
    int nums[]={-2, 1, -3, 4,-1, 2, 1,-5, 4};
    int numsSize=sizeof(nums)/sizeof(nums[0]);
    cout << maxSubArray(nums, numsSize) << endl;
    return 0;
}

