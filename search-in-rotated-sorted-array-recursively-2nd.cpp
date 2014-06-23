#include <iostream>
using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        return binarySearch(A, 0, n - 1, target);
    }
    int binarySearch(int A[], int left, int right, int target)
    {
        if(left <= right)
        {
            int middle = (left + right) / 2;
            if(target == A[middle])
            {
                return middle;
            }
            //middle is on left part
            if(A[middle] > A[right])
            {
                if(target > A[middle])
                {
                    return binarySearch(A, middle + 1, right, target);
                }
                else
                {
                    if(target >= A[left])
                    {
                        return binarySearch(A, left, middle - 1, target);
                    }
                    else if(target <= A[right])
                    {
                        return binarySearch(A, middle + 1, right, target);
                    }
                    else
                    {
                        return -1;
                    }
                }
            }
            else//middle is on right part
            {
                if(target < A[middle])
                {
                    return binarySearch(A, left, middle - 1, target);
                }
                else
                {
                    if(target <= A[right])
                    {
                        return binarySearch(A, middle + 1, right, target);
                    }
                    else if(target >= A[left])
                    {
                        return binarySearch(A, left, middle - 1, target);
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
