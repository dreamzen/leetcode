#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    vector<bool> A;//mark index i
    vector<int> value;//value for each i
    vector<vector<int> > result;
public:
    vector<vector<int> > permute(vector<int> &num)
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
        for(int i = 0; i < n; i++)
        {
            if(A[i] == 0)
            {
                A[i] = 1;
                value[k] = num[i];
                if(k == n - 1)
                {
                    //get the result
                    vector<int> one_result;
                    for(int j = 0; j < n; j++)
                    {
                        one_result.push_back(value[j]);
                    }
                    result.push_back(one_result);
                }
                else
                {
                    permutation(num, n, k + 1);   
                }
                A[i] = 0;
            }
        }
    }
};

int main()
{
    return 0;
}
