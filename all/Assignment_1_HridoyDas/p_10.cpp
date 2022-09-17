
#include<iostream>
using namespace std;
struct person{
    string name;
    int id;
    int salary;
};
int main(){
    int n;
    cin>>n;
    person p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].name>>p[i].id>>p[i].salary;
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(p[i].salary<p[j].salary){
                person temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
            else if(p[i].salary==p[j].salary){
                if(p[i].id<p[j].id){
                    person temp=p[i];
                    p[i]=p[j];
                    p[j]=temp;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<p[i].name<<" "<<p[i].id<<" "<<p[i].salary<<endl;
    }
    return 0;
}
