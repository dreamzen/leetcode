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
            return -1;//Error
        }
        sort(num.begin(), num.end());
        int closest = num[0] + num[1] + num[2];
        for(int i = 0; i + 2 < num.size(); i++)
        {
            int left = i + 1;
            int right = num.size() - 1;
            while(left < right)
            {
                int sum = num[i] + num[left] + num[right];
                if(abs(sum - target) < abs(closest - target))
                {
                    closest = sum;
                }
                if(sum == target)
                {
                    break;
                }
                else if(sum > target)
                {
                    right--;
                }
                else
                {
                    left++;
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
