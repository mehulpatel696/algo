#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <climits>
#include <iostream>
using namespace std;



int main() {
    int arr[60];
    for(int i = 0; i < 50; i++) arr[i] = i + 1;
    int n;
    while (cin>>n) {
        if(n == 0) return 0;
        arr[0] = 0;
        arr[1] = 1;
        for(int i = 2; i <= n + 1; i++) arr[i] = arr[i-1] + arr[i-2];
        cout<<arr[n+1]<<endl;


    }
    return 0;
}
