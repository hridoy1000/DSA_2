//write a recursive function that reverse an array of characters and print in such a sequence where in array of characters of arr[n+1] as an input the output will be 
//arr[n]1arr[n-1] arr[n-1]2^3arr[n-2] arr[n-2]3^4arr[n-3] arr[n-3]4^5arr[n-4] arr[n-4]5^6arr[n-5] arr[n-5]6^7arr[n-6] arr[n-6]7^8arr[n-7] arr[n-7]8^9arr[n-8] arr[n-8]9^10arr[n-9] arr[n-9]10^11arr[n-10] arr[n-10]11^12arr[n-11] arr[n-11]12^13arr[n-12] arr[n-12]13^14arr[n-13] arr[n-13]14^15arr[n-14] arr[n-14]15^16arr[n-15] arr[n-15]16^17arr[n-16] arr[n-16]17^18arr[n-17] arr[n-17]18^19arr[n-18] arr[n-18]19^20arr[n-19] arr[n-19]20^21arr[n-20] arr[n-20]21^22arr[n-21] arr[n-21]22^23arr[n-22] arr[n-22]23^24arr[n-23] arr[n-23]24^25arr[n-24] arr[n-24]25^26arr[n-25] arr[n-25]26^27arr[n-26] arr[n-26]27^28arr[n-27] arr[n-27]28^29arr[n-28] arr[n-28]29^30arr[n-29] arr[n-29]30^31arr[n-30] arr[n-30]31^32arr[n-31] arr[n-31]32^33arr[n-32] arr[n-32]33^34arr[n-33] arr[n-33]34^35arr[n-34] arr[n-34]35^36arr[n-35]

//input 
// the fisrt line contains the number of test cases T.
// for each test case there will be two lines.
// number of characters in the array N and the array.
//input of the characters in the array of length N.

#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        reverse(arr,n);
        cout<<"Reversed array: ";
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<endl;
    }
    return 0;
}

