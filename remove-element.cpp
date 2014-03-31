#include <iostream>
using namespace std;

class Solution
{
public:
    int removeElement(int A[], int n, int elem) 
    {
        int tail = n - 1;
        while(tail >= 0 && A[tail] == elem)
        {
            tail--;
        }
        for(int i = 0; i <= tail; i++)
        {
            if(A[i] == elem)
            {
                A[i] = A[tail];
                tail--;
                while(tail >= 0 && A[tail] == elem)
                {
                    tail--;
                }
            }
        }
        return tail + 1;
    }
};

int main()
{
    return 0;
}
