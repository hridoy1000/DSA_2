#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int nums[n];
    for(int i =0; i < n; i++) {
        cin >> nums[i];
    }
    int max_sum = nums[0];
    int cur_sum = nums[0];
    for(int i = 1; i < n; i++) {
        cur_sum =max(nums[i], cur_sum + nums[i]);
        max_sum =max(max_sum, cur_sum);
    }
    cout << max_sum << endl;
    return 0;

}


