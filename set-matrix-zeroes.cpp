#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        bool row1HasZero = false;
        bool col1HasZero = false;
        //remember the first row/col's state
        for(int i = 0; i < m; i++)
        {
            if(matrix[i][0] == false)
            {
                col1HasZero = true;
                break;
            }
        }
        for(int j = 0; j < n; j++)
        {
            if(matrix[0][j] == 0)
            {
                row1HasZero = true;
                break;
            }
        }
        //use first row/col to store the states
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        //deal with row 1,2... and col 1,2...
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        //deal with first row and first col
        if(row1HasZero)
        {
            for(int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(col1HasZero)
        {
            for(int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
	return 0;
}
