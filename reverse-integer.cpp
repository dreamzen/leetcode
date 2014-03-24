#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int quot = x;
        int remainder;
        int result = 0;
        while(quot)
        {
            remainder = quot % 10;
            quot /= 10;
            result *= 10;
            result += remainder;
        }
        return result;
    }
};

int main()
{
    int x;
    Solution s;
    while(cin >> x)
    {
        if(x == 'e')
            break;
        cout << x << " " << s.reverse(x) << endl;
    }
    return 0;
}
