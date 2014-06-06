#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &num)
    {
        vector<vector<int> > result;
        if(num.size() < 3)
        {
            return result;
        }
        sort(num.begin(), num.end());
        vector<int> newNum;
        vector<int> appeared;
        for(int i = 0; i < num.size(); )
        {
            int val = num[i];
            int times = 0;
            while(num[i] == val)
            {
                i++;
                times++;
            }
            newNum.push_back(val);
            appeared.push_back(times);
        }
        for(int i = 0; i < newNum.size() && newNum[i] < 0; i++)//from left to '0'
        {
            for(int j = newNum.size() - 1; j >= 0 && newNum[j] > 0; j--)//from right to '0'
            {
                int partSum = newNum[i] + newNum[j];
                if(partSum < 0)//k from right to '0'
                {
                    for(int k = j; k >= 0 && newNum[k] > 0; k--)
                    {
                        if(k == j && appeared[k] == 1)
                        {
                            continue;
                        }
                        else
                        {
                            if(partSum + newNum[k] == 0)
                            {
                                vector<int> one_result;
                                one_result.push_back(newNum[i]);
                                if(j < k)
                                {
                                    one_result.push_back(newNum[j]);
                                    one_result.push_back(newNum[k]);
                                }
                                else
                                {
                                    one_result.push_back(newNum[k]);
                                    one_result.push_back(newNum[j]);
                                }
                                result.push_back(one_result);
                            }
                            else if(partSum + newNum[k] < 0)
                            {
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                }
                else if(partSum > 0)//k from left to '0'
                {
                    for(int k = i; k < newNum.size() && newNum[k] < 0; k++)
                    {
                        if(k == i && appeared[k] == 1)
                        {
                            continue;
                        }
                        else
                        {
                            if(partSum + newNum[k] == 0)
                            {
                                vector<int> one_result;
                                if(i < k)
                                {
                                    one_result.push_back(newNum[i]);
                                    one_result.push_back(newNum[k]);
                                }
                                else
                                {
                                    one_result.push_back(newNum[k]);
                                    one_result.push_back(newNum[i]);
                                }
                                one_result.push_back(newNum[j]);
                                result.push_back(one_result);
                            }
                            else if(partSum + newNum[k] > 0)
                            {
                                break;
                            }
                            else
                            {
                                continue;
                            }
                        }
                    }
                }
                else//partSum == 0
                {
                    for(int k = 0; k < newNum.size(); k++)
                    {
                        if(newNum[k] == 0)
                        {   
                            vector<int> one_result;
                            one_result.push_back(newNum[i]);
                            one_result.push_back(newNum[k]);
                            one_result.push_back(newNum[j]);
                            result.push_back(one_result);
                        }
                        else if(newNum[k] > 0)
                        {
                            break;
                        }
                        else
                        {
                            continue;
                        }
                    }
                }
            }
        }
        //deal with 3 '0's
        for(int i = 0; i < newNum.size(); i++)
        {
            if(newNum[i] == 0 && appeared[i] >= 3)
            {
                vector<int> one_result(3, 0);
                result.push_back(one_result);
            }
        }
        return result;
    }
};

int main()
{
	return 0;
}
