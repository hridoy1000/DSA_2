#include <iostream>
using namespace std;

struct course {
    int start, end;
};

struct plan {
    int start, end;
};

struct compare {
    bool operator()(const course &c1, const course &c2) {
        return c1.end < c2.end;
    }
};

struct compare2 {
    bool operator()(const plan &p1, const plan &p2) {
        return p1.end < p2.end;
    }
};


int main() {
    int n, q;
    cin >> n >> q;
    vector<course> courses(n);
    for (int i = 0; i < n; i++) {
        cin >> courses[i].start >> courses[i].end;
    }
    sort(courses.begin(), courses.end(), compare());
    vector<plan> plans(q);
    for (int i = 0; i < q; i++) {
        cin >> plans[i].start >> plans[i].end;
    }
    sort(plans.begin(), plans.end(), compare2());
    int ans = 0;
    int last = -1;
    for (int i = 0; i < q; i++) {
        if (plans[i].start > last) {
            ans++;
            last = plans[i].end;
        }
    }
    cout << ans << endl;
    return 0;
}