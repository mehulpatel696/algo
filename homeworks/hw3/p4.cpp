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

#define i_s(i, j, arr, add, cur)  if(i > 0) (add) ? arr[i][j] += arr[i-1][j] : cur -= arr[i-1][j] ;
#define j_s(i, j, arr, add, cur)  if(j > 0) (add) ? arr[i][j] += arr[i][j - 1] : cur -= arr[i][j - 1];
#define i_j_s(i, j, arr, add, cur) if(i > 0 && j > 0) (add) ? cur += arr[i - 1][j - 1] : arr[i][j] -= arr[i - 1][j - 1];

int n;

int getMaxSum(int arr[100][100], int n){

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int temp = 0;;
            i_s(i,j,arr,true, temp);
            j_s(i,j,arr, true, temp);
            i_j_s(i,j,arr, false, temp);
        }
    }

    int result = 0;
    //4 neseted loops lol
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = i; k < n; k++){
                for(int l = j; l < n; l++){

                    int cur = arr[k][l];
                    i_s(i,l,arr,false,cur);
                    j_s(k,j,arr,false,cur);
                    i_j_s(i,j,arr,true,cur);
                    result = max(result, cur);


                }
            }
        }
    }

    return result;

}

int main(){

    while(cin>>n){
        int arr[100][100];
        for(int i = 0; i < n; i++)for(int j = 0; j < n; j++)  cin>>arr[i][j];
        cout<<getMaxSum(arr, n)<<endl;
    }

    return 0;
}
