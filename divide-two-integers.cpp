#include <iostream>
using namespace std;

class Solution
{
public:
    int divide(int _dividend, int _divisor)
    {
        //use long long in case out of range when MIN_INT --> positive number
        long long dividend = _dividend;
        long long divisor = _divisor;
        if(dividend == 0)
        {
            return 0;
        }
        //result is negative or not
        bool negative = (dividend >> 63) ^ (divisor >> 63);
        //convert to positive number
        if(dividend < 0)
        {
            dividend = ~(dividend - 1);
        }
        if(divisor < 0)
        {
            divisor = ~(divisor - 1);
        }

        long long base = 1;
        long long result = 0;
        //increase divisor 
        while(dividend > 0)
        {
            if(dividend >= divisor)
            {
                dividend -= divisor;
                result += base;
                divisor = divisor << 1;//plus 2
                base = base << 1;//plus 2
            }
            else//means that divisor reaches the top
            {
                break;
            }
        }

        //decrease divisor
        while(dividend > 0)
        {
            if(dividend >= divisor)
            {
                dividend -= divisor;
                result += base;
            }
            else if(base > 1)
            {
                divisor = divisor >> 1;//divided by 2
                base = base >> 1;//divided by 2
            }
            else//base == 1 means complete!
            {
                break;   
            }
        }
        if(negative)
        {
            result = (~result) + 1;
        }
        return result;
    }
};

int main()
{
    int a,b;
    Solution s;
    while(cin >> a >> b)
    {
        if(a == 'e')
            break;
        cout << s.divide(a, b) << endl;
    }
    return 0;
}
