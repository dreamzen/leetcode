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
 *NOW Time Limit Exceeded!!!!!
 *-------------------------------------------------------
 *Traversal from left to right to generate left_profit[]
 *Traversal from right to left to generate right_profit[]
 *O(n)!!
 */
class Solution
{
public:
    vector<int> left_profit;
    vector<int> right_profit;
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
            left_profit.push_back(0);
            right_profit.push_back(0);
        }   

        //traversal from left to right ==> find left_profit[]
        int min = prices[0];
        int max_profit = 0;
        for(int j = 0; j < days; j++)
        {//now we know the min price till now, so we can cal the max profit   
            if(prices[j] < min)
            {
                min = prices[j];
            }
            if(prices[j] - min > max_profit)
            {
                max_profit = prices[j] - min;
            }
            left_profit[j] = max_profit;
        }

        //traversal from right to left ==> find right_profit[]
        int max = prices[days - 1];
        max_profit = 0;
        for(int j = days - 1; j >=0; j--)
        {//now we know the max price in the future, so we can cal the max profit
            if(prices[j] > max)
            {
                max = prices[j];
            }
            if(max - prices[j] > max_profit)
            {
                max_profit = max - prices[j];
            }
            right_profit[j] = max_profit;
        }

        for(int i = 0; i < days; i++)
        {
            if(left_profit[i] + right_profit[i] > max_profit)
            {
                max_profit = left_profit[i] + right_profit[i];
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


