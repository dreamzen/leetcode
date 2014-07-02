#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if(strs.empty())
        {
            return "";
        }
        int num = strs.size() - 1;
        while(num > 0)
        {
            int index = 0;
            for(int i = 0; i <= num; i = i + 2)
            {
                string s1 = strs[i];
                if(i + 1 <= num)
                {
                    string s2 = strs[i + 1];
                    string tmp;
                    for(int i = 0; i < s1.length() && i < s2.length(); i++)
                    {
                        if(s1[i] == s2[i])
                        {
                            tmp += s1[i];
                        }
                        else
                        {
                            break;
                        }
                    }
                    strs[index++] = tmp;
                }
                else
                {
                    strs[index++] = s1;
                }
            }
            num = num >> 1;
        }
        return strs[0];
    }
};

int main()
{
	return 0;
}
