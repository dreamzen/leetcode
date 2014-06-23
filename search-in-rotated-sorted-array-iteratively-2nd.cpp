#include <iostream>
using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int left = 0;
        int right = n - 1;
        while(left <= right)
        {
            int middle = (left + right) / 2;
            if(target == A[middle])
            {
                return middle;
            }
            else
            {
                if(A[middle] > A[right])// middle is on left part
                {
                    if(target > A[middle])
                    {
                        left = middle + 1;
                    }
                    else if(target >= A[left])
                    {
                        right = middle - 1;
                    }
                    else if(target <= A[right])
                    {
                        left = middle + 1;
                    }
                    else
                    {
                        return -1;
                    }
                }
                else// middle is on right part
                {
                    if(target < A[middle])
                    {
                        right = middle - 1;
                    }
                    else if(target <= A[right])
                    {
                        left = middle + 1;
                    }
                    else if(target >= A[left])
                    {
                        right = middle - 1;
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
	return 0;
}
