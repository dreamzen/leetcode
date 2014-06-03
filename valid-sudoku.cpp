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
        vector<vector<bool> > box(9, vector<bool>(10, 0));
        
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }
                if(c < '1' || c > '9')
                {
                    return false;
                }
                int num = c - '0';
                if(row[i][num] == false)
                {
                    row[i][num] = true;
                }
                else
                {
                    return false;
                }
                if(col[j][num] == false)
                {
                    col[j][num] = true;
                }
                else
                {
                    return false;
                }
                if(box[(i / 3) * 3 + (j / 3)][num] == false)
                {
                    box[(i / 3) * 3 + (j / 3)][num] = true;
                }
                else
                {
                    return false;
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
