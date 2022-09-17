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
