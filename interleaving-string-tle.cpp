#include <iostream>
using namespace std;
/**
 * Recursive
 * TLE
 */
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if(s3.length() != (s1.length() + s2.length()))
        {
            return false;
        }
        return dealWith(s1, 0, s2, 0, s3, 0);
    }
    
    bool dealWith(string s1, int i1, string s2, int i2, string s3, int i3)
    {
        if(i3 == s3.length())
        {
            return true;
        }
        else
        {
            bool match = false;
            if(i1 < s1.length() && s1[i1] == s3[i3])
            {
                match = dealWith(s1, i1 + 1, s2, i2, s3, i3 + 1);
            }
            if(i2 < s2.length() && s2[i2] == s3[i3])
            {
                match |= dealWith(s1, i1, s2, i2 + 1, s3, i3 + 1);
            }
            return match;
        }
    }
};

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	Solution s;
	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;
}
