#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool **unsurrounded;//mark unsurrounded 'O'
    bool **searched;//mark has been searched or not
    int row;
    int col;
    void solve(vector<vector<char> > &board)
    {
        //board is row x col
        row = board.size();
        if(row == 0)
        {
            return;
        }
        vector<vector<char> >::iterator ite = board.begin();
        col = (*ite).size();

        //unsurrounded is row x col
        unsurrounded = new bool*[row];
        searched = new bool*[row];
        for(int i = 0; i < row; i++)
        {
            unsurrounded[i] = new bool[col];
            searched[i] = new bool[col];
        }
        
        //init
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                unsurrounded[i][j] = 0;
                searched[i][j] = 0;
            }
        }

        //search left/right edge for 'O'
        for(int i = 0; i < row; i++)
        {
            if(board[i][col - 1] == 'O' && !searched[i][col - 1])
            {
                searchUnsurrounded(board, i, col - 1);
            }
            if(board[i][0] == 'O' && !searched[i][0])
            {
                searchUnsurrounded(board, i, 0);
            }
        }
        //search up/down edge for 'O'
        for(int j = 1; j < col - 1; j++)
        {
            if(board[0][j] == 'O' && !searched[0][j])
            {
                searchUnsurrounded(board, 0, j);
            }
            if(board[row - 1][j] == 'O' && !searched[row - 1][j])
            {
                searchUnsurrounded(board, row - 1, j);
            }
        }

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(!unsurrounded[i][j])
                {
                    board[i][j] = 'X';
                }
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    }

    void searchUnsurrounded(vector<vector<char> > &board, int _row, int _col)
    {
        searched[_row][_col] = 1;
        unsurrounded[_row][_col] = 1;

        if(_row - 1 >= 0 && !searched[_row - 1][_col] && board[_row - 1][_col] == 'O')
        {
            searchUnsurrounded(board, _row - 1, _col);
        }
        if(_row + 1 < row && !searched[_row + 1][_col] && board[_row + 1][_col] == 'O')
        {
            searchUnsurrounded(board, _row + 1, _col);
        }
        if(_col - 1 >= 0 && !searched[_row][_col - 1] && board[_row][_col - 1] == 'O')
        {
            searchUnsurrounded(board, _row, _col - 1);
        }
        if(_col + 1 < col && !searched[_row][_col + 1] && board[_row][_col + 1] == 'O')
        {
            searchUnsurrounded(board, _row, _col + 1);
        }
    }
};

int main()
{
    vector<vector<char> > board;

    vector<char> b;
    b.push_back('X');
    b.push_back('X');
    b.push_back('X');
    b.push_back('X');
    board.push_back(b);

    vector<char> b1;
    b1.push_back('X');
    b1.push_back('O');
    b1.push_back('O');
    b1.push_back('X');
    board.push_back(b1);

    vector<char> b2;
    b2.push_back('X');
    b2.push_back('X');
    b2.push_back('O');
    b2.push_back('X');
    board.push_back(b2);

    vector<char> b3;
    b3.push_back('X');
    b3.push_back('O');
    b3.push_back('X');
    b3.push_back('X');
    board.push_back(b3);

    Solution s;
    s.solve(board);

    int n = 50;
    board.clear();
    while(n--)
    {
        b.clear();
        for(int i = 0; i < 100; i++)
        {
            b.push_back('O');
        }
        board.push_back(b);
    }
    n = 50;
    while(n--)
    {
        b.clear();
        for(int i = 0; i < 100; i++)
        {
            b.push_back('X');
        }
        board.push_back(b);
    }
    s.solve(board);
    return 0;
}
