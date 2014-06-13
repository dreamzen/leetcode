#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<int> result;
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        if(L.empty() || L[0].length() == 0)
        {
            for(int i = 0; i < S.length(); i++)
            {
                result.push_back(i);
            }
            return result;
        }
        for(int i = 0; i < L[0].length(); i++)
        {
            findSubstringFromIndex(S, L, i);
        }
        return result;
    }
    void findSubstringFromIndex(string S, vector<string> &L, int index)
    {
        if((S.length() - index) < (L.size() * L[0].length()))
        {
            return;
        }
        unordered_map<string, int> mapping;
        for(int i = 0; i < L.size(); i++)
        {
            mapping[L[i]] = 0;
        }
        for(int i = 0; i < L.size(); i++)
        {
            mapping[L[i]]++;
        }
        for(int i = 0; i < L.size(); i++)
        {
            string word = S.substr(index + i * L[0].length(), L[0].length());
            unordered_map<string, int>::iterator ite = mapping.find(word);
            if(ite != mapping.end())
            {
                ite->second--;
            }
        }
        if(checkMap(mapping))
        {
            result.push_back(index);
        }
        //continue to search, skip the first word in S
        index += L[0].length();
        while((S.length() - index) >= (L.size() * L[0].length()))
        {
            string firstWord = S.substr(index - L[0].length(), L[0].length());
            string lastWord = S.substr(index + (L.size() - 1) * L[0].length(), L[0].length());
            unordered_map<string, int>::iterator ite = mapping.find(firstWord);
            if(ite != mapping.end())
            {
                ite->second++;
            }
            ite = mapping.find(lastWord);
            if(ite != mapping.end())
            {
                ite->second--;
                if(checkMap(mapping))
                {
                    result.push_back(index);
                }
            }
            index += L[0].length();
        }
    }
    bool checkMap(unordered_map<string, int> &mapping)
    {
        for(unordered_map<string, int>::iterator ite = mapping.begin(); ite != mapping.end(); ite++)
        {
            if(ite->second != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
	return 0;
}
