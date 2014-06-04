#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> one_result;
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        if(candidates.empty())
        {
            return result;
        }
        sort(candidates.begin(), candidates.end());
        
        getCombination(candidates, 0, candidates.size() - 1, target);
        return result;
    }
    
    void getCombination(vector<int> &candidates, int x, int y, int target)
    {
        //get one result
        if(target == 0)
        {
            result.push_back(one_result);
            return;
        }
        //no match
        if(x > y || candidates[x] > target)
        {
            return;
        }
        //move forward
        int times = target / candidates[x];
        for(int i = 0; i <= times; i++)
        {
            int j = i;
            while(j--)
            {
                one_result.push_back(candidates[x]);
            }
            getCombination(candidates, x + 1, y, target - i * candidates[x]);
            j = i;
            while(j--)
            {
                one_result.pop_back();
            }
        }
    }
};

int main()
{
	return 0;
}
