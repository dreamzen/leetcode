#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        queue<string> qStr;
        queue<int> qLen;
        qStr.push(start);
        qLen.push(0);
//FIX
		dict.insert(start);
		dict.insert(end);
        
        while(!qStr.empty())
        {
            string str = qStr.front();
            qStr.pop();
            int len = qLen.front();
            qLen.pop();
            if(inDict(str, dict))
            {
                len++;
                dict.erase(dict.find(str));
                if(str == end)
                {
                    return len;
                }
                for(int i = 0; i < str.length(); i++)
                {
                    string tmp = str;
                    for(int j = 0; j < 26; j++)
                    {
                        tmp[i] = 'a' + j;
                        if(inDict(tmp, dict))
                        {
                            qStr.push(tmp);
                            qLen.push(len);
                        }
                    }
                    
                }
            }
        }
        return 0;
    }
    
    bool inDict(string str, unordered_set<string> &dict)
    {
        if(dict.find(str) != dict.end())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}
