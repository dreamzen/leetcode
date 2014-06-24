#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        vector<vector<int> > result;
        if(num.size() < 4)
        {
            return result;
        }
        sort(num.begin(), num.end());
        for(int i = 0; i + 3 < num.size(); )
        {
            for(int j = i + 1; j + 2 < num.size(); )
            {
                int left = j + 1;
                int right = num.size() - 1;
                while(left < right)
                {
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if(sum == target)
                    {
                        vector<int> one_result;
                        one_result.push_back(num[i]);
                        one_result.push_back(num[j]);
                        one_result.push_back(num[left]);
                        one_result.push_back(num[right]);
                        result.push_back(one_result);
                        right--;
                        while(right >= 0 && num[right] == num[right + 1])
                        {
                            right--;
                        }
                        left++;
                        while(left < num.size() && num[left] == num[left - 1])
                        {
                            left++;
                        }
                    }
                    else if(sum > target)
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
                j++;
                while(j + 2 < num.size() && num[j] == num[j - 1])
                {
                    j++;
                }
            }
            i++;
            while(i + 3 < num.size() && num[i] == num[i - 1])
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
