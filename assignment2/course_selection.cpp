// Course Selection Problem 
// X-land has a very famous university. The university offers N courses. Each course runs for some 
// consecutive range of days. You are given starting and ending days of the ith course by starti and 
// endi, respectively. 
// Sam wanted to enrol himself in the university. But he is not sure about the exact time for which he 
// wants to study. Though he has Q such tentative plans in his mind. Each plan consists of a start date 
// plan_startj and an end date plan_endj.  
// Sam wants your help in finding out the maximum number of courses he can complete during each 
// of his plans. Note that at a time, Sam cannot handle multiple courses, i.e. he can attend at most one 
// course during a day. Also, a course will be considered completed only if Sam attends all the classes 
// of the course. 

// Input 
// ➢ There is a single test case. 
// ➢ The  first  line  of  the  input  contains  two  space-separated  integers  N  and  Q  denoting  the 
// number  of  courses  the  university  offers  and  the  number  of  plans  Sam  has  in  mind, 
// respectively. 
// ➢ The ith of the next N lines contains two space-separated integers starti and endi denoting 
// the starting and the ending day of the ith course. 
// ➢ The jth of the next Q lines contains two space-separated integers plan_startj and plan_endj, 
// denoting the start and the end day of Sam’s plan. 

// Output 
// Output Q lines - each containing an integer corresponding to the maximum number of the courses 
// Sam can complete in the corresponding planned visit.

// Course Selection Problem 
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

// Course Selection Problem
// X-land has a very famous university. The university offers N courses. Each course runs for some
// consecutive range of days. You are given starting and ending days of the ith course by starti and
// endi, respectively.
// Sam wanted to enrol himself in the university. But he is not sure about the exact time for which he
// wants to study. Though he has Q such tentative plans in his mind. Each plan consists of a start date
// plan_startj and an end date plan_endj.
// Sam wants your help in finding out the maximum number of courses he can complete during each of his
// plans. Note that at a time, Sam cannot handle multiple courses, i.e. he can attend at most one course
// during a day. Also, a course will be considered completed only if Sam attends all the classes of the
// course.


// Input
// There is a single test case.
// The first line of the input contains two space-separated integers N and Q denoting the number of
// courses the university offers and the number of plans Sam has in mind, respectively.
// The ith of the next N lines contains two space-separated integers starti and endi denoting the
// starting and the ending day of the ith course.
// The jth of the next Q lines contains two space-separated integers plan_startj and plan_endj,
// denoting the start and the end day of Sam’s plan.


// Output
// Output Q lines - each containing an integer corresponding to the maximum number of the courses Sam can complete in the corresponding planned visit.
