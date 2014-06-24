#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        vector<vector<bool> > row(9, vector<bool>(10, 0));
        vector<vector<bool> > col(9, vector<bool>(10, 0));
        vector<vector<bool> > cube(9, vector<bool>(10, 0));
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                {
                    continue;
                }
                else if(board[i][j] < '1' || board[i][j] > '9')
                {
                    return false;
                }
                else
                {
                    int num = board[i][j] - '0';
                    if(row[i][num] == false && col[j][num] == false && cube[i / 3 * 3 + j / 3][num] == false)
                    {
                        row[i][num] = true;
                        col[j][num] = true;
                        cube[i / 3 * 3 + j / 3][num] = true;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
	return 0;
}
