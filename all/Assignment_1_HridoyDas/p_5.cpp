#include<iostream>
using namespace std;

int main(){
    int n1, n2;
    cout<<"Enter the first number: ";
    cin>>n1;
    cout<<"Enter the second number: ";
    cin>>n2;
    int factorial1=1, factorial2=1;
    for(int i=1;i<=n1;i++){
        factorial1*=i;
    }
    for(int i=1;i<=n2;i++){
        factorial2*=i;
    }
    cout<<"Factorial of "<<n1<<" is "<<factorial1<<endl;
    cout<<"Factorial of "<<n2<<" is "<<factorial2<<endl;
    return 0;
}


