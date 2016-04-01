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



int alist[105][105];
int parent[105];
int n,m;
int flow, max_flow;

void print(int arr[105][105], int k, int l){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < l; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}


void printvi(int arr[105]){
    for(int i = 0; i < 105; i++) cout<<i<<" : "<<arr[i]<<endl;

}

int getVal(string a){
    if(a == "XXL") return 1;
    else if(a == "XL") return 2;
    else if(a == "L") return 3;
    else if(a == "M") return 4;
    else if(a == "S") return 5;
    else if(a == "XS") return 6;
    else return 0;
}

void augmentPath()
{
    flow = INT_MAX;
    int a = m + 7;
    while(a != 0){
        int b = parent[a];
        flow = min(flow, alist[b][a]);
        a = b;
    }
    a = m + 7;
    while(a != 0){
        int b = parent[a];
        alist[b][a] -= flow;
        alist[a][b] += flow;
        a = b;
    }
}

int maximumFlow(){
    max_flow = 0;
    int cut_off = 7 + m;
    while(1){
        vector<int> unq(105, INT_MAX);
        unq[0] = 0;
        flow = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(temp == cut_off) break;
            for(int i = 0; i < 105; i++){
                if(alist[temp][i] > 0 && unq[i] == INT_MAX){
                    unq[i] = unq[temp] + 1;
                    parent[i] = temp;
                    q.push(i);
                }
            }

        }
        augmentPath();
        if(flow == 0) break;
        max_flow += flow;
    }
    return max_flow;
}
int main(){

    int testcases;
    cin>>testcases;
    while(testcases--){
        memset(alist, 0, sizeof alist);
        memset(parent, -1, sizeof parent);
        cin>>n>>m;
        for(int i = 1; i < 7; i++) alist[0][i] = n/6;
        for(int i = 7; i < 7 + m; i++) alist[i][m+7] = 1;
        for(int i = 7; i < 7 + m; i++){
            string a;
            cin>>a;
            alist[getVal(a)][i] = 1;
            cin>>a;
            alist[getVal(a)][i] = 1;
        }
        //print(alist, 105, 105)
        if(maximumFlow() == m)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


}
/*        memset(alist, 0, sizeof alist);
 memset(parent, -1, sizeof parent);

 for(int i = 1; i <= n; i++) cin>>alist[i][i];

 int m;
 cin>>m;

 for(int i = 0; i < m; i++){
 int a,b,c;
 cin>>a>>b>>c;
 alist[a][b] = c;
 }

 int so_c, si_c;
 cin>>so_c>>si_c;
 int d;
 for(int i = 0; i < so_c + si_c; i++){
 cin>>d;
 if(i < so_c){
 alist[0][d] = 1;
 } else {
 alist[n+1][d] = 1;
 }
 }

 print(alist, 6, 6);
 // cout<<maximumFlow()<<endl;
 */
