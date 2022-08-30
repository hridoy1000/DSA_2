
#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    struct employee{
        string name;
        int height;
        int age;
    };
    employee e[n];
    for(int i=0;i<n;i++){
        cin>>e[i].name>>e[i].height>>e[i].age;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(e[i].height<e[j].height){
                employee temp=e[i];
                e[i]=e[j];
                e[j]=temp;
            }
            else if(e[i].height==e[j].height){
                if(e[i].age<e[j].age){
                    employee temp=e[i];
                    e[i]=e[j];
                    e[j]=temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<e[i].name<<" "<<e[i].height<<" "<<e[i].age<<endl;
    }
    return 0;
}