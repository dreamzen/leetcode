#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        if(numRows <= 0)
        {
            vector<vector<int> > nop;
            return nop;
        }
        vector<int> row;
        row.push_back(1);
        vector<vector<int> > triangle;
        triangle.push_back(row);
        for(int i = 1; i < numRows; i++)
        {
            vector<int> tmp_row;
            tmp_row.push_back(1);
            for(int j = 1; j < i; j++)
            {
                tmp_row.push_back(triangle[i - 1][j - 1] + triangle[i - 1][j]);
            }
            tmp_row.push_back(1);
            triangle.push_back(tmp_row);
        }
        return triangle;
    }
};


int main()
{
    vector<vector<int> > triangle;
    Solution s;
    int k;
    while(cin >> k)
    {
        triangle = s.generate(k);
        int row = triangle.size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                cout << triangle[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
    
