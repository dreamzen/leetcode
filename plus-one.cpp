#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        vector<int> reverse;
        if(digits[0] == 0)
        {
            result.push_back(1);
            return result;
        }
        int flag = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            int num = digits[i] + flag;
            if(num >= 10)
            {
                reverse.push_back(num - 10);
                flag = 1;
            }
            else
            {
                reverse.push_back(num);
                flag = 0;
            }
        }
        if(flag)
        {
            reverse.push_back(1);
        }
        for(int i = reverse.size() - 1; i >= 0; i--)
        {
            result.push_back(reverse[i]);
        }
        return result;
    }
};

int main()
{
	return 0;
}
