#include <iostream>
#include <string.h>
using namespace std;

class Solution
{
public:
    int atoi(const char *str)
    {
        int i = 0;
        int len = strlen(str);
        bool negative = false;
        long long result = 0;
        int MAX_INT = 0x7FFFFFFF;//0111 1111 1111 1111 1111
        int MIN_INT = 1 << 31;   //1000 0000 0000 0000 0000
        if(str == NULL)
        {
            return 0;
        }
        
        //pass spaces at the beginning
        while(str[i] == ' ')
        {
            i++;
        }

        //must begin with '-' '+' or '0-9' --> 00-2 (wrong) 0002 (right)
        if(str[i] != '-' && str[i] != '+' && !isNum(str[i]))
        {
            return 0;
        }

        if(str[i] == '-')
        {
            i++;
            negative = true;
        }
        if(str[i] == '+')
        {
            i++;
        }
        for(; i < len; i++)
        {
            if(!isNum(str[i]))
            {
                break;
            }
            else
            {
                if(negative)
                {
                    result *= 10;
                    result -= toNum(str[i]);
                    if(result < MIN_INT || result > 0)
                    {
                        return MIN_INT;
                    }
                }
                else
                {
                    result *= 10;
                    result += toNum(str[i]);
                    if(result > MAX_INT || result < 0)
                    {
                        return MAX_INT;
                    }
                }
            }
        }
        
        return result;
    }

    bool isNum(const char chr)
    {
        if(chr >= '0' && chr <= '9')
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int toNum(const char chr)
    {
        return (chr - '0');
    }
};


int main()
{
    char p[100];
    Solution s;
    while(cin >> p)
        cout << s.atoi(p) << endl;
    return 0;
}
