#include <iostream>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        if(n == 0)
        {
            return 1;
        }
        for(int i = 0; i < n; i++)
        {
            deal(A, n, i, A[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(A[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
    
    void deal(int A[], int n, int index, int val)
    {
        if(val <= 0 || val > n)
        {
            return;
        }
        if(val != index + 1)
        {
            int tmp = A[val - 1];
            A[val - 1] = val;
            deal(A, n, val - 1, tmp);
        }
    }
};

int main()
{
	return 0;
}
