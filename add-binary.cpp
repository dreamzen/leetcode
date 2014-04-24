#include <iostream>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        string longer, shorter;
        if(a.length() > b.length())
        {
            longer = a;
            shorter = b;
        }
        else
        {
            longer = b;
            shorter = a;
        }
        int len1 = longer.length();
        int len2 = shorter.length();
        int i, j;
        int flag = 0;
        for(i = len1 - 1, j = len2 - 1; j >= 0; i--, j--)
        {
            int tmp = longer[i] - '0' + shorter[j] - '0' + flag;
            if(tmp == 3)
            {
                flag = 1;
                result = '1' + result;
            }
            else if(tmp == 2)
            {
                flag = 1;
                result = '0' + result;
            }
            else if(tmp == 1)
            {
                flag = 0;
                result = '1' + result;
            }
            else
            {
                flag = 0;
                result = '0' + result;
            }
        }
        for(; i >= 0; i--)
        {
            int tmp = longer[i] - '0' + flag;
            if(tmp == 2)
            {
                flag = 1;
                result = '0' + result;
            }
            else if(tmp == 1)
            {
                flag = 0;
                result = '1' + result;
            }
            else
            {
                flag = 0;
                result = '0' + result;
            }
        }
        if(flag)
        {
            result = '1' + result;
        }
        return result;
    }
};

int main()
{
	return 0;
}
