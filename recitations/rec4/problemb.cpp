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
#include <climits>
#include <math.h>

using namespace std;
#define printv(a) for(int i = 0; i < a.size(); i++) cout<<a[i]<<endl;



int main(){

    int n, q;
    int casen = 1;
    while(cin>>n>>q){
        if(n == 0 && q == 0) break;
        cout<<"CASE# "<<casen<<":"<<endl;
        casen++;
        vector<int> marbles(n);
        for(int i = 0; i < n; i++) cin>>marbles[i];
        sort(marbles.begin(),marbles.end());
        for(int i = 0; i < q; i++){
            int t;
            cin>>t;
            vector<int>::iterator it = find(marbles.begin(), marbles.end(), t);
            if(it != marbles.end())cout<<t<<" found at "<<it - marbles.begin() + 1<<endl;
            else  cout<<t<<" not found"<<endl;
        }

    }
    return 0;
}
