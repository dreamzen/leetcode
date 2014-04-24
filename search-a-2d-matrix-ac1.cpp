#include <iostream>
#include <vector>
using namespace std;

//O(m+n), cut a row or col a time.
class Solution
{
private:
    int m, n;
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        m = matrix.size();
        n = matrix[0].size();
        return searchVal(matrix, target, 0, n - 1);
    }
    bool searchVal(vector<vector<int> > &matrix, int target, int i, int j)
    {
        if(i >= m || j < 0)
        {
            return false;
        }
        else
        {
            if(matrix[i][j] == target)
            {
                return true;
            }
            else if(matrix[i][j] > target)
            {
                return searchVal(matrix, target, i, j - 1);
            }
            else
            {
                return searchVal(matrix, target, i + 1, j);
            }
        }
    }
};

int main()
{
	return 0;
}
