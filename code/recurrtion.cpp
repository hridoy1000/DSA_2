#include<iostream>
using namespace std;

int main(){
    int t;  
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n][3];
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            int c;
            cin >> c;
            arr[i][0] = c;
            if(s == "S1"){
                arr[i][1] = c;
            }
            else if(s == "S2"){
                arr[i][2] = c;
            }
        }
        int sum[n];
        for(int i=0;i<n;i++){
            sum[i] = arr[i][0] + arr[i][1] + arr[i][2];
        }
        for(int i=0;i<n;i++){
            cout << sum[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
