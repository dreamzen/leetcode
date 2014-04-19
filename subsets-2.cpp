#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    vector<vector<int> > result;
    vector<int> one_result;
    unordered_map<int, int> m; //<key, value> means <number, duplicates>
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S)
    {
        sort(S.begin(), S.end());
        for(int i = 0; i < S.size() ; i++)
        {
            int tmp = S[i];
            int dup = 1;
            while(i + 1 < S.size() && tmp == S[i + 1])
            {
                i++;
                dup++;
            }
            m.insert(make_pair(S[i], dup));
        }
        dealWith(S, 0);
        return result;
    }
    void dealWith(vector<int> &S, int index)
    {
        if(index == S.size())
        {
            result.push_back(one_result);
            return;
        }
        unordered_map<int, int>::iterator ite = m.find(S[index]);
        if(ite == m.end())
        {
            dealWith(S, index + 1);
            return;
        }
        int dup = ite->second;
        m.erase(ite);//in case multi-select numbers equal to S[index]
        //select index i times
        for(int i = 0; i <= dup; i++)
        {
            int tmp = i;
            while(tmp--)
            {
                one_result.push_back(S[index]);
            }
            dealWith(S, index + 1);
            tmp = i;
            while(tmp--)
            {
                one_result.pop_back();
            }
        }
        m.insert(make_pair(S[index], dup));//ATTENTION!
    }
};

int main()
{
	return 0;
}
