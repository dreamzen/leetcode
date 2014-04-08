#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<bool> A;//A[i] = 1 means words in s[0],s[1],...,s[i] are all in dict
public:
    bool wordBreak(string s, unordered_set<string> &dict)
    {
        int len = s.length();
        A.resize(len, 0);
        for(int i = 0; i < len; i++)
        {
            A[i] = inDict(s.substr(0, i + 1), dict);
            if(A[i])
            {
                continue;
            }
            else
            {//seperate (s[0],...s[i]) to (s[0],...s[j]) and (s[j+1],...,s[i])
                for(int j = 0; j < i; j++)
                {
                    if(A[j] && inDict(s.substr(j + 1, i - j), dict))
                    {
                        A[i] = 1;
                        break;
                    }
                }
            }
        }
        return A[len - 1];
    }
    
    bool inDict(string s, unordered_set<string> &dict)
    {
        unordered_set<string>::iterator ite;
        ite = dict.find(s);
        if(ite == dict.end())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    return 0;
}
