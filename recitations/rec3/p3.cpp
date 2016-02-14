#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;



int main ()
{
    int num;
    while(cin>>num){
        if(num == 0) break;
        bitset<64> temp(num);
        string t = temp.to_string();
        string a = "";
        string b = "";

        int num_ones = 1;
        for(int i = 0; i < temp.size(); i++){

            if(t[i] == '1') {
                if(num_ones%2 == 0) {
                    b += "1";
                    a += "0";
                } else {
                    a += "1";
                    b += "0";
                }
                 num_ones++;

            }
            else {
                a += "0";
                b += "0";
            }
        }



        bitset<64> temp1(a);
        bitset<64> temp2(b);

        cout<<temp1.to_ullong()<<" "<<temp2.to_ullong()<<endl;





    }
    return 0;

}
