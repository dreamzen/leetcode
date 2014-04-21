#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n)
    {
        unordered_set<int> s;
        if(n <= 1)
        {
            return n;
        }
        int current = A[0];
        int index = 1;//the index we will put the number
        for(int i = 1; i < n; i++)//deal with A[i]
        {
            if(A[i] != current)//never exist
            {
                A[index] = A[i];
                index++;
                current = A[i];
            }
            else//exist once
            {
                if(s.find(A[i]) == s.end())//only once
                {
                    A[index] = A[i];
                    index++;
                    s.insert(A[i]);//indcate exist twice
                } //else  exist at least twice
            }
        }
        return index;
    }
};

int main()
{
	return 0;
}
