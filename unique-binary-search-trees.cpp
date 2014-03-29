#include <iostream>
#include <vector>
using namespace std;

/**
 *      
 *      = 1, n = 0  
 * f(n) = 1, n = 1
 *      = plus{f(i)*f(n-1-i)}, i = 0, 1, ..., n-1
 *
 */
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> result(n + 1);
        if(n == 0 || n == 1)
        {
            return 1;
        }
        result[0] = result[1] = 1;
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                result[i] += (result[j] * result[i - 1 - j]);
            }
        }
        return result[n];
    }
};

int main()
{
    int n;
    Solution s;
    while(cin >> n)
    {
        cout << s.numTrees(n) << endl;
    }
    return 0;
}
