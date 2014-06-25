#include <iostream>
#include <vector>
using namespace std;

/**
 * [1, 2, -4, 4]
 * start=1, when we cal sum += -4, we found that sum < 0,
 * then, start=4, we can ignore 2 and -4!
 */
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        if(gas.empty())
        {
            return -1;
        }
        vector<int> remainingGas(gas.size());
        for(int i = 0; i < gas.size(); i++)
        {
            remainingGas[i] = gas[i] - cost[i];
        }
        //select starting point
        int start = 0;
        while(start < gas.size())
        {
            if(remainingGas[start] < 0)
            {
                start++;
                continue;
            }
            int sum = 0;
            bool found = true;
            //travel a cycle
            for(int i = 0; i < gas.size(); i++)
            {
                sum += remainingGas[(start + i) % gas.size()];
                if(sum < 0)
                {
                    found = false;
                    start = start + i + 1;// starting point must be selected once.
                    break;
                }
            }
            if(found)
            {
                return start;
            }
        }
        return -1;
    }
};

int main()
{
	return 0;
}
