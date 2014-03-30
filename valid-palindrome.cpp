#include <iostream>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.length();
        if(len <= 1)
        {
            return true;
        }
        int left = 0;
        int right = len - 1;
        while(left <= right)
        {
            while(!isAlphanumberic(s[left]) && left < len)
            {
                left++;
            }
            if(left >= len)//in case ",.:"
            {
                return true;
            }
            while(!isAlphanumberic(s[right]) && right >= 0)
            {
                right--;
            }
            if(right < 0)//in case "..,"
            {
                return true;
            }
            if(!isEqual(s[left], s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

    bool isAlphanumberic(char c)
    {
        if(c >= '0' && c <= '9')
        {
            return true;
        }
        if(c >= 'a' && c <= 'z')
        {
            return true;
        }
        if(c >= 'A' && c <= 'Z')
        {
            return true;
        }
        return false;
    }

    bool isEqual(char a, char b)
    {
        if(a == b)
        {
            return true;
        }
        if(a >= 'a' && a <= 'z' && b >= 'A' && b <= 'Z')
        {
            if((a - 'a') == (b - 'A'))
            {
                return true;
            }
            return false;
        }
        if(a >= 'A' && a <= 'Z' && b >= 'a' && b <= 'z')
        {
            if((a - 'A') == (b - 'a'))
            {
                return true;
            }
            return false;
        }
        return false;
    }
};

int main()
{
    string str;
    while(getline(cin, str))
    {
        Solution s;
        cout << s.isPalindrome(str) << endl;
    }
    return 0;
}
