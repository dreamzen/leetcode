#include <iostream>
#include <vector>
using namespace std;

//O(lgm + lgn),do binary search on the first col, then do binary search on the row we found.
class Solution
{
private:
    int m, n;
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        m = matrix.size();
        n = matrix[0].size();
        int p = searchCol(matrix, target, 0, m - 1);
        if(p == -1)
        {
            return false;
        }
        else
        {
            return searchRow(matrix[p], target, 0, n - 1);
        }
    }
    
    bool searchRow(vector<int> v, int target, int l, int r)
    {
        if(l <= r)
        {
            int middle = (l + r) / 2;
            if(v[middle] == target)
            {
                return true;
            }
            else if(v[middle] > target)
            {
                return searchRow(v, target, l, middle - 1);
            }
            else
            {
                return searchRow(v, target, middle + 1, r);
            }
        }
        return false;
    }
    
    int searchCol(vector<vector<int> > &matrix, int target, int up, int down)
    {
        if(up >= m || down < 0)
        {
            return -1;
        }
        else if(up == m - 1)
        {
            return up;
        }
        else
        {
            int middle = (up + down) / 2;
            if(matrix[middle][0] == target)
            {
                return middle;
            }
            else if(matrix[middle][0] > target)
            {
                return searchCol(matrix, target, up, middle - 1);
            }
            else
            {
                if(middle + 1 < m && matrix[middle + 1][0] > target)
                {
                    return middle;
                }
                else
                {
                    return searchCol(matrix, target, middle + 1, down);
                }
            }
        }
    }
    
};

int main()
{
	return 0;
}
