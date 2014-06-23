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
        int lastIndexOfNewArray = 1;
        for(int i = 2; i < n; i++)
        {
            if((A[i] == A[lastIndexOfNewArray]) && (A[i] == A[lastIndexOfNewArray - 1]))
            {
                continue;
            }
            A[++lastIndexOfNewArray] = A[i];
        }
        return lastIndexOfNewArray + 1;
    }
};

int main()
{
	return 0;
}
