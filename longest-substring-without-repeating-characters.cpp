#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> cMap;
        int left = 0;
        int len = 0;
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            unordered_map<char, int>::iterator ite = cMap.find(s[i]);
            if(ite != cMap.end())
            {
                if(ite->second >= left)
                {
                    len = i - ite->second;
                    left = ite->second + 1;
                    ite->second = i;
                }
                else
                {
                    len++;
                    ite->second = i;
                }
            }
            else
            {
                cMap.insert(make_pair(s[i], i));
                len++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};

int main()
{
	return 0;
}
