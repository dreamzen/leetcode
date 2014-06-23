#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int removeDuplicates(int A[], int n)
	{
		if(n <= 1)
		{
			return n;
		}
		int lastIndexOfNewArray = 0;
		for(int i = 1; i < n; i++)
		{
			if(A[i] != A[lastIndexOfNewArray])
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
