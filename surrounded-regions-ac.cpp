#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos
{
    int row;
    int col;
    Pos(int x, int y) : row(x), col(y) {}
};

class Solution
{
public:
    bool **unsurrounded;//mark unsurrounded 'O'
    bool **searched;//mark has been searched or not
    int row;
    int col;
    queue<Pos> q;
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
                searched[i][col - 1] = 1;
                Pos s(i, col - 1);
                q.push(s);
                searchUnsurrounded(board);
            }
            if(board[i][0] == 'O' && !searched[i][0])
            {
                searched[i][0] = 1;
                Pos s(i, 0);
                q.push(s);
                searchUnsurrounded(board);
            }
        }
        //search up/down edge for 'O'
        for(int j = 1; j < col - 1; j++)
        {
            if(board[0][j] == 'O' && !searched[0][j])
            {
                searched[0][j] = 1;
                Pos s(0, j);
                q.push(s);
                searchUnsurrounded(board);
            }
            if(board[row - 1][j] == 'O' && !searched[row - 1][j])
            {
                searched[row - 1][j] = 1;
                Pos s(row - 1, j);
                q.push(s);
                searchUnsurrounded(board);
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

    void searchUnsurrounded(vector<vector<char> > &board)
    {
        while(!q.empty())
        {
            Pos pos = q.front();
            q.pop();
            unsurrounded[pos.row][pos.col] = 1;

            if(pos.row - 1 >= 0 && !searched[pos.row - 1][pos.col] && board[pos.row - 1][pos.col] == 'O')
            {
                searched[pos.row - 1][pos.col] = 1;
                Pos s(pos.row - 1, pos.col);
                q.push(s);
            }
            if(pos.row + 1 < row && !searched[pos.row + 1][pos.col] && board[pos.row + 1][pos.col] == 'O')
            {
                searched[pos.row + 1][pos.col] = 1;
                Pos s(pos.row + 1, pos.col);
                q.push(s);
            }
            if(pos.col - 1 >= 0 && !searched[pos.row][pos.col - 1] && board[pos.row][pos.col - 1] == 'O')
            {
                searched[pos.row][pos.col - 1] = 1;
                Pos s(pos.row, pos.col - 1);
                q.push(s);
            }
            if(pos.col + 1 < col && !searched[pos.row][pos.col + 1] && board[pos.row][pos.col + 1] == 'O')
            {
                searched[pos.row][pos.col + 1] = 1;
                Pos s(pos.row, pos.col + 1);
                q.push(s);
            }
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

    int n = 5;
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
    n = 5;
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
