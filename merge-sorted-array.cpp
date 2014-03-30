#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        if(m == 0)
        {
            for(int i = 0; i < n; i++)
            {
                A[i] = B[i];
            }
            return;
        }
        if(n == 0)
        {
            return;
        }
        //merge from tail to head
        int p = m - 1;
        int q = n - 1;
        while( p >= 0 && q >= 0)
        {
            if(A[p] > B[q])
            {
                A[p + q + 1] = A[p];
                p--;
            }
            else
            {
                A[p + q + 1] = B[q];
                q--;
            }
        }
        if(p >= 0)
        {
            //do nothing, because A[] is already there 
        }   
        if(q >=0)
        {
            for(int i = 0; i <= q; i++)
            {
                A[i] = B[i];
            }
        }
    }
};

int main()
{
    int A[4] = {1, 2};
    int B[2] = {3, 4};
    Solution s;
    s.merge(A, 2, B, 2);
    for(int i = 0; i < 4; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
