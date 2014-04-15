#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int n;
public:
    void rotate(vector<vector<int> > &matrix)
    {
        n = matrix.size();
        for(int i = 0; i <= (n - 1) / 2; i++)
        {
            for(int j = i; i + j < n - 1; j++)
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
