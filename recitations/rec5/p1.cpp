#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <climits>
#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int size)
{
    int max_so_far = 0, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_ending_here < 0)
            max_ending_here = 0;
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}

int main() {
    int n;
    while (cin>>n) {
        if(n == 0) return 0;

        int arr[n];
        for(int i = 0; i < n; i++) cin>>arr[i];
        int max_streak = maxSubArraySum(arr, n);
        if(max_streak > 0) cout<< "The maximum winning streak is "<<max_streak<<"."<<endl;
        else cout<<"Losing streak."<<endl;

    }
    return 0;
}
