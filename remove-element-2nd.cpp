#include <iostream>
using namespace std;

class Solution
{
public:
    int removeElement(int A[], int n, int elem)
    {
        if(A == NULL || n == 0)
        {
            return 0;
        }
        int indexToPutValue = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] != elem)
            {
                A[indexToPutValue++] = A[i];
            }
        }
        return indexToPutValue;
    }
};

int main()
{
	return 0;
}
