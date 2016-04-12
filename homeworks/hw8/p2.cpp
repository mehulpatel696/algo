
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

using namespace std;

long long m,x;
long long ans;

void findV(){
    double t = m - 1.0;
    //effective income percent
    double s = 100.0 - x;
    ans = (long long) (100.0 * t) / s;
    //subtract 1 if s and t are divisible because there was truncating by default if you don't it will overflow by one
    if( (long long)( 100.0 * t) % (long long)s == 0) ans--;
    //we are looking for a value greater than m
    if(ans < m) cout<<"Not found"<<endl;
    else cout<<ans<<endl;
}


int main(){

    while(cin>>m>>x){
        if(m == 0 && x == 0) break;
        //if the percent is 0 or 100 the value can't be found
        if(x == 0 || x == 100){
            cout<<"Not found"<<endl;
            continue;
        }
        findV();


    }
    return 0;

}










