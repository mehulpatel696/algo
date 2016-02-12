#include <iostream>
#include <vector>

using namespace std;

class FenTree{
    private:
        vector<int> data;
    public:
        FenTree(int size){
            data.resize(size+1);
        }

        int getSum(int b){
            int sum = 0;
            for( ;b; b -= LSOne (b)) sum += data[b];
            return sum;
        }

        int getSum(int a, b){
            return getSum(b) - (a == 1 ? 0 : getSum(a - 1));
        }

        void fix(int x, int v){
            for(; k < )
        }
};
