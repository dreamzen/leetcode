#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        if(obstacleGrid.empty())
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int> > A(m + 1, vector<int>(n + 1, 0));
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                if(obstacleGrid[i][j] == 0)
                {
                    if(i == m - 1 && j == n - 1)
                    {
                        A[i][j] = 1;
                    }
                    else
                    {
                        A[i][j] = A[i + 1][j] + A[i][j + 1];
                    }
                }
                else
                {
                    A[i][j] = 0;
                }
            }
        }
        return A[0][0];
    }
};

int main()
{
	return 0;
}
