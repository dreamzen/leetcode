#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        int len = num.size();
        int a = -1;
        for(int i = len - 1; i > 0; i--)
        {
            if(num[i] > num[i - 1])
            {
                a = i - 1;
                break;
            }
        }
        if(a == -1)
        {
            for(int i = 0; i < len / 2; i++)
            {
                swap(num[i], num[len - 1 - i]);
            }
        }
        else
        {
            int i;
            for(i = len - 1; i > a; i--)
            {
                if(num[i] > num[a])
                {
                    swap(num[i], num[a]);
                    break;
                }
            }
            //reorder
            int len2 = len - a - 1;
            for(int j = 0; j < len2 / 2; j++)
            {
                swap(num[a + 1 + j], num[a + 1 + len2 - 1 - j]);
            }
        }
    }
};

int main()
{
	return 0;
}
