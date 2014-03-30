#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> grayCode(int n)
    {
        vector<int> result;
        result.push_back(0);
        if(n == 0)
        {
            return result;
        }
        result.push_back(1);
        if(n == 1)
        {
            return result;
        }
        for(int i = 2; i <= n; i++)
        {
            int len = result.size();
            for(int j = len - 1; j >=0; j--)
            {
                result.push_back(result[j] + (2 << (i - 2)));
            }
        }
        
    }
};

int main()
{
    int n;
    while(cin >> n)
    {
        Solution s;
        vector<int> result = s.grayCode(n);
        int len = result.size();
        for(int i = 0; i < len; i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
