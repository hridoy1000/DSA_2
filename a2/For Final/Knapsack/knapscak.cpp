#include<bits/stdc++.h>
using namespace std;

int n, kW; /// kW = weight of the knapsack

struct kSack{
    string name;
    int weight;
    int value;
    float valWeight;
};


bool compare(kSack k1, kSack k2)
{
    return k1.valWeight>k2.valWeight;
}

float knapsackFractional(kSack k[], int kW)
{
    float value = 0.0;
    for(int i = 0; i<n; i++)
    {
        if(kW>k[i].weight)
        {
            value += k[i].value;
            kW = kW - k[i].weight;
            cout << k[i].name << " ";
        }
        else{
            value += k[i].valWeight * kW;
            cout << k[i].name << " ";
            break;
        }
    }
    return value;
}

int main()
{
    cout << "How many products?\n--> ";
    cin >> n;
    struct kSack ks[n];
    for(int i = 0; i<n; i++)
    {
        //getline(cin, ks[i].name);
        cin >> ks[i].name >> ks[i].weight >> ks[i].value;
        ks[i].valWeight = ((float)ks[i].value/ks[i].weight);
    }

    cout << "What is weight of the knapsack?\n--> ";
    cin >> kW;

    sort(ks,ks+n,compare);

    float result = knapsackFractional(ks, kW);
    cout << "--> "  << result;

    return 0;
}
