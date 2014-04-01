#include <iostream>
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
        int current = A[0];
        int index = 1;
        for(int i = 1; i < n; i++)
        {
            if(A[i] != current)
            {
                A[index] = A[i];
                index++;
                current = A[i];
            }
        }
        return index;
    }
};

int main()
{
    return 0;
}
