#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s)
    {
        string result = "";
        for(int i = 0; i < s.length(); i++)
        {
            string str = getPalindrome(s, i);
            if(str.length() > result.length())
            {
                result = str;
            }
        }
        return result;
    }
    
    string getPalindrome(string s, int pos)
    {
        int shift = 0;
        while(pos - shift >= 0 && pos + shift < s.length() && s[pos-shift] == s[pos + shift])
        {
            shift++;
        }
        shift--;
        string s1 = s.substr(pos - shift, 2 * shift + 1);
        shift = 0;
        while(pos - shift >= 0 && pos + shift + 1 < s.length() && s[pos - shift] == s[pos + 1 + shift])
        {
            shift++;
        }
        shift--;
        string s2 = s.substr(pos - shift, 2 * shift + 2);
        if(s1.length() > s2.length())
        {
            return s1;
        }
        else
        {
            return s2;
        }
    }
};

int main()
{
	return 0;
}
