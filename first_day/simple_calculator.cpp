#include<iostream>
using namespace std;

int main(){

    int n1, n2;
    cout<<"Enter two numbers";
    cin>>n1>>n2;

    char op;
    cout<<"Enter Operator";
    cin>>op;

    switch (op)
    {
    case '+':
    cout<<n1+n2<<endl;
        break;
    case '-':
    cout<<n1-n2<<endl;
        break;
         case '*':
    cout<<n1*n2<<endl;
        break;
         case '/':
    cout<<n1/n2<<endl;
        break; 
    default:
    cout<<"Enter a operator"<<endl;
        break;
    }

}