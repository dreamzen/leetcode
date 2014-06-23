#include <iostream>
using namespace std;

class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        return binarySearch(A, 0, n - 1, target);   
    }
    bool binarySearch(int A[], int left, int right, int target)
    {
        while(left <= right)
        {
            int middle = (left + right) / 2;
            if(target == A[middle])
            {
                return true;
            }
            else
            {
                if(A[middle] > A[right])// middle is on left part
                {
                    if(target > A[middle])
                    {
                        return binarySearch(A, middle + 1, right, target);
                    }
                    else if(target >= A[left])
                    {
                        return binarySearch(A, left, middle - 1, target);
                    }
                    else if(target <= A[right])
                    {
                        return binarySearch(A, middle + 1, right, target);
                    }
                    else
                    {
                        return false;
                    }
                }
                else if(A[middle] == A[right])// we don't know where middle is. [1, 1, 0, 1] or [2, 1, 1, 1]
                {
                    return binarySearch(A, left, right - 1, target);// delete A[right]
                }
                else// middle is on right part
                {
                    if(target < A[middle])
                    {
                        return binarySearch(A, left, middle - 1, target);
                    }
                    else if(target <= A[right])
                    {
                        return binarySearch(A, middle + 1, right, target);
                    }
                    else if(target >= A[left])
                    {
                        return binarySearch(A, left, middle - 1, target);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return false;
    }
};

int main()
{
	return 0;
}
