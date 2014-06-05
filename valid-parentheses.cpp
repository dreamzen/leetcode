#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        int len = s.length();
        stack<char> sStack;
        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                sStack.push(s[i]);
            }
            else
            {
                if(sStack.empty())
                {
                    return false;
                }
                char c = sStack.top();
                sStack.pop();
                if(!match(c, s[i]))
                {
                    return false;
                }
            }
        }
        if(sStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool match(char a, char b)
    {
        switch (a)
        {
            case '(':
                return (b == ')');
                break;
            case '[':
                return (b == ']');
                break;
            case '{':
                return (b == '}');
                break;
            default:
				return false;
                break;
        }
    }
};

int main()
{
	return 0;
}
