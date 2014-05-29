#include <iostream>
using namespace std;

class Solution {
private:
    string result;
public:
    string getPermutation(int n, int k)
    {
        string str;
        int total = 1;
        for(int i = 0; i < n; i++)
        {
            str += ('1' + i);
            if(i != 0)
            {
                total *= i;
            }
        }
        getString(str, total, k);
        return result;
    }
    void getString(string str, int total, int k)
    {
        if(k == 1)
        {
            result += str;
            return;
        }
        int outer_shift = k / total;
        int inner_shift = k % total;
        string outer_string;
        string inner_string;
        if(inner_shift == 0)
        {
            outer_string = str.substr(outer_shift - 1, 1);
            if(outer_shift == 1)
            {
                inner_string = str.substr(1, str.length() - 1);
            }
            else
            {
                inner_string = str.substr(0, outer_shift - 1) + str.substr(outer_shift, str.length() - outer_shift);
            }
            result += outer_string;
            getString(inner_string, total / (str.length() - 1), total);
        }
        else
        {
            outer_string = str.substr(outer_shift, 1);
            if(outer_shift == 0)
            {
                inner_string = str.substr(1, str.length() - 1);
            }
            else
            {
                inner_string = str.substr(0, outer_shift) + str.substr(outer_shift + 1, str.length() - outer_shift - 1);
            }
            result += outer_string;
            getString(inner_string, total / (str.length() - 1), inner_shift);
        }
    }
};

int main()
{
	int n, k;
	cin >> n >> k;
	Solution s;
	cout << s.getPermutation(n, k) << endl;
	return 0;
}
