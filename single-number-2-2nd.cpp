#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int one = 0;
        int two = 0;
        int thr = 0;
        for(int i = 0; i < n; i++)
        {
            //A[i] will effect one!
            int newOne = one + (thr & A[i]) - (one & A[i]) + (~(one + two + thr) & A[i]);
            int newTwo = two + (one & A[i]) - (two & A[i]);
            int newThr = thr + (two & A[i]) - (thr & A[i]);
            one = newOne; 
            two = newTwo;
            thr = newThr;
        }
        return one;
    }
};

int main()
{
	return 0;
}
