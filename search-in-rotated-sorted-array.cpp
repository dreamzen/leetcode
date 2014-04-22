#include <iostream>
using namespace std;

class Solution
{
public:
    int search(int A[], int n, int target)
    {
        return searchRotated(A, 0, n - 1, target);
    }
    
    int searchRotated(int A[], int lhs, int rhs, int target)
    {
        if(lhs == rhs)
        {
            return (A[lhs] == target) ? lhs : -1;
        }
        int middle = (lhs + rhs) / 2;
        int leftA, rightA;
        if(A[lhs] < A[middle])
        {
            leftA = searchSorted(A, lhs, middle, target);
        }
        else
        {
            leftA = searchRotated(A, lhs, middle, target);
        }
        if(A[rhs] > A[middle + 1])
        {
            rightA = searchSorted(A, middle + 1, rhs, target);
        }
        else
        {
            rightA = searchRotated(A, middle + 1, rhs, target);
        }
        return (leftA == -1) ? rightA : leftA;
    }
    
    int searchSorted(int A[], int lhs, int rhs, int target)
    {
        if(lhs <= rhs)
        {
            int middle = (lhs + rhs) / 2;
            if(target == A[middle])
            {
                return middle;
            }
            else if(target < A[middle])
            {
                return searchSorted(A, lhs, middle - 1, target);
            }
            else
            {
                return searchSorted(A, middle + 1, rhs, target);
            }
        }
        return -1;
    }
};

int main()
{
	return 0;
}
