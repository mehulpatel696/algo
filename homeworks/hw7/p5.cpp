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
#include <stdio.h>
#include <limits.h>
#include <string.h>

using namespace std;

int alist[26][26];
int p[26];
int indeg[26] = {0};
int outdeg[26] = {0};
int n,m;
bool vis[26];

int union_find(int x){
    if(p[x] == x) return x;
    else return p[x] = union_find(p[x]);
}

bool isPossible(){
    bool isP = true;;
    for(int i = 0; i <= m; i++){
        if(indeg[i] - outdeg[i] > 1) {
            isP = false;
            break;
        }
        for(int j = 0; j <= m; j++){
            if(vis[i] && vis[j] && union_find(i) != union_find(j)){
                isP = false;
                break;
            }
        }


    }
    return isP;
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        m = -INT_MAX;
        memset(alist, 0, sizeof alist);
        for(int i = 0; i < 26; i++) p[i] = i;
        memset(vis, false, sizeof vis);
        memset(indeg, 0, sizeof indeg);
        memset(outdeg, 0, sizeof outdeg);
        cin>>n;
        for(int i = 0; i < n; i++){
            string a;
            cin>>a;
            m = max(m, max(a[0] - 'a', a[a.length()-1] - 'a'));
            alist[a[0] - 'a'][a[a.length()-1] - 'a']++;
            indeg[a[(a.length()-1)] - 'a'] += 1;
            outdeg[a[0] - 'a'] += 1;
            int c = union_find(a[0] - 'a');
            int d = union_find(a[(a.length()-1)] - 'a');
            if(c != d) p[d] = c;
            vis[c] = vis[d] = true;
        }

        if(isPossible()) cout<<"Ordering is possible."<<endl;
        else cout<<"The door cannot be opened."<<endl;


    }
    return 0;


}
