#include <iostream>
#include <vector>
using namespace std;
/*
1.from left to right, if right.rating > left.rating, then give one more candy to him/her, else give him/her one candy.
2.from right to left, if left.rating > right.rating && right.candy + 1 > left, then change the amount to (right.candy + 1), or keep the amount of candy.
*/
class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int>::iterator rIter;
        vector<int>::iterator cIter;
        vector<int>::reverse_iterator r_rIter;
        vector<int>::reverse_iterator r_cIter;
        vector<int> candys;
        int num_candys = 0;

        //parse from left to right
        rIter = ratings.begin();
        int temp_rate = *rIter;
        int temp_candy = 1;
        candys.push_back(temp_candy);
        rIter++;
        for(; rIter != ratings.end(); rIter++)
        {
            if(*rIter > temp_rate)
            {
                temp_candy++;
                candys.push_back(temp_candy);
            }
            else
            {
                temp_candy = 1;
                candys.push_back(temp_candy);
            }
            temp_rate = *rIter;   
        }

        //parse from right to left
        r_rIter = ratings.rbegin();
        r_cIter = candys.rbegin();
        temp_rate = *r_rIter;
        temp_candy = *r_cIter;
        r_rIter++;
        r_cIter++;
        for(; r_rIter != ratings.rend(); r_rIter++, r_cIter++)
        {
            if(*r_rIter > temp_rate)
            {
                temp_rate = *r_rIter;
                temp_candy++;
                if(temp_candy > *r_cIter)
                {
                    *r_cIter = temp_candy;
                }
                else
                {
                    temp_candy = *r_cIter;
                }
            }
            else
            {
                temp_rate = *r_rIter;
                temp_candy = *r_cIter;
            }
        }
         
        for(cIter = candys.begin(); cIter != candys.end(); cIter++)
        {
            num_candys += *cIter;
        }
        return num_candys; 
    }
};

int main()
{
    vector<int> ratings;
    ratings.push_back(7);
    ratings.push_back(8);
    ratings.push_back(9);
    ratings.push_back(10);
    ratings.push_back(1);
    ratings.push_back(2);
    ratings.push_back(3);
    ratings.push_back(5);
    ratings.push_back(10);
    ratings.push_back(9);
    ratings.push_back(8);
    ratings.push_back(7);
    ratings.push_back(6);
    ratings.push_back(5);

    vector<int> ratings2;
    ratings2.push_back(1);
    Solution s;
    cout << "min candys: " << s.candy(ratings2) << endl;
    return 0;
}
