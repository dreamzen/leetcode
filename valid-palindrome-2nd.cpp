#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if(s.empty())
        {
            return true;
        }
        int start = 0;
        int end = s.length() - 1;
        while(start < end)
        {
            while(start < s.length() && !isValid(s[start]))
            {
                start++;
            }
            while(end >= 0 && !isValid(s[end]))
            {
                end--;
            }
            if(start > end)
            {
                return true;
            }
            if(!isMatch(s[start], s[end]))
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    
    bool isValid(char c)
    {
        if(c >= '0' && c <= '9')
        {
            return true;
        }
        else if(c >= 'a' && c <= 'z')
        {
            return true;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    bool isMatch(char a, char b)
    {
        if(a >= '0' && a <= '9')
        {
            return (a == b);
        }
        else if(a >= 'a' && a <= 'z')
        {
            return (a == b) || (a == (b - 'A' + 'a'));
        }
        else
        {
            return (a == b) || (b == (a - 'A' + 'a'));
        }
    }
};

int main()
{
	return 0;
}
