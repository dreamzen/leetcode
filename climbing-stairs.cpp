#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> result(n + 1);
        if(n == 0 || n == 1)
        {
            return 1;
        }
        result[0] = result[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            result[i] = result[i - 1] + result[i - 2];
        }
        return result[n];
    }
};

int main()
{
    int n;
    while(cin >>n)
    {
        Solution s;
        cout << s.climbStairs(n) << endl;
    }
    return 0;
}
