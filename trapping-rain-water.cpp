#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int trap(int A[], int n)
    {
        if(n < 3)
        {
            return 0;
        }
        int result = 0;
        int max = 0;
        for(int i = 1; i < n; i++)
        {
            if(A[i] > A[max])
            {
                max = i;
            }
        }
        
        //deal with left part
        int height = A[0];
        for(int i = 1; i < max; i++)
        {
            if(A[i] > height)
            {
                height = A[i];
            }
            else
            {
                result += (height - A[i]);
            }
        }
        
        //deal with right part
        height = A[n - 1];
        for(int i = n - 2; i > max; i--)
        {
            if(A[i] > height)
            {
                height = A[i];
            }
            else
            {
                result += (height - A[i]);
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
