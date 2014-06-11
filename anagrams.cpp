#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> result;
        unordered_map<string, vector<string> > groups;
        for(int i = 0; i < strs.size(); i++)
        {
            string key = strs[i];
            sort(key.begin(), key.end());
            groups[key].push_back(strs[i]);
        }
        for(unordered_map<string, vector<string> >::iterator ite = groups.begin(); ite != groups.end(); ite++)
        {
            vector<string> one_group = ite->second;
            if(one_group.size() > 1)
            {
                for(int i = 0; i < one_group.size(); i++)
                {
                    result.push_back(one_group[i]);
                }
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
