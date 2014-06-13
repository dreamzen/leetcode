#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        unordered_map<char, int> needAppeared;
        unordered_map<char, int> appeared;
        for(int i = 0; i < T.length(); i++)
        {
            needAppeared[T[i]] = 0;
            appeared[T[i]] = 0;
        }
        for(int i = 0; i < T.length(); i++)
        {
            needAppeared[T[i]]++;
        }
        int minStart = 0;
        int minEnd = -1;
        int start = 0;
        int end = -1;
        int totalNeedAppeared = T.length();
        int totalAppeared = 0;
        while(end + 1 < S.length() && totalAppeared < totalNeedAppeared)
        {
            end++;
            char c = S[end];
            unordered_map<char, int>::iterator ite = needAppeared.find(c);
            if(ite == needAppeared.end())
            {
                continue;
            }
            else
            {
                if(appeared[c] < needAppeared[c])
                {
                    appeared[c]++;
                    totalAppeared++;
                }
                else
                {
                    appeared[c]++;
                }
            }
        }
        //no match
        if(totalAppeared < totalNeedAppeared)
        {
            return "";
        }
        else
        {
            minStart = start;
            minEnd = end;
        }
        //match, move start and end
        while(true)
        {
            //move start
            while(start <= end)
            {
                unordered_map<char, int>::iterator ite = needAppeared.find(S[start]);
                if(ite == needAppeared.end())
                {
                    start++;
                }
                else if(appeared[S[start]] > needAppeared[S[start]])
                {
                    appeared[S[start]]--;
                    start++;
                }
                else
                {
                    break;
                }
            }
            //get result
            if(end - start < minEnd - minStart)
            {
                minStart = start;
                minEnd = end;
            }
            //move end
            end++;
            while(end < S.length())
            {
                unordered_map<char, int>::iterator ite = needAppeared.find(S[end]);
                if(ite == needAppeared.end())
                {
                    end++;
                }
                else
                {
                    appeared[S[end]]++;
                    break;
                }
            }
            if(end == S.length())
            {
                break;
            }
        }
        return S.substr(minStart, minEnd - minStart + 1);
    }
};

int main()
{
	return 0;
}
