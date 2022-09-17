#include<bits/stdc++.h>
using namespace std;

struct activity{
	int name;
	int start;
	int end;
};

bool myFunction (activity a, activity b){
	return a.end < b.end;
}

int activity_seletion(activity arr[], int n){

	int curr =0; int next;
	cout<<arr[curr].name << " ";
	for(next=1;next<n;next++){

		if(arr[curr].end <= arr[next].start){
			curr=next;
			cout<< arr[curr].name << " ";
		}
	}
    return 0;
}

int main(){
	int n;
	cin>>n;
	struct activity activitys [n];
	for(int i=0; i<n; i++){
		activitys[i].name = i+1;
		cin>> activitys[i].start;
		cin>> activitys[i].end;
	}
	sort(activitys,activitys+n, myFunction);
    activity_seletion(activitys,n);
	return 0;
}



