#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> leftPos;
        vector<int> rightPos(s.length(), -1);
        int maxLen = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
            {
                leftPos.push(i);
            }
            else
            {
                if(!leftPos.empty())
                {
                    int pos = leftPos.top();
                    leftPos.pop();
                    rightPos[pos] = i;
                }
            }
        }
        for(int i = 0; i < rightPos.size(); i++)
        {
            int len = 0;
            while(i < rightPos.size() && rightPos[i] > 0)
            {
                len += (rightPos[i] - i + 1);
                maxLen = max(maxLen, len);
                i = rightPos[i] + 1;
            }
        }
        return maxLen;
    }
};

int main()
{
	return 0;
}
