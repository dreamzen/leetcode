#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--)
        {
            int sum = digits[i] + carry;
            digits[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry)
        {
            result.push_back(carry);
        }
        for(int i = 0; i < digits.size(); i++)
        {
            result.push_back(digits[i]);
        }
        return result;
    }
};

int main()
{
	return 0;
}
