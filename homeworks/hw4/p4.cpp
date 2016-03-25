#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;


void print(char grid[50][50], int a, int b){
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++){
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}


int visited[50][50];
char grid[50][50];
int a,b,g = 0;

void dfs(int i, int j){
    if(i >= a || j >= b || i < 0 || j <0 || visited[i][j] || grid[i][j] == '#') return;
    visited[i][j] = 1;
    if(grid[i][j] == 'G') g++;
    if(grid[i-1][j] == 'T' || grid[i+1][j] == 'T' || grid[i][j-1] == 'T' || grid[i][j+1] =='T') return;
    dfs(i - 1, j);
    dfs(i + 1, j);
    dfs(i, j - 1);
    dfs(i, j + 1);
}



int main() {
    while(cin>>b>>a){
        memset(visited, 0, sizeof(visited));
        memset(grid, 0, sizeof(grid));
        int ia,jb;
        g = 0;
        for(int i = 0; i < a; i++){
            for(int j = 0; j < b; j++){
                cin>>grid[i][j];
                if(grid[i][j] == 'P') {
                   ia = i;
                    jb = j;
                }
            }
        }
        dfs(ia,jb);
        cout<<g<<endl;
    }


}
