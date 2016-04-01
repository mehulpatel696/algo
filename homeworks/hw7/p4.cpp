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
int alist2[205][205];

int parent[205];
int n,s = 0,m,t = 1,a,b,c;
int flow, max_flow;
int visited[205];
bool debug = false;
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


void dfs(int u){
    if(visited[u]) return;
    visited[u] = 1;
    for(int j = 0; j < n; j++) {
        if(alist2[u][j] != -1) if(alist[u][j] > 0) dfs(j);
    }
}

void minimumCut(){
    memset(visited, 0, sizeof visited);
    dfs(0);
    for(int i = 0; i < n; i++){
        if(visited[i] == 1){
            for(int j = 0; j < n; j++){
                if(alist2[i][j] > -1){
                    if(visited[j] == 1) continue;
                    if (alist[i][j] <= 0) cout<<i + 1<<" "<<j + 1<<endl;
                }
            }
        }
    }
}


void augmentPath ( int v ,int minedge){
    if( v == s) { flow =  minedge; return ;}
    else if( parent[v] != -1){
        augmentPath(parent[v] , min(minedge,alist[parent[v]][v]) );
        alist[parent[v]][v] -= flow;
        alist[v][parent[v]] += flow;
    }
}



void maximumFlow(){
    max_flow = 0;
    int cut_off = t;
    while(1){
        memset(parent, -1, sizeof parent);
        if(debug) cout<<"HERE 1"<<endl;
        vector<int> unq(205, INT_MAX - 10000);
        //source
        unq[0] = 1;
        flow = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            if(debug) cout<<"HERE 2"<<endl;
            int temp = q.front();
            q.pop();
            if(temp == cut_off) break;
            for(int i = 0; i < n; i++){
                if(debug) cout<<"HERE 3"<<endl;
                if(alist2[temp][i] > -1){
                    if(alist[temp][i] > 0 && unq[i] == (INT_MAX - 10000)){
                        unq[i] = unq[temp] + 1;
                        parent[i] = temp;
                        q.push(i);
                    }
                }
            }

        }
        augmentPath(t, INT_MAX - 10000);
        if(flow == 0 ) break;
        max_flow += flow;
    }

    //return max_flow;
}


int main(){

    while(cin>>n>>m){
        if(n == 0 && m == 0) break;
        memset(alist, 0, sizeof alist);

        memset(alist2, -1, sizeof alist2);

        for(int i = 0; i < m; i++){
            cin>>a>>b>>c;

            alist[a-1][b-1] += c;
            alist[b-1][a-1] += c;

            alist2[a-1][b-1] = c;
            alist2[b-1][a-1] = c;


        }
        maximumFlow();
        minimumCut();
        cout<<endl;

    }
    return 0;


}
