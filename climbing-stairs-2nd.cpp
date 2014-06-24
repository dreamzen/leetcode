#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if(n <= 1)
        {
            return 1;
        }
        int a0 = 1;
        int a1 = 1;
        int a2;
        for(int i = 2; i <= n; i++)
        {
            a2 = a1 + a0;
            a0 = a1;
            a1 = a2;
        }
        return a2;
    }
};

int main()
{
	return 0;
}
