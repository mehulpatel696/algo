#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

int main(){
    while(true){
        int height; 
        int width;
        int store_width;
        cin>>height>>width;
        if(height == 0 && width == 0) break;
        store_width = width;
        int min = INT_MAX;
        while(width){
            int temp; 
            cin>>temp;
            if(temp < min) min = temp;
            width--;
            
        }
        if(min == 0) min = 1;
        cout<<store_width - min<<endl;
        
    }
    return 0;
}