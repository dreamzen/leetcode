#include <iostream>
using namespace std;

class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        if(n == 1)
        {
            return A[0];
        }
        //A[i] <== A[0]+...+A[i]
        for(int i = 1; i < n; i++)
        {
            A[i] += A[i-1];
        }
        int max = A[0];
        int min = 0;
        //we can't swap the two if() below, or max will compare with (A[i]-A[i]=0)
        for(int i = 0; i < n; i++)
        {
            if(A[i] - min > max)
            {
                max = A[i] - min;
            }
            if(A[i] < min)
            {
                min = A[i];
            }
        }
        return max;
    }
};

int main()
{
    return 0;
}
