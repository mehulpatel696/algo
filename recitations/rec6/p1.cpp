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
using namespace std;











int main(){

    int n,m;
    while(cin>>n>>m){

        if(n == 0 && m == 0) break;
        vector<int> sub(n,-1);
        vector< vector<int> > vvi(n,sub);
        for(int i = 0; i < m; i++){
            int a,b;
            cin>>a>>b;
            vvi[a-1][b-1] = 1;
            vvi[b-1][a-1] = 1;
        }



    }
    return 0;

}
