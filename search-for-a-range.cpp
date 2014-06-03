#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> searchRange(int A[], int n, int target)
    {
        vector<int> result;
        float left = target - 0.1;
        float right = target + 0.1;
        int from = binarySearch(A, 0, n - 1, left);
        int to = binarySearch(A, 0, n - 1, right);
        if(from == to)
        {
            if(A[from] == target)
            {
                result.push_back(from);
                result.push_back(to);
            }
            else
            {
                result.push_back(-1);
                result.push_back(-1);
            }
        }
        else
        {
            if(A[from] == target)
            {
                result.push_back(from);
            }
            else
            {
                result.push_back(from + 1);
            }
            if(A[to] == target)
            {
                result.push_back(to);
            }
            else
            {
                result.push_back(to - 1);
            }
        }
        return result;
    }
    
    int binarySearch(int A[], int left, int right, float target)
    {
        if(left >= right)
        {
            return left;
        }
        int middle = (left + right) / 2;
        if(A[middle] < target)
        {
            return binarySearch(A, middle + 1, right, target);
        }
        else
        {
            return binarySearch(A, left, middle - 1, target);
        }
    }
    
};

int main()
{
	return 0;
}
