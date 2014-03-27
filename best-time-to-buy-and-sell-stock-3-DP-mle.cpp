#include <iostream>
#include <vector>
using namespace std;

/**
 *profit[i][j] = max{profit[i][j - 1], profit[i + 1][j], prices[j] - prices[i]}, i < j
 *             = 0, i == j
 */
class Solution
{
public:
    vector<vector<int> > profit;
    int maxProfit(vector<int> &prices)
    {
        int days = prices.size();
        if(days <= 1)
        {
            return 0;
        }
        //init profit[][] with 0
        for(int i = 0; i < days; i++)
        {
            vector<int> tmp;
            for(int j = 0; j < days; j++)
            {
                tmp.push_back(0);
            }
            profit.push_back(tmp);
        }

        for(int i = 2; i <= days; i++)
        {
            for(int j = 0; j + i - 1 < days; j++)
            {
                int profit_one = profit[j + 1][j + i - 1];
                int profit_two = profit[j][j + i - 2];
                int profit_three = prices[j + i - 1] - prices[j];
                int profit_tmp = (profit_one > profit_two) ? profit_one : profit_two;
                profit[j][j + i - 1] = (profit_tmp > profit_three) ? profit_tmp : profit_three;
            }
        }
        int max_profit = profit[0][days - 1];
        for(int i = 0; i < days; i++)
        {
            if(profit[0][i] + profit[i][days - 1] > max_profit)
            {
                max_profit = profit[0][i] + profit[i][days - 1];
            }
        }
       
        return max_profit;
    }
};

int main()
{
    vector<int> prices;
    int i;
    Solution s;
    while(cin >> i)
    {
        if(i == 0)
        {
            cout << s.maxProfit(prices) << endl;
            break;
        }
        else
        {
            prices.push_back(i);
        }
    }
    return 0;
}


