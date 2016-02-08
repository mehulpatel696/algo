nclude <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int testcases;
    cin>>testcases;
    cin.ignore();
    while(testcases){
        string parts;
        getline(cin, parts);
        vector<int> males;
        vector<int> females;
        for(int i = 0; i < parts.size(); i++){
            if(parts[i] == 'M') males.push_back(1);
            else if(parts[i] == 'F') females.push_back(1);
        }
        if(males.size() == females.size() && parts.size() > 3) cout<<"LOOP"<<endl;
        else cout<<"NO LOOP"<<endl;
        testcases--;
    }
    return 0;
}


