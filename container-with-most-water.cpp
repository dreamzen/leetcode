#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int result = 0;
        if(height.size() <= 1)
        {
            return result;
        }
        int left = 0;
        int right = height.size() - 1;
        while(left < right)
        {
            int area = min(height[left], height[right]) * (right - left);
            result = max(result, area);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
