#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<string> > result;
    vector<string> one_result;
    unordered_map<string, vector<string> > childToParent;
    int k;
    bool found;
public:
    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict)
    {
        unordered_set<string> qStr[2];
        //we should not erase the word when it being inserted to the qStr, because it may turn up twice or more times at the same level. Instead, we should erase the whole level of qStr at the same time.
        k = 0;
        qStr[k % 2].insert(start);
        found = false;

        dict.insert(start);
        dict.insert(end);
        
        dict.erase(dict.find(start));
        
        while(!qStr[k % 2].empty())
        {
            unordered_set<string>::iterator ite = qStr[k % 2].begin();
            string str = *ite;
            qStr[k % 2].erase(ite);

            if(str == end)
            {
                found = true;
                continue;
            }
            if(!found)
            {
                for(int i = 0; i < str.length(); i++)
                {
                    string tmp = str;
                    for(int j = 0; j < 26; j++)
                    {
                        tmp[i] = 'a' + j;
                        if(inDict(tmp, dict))
                        {
                            childToParent[tmp].push_back(str);
                            qStr[(k + 1) % 2].insert(tmp);
                        }
                    }
                }
            }
            if(qStr[k % 2].empty() && !found)
            {
                k++;
                //erase the whole level from dict
                for(unordered_set<string>::iterator ite = qStr[k % 2].begin(); ite != qStr[k % 2].end(); ite++)
                {
                    dict.erase(dict.find(*ite));
                }
            }
        }
        findPath(end, start);
        return result;
    }
    
    void findPath(string str, string start)
    {
        one_result.push_back(str);
        if(str == start)
        {
 //           if(one_result.size() - 1 == k)
            {
                vector<string> vStr;
                for(int i = k; i >= 0; i--)
                {
                    vStr.push_back(one_result[i]);
                }
                result.push_back(vStr);
            }
        }
        else
        {
            unordered_map<string, vector<string> >::iterator ite = childToParent.find(str);
            if(ite != childToParent.end())
            {
                vector<string> parents = ite->second;
                for(int i = 0; i < parents.size(); i++)
                {
                    findPath(parents[i], start);
                }
            }
        }
        one_result.pop_back();
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
