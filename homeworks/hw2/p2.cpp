#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>


using namespace std;


char c[6] = { 'R', 'G', 'B', 'Y', 'O', 'V' };
#define seta(p,at,bt,i) p.first++, at[i] = '1',bt[i] = '1'
#define setb(p,at,bt,i,j) p.second++, at[i] = '1',bt[j] = '1'


pair<int, int> cp(string a, string b){
    pair<int, int> cmp(0,0);
    string at = "0000";
    string bt = "0000";
    for(int i = 0; i < 4; i++) if(a[i] == b[i]) seta(cmp,at,bt,i);
    for(int i = 0; i < 4; i++) if(at[i] != '1') for(int j = 0; j < 4; j++)  if(bt[j] != '1')  if(a[i] == b[j])  setb(cmp,at,bt,i,j);
    return cmp;
}

set<string> generate_matches(string &s, int a , int b, set<string>& perms){
    set<string> ms;
    for(set<string>::iterator it = perms.begin(); it != perms.end(); it++){
        pair<int,int> p = cp(s, *it);
        if(p.first == a && p.second == b) ms.insert(*it);
    }
    return ms;
}

void strings(int depth, string result, set<string> &perms, bool in[6]) {
    if (depth == 4) {
        perms.insert(result);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (!in[i]) {
            in[i] = true;
            strings(depth + 1, result + c[i], perms, in);
            in[i] = false;
        }
    }
}


int main(void)
{
    set<string> perms;
    bool in[6] = {false};
    strings(0, "", perms, in);
    int testcases;
    cin>>testcases;
    while(testcases--){
        string g;
        int a,b;
        cin>>g>>a>>b;
        set<string> msa = generate_matches(g,a,b, perms);
        cin>>g>>a>>b;
        set<string> msb = generate_matches(g,a,b, msa);
        (msb.empty()) ? cout << "Cheat" << endl : cout << "Possible" << endl;
    }
    return 0;

}
