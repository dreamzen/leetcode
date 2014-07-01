#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if(*p == '\0')
        {
            return (*s == '\0');
        }
        if(*s == '\0')
        {
            while((*p == '*') || (*p != '\0' && *(p + 1) == '*'))
            {
                p++;
            }
            return (*p == '\0');
        }
        if(*(p + 1) == '*')
        {
            if(*s == *p || *p == '.')
            {
                return isMatch(s, p + 2) || isMatch(s + 1, p);
            }
            else
            {
                return isMatch(s, p + 2);
            }
        }
        else
        {
            if(*s == *p || *p == '.')
            {
                return isMatch(s + 1, p + 1);
            }
            else
            {
                return false;
            }
        }
    }
};

int main()
{
	return 0;
}
