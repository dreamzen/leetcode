#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if(n <= 2)
        {
            return n;
        }
		int duplicates = 2;// Extensibility!
        int lastIndexOfNewArray = duplicates - 1;
        for(int i = lastIndexOfNewArray + 1; i < n; i++)
        {
			//Because A is sorted, so it's enough.
			if(A[i] != A[lastIndexOfNewArray - duplicates + 1])
			{
            	A[++lastIndexOfNewArray] = A[i];
			}
        }
        return lastIndexOfNewArray + 1;
    }
};

int main()
{
	return 0;
}
