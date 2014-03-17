#include <iostream>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        string result;
        int quot;
        int remainder;

        //max num is 3999, so 1000 is enough 
        quot = num / 1000;
        remainder = num % 1000;
        if(quot)
        {
            result += toRoman(quot, 3);
        }

        quot = remainder / 100;
        remainder %= 100;
        if(quot)
        {
            result += toRoman(quot, 2);
        }

        quot = remainder / 10;
        remainder %= 10;
        if(quot)
        {
            result += toRoman(quot, 1);
        }

        quot = remainder;
        if(quot)
        {
            result += toRoman(quot, 0);
        }
        return result;       
    }
    
    //weight: 0,1,2,3. '3' means x000.
    string toRoman(int quot, int weight)
    {
        switch(quot)
        {
            case 9://max num is 3999, so weight won't be '3' 
                switch(weight)
                {
                    case 2:
                        return "CM";
                    case 1:
                        return "XC";
                    case 0:
                        return "IX";
                    default:
                        break;
                }
                break;
            case 8:
                switch(weight)
                {
                    case 2:
                        return "DCCC";
                    case 1:
                        return "LXXX";
                    case 0:
                        return "VIII";
                    default:
                        break;
                }
                break;
            case 7:
                switch(weight)
                {
                    case 2:
                        return "DCC";
                    case 1:
                        return "LXX";
                    case 0:
                        return "VII";
                    default:
                        break;
                }
                break;
            case 6:
                switch(weight)
                {
                    case 2:
                        return "DC";
                    case 1:
                        return "LX";
                    case 0:
                        return "VI";
                    default:
                        break;
                }
                break;
            case 5:
                switch(weight)
                {
                    case 2:
                        return "D";
                    case 1:
                        return "L";
                    case 0:
                        return "V";
                    default:
                        break;
                }
                break;
            case 4:
                switch(weight)
                {
                    case 2:
                        return "CD";
                    case 1:
                        return "XL";
                    case 0:
                        return "IV";
                    default:
                        break;
                }
                break;
            case 3:
                switch(weight)
                {
                    case 3:
                        return "MMM";
                    case 2:
                        return "CCC";
                    case 1:
                        return "XXX";
                    case 0:
                        return "III";
                    default:
                        break;
                }
                break;
            case 2:
                switch(weight)
                {
                    case 3:
                        return "MM";
                    case 2:
                        return "CC";
                    case 1:
                        return "XX";
                    case 0:
                        return "II";
                    default:
                        break;
                }
                break;
            case 1:
                switch(weight)
                {
                    case 3:
                        return "M";
                    case 2:
                        return "C";
                    case 1:
                        return "X";
                    case 0:
                        return "I";
                    default:
                        break;
                }
                break;
            case 0:
                return "";
            default:
                break;
        }
    }
};

int main()
{
    while(true)
    {
        int num;
        cin >> num;
        if(num <= 0)
        {
            break;
        }
        Solution s;
        cout << s.intToRoman(num) << endl;
    }
    return 0;
}
