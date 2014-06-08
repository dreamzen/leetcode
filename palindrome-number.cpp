#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if(x < 0)
        {
            return false;
        }
        int base = 1;
        while(x / base >= 10)
        {
            base *= 10;
        }
        while(base > 1)
        {
            if(x / base == x % 10)
            {
                x = (x % base) / 10;
                base /= 100;
            }
            else
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
