#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

struct person{
string name;
int age;
int height;
};

bool compare (person a, person b)
{
    if(a.height == b.height) return a.age>b.age;
    else return a.height > b.height;
}

int main()
{
    int number;
    cin>>number;

    struct person people[number];

    for(int i=0; i<number; i++)
    {
        cin.ignore();
        getline(cin,people[i].name);
        //cin>>people[i].name;
        cin>>people[i].age;
        cin>>people[i].height;
    }
        sort(people,people+(number),compare);
        for(int i=0; i<number; i++)
    {
        cout<<people[i].name<<" ";
        cout<<people[i].age<< " ";
        cout<<people[i].height;
        cout<<endl;
    }

    return 0;
}
