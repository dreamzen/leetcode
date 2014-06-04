#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> one_result;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target)
    {
        if(num.empty())
        {
            return result;
        }
        sort(num.begin(), num.end());
        
        getCombination(num, 0, num.size() - 1, target);
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
        int times = 0;
        int val = candidates[x];
        while(x <= y && candidates[x] == val)
        {
            times++;
            x++;
        }
        times = (target / val < times) ? (target / val) : times;
        for(int i = 0; i <= times; i++)
        {
            int j = i;
            while(j--)
            {
                one_result.push_back(val);
            }
            getCombination(candidates, x, y, target - i * val);
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
