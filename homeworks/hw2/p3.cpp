#include <stdio.h>
char g[10][10];
char s[10] = "@IEHOVA#";
int n, m, p[10];

#define edge(x,y) if(x < 0 || y < 0 || x >= n || y >= m) return;

void print(int l){
    for(int i = 0; i < l; i++) {
        if(i)   putchar(' ');
        if(p[i] == 0) printf("forth");
        else if(p[i] == 2) printf("right");
        else  printf("left");
    }
    puts("");
}
void dfs(int x, int y, int l) {
    edge(x,y);
    if(g[x][y] != s[l]) return;
    if(g[x][y] == '#')  return print(l);
    //Forth step
    p[l] = 0;
    dfs(x-1, y, l+1);
    //Left step
    p[l] = 1;
    dfs(x, y-1, l+1);
    //Right step
    p[l] = 2;
    dfs(x, y+1, l+1);
}


int main() {
    int testcase, i, j;
    scanf("%d", &testcase);
    while(testcase--) {
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++)  scanf("%s", &g[i]);
        for(i = 0; i < n; i++)  for(j = 0; j < m; j++) if(g[i][j] == '@') dfs(i, j, 0);
    }
    return 0;
}

