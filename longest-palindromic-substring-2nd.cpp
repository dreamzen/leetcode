#include <iostream>
using namespace std;

class Solution {
private:
    int maxLen;
    int start;
public:
    string longestPalindrome(string s)
    {
        maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            getPalindrome(s, i);
        }
        return s.substr(start, maxLen);
    }
    
    void getPalindrome(string s, int index)
    {
        int len1 = 1;
        for(int i = 1; index - i >= 0 && index + i < s.length(); i++)
        {
            if(s[index - i] == s[index + i])
            {
                len1 += 2;
            }
            else
            {
                break;
            }
        }
        int len2 = 0;
        for(int i = 0; index - i >= 0 && index + i + 1 < s.length(); i++)
        {
            if(s[index - i] == s[index + i + 1])
            {
                len2 += 2;
            }
            else
            {
                break;
            }
        }
        if(len1 > maxLen)
        {
            maxLen = len1;
            start = index - len1 / 2;
        }
        if(len2 > maxLen)
        {
            maxLen = len2;
            start = index - len2 / 2 + 1;
        }
    }
};

int main()
{
	return 0;
}
