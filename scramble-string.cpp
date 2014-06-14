#include <iostream>
using namespace std;

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        int len1 = s1.length();
        int len2 = s2.length();
        if(len1 != len2)
        {
            return false;
        }
        if(s1 == s2)
        {
            return true;
        }
        string tmp1 = s1;
        string tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        //if not, return directly.
        if(tmp1 != tmp2)
        {
            return false;
        }
        string s1Left;
        string s1Right;
        string s2Left;
        string s2Right;
        //the length of s1Left
        for(int len = 1; len < len1; len++)
        {
            s1Left = s1.substr(0, len);
            s1Right = s1.substr(len, len1 - len);
            s2Left = s2.substr(0, len);
            s2Right = s2.substr(len, len2 - len);
            bool situation1 = (isScramble(s1Left, s2Left) && isScramble(s1Right, s2Right));
            s2Left = s2.substr(0, len2 - len);
            s2Right = s2.substr(len2 - len, len);
            bool situation2 = (isScramble(s1Left, s2Right) && isScramble(s1Right, s2Left));
            if(situation1 || situation2)
            {
                return true;
            }
        }
        return false;
    }
};

int main()
{
	return 0;
}
