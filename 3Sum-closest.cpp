#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        if(num.size() < 3)
        {
            return 0;
        }
        sort(num.begin(), num.end());
        int closest = num[0] + num[1] + num[2];
        int delta = abs(closest - target);
        for(int i = 0; i < num.size() - 2; i++)
        {
            int j = num.size() - 1;
            int k = i + 1;
            while(k < j)
            {
                int sum = num[i] + num[j] + num[k];
                int tmpDelta = abs(sum - target);
                if(tmpDelta < delta)
                {
                    delta = tmpDelta;
                    closest = sum;
                }
                if(sum > target)
                {
                    j--;
                }
                else
                {
                    k++;
                }
            }
        }
        return closest;
    }
};

int main()
{
	return 0;
}
