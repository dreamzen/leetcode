#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int>::iterator i;
        if(prices.size() <= 1)
        {
            return 0;
        }
        i = prices.begin();
        int max_profit = 0;
        int min = *i;
        for(; i != prices.end(); i++)
        {
            int price = *i;
            if(min > price)
            {
                min = price;
            }
            if((price - min) > max_profit)
            {
                max_profit = price - min;
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


