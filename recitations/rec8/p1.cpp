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

char grid[105][105];
int n;
int num_ships = 0;
int visited[105][105] = {0};
int directions[8][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} , {1,1}, {1,-1}, {-1,1}, {-1,-1}};

void dfs(int i, int j, bool x){
    if(i < 0 || j < 0 || i >= n || j >= n) return;
    if(grid[i][j] == '.') return;
    grid[i][j] = '.';
    for(int k = 0; k < 8; k++) {
        dfs(i + directions[k][0], j + directions[k][1], x);
    }
}


int main(){
    int testcases;
    cin>>testcases;
    int caseno = 1;
    while(testcases--){
        num_ships = 0;
        memset(grid, '-', sizeof grid);
        memset(visited, 0, sizeof visited);

        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){

                cin>>grid[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'x') {
                    num_ships++;
                    dfs(i,j, false);
                }
            }
        }
        cout<<"Case "<<caseno++<<": "<<num_ships<<endl;





    }
    return 0;


}
