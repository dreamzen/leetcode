#include <iostream>
using namespace std;

/*
    1 1 0 0 1   <--- one
    1 0 1 0 1
    1 0 1 0 1
+   1 0 1 0 1
---------------
    4 1 3 0 4
%3
--------------
    1 1 0 0 1   <--- one

With no extra space, I have no idea yet. 
So we use one to mark the bits shown (%3=)1 time  (like bit3)
          two to mark the bits shown (%3=)2 time  
          three to mark the bits shown 3n times (like bit1)
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
            int one, two, three, tmp1, tmp2, whole;
            one = A[0];
            two = 0;
            three = 0;
            tmp1 = 0;
            tmp2 = 0;
            whole = A[0];
            for(int i = 1; i < n; i++)
            {
                tmp1 = one;
                one &= (~A[i]);
                one |= (A[i] & ~whole);//ATTENTION:first time here
                one |= (three & A[i]);//one = (three & this) | (one & ~this) | 'first time here'

                tmp2 = two;
                two &= (~A[i]);
                two |= (tmp1 & A[i]);//two = (one & this) | (two & ~this)

                three &= (~A[i]);
                three |= (tmp2 & A[i]);//three = (two & this) | (three & ~this) 
                whole |= A[i];
            }
            return one;//one is the result
        }
    }
};

int main()
{
    int A[7] = {3, 1, 1, 1, 3, 3, 2};
    Solution s;
    cout << s.singleNumber(A, 7) << endl;
    int B[1] = {1};
    cout << s.singleNumber(B, 1) << endl;
    return 0;
}
