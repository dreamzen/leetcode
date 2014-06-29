#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0;
        int total = 0;
        int start = 0;
		// We just need one-pass! O(1) space!
        for(int i = 0; i < gas.size(); i++)
        {
            int delta = gas[i] - cost[i];
            sum += delta;
            total += delta;
            if(sum < 0)// take next station to start
            {
                sum = 0;
                start = i + 1;
            }
        }
        if(total >= 0)// have result
        {
            return start;
        }
        return -1;
    }
};

int main()
{
	return 0;
}
