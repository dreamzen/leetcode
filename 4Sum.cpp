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
        for(int i = 0; i < num.size() - 3; )
        {
            for(int j = i + 1; j < num.size() - 2; )
            {
                int left = j + 1;
                int right = num.size() - 1;
                while(left < right)
                {
                    int sum = num[i] + num[j] + num[left] + num[right];
                    if(sum == target)
                    {
                        vector<int> tmp;
                        tmp.push_back(num[i]);
                        tmp.push_back(num[j]);
                        tmp.push_back(num[left]);
                        tmp.push_back(num[right]);
                        result.push_back(tmp);
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
                    else if(sum < target)
                    {
                        left++;
                        while(left < num.size() && num[left] == num[left - 1])
                        {
                            left++;
                        }
                    }
                    else
                    {
                        right--;
                        while(right >= 0 && num[right] == num[right + 1])
                        {
                            right--;
                        }
                    }
                }
                j++;
                while(j < num.size() - 2 && num[j] == num[j - 1])
                {
                    j++;
                }
            }
            i++;
            while(i < num.size() - 3 && num[i] == num[i - 1])
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
