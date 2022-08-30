// Q3 Burst the Balloons 
// There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons 
// are represented as a 2D integer array of points where points[i] = [xstart, xend] denotes 
// a balloon whose horizontal diameter stretches between xstart and xend. You do not know the 
// exact y-coordinates of the balloons. 
 
// Arrows can be shot up directly vertically (in the positive y-direction) from different points along 
// the x-axis. A balloon with xstart and xend is burst by  an arrow shot at x if  xstart <= x <= 
// xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up 
// infinitely, bursting any balloons in its path. 
 
// Given  the  array  points,  return  the  minimum  number  of  arrows  that  must  be  shot  to  burst  all 
// balloons. 
 
// Sample Input Sample Output Explanation 
// 4 
// 10 16 
// 2 8 
// 1 6 
// 7 12 
 
// 2 
 
// The balloons can be burst by 2 
// arrows: 
// - Shoot an arrow at x = 6, bursting 
// the balloons [2,8] and [1,6]. 
// - Shoot an arrow at x = 11, bursting 
// the balloons [10,16] and [7,12]. 
 
// 4 
// 1 2 
// 3 4 
// 5 6 
// 7 8 
// 4 One arrow needs to be shot for each 
// balloon for a total of 4 arrows.


// Q3 Burst the Balloons 

#include<iostream>
using namespace std;
#define ll long long

int main(){
 vector<pair<ll,ll>> v={{10,16},{2,8},{1,6},{7,12}};
 vector<pair<ll,ll>> v={{1,2},{3,4},{5,6},{7,8}};
     sort(v.begin(),v.end());
     ll ans=0,last=-1;
     for(auto [l,r]:v) if(l>last) {
      ans++;
      last=r;
}
   cout<< ans <<"\n";
}





