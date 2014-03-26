#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int days = prices.size();
        int max_profit = 0;
        if(days <= 1)
        {
            return 0;
        }
        for(int i = 0; i < days - 1; i++)
        {
            if(prices[i + 1]> prices[i])
            {
                max_profit += prices[i + 1] - prices[i]; 
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
            cout << "hehe" << endl;
            cout << s.maxProfit(prices) << endl;
            prices.clear();
        }
        else
        {
            prices.push_back(i);
        }
    }
    return 0;
}


