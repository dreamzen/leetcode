#include <iostream>
using namespace std;

class Solution
{
public:
    int searchInsert(int A[], int n, int target)
    {
        int index = 0;
        for(int i = 0; i < n; i++)
        {
            if(target == A[i])
            {
                return index;
            }
            if(target > A[i])
            {
                index++;
            }
            else
            {
                break;
            }
        }
        return index;
    }
};

int main()
{
    int A[4] = {1, 2, 4, 5};
    int target;
    while(cin >> target)
    {
        Solution s;
        cout << s.searchInsert(A, 4, target) << endl;
    }
    return 0;
}
