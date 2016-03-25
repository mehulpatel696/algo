#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;


#define refresh(n) for(int i = 0; i < 103; i++) for(int j = 0; j < 103;j++) n[i][j] = 0;
#define refresh1d(n) for(int i = 0; i < 103; i++) n[i] = 0;

int graph[103][103];
int rel[103][103];
int n;


void dfs(int u, int ex, vector<int> &graph_vs){
    if(u != ex){
        graph_vs[u] = true;
        for(int i = 0; i < n; i++) if(!graph_vs[i] && graph[u][i]) dfs(i,ex, graph_vs);
    }
}

int main() {

    int testcases;
    cin>>testcases;

    while(testcases--){

        refresh(graph);
        refresh(rel);
        cin>>n;
        for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin>>graph[i][j];

        //visit everynode first
        vector<int> graph_vs(103);
        dfs(0,-1,graph_vs);

        //Now visit every node and call dfs on each one but exlcude the connection you trying to see is dominated and if even after excluding that node is visited then
        //the node does not dominate the node youre comparing it with

        for(int i = 0; i < n; i++){
            vector<int> graph_vs_t(103);
            dfs(0,i,graph_vs_t);
            for(int j = 0; j < n; j++) {
                if(!graph_vs_t[j] && graph_vs[j]) rel[i][j] = 1;
                else rel[i][j] = 0;
            }
        }

        for(int i = 0; i < n; i++){
            cout<<"+";
            for(int j = 0; j < ( (n*2)-1 ); j++) cout<<"-";
            cout<<"+"<<endl;
            cout<<"|";
            for(int j = 0; j < n; j++){
                if(rel[i][j] == true) cout<<"Y";
                else cout<<"N";
                cout<<"|";
            }
            cout<<endl;

        }
        cout<<"+";
        for(int j = 0; j < ( (n*2)-1 ); j++) cout<<"-";
        cout<<"+"<<endl;



    }


    return 0;
}
