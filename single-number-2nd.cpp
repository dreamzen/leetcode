#include <iostream>
#include <vector>
using namespace std;

/**
 * a ^ b ^ a = b
 */

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int single = A[0];
        for(int i = 1; i < n; i++)
        {
            single ^= A[i];
        }
        return single;
    }
};

int main()
{
	return 0;
}
