

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

int n;
double p;

#define MOD 10000007



long double nchooser(int n, int r){
    long double ans = 1.0;
    int b2 = n - r;
    for(int i = n; i > r ; i--){
        int divide = b2-(n-i);
        divide =  (divide <= 0) ? 1 : divide;
        //cout<<i<<" "<<divide<<endl;
        double a =  ((double) i/ (double) divide);
        ans *= a;

    }
    return ans;
}


int main(){

   // cout<<nchooser(8,5)<<endl;


    int testcases;
    cin>>testcases;

    while(testcases--){
        cin>>n>>p;

        //Prob B wins
        double q = 1.0 - p;
        //cout<<q<<endl;
        //Ans
        double ans = 0.0;

        int total = 2*n - 1;

        for(int i = n; i <= total; i++){
            double long ncr = nchooser(total, i);
            ans += ( ncr * pow(p, i) * pow(q,total - i) );

        }

        printf("%.2f\n", ans);


    }
    return 0;
}


