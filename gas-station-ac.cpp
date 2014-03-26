#include <iostream>
#include <vector>
using namespace std;
/*
Although it's AC, but actually it's not correct.
Run it and you will see.
We should parse the whole cycle from 'head' to 'tail',
not just from v.begin() to v.end().
*/
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        vector<int>::iterator i_gas;
        vector<int>::iterator i_cost;
        vector<int> value;// value <-- (gas - cost)
        vector<int>::iterator i_value;
        bool has_head = false;
        int start_value, whole_value;

        for(i_gas = gas.begin(), i_cost = cost.begin(); i_gas != gas.end(); i_gas++, i_cost++)
        {
            value.push_back(*i_gas - *i_cost);
        }
          
        //parse, if whole_value >=0 && has_head, then head is the start
        i_value = value.begin();
        start_value = whole_value = *i_value;
        if(start_value >= 0)
        {
            has_head = true;
        }
        i_value++;
        int index = 0;//NOTE: the start index is 0
        int j;
        for(j = 1; i_value != value.end(); i_value++, j++)
        {
            whole_value += *i_value;
            if(*i_value >= 0 && !has_head && whole_value >= 0)
            {
                start_value = *i_value;
                has_head = true;
                index = j;
            }
            else if(whole_value < 0)//if whole_value < 0
            {
                has_head = false;//then has_head <-- false
                whole_value = 0;//and refind the head
            }
            else
            {
                continue;
            }
        }

        if(has_head)
        {
            return index;
        }
        else
        {
            return -1;
        }
    }
};

int main()
{
    vector<int> gas;
    vector<int> cost;

    gas.push_back(4);
    gas.push_back(1);
    gas.push_back(5);
    gas.push_back(2);
    gas.push_back(1);
    gas.push_back(13);
    gas.push_back(2);

    cost.push_back(70);
    cost.push_back(30);
    cost.push_back(60);
    cost.push_back(20);
    cost.push_back(21);
    cost.push_back(14);
    cost.push_back(1);

    Solution s;
    cout << s.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
