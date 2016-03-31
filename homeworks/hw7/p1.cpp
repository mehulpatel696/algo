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

void print(double arr[32][32], int k, int l){
    for(int i = 0; i < k; i++){
        for(int j = 0; j < l; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}


void printvi(int arr[105]){
    for(int i = 0; i < 105; i++) cout<<i<<" : "<<arr[i]<<endl;
}


int main(){

    int n;
    int caseno = 1;
    while(cin>>n){
        if(n == 0) break;

        double arr[32][32] = { 0 };
        unordered_map<string, int> curr_index;

        for(int i = 1; i <= n; i++) {
            string a;
            cin>>a;
            curr_index[a] = i;
        }

        for (int i = 1; i <= n; i++) arr[i][i] = 1.0;

        int m;
        cin>>m;
        for(int i = 0; i < m; i++){
            string a,b;
            double c;
            cin>>a>>c>>b;
            arr[curr_index[a]][curr_index[b]] = c;
        }

        //print(arr, n+1,n+1);

        //Floyd-Warshall's Algo - use max instead of min and multiply
        for(int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) arr[i][j] = max(arr[i][j], arr[i][k] * arr[k][j]);

        //print(arr,n,n);
        //Go through the array and check if it's possible

        bool f = true;
        for(int i = 1; i <= n; i++){
            if(arr[i][i]> 1.0){
                f = false;
                break;
            }
        }

        cout<<"Case "<<caseno++<<": ";
        if(f) cout<<"No"<<endl;
        else cout<<"Yes"<<endl;


    }


}
