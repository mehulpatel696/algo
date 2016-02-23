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

    int n,d,r;
    while(cin>>n>>d>>r){
        if(n == 0 && d == 0 && r == 0) break;
        vector<int> morning(n);
        vector<int> evening(n);
        for(int i = 0; i < n; i++) cin>>morning[i];
        for(int i = 0; i < n; i++) cin>>evening[i];
        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());
        int pay = 0;
        for(int i = 0; i < n; i++)  if( (morning[i] + evening[n - 1 - i])  - d > 0) pay += (( (morning[i] + evening[n - 1 - i]) - d));
        cout<<pay * r<<endl;
     }
    return 0;
}
