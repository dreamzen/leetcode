#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    int m, n;
    vector<vector<bool> > A;
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                A.resize(m, vector<bool>(n, 0));
                if(search(board, i, j, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(vector<vector<char> > &board, int i, int j, string word, int index)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || A[i][j] == true)
        {
            return false;
        }
        A[i][j] = true;
        if(board[i][j] == word[index])
        {
            if(index == word.length() - 1)
            {
                return true;
            }
            else
            {
                int result = (search(board, i + 1, j, word, index + 1)
                        || search(board, i - 1, j, word, index + 1)
                        || search(board, i, j + 1, word, index + 1)
                        || search(board, i, j - 1, word, index + 1));
                A[i][j] = false;
                return result;
            }
        }
        else
        {
            A[i][j] = false;
            return false;
        }
    }
};

int main()
{
	return 0;
}
