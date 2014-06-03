#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<vector<bool> > row;
    vector<vector<bool> > col;
    vector<vector<bool> > box;
    vector<vector<char> > result;
public:
    void solveSudoku(vector<vector<char> > &board)
    {
        row.resize(9, vector<bool>(10, 0));
        col.resize(9, vector<bool>(10, 0));
        box.resize(9, vector<bool>(10, 0));
        result.resize(9, vector<char>(9));
        init(board);
        fillSudoku(board, 0, 0);
        copyResult(board);
    }
    void init(vector<vector<char> > &board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] != '.')
                {
                    mark(board, i, j, board[i][j] - '0');
                }
            }
        }
    }
    void copyResult(vector<vector<char> > &board)
    {
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                board[i][j] = result[i][j];
            }
        }
    }
    void fillSudoku(vector<vector<char> > &board, int x, int y)
    {
        if(board[x][y] != '.')
        {
            fillNext(board, x, y);
        }
        else
        {
            for(int i = 1; i <= 9; i++)
            {
                if(isValid(board, x, y, i))
                {
                    mark(board, x, y, i);
                    fillNext(board, x, y);
                    clear(board, x, y, i);
                }
            }
        }
    }
    void fillNext(vector<vector<char> > &board, int x, int y)
    {
        if(x == 8 && y == 8)
        {
            //get the result
            for(int i = 0; i < 9; i++)
            {
                for(int j = 0; j < 9; j++)
                {
                    result[i][j] = board[i][j];
                }
            }
            return;
        }
        if(y == 8)
        {
            fillSudoku(board, x + 1, 0);
        }
        else
        {
            fillSudoku(board, x, y + 1);
        }
    }
    bool isValid(vector<vector<char> > &board, int x, int y, int num)
    {
        if(row[x][num] == false && col[y][num] == false && box[(x / 3) * 3 + (y / 3)][num] == false)
        {
            return true;
        }
        return false;
    }
    void mark(vector<vector<char> > &board, int x, int y, int num)
    {
        board[x][y] = num + '0';
        row[x][num] = true;
        col[y][num] = true;
        box[(x / 3) * 3 + (y / 3)][num] = true;
    }
    void clear(vector<vector<char> > &board, int x, int y, int num)
    {
        board[x][y] = '.';
        row[x][num] = false;
        col[y][num] = false;
        box[(x / 3) * 3 + (y / 3)][num] = false;
    }
};

int main()
{
	return 0;
}
