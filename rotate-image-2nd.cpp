#include <iostream>
#include <vector>
using namespace std;

/**
 * (x, y) ==> (y, n-1-x)
 * (x, y) <== (n-1-y, x)
 * Take care of the order!
 */
class Solution
{
public:
    void rotate(vector<vector<int> > &matrix)
    {
        int n = matrix.size();
        if(n <= 1)
        {
            return;
        }
        for(int i = 0; i <= (n - 1) / 2; i++)
        {
            for(int j = 0; j < n / 2; j++)
            {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = tmp;
            }
        }
    }
};

int main()
{
	return 0;
}
