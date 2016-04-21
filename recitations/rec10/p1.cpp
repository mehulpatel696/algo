

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
#include <math.h>
#include <random>

using namespace std;



string n;


int main(){

   while(cin>>n){
        if(n == "0") break;
        int r = 0;
        for(int i = 0; i < n.size(); i++ ) r = ( ((char) n[i] - 48)  +  (r *10)) %17;
        if(r) cout<<0<<endl;
        else cout<<1<<endl;
    }
    return 0;
}


