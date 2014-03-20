#include <iostream>
using namespace std;

/*
a^b^a = b
SO:
*/
class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        if(n == 1)
        {
            return A[0];
        }
        else
        {
            for(int i = 1; i < n; i++)
            {
                A[0] ^= A[i];
            }
            return A[0];
        }
    }
};

int main()
{
    int A[5] = {1, 1, 2, 3, 3};
    Solution s;
    cout << s.singleNumber(A, 5) << endl;
    int B[1] = {1};
    cout << s.singleNumber(B, 1) << endl;
    return 0;
}
