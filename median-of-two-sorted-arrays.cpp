#include <iostream>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if((m + n) % 2 == 1)
        {
            return findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1);
        }
        else
        {
            return (findKthSortedArrays(A, m, B, n, (m + n) / 2) + findKthSortedArrays(A, m, B, n, (m + n) / 2 + 1)) / 2.0;
        }
    }
    double findKthSortedArrays(int A[], int m, int B[], int n, int k)
    {
        //always m <= n
        if(m > n)
        {
            return findKthSortedArrays(B, n, A, m, k);
        }
        if(m == 0)
        {
            return B[k - 1];
        }
        if(k == 1)
        {
            return min(A[0], B[0]);
        }
        //find the k/2-th value in A and B, and remove the smaller
        int toBeRemovedFromA = min(m, k / 2);
        int toBeRemovedFromB = k - toBeRemovedFromA;
        if(A[toBeRemovedFromA - 1] < B[toBeRemovedFromB - 1])
        {
            return findKthSortedArrays(A + toBeRemovedFromA, m - toBeRemovedFromA, B, n, k - toBeRemovedFromA);
        }
        else if(A[toBeRemovedFromA - 1] > B[toBeRemovedFromB - 1])
        {
            return findKthSortedArrays(A, m, B + toBeRemovedFromB, n - toBeRemovedFromB, k - toBeRemovedFromB);
        }
        else
        {
            return A[toBeRemovedFromA - 1];
        }
    }
};

int main()
{
	return 0;
}
