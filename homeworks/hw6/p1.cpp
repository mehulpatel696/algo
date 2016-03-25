
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
using namespace std;


#define fill_a (a,j) for(int i = 0; i < j; j++) a[i] = i;
#define fill_v (a,j) for(int i = 0; i < j; j++) a.push_back(i);



int SIZE = 9;
int directions[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
bool w, b;
int num = 0;

void print(char arr[9][9]){
    for(int i  = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}

void pseudo_fill(char data[9][9], int i, int j){
    if(i < 0 || j < 0 || i >= SIZE || j >= SIZE) return;
    if(data[i][j] == 'a') return;
    if( data[i][j] == '.' ) {

        data[i][j] = 'a';
        num++;
    }
    else{
        if(data[i][j] == 'O') w = 1;
        else if(data[i][j] == 'X') b = 1;
        return;
    }
    for(int k = 0; k < 4; k++) pseudo_fill(data, i + directions[k][0], j + directions[k][1]);
}

int main(){
    int testcases;
    cin>>testcases;
    while(testcases--){
        char data[9][9] = { '0' };
        int visited[9][9] = { 0 };
        int black_count = 0, white_count = 0;
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++){
                cin>>data[i][j];
                if(data[i][j] == 'X') black_count++;
                else if (data[i][j] == 'O') white_count++;
            }
        }
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++){
                if(data[i][j] == '.'){
                    num = w = b = 0;
                    pseudo_fill(data, i, j);
                    if(w && b) continue;
                    if(b) black_count += num;
                    else  white_count += num;
                }
            }
        }



        cout<<"Black "<<black_count<<" White "<<white_count<<endl;


    }

    return 0;
}
