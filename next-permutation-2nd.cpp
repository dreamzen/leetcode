#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        //find the first decreasing element in num from tail to head
        int indexOfDecreasingNum = num.size() - 2;
        for(; indexOfDecreasingNum >= 0; indexOfDecreasingNum--)
        {
            if(num[indexOfDecreasingNum] < num[indexOfDecreasingNum + 1])
            {
                break;
            }
        }
        //num is sorted. [3, 2, 1]
        if(indexOfDecreasingNum == -1)
        {
            //as num is sorted, so reversing it is enough ==> O(n)
            //sort(num.begin(), num.end()); ==> O(nlogn)
            for(int i = 0; i < num.size() / 2; i++)
            {
                swap(num[i], num[num.size() - 1 - i]);
            }
            return;
        }
        //find the first element greater than num[indexOfDecreasingNum] from tail to head
        int indexOfGreaterNum = num.size() - 1;
        for(; indexOfGreaterNum >= 0; indexOfGreaterNum--)
        {
            if(num[indexOfGreaterNum] > num[indexOfDecreasingNum])
            {
                break;
            }
        }
        //swap two element [1, 3, 5, 4, 2] ==> [1, 4, 5, 3, 2]
        swap(num[indexOfDecreasingNum], num[indexOfGreaterNum]);
        //sort [1, 4, 5, 3, 2] ==> [1, 4, 2, 3, 5]
        //Use O(n) algorithm instead
        //sort(num.begin() + indexOfDecreasingNum + 1, num.end()); ==> O(nlogn)
        for(int i = 0; i < (num.size() - indexOfDecreasingNum - 1) / 2; i++)
        {
            swap(num[indexOfDecreasingNum + 1 + i], num[num.size() - 1 - i]);
        }
		//it's more efficient than reverse(num.begin(), num.end());
    }
};

int main()
{
	return 0;
}
