#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        if(matrix.empty())
        {
            return;
        }
        bool setFirstRowZeros = false;
        bool setFirstColZeros = false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(matrix[i][j] == 0)
                {
                    if(i == 0)
                    {
                        setFirstRowZeros = true;
                    }
                    else
                    {
                        matrix[i][0] = 0;
                    }
                    if(j == 0)
                    {
                        setFirstColZeros = true;
                    }
                    else
                    {
                        matrix[0][j] = 0;
                    }
                }
            }
        }
        //set cols 
        for(int j = 1; j < cols; j++)
        {
            if(matrix[0][j] == 0)
            {
                for(int i = 0; i < rows; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        //set rows
        for(int i = 1; i < rows; i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 0; j < cols; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if(setFirstRowZeros)
        {
            for(int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(setFirstColZeros)
        {
            for(int i = 0; i < rows; i++)
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
