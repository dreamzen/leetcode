#include <iostream>
using namespace std;

class Solution
{
public:
    int trap(int A[], int n)
    {
        int result = 0;
        if(A == NULL || n <= 2)
        {
            return 0;
        }
        int indexOfHighest = 0;
        for(int i = 1; i < n; i++)
        {
            if(A[i] > A[indexOfHighest])
            {
                indexOfHighest = i;
            }
        }
        //left -> indexOfHighest
        int maxOfLeft = A[0];
        for(int i = 1; i < indexOfHighest; i++)
        {
            if(A[i] > maxOfLeft)
            {
                maxOfLeft = A[i];
            }
            else
            {
                result += (maxOfLeft - A[i]);
            }
        }
        //right -> indexOfHighest
        int maxOfRight = A[n - 1];
        for(int i = n - 2; i > indexOfHighest; i--)
        {
            if(A[i] > maxOfRight)
            {
                maxOfRight = A[i];
            }
            else
            {
                result += (maxOfRight - A[i]);
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
