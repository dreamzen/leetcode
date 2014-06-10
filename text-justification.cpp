#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int L)
    {
        vector<string> result;
        if(words.empty())
        {
            return words;
        }
        //remove ""
        vector<string> newWords;
        for(int i = 0; i < words.size(); i++)
        {
            if(words[i].length() != 0)
            {
                newWords.push_back(words[i]);
            }
        }
        if(newWords.empty())
        {
            string wStr(L, ' ');
            result.push_back(wStr);
            return result;
        }
        int from = 0;
        int to = 0;
        int len = newWords[0].length();//including one ' ' between every two words
        for(int i = 1; i < newWords.size(); i++)
        {
            if(len + 1 + newWords[i].length() <= L)//have enough space
            {
                len = len + 1 + newWords[i].length();
                to = i;
            }
            else//justify[from, to]
            {
                string one_result;
                if(from == to)//just one word
                {
                    string wStr(L - newWords[from].length(), ' ');
                    one_result = newWords[from] + wStr;
                }
                else//more than one word
                {
                    int whiteSpace = L;
                    for(int j = from; j <= to; j++)
                    {
                        whiteSpace -= newWords[j].length();
                    }
                    //fill white space
                    int gaps = to - from;
                    for(int j = to; j > from; j--)
                    {
                        string wStr(whiteSpace / gaps, ' ');
                        one_result = wStr + newWords[j] + one_result;
                        whiteSpace -= (whiteSpace / gaps);
                        gaps--;
                    }
                    one_result = newWords[from] + one_result;
                }
                result.push_back(one_result);
                //update from and to
                from = i;
                to = i;
                len = newWords[i].length();
            }
        }
        //deal with last line
        string one_result;
        one_result = newWords[from];
        for(int i = from + 1; i <= to; i++)
        {
            one_result = one_result + " " + newWords[i];
        }
        string wStr(L - one_result.length(), ' ');
        one_result = one_result + wStr;
        result.push_back(one_result);
        return result;
    }
};

int main()
{
	return 0;
}
