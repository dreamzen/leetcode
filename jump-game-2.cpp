#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int jump(int A[], int n)
    {
        if(n == 1)
        {
            return 0;
        }
        if(n == 0 || A[0] == 0)
        {
            return -1;
        }
        int steps = 0;
        int has_reached = 0;
        int max_index_can_jump = 0;
        for(int i = 0; i < n; i++)
        {
            if(i > has_reached)//must make another step
            {
                steps++;
                has_reached = max_index_can_jump;//update to the furthest index
            }
            int index = i + A[i];
            max_index_can_jump = (index > max_index_can_jump) ? index : max_index_can_jump;//update max
        }
        if(max_index_can_jump < n - 1)
        {
            return -1;
        }
        else
        {
            return steps;
        }
    }
};

int main()
{
	return 0;
}
