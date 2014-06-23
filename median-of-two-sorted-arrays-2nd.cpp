#include <iostream>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if((m + n) % 2 != 0)
        {
            return findKthInSortedArrays(A, m, B, n, (m + n) / 2 + 1);
        }
        else
        {
            return (findKthInSortedArrays(A, m, B, n, (m + n) / 2) + findKthInSortedArrays(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
    int findKthInSortedArrays(int A[], int m, int B[], int n, int k)
    {
        if(k <= 0 || k > (m + n))
        {
            return -1;//Error
        }
        //assume m always >= n
        if(m < n)
        {
            return findKthInSortedArrays(B, n, A, m, k);
        }
        if(n == 0)
        {
            return A[k - 1];
        }
        if(k == 1)
        {
            return min(A[0], B[0]);
        }
        int kthInB = min(n, k / 2);
        int kthInA = k - kthInB;
        if(A[kthInA - 1] == B[kthInB - 1])
        {
            return A[kthInA - 1];
        }
        else if(A[kthInA - 1] < B[kthInB - 1])
        {
            return findKthInSortedArrays(A + kthInA, m - kthInA, B, n, k - kthInA);
        }
        else
        {
            return findKthInSortedArrays(A, m, B + kthInB, n - kthInB, k - kthInB);
        }
    }
};

int main()
{
	return 0;
}
