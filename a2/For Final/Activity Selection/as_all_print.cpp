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


int main()
{
    int n;
    cout << "How many jobs?\n-->";
    cin >> n;
    struct activtiySelection as[n];
    for(int i = 0; i<n; i++)
    {
        cin >> as[i].number; /// Job number
        cin >> as[i].start;  /// Starting time
        cin >> as[i].finish; /// Finish time
    }

    sort(as, as+n,compare);

   /**for(int i = 0; i<n; i++)
    {
        cout << "[" << as[i].number << "," << as[i].start << "," << as[i].finish << "]\n";
    }*/

    cout << endl;

    int cmaxx=0, maxx;
    for(int current = 0; current<n; current++)
    {
        maxx = 0;
        cout << as[current].number << " ";
        maxx++;
        int temp = current;
        for(int next = temp+1 ; next<n ; next++)
        {
            if(as[temp].finish <= as[next].start)
            {
                temp = next;
                cout << as[temp].number << " ";
                maxx++;
            }
        }
        if(cmaxx<=maxx)
        {
           cmaxx = maxx;
        }
        cout << endl;
    }

    cout << "The man can do maximum " << cmaxx << " jobs." << endl;


}


