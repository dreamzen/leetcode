#include <iostream>
#include <vector>
using namespace std;

/**
 * we suppose that 192.168.000.001 is valid
 * BUT, it's WRONG!
 */
class Solution
{
public:
    vector<string> result;
    vector<string> restoreIpAddresses(string s)
    {
        findIpAddresses(s, 0, 0, 0, 1);
        return result;
    }

    //s: the given string
    //one/two/three: the end of first/second/third part's index
    //current: the 1/2/3/4th part we are looking for
    void findIpAddresses(string s, int one, int two, int three, int current)
    {
        int len = s.length();
        if(current == 4)//looking for the last part
        {
            int len_four = len - three - 1;
            if(len_four < 1 || len_four > 3)//must be 0-255
            {
                return;
            }
            if(len_four > 1 && s[three + 1] == '0')//0xx is NOT OK
            {
                return;
            }
            if(len_four == 3)//>255
            {
                if(!isValid(s, three + 1))
                {
                    return;
                }
            }
            //get the IP address
            string str_one = s.substr(0, one + 1);
            string str_two = s.substr(one + 1, two - one);
            string str_three = s.substr(two + 1, three - two);
            string str_four = s.substr(three + 1, len_four);
            string ip = str_one + "." + str_two + "." + str_three + "." + str_four;
            //put into vector
            result.push_back(ip);
        }
        else if(current == 3)
        {
            int len_three = len - two - 1;
            if(len_three < 2 || len_three > 6)
            {
                return;
            }
            findIpAddresses(s, one, two, two + 1, 4);//any x is OK
            if(s[two + 1] != '0')
            {
                findIpAddresses(s, one, two, two + 2, 4);//any xy is OK except 0y
            }
            if(len_three >= 3)//xyz...
            {
                if(isValid(s, two + 1))
                {
                    findIpAddresses(s, one, two, two + 3, 4);
                }
            }
        }
        else if(current == 2)
        {
            int len_two = len - one - 1;
            if(len_two < 3 || len_two > 9)
            {
                return;
            }
            findIpAddresses(s, one, one + 1, 0, 3);
            if(s[one + 1] != '0')
            {
                findIpAddresses(s, one, one + 2, 0, 3);
            }
            if(isValid(s, one + 1))
            {
                findIpAddresses(s, one, one + 3, 0, 3);
            }
        }
        else if(current == 1)
        {
            int len_one = len;
            if(len < 4 || len > 12)
            {
                return;
            }
            findIpAddresses(s, 0, 0, 0, 2);
            if(s[0] != '0')
            {
                findIpAddresses(s, 1, 0, 0, 2);
            }
            if(isValid(s, 0))
            {
                findIpAddresses(s, 2, 0, 0, 2);
            }
            
        }
            
    }

    //return if s[start, start+1, start+2] <= 255
    bool isValid(string s, int start)
    {
        if(s[start] == '0')
        {
            return false;
        }
        if(s[start] > '2')
        {
            return false;
        }
        if(s[start] == '2')
        {
            if((s[start + 1] > '5') || (s[start + 1] == '5' && s[start + 2] > '5'))
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str;
    while(cin >> str)
    {
        vector<string> v = s.restoreIpAddresses(str);
        for(vector<string>::iterator i = v.begin(); i != v.end(); i++)
        {
            cout << *i << endl;
        }
    }
    return 0;
}
