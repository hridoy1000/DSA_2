
#include<iostream>

using namespace std;

int main(){


    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> s1(n);
        vector<int> c1(n);
        vector<string> s2(n);
        vector<int> c2(n);
        vector<string> s3(n);
        vector<int> c3(n);
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            int c;
            cin >> c;
            s1[i] = s;
            c1[i] = c;
        }
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            int c;
            cin >> c;
            s2[i] = s;
            c2[i] = c;
        }
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            int c;
            cin >> c;
            s3[i] = s;
            c3[i] = c;
        }
        map<string,int> m1;
        map<string,int> m2;
        map<string,int> m3;
        for(int i=0;i<n;i++){
            m1[s1[i]] += c1[i];
            m2[s2[i]] += c2[i];
            m3[s3[i]] += c3[i];
        }
        vector<string> v1;
        vector<string> v2;
        vector<string> v3;
        for(auto it=m1.begin();it!=m1.end();it++){
            v1.push_back(it->first);
        }
        for(auto it=m2.begin();it!=m2.end();it++){
            v2.push_back(it->first);
        }
        for(auto it=m3.begin();it!=m3.end();it
    return 0;
    }
}
jhfgfhfdskfg



