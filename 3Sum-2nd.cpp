#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> > result;
        if(num.size() < 3)
        {
            return result;
        }
        sort(num.begin(), num.end());
        for(int i = 0; i + 2 < num.size(); )
        {
            int left = i + 1;
            int right = num.size() - 1;
            while(left < right)
            {
                int sum = num[i] + num[left] + num[right];
                if(sum == 0)
                {
                    vector<int> one_result;
                    one_result.push_back(num[i]);
                    one_result.push_back(num[left]);
                    one_result.push_back(num[right]);
                    result.push_back(one_result);
                    left++;
                    while(left < num.size() && num[left] == num[left - 1])
                    {
                        left++;
                    }
                    right--;
                    while(right >= 0 && num[right] == num[right + 1])
                    {
                        right--;
                    }
                }
                else if(sum > 0)
                {
                    right--;
                    while(right >= 0 && num[right] == num[right + 1])
                    {
                        right--;
                    }
                }
                else
                {
                    left++;
                    while(left < num.size() && num[left] == num[left - 1])
                    {
                        left++;
                    }
                }
            }
            //skip i
            i++;
            while(i + 2 < num.size() && num[i] == num[i - 1])
            {
                i++;
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
