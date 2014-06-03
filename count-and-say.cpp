#include <iostream>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        string s = "1";
        for(int i = 0; i < n - 1; i++)
        {
            s = getSequence(s);
        }
        return s;
    }
    string getSequence(string s)
    {
        int len = s.length();
        int count = 1;
        int i;
        for(i = 1; i < len; i++)
        {
            if(s[i] == s[0])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        string str = "  ";
        str[0] = count + '0';
        str[1] = s[0];
        if(i != len)
        {
            str += getSequence(s.substr(i, len - i));
        }
        return str;
    }
};

int main()
{
	return 0;
}
