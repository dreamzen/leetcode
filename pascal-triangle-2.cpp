#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if(rowIndex < 0)
        {
            vector<int> nop;
            return nop;
        }
        vector<int> row(rowIndex + 1);
        //row[k] = row[k] + row[k - 1], k + 1 will use k, it's not OK
        //so we cal from right to left, then row[k - 1] = row[k - 1] + row[k - 2], it's OK
        for(int i = 0; i <= rowIndex; i++)
        {
            row[i] = 1;
            for(int j = i - 1; j > 0; j--)
            {
                row[j] += row[j - 1];
            }
            row[0] = 1;
        }
            
        return row;
    }
};


int main()
{
    vector<int> row;
    Solution s;
    int k;
    while(cin >> k)
    {
        row = s.getRow(k);
        int len = row.size();
        for(int i = 0; i < len; i++)
        {
            cout << row[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
    
