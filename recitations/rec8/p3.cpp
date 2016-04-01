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
int flow, max_flow;
int n,c, m,s,t;
int a,b,d;

//
//void augmentPath ( int v ,int minedge){
//    if( v == s) { flow =  minedge; return ;}
//    else if( parent[v] != -1){
//        augmentPath(parent[v] , min(minedge,alist[parent[v]][v]) );
//        alist[parent[v]][v] -= flow;
//        alist[v][parent[v]] += flow;
//    }
//}
//
//


void augmentPath()
{

    flow = INT_MAX;
    int a = t;
    while(a != s){
        int b = parent[a];
        if(b == -1) break;
        flow = min(flow, alist[b][a]);
        a = b;
    }
    a = t;
    while(a != s){
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
        vector<int> unq(105, INT_MAX);
        unq[0] = s;
        flow = s;
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(temp == cut_off) break;
            for(int i = 0; i <= n; i++){
                if(alist[temp][i] > 0 && unq[i] == INT_MAX){
                    unq[i] = unq[temp] + 1;
                    parent[i] = temp;
                    q.push(i);
                }
            }

        }
        augmentPath();
        if(flow == 0 || flow == INT_MAX) break;
        max_flow += flow;
    }
    return max_flow;
}


int main(){

    int caseNo = 1;

    while(cin>>n){
        if(n == 0) break;
        memset(alist, 0, sizeof alist);
        memset(parent, -1, sizeof parent);
        flow = max_flow = 0;
        cin>>s>>t>>c;

        for(int i = 1; i <= c; i++){
            cin>>a>>b>>d;
            alist[a][b] += d;
            alist[b][a] += d;
        }


        cout<<"Network "<<caseNo++<<endl;
        cout<<"The bandwidth is "<<maximumFlow()<<"."<<endl;
        cout<<endl;
    }



    return 0;


}
