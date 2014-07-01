#include <iostream>
using namespace std;

class Solution
{
public:
    int atoi(const char *str)
    {
        if(str == NULL || strlen(str) == 0)
        {
            return 0;
        }
        double result = 0;
        int flag = 1;
        //skip leading white space
        while(str != NULL && *str == ' ')
        {
            str++;
        }
        //leading +/-
        if(str != NULL)
        {
            if(*str == '+')
            {
                flag = 1;
                str++;
            }
            else if(*str == '-')
            {
                flag = -1;
                str++;
            }
        }
        while(str != NULL)
        {
            if(*str >= '0' && *str <= '9')
            {
                result = result * 10 + (*str - '0');
                if(flag == 1 && result >= INT_MAX)
                {
                    return INT_MAX;
                }
                if(flag == -1 && -result <= INT_MIN)
                {
                    return INT_MIN;
                }
                str++;
            }
            else
            {
                break;
            }
        }
        return (flag * result);
    }
};

int main()
{
	return 0;
}
