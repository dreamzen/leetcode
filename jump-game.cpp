#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(int A[], int n)
    {
        if(n == 1)
        {
            return true;
        }
        if(n == 0 || A[0] == 0)
        {
            return  false;
        }
        vector<int> max(n, 0);
        vector<int> zero;
        max[0] = A[0];
        for(int i = 1; i < n - 1; i++)
        {
            if(A[i] == 0)
            {
                zero.push_back(i);
            }
            max[i]  = A[i] + i;
            if(max[i] < max[i - 1])
            {
                max[i] = max[i - 1];
            }
        }
        for(int i = 0; i < zero.size(); i++)
        {
            int pos = zero[i];
            if(max[pos] <= (A[pos] + pos))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
	return 0;
}
