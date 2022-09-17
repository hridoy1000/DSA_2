#include<bits/stdc++.h>

using namespace std;

struct item{
	string name;
	int value;
	int weight;
	float ratio;
};


float frac_knap ( item arr[], int n, int knapsackWeight){

	float knapsackValue = 0.0;
	for(int i=0;i<n;i++){ /// Whole Object
		if(knapsackWeight>=arr[i].weight){
			knapsackValue = knapsackValue + arr[i].value;
			knapsackWeight = knapsackWeight - arr[i].weight;
			cout << arr[i]. name << " ";
		}
		else{ /// Fraction of the Object
			float fraction = (float)knapsackWeight/arr[i].weight;
			knapsackValue = knapsackValue + (fraction * arr[i].value);
			cout << arr[i]. name << " ";
			break;
		}
	}
	return knapsackValue;
}


bool compare (item a, item b){
	return a.ratio > b.ratio;
}


int main(){
	int n;
	cin>>n;

	struct item itemset [n];
	//cin.ignore()
	for(int i=0; i<n; i++){
		//getline(cin, itemset[i].name);
		cin>> itemset[i].name;
		cin>> itemset[i].weight;
		cin>> itemset[i].value;
		itemset[i].ratio = (float)(itemset[i].value/itemset[i].weight);
	}

	sort(itemset,itemset+n, compare);
	cout << frac_knap(itemset,n, 10);
	return 0;
}

