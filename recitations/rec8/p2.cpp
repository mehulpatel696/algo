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

int getSum(int x){
    if(x < 10) return x;
    return x%10 + getSum(x/10);
}

int getSquareSum(int x){

    int sum = 0;
    while(x != 0 ){

        int b = x%10;
        sum += (b*b);
        x = x/10;
    }
    return sum;
}

int main(){
   // cout<<getSquareSum(58);
    int n;
    int caseNo = 1;
    int testcases;
    cin>>testcases;
    while(testcases--){
        cin>>n;
        int a = n;
        bool notFirst = true;
        while(a >= 10 || notFirst){
            notFirst = false;
            a = getSquareSum(a);

        }
        cout<<"Case #"<<caseNo++<<": "<<n;
        if(getSum(a) == 1)  cout<<" is a Happy number."<<endl;
        else cout<<" is an Unhappy number."<<endl;
    }
    return 0;


}
