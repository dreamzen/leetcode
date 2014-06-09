#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    string multiply(string num1, string num2)
    {
        if(num1 == "0" || num2 == "0")
        {
            return "0";
        }
        string str;
        vector<int> result(num1.length() + num2.length(), 0);
        int len1 = num1.length();
        int len2 = num2.length();
        for(int i = len1 - 1; i >= 0; i--)
        {
            for(int j = len2 - 1; j >= 0; j--)
            {
                int index = i + j;
                result[index] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        //deal with carry
        int carry = 0;
        for(int i = len1 + len2 - 2; i >= 0; i--)
        {
            int sum = result[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }
        if(carry)
        {
            str += (carry + '0');
        }
        for(int i = 0; i <= len1 + len2 - 2; i++)
        {
            str += (result[i] + '0');
        }
        return str;
    }
};

int main()
{
	return 0;
}
