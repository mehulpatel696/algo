#include <iostream>
#include <vector>
#include <bitset>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

#define nodups(c,n, b) for(int i=0;i<n+1;i++) if(c[i]==c[i+1]) b = false;


bitset<20> data[110], c[110],u;
int p,n,m;



bool compare(const bitset<20> &a,const bitset<20> &b)
{
    return (a.to_ulong()<b.to_ulong());
}



void dfs(int d){
    if(d > p){
        for(int i = 1; i <= n; i++) c[i] = data[i];
        for(int i = 1; i <= n; i++) c[i] = c[i] & u;
        sort(c, c+n, compare);
        bool noDuplicates = true;;
        nodups(c,n, noDuplicates);
        if(noDuplicates) m = min(m,(int)u.count());
        return;
    }
    dfs(d+1);
    u[d] = 1;
    dfs(d+1);
    u[d] = 0;
}




int main(){

    int testcases;
    cin>>testcases;
    while(testcases--){
        cin>>p>>n;
        for(int i = 1; i <= n; i++) data[i].reset();
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= p;j++){
                int t;
                cin>>t;
                data[i][j] = t;
            }
        }
        m = 315;
        u.reset();
        dfs(1);
        cout<<m<<endl;
    }
    return 0;
}
