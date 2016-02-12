#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

#define isp(is)  if(is) cout<<"POSSIBLE"<<endl; else cout<<"IMPOSSIBLE"<<endl;
#define v(x) vector<x>
#define m(i,b) map<i,b>
#define mi(i,b) map<i,b>::iterator

int owed[10005];
m(int,int) remain;


class DisjointSet {

private:
    v(int) p, heirarchy, ss;

public:

    DisjointSet(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; i++)  p[i] = i;
        heirarchy.assign(N, 0);
        ss.assign(N, 1);
    }

   int fs(int i) {
        if(p[i] == i) return i;
        else return p[i] = fs(p[i]);
    }

   void us(int i, int j) {
        if (!(fs(i) == fs(j))) {
            int x = fs(i), y = fs(j);
            if (heirarchy[x] > heirarchy[y]) {
                p[y] = x;
                ss[fs(x)] += ss[fs(y)];
            } else {
                p[x] = y;
                if (heirarchy[x] == heirarchy[y])  heirarchy[y]++;
                ss[fs(y)] += ss[fs(x)];
            }

        }
    }

};

int main() {

    int testcases;
    cin>>testcases;
    while (testcases--) {
        int n, m, u, v;
        cin>>n>>m;
        DisjointSet ue(n);
        remain.clear();
        for(int i=0;i<n;i++)  cin>>owed[i];
        for (int i = 0; i < m; i++) cin>>u>>v, ue.us(u, v);
        for(int i=0;i<n;i++){
            if(remain.count(ue.fs(i))==0) remain[ue.fs(i)] = owed[i];
            else remain[ue.fs(i)] += owed[i];
        }
        bool isPossible = true;
        for(mi(int, int) it = remain.begin();it != remain.end();it++){
            if(it->second != 0) {
                isPossible = false;
                break;
            }
        }
        isp(isPossible);
    }

    return 0;
}
