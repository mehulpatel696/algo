#include <algorithm>
#include <cmath>
#include <climits>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <stdio.h>
#include <string.h>

using namespace std;




int arr[27][27][352];
void getNum(int start1, int end1, int start2){
    if(start1 >= end1) return;
    if(start2 > start1) return getNum(start1 + 1, end1, 0);
    for(int i = 0; i < 352; i++){
        arr[start1][start2][i] = arr[start1-1][start2][i];
        if(start2 > 0 && i >= start1) arr[start1][start2][i] += arr[start1-1][start2 - 1][i - start1];
    }
    getNum(start1, end1, start2 + 1);
}

int main() {

    int a, b;
    int casnum = 1;
    memset(arr, 0, sizeof(arr));
    arr[0][0][0] = 1;
    getNum(1,27,0);

    while(cin>>a>>b){
        if( a == 0 || b == 0) break;
        cout<<"Case "<<casnum++<<": ";
        if( a > 26 || b > 351) cout<<0<<endl;
        else cout<<arr[26][a][b]<<endl;
    }
    return 0;
}
