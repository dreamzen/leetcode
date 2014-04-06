#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
private:
    map<int, int> m;//<value, max_index>
    vector<bool> A;
    vector<int> value;//value for each index i
    vector<vector<int> > result;
public:
    vector<vector<int> > permuteUnique(vector<int> &num)
    {
        int n = num.size();
        A.resize(n, 0);
        value.resize(n);
        permutation(num, n, 0);
        return result;
    }
    
    //the k-th number, k from 0
    void permutation(vector<int> &num, int n, int k)
    {
        map<int, int>::iterator ite;
        ite = m.find(num[k]);
        int begin;
        if(ite == m.end())
        {
            begin = 0;
        }
        else
        {
            begin = ite->second + 1;
        }
        if(begin >= n)
        {
            return;
        }
        for(int i = begin; i < n; i++)
        {
            if(A[i] == 0)
            {
                A[i] = 1;
                ite = m.find(num[k]);//must find again, because it may be inserted into map within the following code.
                if(ite == m.end())
                {
                    m.insert(make_pair(num[k], i));
                }
                else
                {
                    ite->second = i;
                }
                value[i] = num[k];
                if(k == n - 1)
                {
                    //get the result
                    vector<int> one_result;
                    for(int j = 0; j < n; j++)
                    {
                        one_result.push_back(value[j]);
                        cout << value[j] << " ";
                    }
                    cout << endl;
                    result.push_back(one_result);
                }
                else
                {
                    permutation(num, n, k + 1);
                }
                A[i] = 0;
            }
        }
        ite = m.find(num[k]);
        ite->second = begin - 1;
    }
};

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(1);
    Solution s;
    s.permuteUnique(num);
    return 0;
}
