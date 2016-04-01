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




int alist[205][205];
int parent[205];
int n,s,m,t,g;
int flow, max_flow;

void print(int arr[205][205], int k, int l){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < l; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


void printvi(int arr[205]){
    for(int i = 0; i < 205; i++) cout<<i<<" : "<<arr[i]<<endl;

}


void augmentPath()
{

    flow = INT_MAX - 10000;
    int a = t;
    while(a != -1){
        int b = parent[a];
        if(b == -1) break;
        flow = min(flow, alist[b][a]);
        a = b;
    }
    a = t;
    while(a != -1){
        int b = parent[a];
        if(b == -1) break;
        alist[b][a] -= flow;
        alist[a][b] += flow;
        a = b;
    }

}



int maximumFlow(){
    max_flow = 0;
    int cut_off = t;
    while(1){
        vector<int> unq(205, INT_MAX - 10000);
        //source
        unq[1] = 1;
        flow = 0;
        queue<int> q;
        q.push(1);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(temp == cut_off) break;
            for(int i = 1; i <= t; i++){
                if(alist[temp][i] > 0 && unq[i] == (INT_MAX - 10000)){
                    unq[i] = unq[temp] + 1;
                    parent[i] = temp;
                    q.push(i);
                }
            }

        }
        augmentPath();
        if(flow == 0 || flow == (INT_MAX - 10000) ) break;
        max_flow += flow;
    }
    return max_flow;
}


int main(){


    while(cin>>n){

        memset(alist, 0, sizeof alist);
        memset(parent, -1, sizeof parent);
        for(int i = 1; i <= n; i++){
            cin>>g;
            alist[2*i][2*i+1] = g;
        }
        int m;
        cin>>m;
        for(int i = 0; i < m; i++){
            int a,b,c;
            cin>>a>>b>>c;
            alist[2*a+1][2*b] = c;
        }
        int so_c, si_c;
        cin>>so_c>>si_c;
        int d;
        s = 2*n + 1;
        t = s + 1;
        int u,v;
        while(so_c--) {
            cin>>u;
            alist[1][2*u] = INT_MAX - 10000;
        }
        while(si_c--) {
            cin>>u;
            alist[2*u+1][t] = INT_MAX - 10000;
        }
        cout<<maximumFlow()<<endl;

    }
    return 0;

}
