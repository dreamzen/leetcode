#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        if(num.size() <= 1)
        {
            return num.size();
        }
        unordered_map<int, bool> used;
        int longest = 0;
        //used has element means the element is in vector num
        for(int i = 0; i < num.size(); i++)
        {
            used[num[i]] = false;
        }
        //search
        for(int i = 0; i < num.size(); i++)
        {
            if(used[num[i]] == true)
            {
                continue;//make sure every element is visited once
            }
            used[num[i]] = true;
            int len = 1;
            for(int left = num[i] - 1; used.find(left) != used.end(); left--)
            {
                used[left] = true;
                len++;
            }
            for(int right = num[i] + 1; used.find(right) != used.end(); right++)
            {
                used[right] = true;
                len++;
            }
            longest = max(longest, len);
        }
        return longest;
    }
};

int main()
{
	return 0;
}
