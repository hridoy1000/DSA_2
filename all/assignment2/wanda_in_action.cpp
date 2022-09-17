// Q4 WANDA in Action 
// Problem 
// In 2021, The Avenger land became infected by a deadly virus named “Thanos-v2.0”. The Avenger land has 
// many cities and some cities are connected to other cities. In order to prevent virus from spreading Wanda plans 
// on destroying the connection between all the cities. Wanda has got a power called wanda-suprema. Using this 
// power she can destroy any city, which results in destruction of all connections from this city. For destroying one 
// city, Wanda requires one unit of wanda-suprema power. Wanda’s final aim is to isolate all the cities. In order 
// to do so, Wanda follows a simple approach, he keeps on destroying the city with most number of connections in 
// it at that moment. 
 
// Since Wanda  is  a  high-tempered  lady  who  is  not  very  sharp  in  calculation, please help  her  in  finding  out  the 
// units  of  wanda-suprema  power  required  by  her  to  achieve  the  aim.  There  cannot  be  multiple  connections 
// between two cities i.e. two cities can have only one road connected to them. 
// Note: If there are multiple cities with highest connections, destroy the city with the lowest index. 


// Input Format: 
// ➢ The  first  line  will  contain  2  space  separated  integers N and M,  where N is  the  number  of  cities  in 
// Wanda's town and M is the number of connections that the cities have. 
// ➢ Next M lines follow, each line consists of two integers A and B, specifying that city A has a connection 
// with city B and B has a connection with the city A. 
// Output Format:  
// For each test case, output the minimum energy that Wanda requires to achieve his aim. 
// Image for sample Test case: 
 
// Sample 
// Input 
// Sample 
// Output Explanation 
// 4 2 
// 1 2 
// 3 4 
// 2 To achieve Wanda's aim, she can either destroy the cities numbered: 
// ➢ 1 and 3, or 
// ➢ 2 and 3, or 
// ➢ 1 and 4, or 
// ➢ 2 and 4  

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct city {
    int id;
    int connections;
};

struct compare {
    bool operator()(const city &c1, const city &c2) {
        return c1.connections > c2.connections;
    }
};


int main() {
    int n, m;
    cin >> n >> m;
    vector<city> cities(n);
    for (int i = 0; i < n; i++) {
        cities[i].id = i + 1;
        cities[i].connections = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cities[a - 1].connections++;
        cities[b - 1].connections++;
    }
    sort(cities.begin(), cities.end(), compare());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cities[i].connections;
    }
    cout << ans << endl;
    return 0;
}



// Q5 WANDA in Action
// Problem
// Wanda is a high-tempered lady who is not very sharp in calculation. Please help her in finding out the units of wanda-suprema power required by her to achieve the aim. There cannot be multiple connections between two cities i.e. two cities can have only one road connected to them.
// Note: If there are multiple cities with highest connections, destroy the city with the lowest index.
// Input Format:
// ➢ The first line will contain 2 space separated integers N and M, where N is the number of cities in Wanda's town and M is the number of connections that the cities have.
// ➢ Next M lines follow, each line consists of two integers A and B, specifying that city A has a connection with city B and B has a connection with the city A.
// Output Format:
// For each test case, output the minimum energy that Wanda requires to achieve his aim.
// Image for sample Test case:
// Sample
// Input
// Sample
// Output Explanation
// 4 2
// 1 2
// 3 4
// 2 To achieve Wanda's aim, she can either destroy the cities numbered:
// ➢ 1 and 3, or
// ➢ 2 and 3, or
// ➢ 1 and 4, or
// ➢ 2 and 4

 