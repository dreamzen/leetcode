#include <iostream>
#include <vector>
using namespace std;

/**
 *profit[i][j] = max{profit[i][j - 1], profit[i + 1][j], prices[j] - prices[i]}, i < j
 *             = 0, i == j
 *Memory Limit Exceeded.
 *So, wo just use profit[days]. profit[j] means the max profit from day j to day j+i-1, i is the len of days
 *Finally, we will get profit[], the element profit[j] means the max profit from day j to the last day.
 *But, we also need to know the max profit from day 0 to day i, so we use left_profit[] to store them. 
 *
 *At last, left_profit[i] is the max profit from day 0 to day i
 *              profit[i] is the max profit from day i to the last day
 */
class Solution
{
public:
    vector<int> profit;
    vector<int> left_profit;
    int maxProfit(vector<int> &prices)
    {   
        int days = prices.size();
        if(days <= 1)
        {   
            return 0;
        }   
        //init profit[] with 0
        for(int i = 0; i < days; i++)
        {   
            profit.push_back(0);
            left_profit.push_back(0);
        }   

        for(int i = 2; i <= days; i++)
        {   
            //(from j, len is i) = max{(from j, len is i-1), (from j+1, len is i-1),  prices[j +i-1] - prices[j]}
            for(int j = 0; j + i - 1 < days; j++)
            {   
                int profit_one = profit[j];//j, j+1, ..., j + i - 2 (len is i - 1)
                int profit_two = profit[j + 1];//j+1, j+2, ..., j + i - 3 (len is i - 1)
                int profit_three = prices[j + i - 1] - prices[j];
                int profit_tmp = (profit_one > profit_two) ? profit_one : profit_two;
                profit[j] = (profit_tmp > profit_three) ? profit_tmp : profit_three;//update profit[j], because now len is i
                if(j == 0)
                {
                    left_profit[i - 1] = profit[j];//store profit from day 0 to day i-1
                }
            }
        }
        int max_profit = profit[0];
        for(int i = 0; i < days; i++)
        {
            if(profit[i] + left_profit[i] > max_profit)
            {
                max_profit = profit[i] + left_profit[i];
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
    int k = 10000;
    while(k)
    {
        prices.push_back(k--);
    }
    k = 10000;
    while(k)
    {
        prices.push_back(0);
        k--;
    }
    cout << s.maxProfit(prices) << endl;
    return 0;
}


