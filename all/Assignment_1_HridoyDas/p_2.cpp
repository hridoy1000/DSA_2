#include<iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter a character: ";
    cin>>ch;
    while(ch!='A'){
        cout<<ch<<endl;
        cin>>ch;
    }
    return 0;
}