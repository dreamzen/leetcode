#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        if(grid.empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int> > A(m, vector<int>(n, 0));
        A[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int i = m - 2; i >= 0; i--)
        {
            A[i][n - 1] = A[i + 1][n - 1] + grid[i][n - 1];
        }
        for(int j = n - 2; j >= 0; j--)
        {
            A[m - 1][j] = A[m - 1][j + 1] + grid[m - 1][j];
        }
        for(int i = m - 2; i >= 0; i--)
        {
            for(int j = n - 2; j >= 0; j--)
            {
                A[i][j] = (A[i + 1][j] > A[i][j + 1]) ? (A[i][j + 1] + grid[i][j]) : (A[i + 1][j] + grid[i][j]);
            }
        }
        return A[0][0];
    }
};

int main()
{
	return 0;
}
