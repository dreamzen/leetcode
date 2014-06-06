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
        int edge = strs[0].size();
        for(int i = 1; i < strs.size(); i++)
        {
            int len = strs[i].size();
            edge = min(edge, len);
            for(int j = 0; j < edge; j++)
            {
                if(strs[i][j] != strs[0][j])
                {
                    edge = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, edge);
    }
};

int main()
{
	return 0;
}
