#include <iostream>
using namespace std;

class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int zero = 0;
        int one = 0;
        int two = 0;
        for(int i = 0; i < n; i++)
        {
            if(A[i] == 0)
            {
                zero++;
            }
            else if(A[i] == 1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        int index = 0;
        for(int i = 0; i < zero; i++)
        {
            A[index++] = 0;
        }
        for(int i = 0; i < one; i++)
        {
            A[index++] = 1;
        }
        for(int i = 0; i < two; i++)
        {
            A[index++] = 2;
        }
    }
};

int main()
{
    return 0;
}

