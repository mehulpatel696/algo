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
/*

*/

#define printv(v) for(int i = 0;i < v.size(); i++) cout<<v[i]<<endl;

//int binarySearch(vector<int> &array, int start, int end, int elm){
//    if(start > end) return -1;
//    int mid = (start + end)/2;
//    if(array[mid] == elm) return mid;
//    if(array[mid] > elm) return binarySearch(array, start, mid - 1, elm);
//    else return binarySearch(array, mid + 1, end, elm);
//}


int LIS(vector<int> &d, vector<int> &w, bool isDecreasing){

    vector<vector<int>> ss(d.size());
    vector<vector<int>> is(d.size());

    ss[0].push_back(d[0]);
    is[0].push_back(0);

    for(int i = 1; i < d.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(isDecreasing){
                if( (d[j] > d[i]) && (ss[i].size() < ( ss[j].size() + 1))) {
                    ss[i] = ss[j];
                    is[i] = is[j];
                }
            } else  {
                if( (d[j] < d[i]) && (ss[i].size() < ( ss[j].size() + 1))) {
                    ss[i] = ss[j];
                    is[i] = is[j];
                }
            }

        }
        ss[i].push_back(d[i]);
        is[i].push_back(i);
    }

    int max_sum = INT_MIN;
    for(int i = 0; i < is.size();i++){
        int sum = 0;
        for(int j = 0; j < is[i].size();j++){
            sum += w[is[i][j]];
        }
        cout<<sum<<endl;
        max_sum = max(sum, max_sum);
    }
    return max_sum;
}

void lis_lds(int n, vector<int> &heights, vector<int> &widths, vector<int> &lis, vector<int> &lds, int &lis_max, int &lds_max){

    for(int i = 0; i < n; i++) cin>>heights[i];
    for(int i = 0; i < n; i++) cin>>widths[i];
    int lis_temp, lds_temp;
    for(int i = 0; i < n; i++){
        lis_temp = lds_temp = lis[i] = lds[i] = widths[i];
        for(int j = 0; j < n; j++){
            if(heights[j] < heights[i]) lis[i] = max(lis[i], lis_temp + lis[j]);
            if(heights[j] > heights[i]) lds[i] = max(lds[i], lds_temp + lds[j]);
        }
        lis_max = max(lis_max, lis[i]);
        lds_max = max(lds_max, lds[i]);
    }

}
int main(){

    int testcases;
    cin>>testcases;
    int caseN = 1;
    while(testcases--){
        int n, lis_max = INT_MIN, lds_max = INT_MIN;
        cin>>n;
        vector<int> heights(n),  widths(n), lis(n), lds(n);
        lis_lds(n, heights, widths, lis, lds, lis_max, lds_max);
        cout<<"Case "<<caseN<<". ";
        if(lis_max >= lds_max) cout<<"Increasing ("<<lis_max<<"). Decreasing ("<<lds_max<<")."<<endl;
        else cout<<"Decreasing ("<<lds_max<<"). Increasing ("<<lis_max<<")."<<endl;
        caseN++;
    }

    return 0;
}
