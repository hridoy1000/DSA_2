#include<bits/stdc++.h>
using namespace std;

struct activtiySelection{
    int number;
    int start;
    int finish;
};

bool compare(activtiySelection a, activtiySelection b)
{
    return a.finish < b.finish;
}


vector<vector<int>> activities;
vector<int> ans;
int tot=0;

void rec(int i=0) {
   if(i==tot) {
      for(int j:ans) cout<<j <<" \n"[j==ans.back()];
      return;
   }
   for(int j:activities[i]) {
      ans.push_back(j);
      rec(i+1);
      ans.pop_back();
   }
}

int main()
{
    int n;
    cout << "How many jobs?\n-->";
    cin >> n;
    activtiySelection as[n];
    for(int i = 0; i<n; i++)
    {
        cin >> as[i].number; /// Job number
        cin >> as[i].start;  /// Starting time
        cin >> as[i].finish; /// Finish time
    }

    sort(as, as+n,compare);

    for(int i = 0; i<n; i++)
    {
        cout << "[" << as[i].number << "," << as[i].start << "," << as[i].finish << "]\n";
    }

    int tmaxx=0,pmaxx;
    for(int i = 0; i<n; i++)
    {
        cout << as[i].start << " " << tmaxx <<endl;
        if(as[i].start>=tmaxx) {
            pmaxx=tmaxx;
            tmaxx=as[i].finish;
            activities.push_back({as[i].number});
            tot++;
        } else if(as[i].start>=pmaxx && as[i].finish<=tmaxx) {
           activities.back().push_back(as[i].number);
        }
    }

    cout << "\nThe man can do maximum " << tot << " jobs. Which are--> " << endl;
    rec();


}
