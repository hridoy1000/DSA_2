#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[] = {4,256,2,4,3,3,5};
    int n = sizeof(arr)/sizeof(arr[3]); /// sizeof returns the byte size of an array;
                                        /// 7x4 bytes = 28 bytes / 4 bytes = 7
   for (int i=0; i<n;i++)
   {
       cout << "checking :" << arr[i] << endl;
       for(int j=i+1;j<n;j++)
       {
           //cout<< setprecision(4);
           cout<< "\t elm : " << arr[j] << endl;
           if(arr[i]==arr[j])
           {
                arr[i] = -1;
                break;
           }
       }

       if(arr[i]!=-1) cout << arr[i] << " is unique" << endl;
   }


/*
/// CASE 01: (n^2)

/// arr of size n
/// for (i= 0 to n)
        /// for (j = i+1 to n)
            ///arr[i]=arr[j] Change arr[i]to -1
///traverse arr
///    if (arr[x]!=-1) print arr[x]


/// CASE 02: (n^2)
4 256 2 4 3 3 5

/// for (i= 0 to n)
        ///unique_flag = 1;
        /// for (j = 0 to i-1)
                ///arr[i]=arr[j] Change unique_flag = 0; break;

///     if(unique_flag==1) cout << arr[i];

4
256: 4 X
2  : 4 256 X
4  : 4 (M) break
3  : 4 256 2 4 X
3  : 4 256 2 4 3 (M) break
5  : 4 256 2 4 3 3 X
*/
    return 0;
}

