#include <iostream>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result;
        int carry = 0;
        int i = a.length() - 1;
        int j = b.length() - 1;
		//while(i || j) is wrong!
        while(i >= 0 || j >= 0)
        {
            int val1 = 0;
            int val2 = 0;
            if(i >= 0)
            {
                val1 = a[i] - '0';
                i--;
            }
            if(j >= 0)
            {
                val2 = b[j] - '0';
                j--;
            }
            int sum = val1 + val2 + carry;
            carry = sum >> 1;
            char c = sum % 2 + '0';
            result = c + result;
        }
        if(carry)
        {
            result = '1' + result;
        }
        return result;
    }
};

int main()
{
	return 0;
}
