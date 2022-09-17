#include<bits/stdc++.h>
using namespace std;
struct item{
	string name;
	int value;
	int weight;
	float ratio;
};

bool myFunction (item a, item b){
	return a.ratio > b.ratio;
}

float fKnap ( item arr[], int n, int knapsackWeight){
	float knapsackValue = 0.0;
	for(int i=0; i<n; i++){
		if(arr[i].weight <= knapsackWeight){
			knapsackValue += arr[i].value;
			knapsackWeight -= arr[i].weight;
		}
		else{
			knapsackValue += (float)knapsackWeight/arr[i].weight * arr[i].value;
			knapsackWeight = 0;
		}
	}

	return knapsackValue;
}

int main(){
	int n;
	cin>>n;
	item items [n];

	for(int i=0; i<n; i++){
		cin>> items[i].name;
		cin>> items[i].value;
		cin>> items[i].weight;

		items[i].ratio = (float)items[i].value/items[i].weight;
	}

	sort(items,items+n, myFunction);
	int knapsackWeight;
	cin>>knapsackWeight;

	cout<<fKnap(items,n,knapsackWeight)<<endl;


	return 0;
}