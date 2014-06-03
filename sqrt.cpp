#include <iostream>
using namespace std;

class Solution
{
public:
    int sqrt(int x)
    {
        if(x == 0)
        {
            return 0;
        }
        if(x < 0)
        {
            return -1;
        }
        if(x <= 3)
        {
            return 1;
        }
        int left = 1;
        int right = x / 2;//sqrt(x) <= x/2, when x > 1
        int last_middle;
        while(left <= right)
        {
            int middle = (left + right) / 2;
            if(x / middle > middle)
            {
                last_middle = middle;
                left = middle + 1;
            }
            else if(x / middle < middle)
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return last_middle;
    }
};

int main()
{
	int x;
	cin >> x;
	Solution s;
	cout << s.sqrt(x) << endl;
	return 0;
}
