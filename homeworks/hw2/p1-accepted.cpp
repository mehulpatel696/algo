#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int FIRST(17);
const int SECOND(107);

#define res(r,n) for(int i=1;i<=n;i++) r[i].reset();
#define cp(a, b, c) (a.to_ulong() < b.to_ulong) ? c = true : c = false;




int p,n,ans;
bitset<FIRST> r[SECOND];
bitset<FIRST> u,t[SECOND];


void fill(int n, int p) {
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=p;j++) {
            int z;
            cin>>z;
            r[i][j] = z;
        }
    }
}

bool compare(const bitset<FIRST> &a,const bitset<FIRST> &b)
{
    return (a.to_ulong()<b.to_ulong());
}


bool noDups(){
    for(int i=1;i<n;i++) if(t[i]==t[i+1]) return false;
    return true;
}

void search(int depth)
{
    if(depth>p) {
        for(int i=1;i<=n;i++) t[i]=r[i];
        for(int i=1;i<=n;i++) t[i]=t[i]&u;
        sort(t+1,t+n+1,compare);
        if(noDups()) ans=min(ans,(int)u.count());
        return;
    }
    search(depth+1);
    u[depth]=1;
    search(depth+1);
    u[depth]=0;
}

int main()
{

    int testcases;
    cin>>testcases;
    while(testcases--)
    {
        cin>>p>>n;
        res(r,n);
        fill(n,p);
        ans=420;
        u.reset();
        search(1);
        cout<<ans<<endl;
    }

    return 0;
}
