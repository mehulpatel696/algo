
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

/*



      SourceRecepectaleDeviceSink
 S
 o
 u
 r
 c
 e
 R
 e
 c
 e
 p
 e
 c
 t
 a
 l
 e
 D
 e
 v
 i
 c
 e
 S
 i
 n
 k







 */

int alist[405][405];
int parent[405];
int n,m, size, s,t,c, flow, max_flow;
int MAX = INT_MAX;



void print(int arr[405][405], int k, int l){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < l; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}


void printvi(int arr[405]){
    for(int i = 0; i < 405; i++) cout<<i<<" : "<<arr[i]<<endl;

}




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
        vector<int> unq(405, INT_MAX);
        unq[0] = 0;
        flow = 0;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            if(temp == cut_off) break;
            for(int i = 0; i < n+m+2; i++){
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

    int testcases;
    cin>>testcases;
    while(testcases--){

        memset(alist, 0, sizeof alist);
        memset(parent, -1, sizeof parent);
        cin>>n;
        map<string, int> receptacles;
        map<string, int> devices;
        map<string, int> devices_recs;
        vector<int> numrecs(n+1, 0);

        for(int i = 1; i <=n; i++ ) {
            string temp;
            cin>>temp;
            receptacles[temp] = i;

        }

        cin>>m;
        int temp_n = n;
        for(int i = temp_n + 1; i <=m + temp_n; i++ ) {
            string temp, temp2;
            cin>>temp>>temp2;
            if(receptacles.find(temp2) == receptacles.end()) {
                receptacles[temp2] = ++n;
                numrecs.push_back(0);
            }
            devices_recs[temp] = receptacles[temp2];
            devices[temp] = i;
           // cout<<"a "<<receptacles[temp2]<<endl;
            numrecs[receptacles[temp2]]++;
        }
        s = 0; t = n + m + 1;

        for(int i = n + 1; i <= n + m; i++) alist[s][i] = 1;
        for(map<string, int>::iterator it = devices_recs.begin(); it != devices_recs.end(); it++) {
           // cout<<"A: ";
           // cout<<devices_recs[it->first]<< " "<<devices[it->first]<<endl;
            //alist[devices_recs[it->first]][devices[it->first]] = 1;

            alist[devices[it->first]][it->second] = 1;
        }


        for(int i = 1; i <= n; i++) alist[t][i] = numrecs[i];

        cin>>c;
        for(int i = 0; i < c; i++){
           // cout<<"here"<<endl;
            string a,b;
            cin>>a>>b;
           // cout<<receptacles[a]<<" "<<receptacles[b]<<endl;
            alist[receptacles[a]][receptacles[b]] = MAX;
        }
        print(alist, 15, 15);
        cout<<maximumFlow()<<endl;
    }


}
