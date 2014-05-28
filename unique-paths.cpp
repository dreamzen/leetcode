#include <iostream>
using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int b = m + n - 2;
        int a = (m > n) ? n - 1 : m - 1;
        if(a == 0)
        {
            return 1;
        }
        long long aa = 1;
        long long bb = 1;
        for(int i = 1; i <= a; i++)
        {
            aa *= i;
            bb *= b;
            b--;
        }
        return (bb / aa);
    }
};

int main()
{
	int a, b;
	cin >> a >> b;
	Solution s;
	cout << s.uniquePaths(a, b) << endl;
	return 0;
}
