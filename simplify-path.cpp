#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        if(path.length() <= 1)
        {
            return path;
        }
        //remove duplicates "./" and "//////"
        vector<bool> needRemoved(path.length(), 0);
        for(int i = 0; i < path.length(); )
        {
            switch (path[i])
            {
                case '.':
                    if(i == path.length() - 1)// "/a/b/."
                    {
                        needRemoved[i] = 1;
                        i = i + 1;
                    }
                    else if(i + 1 < path.length() && path[i + 1] == '/')// "/a/b/./xx"
                    {
                        needRemoved[i] = 1;
                        while(i + 1 < path.length() && path[i + 1] == '/')// ".///"
                        {
                            needRemoved[i + 1] = 1;
                            i = i + 1;
                        }
                    }
                    else// "/a/b/.." or file name "....." 
                    {
                        while(i < path.length() && path[i] == '.')
                        {
                            i++;
                        }
                    }
                    break;
                case '/':
                    if(i + 1 < path.length() && path[i + 1] == '/')// "/a/b//xx"
                    {
                        needRemoved[i] = 1;
                        i = i + 1;
                    }
                    else// normal situation
                    {
                        i = i + 1;
                    }
                    break;
                default: //charactors
                    i = i + 1;
                    break;
            }
        }
        string newPath;
        for(int i = 0; i < needRemoved.size(); i++)
        {
            if(needRemoved[i] == 0)
            {
                newPath += path[i];
            }
        }
        //deal with '/' at the tail
        if(newPath.length() != 1 && newPath[newPath.length() - 1] == '/')
        {
            newPath = newPath.substr(0, newPath.length() - 1);
        }
        //deal with newPath  /home/name/../working/leetcode
        if(newPath.length() <= 1)
        {
            return newPath;
        }
        string result;
        stack<int> sIndex;
        for(int i = 0; i < newPath.length(); )
        {
            if(newPath[i] == '/')// i + 1 must be < newPath.length()
            {
                if(i + 2 < newPath.length() && newPath[i + 1] == '.' && newPath[i + 2] == '.')// "/..xxx"
                {
                    if(i + 3 == newPath.length() || newPath[i + 3] == '/')// "/../"
                    {
                        if(sIndex.empty())
                        {
                            result = "";
                        }
                        else
                        {
                            result = result.substr(0, sIndex.top());
                            sIndex.pop();
                        }
                        i = i + 3;// skip ".."
                    }
                    else// "/..." valid name
                    {
                        result += newPath[i];
                        i = i + 1;
                    }
                }
                else if(i + 1 < newPath.length())// normal situation "/a/b"
                {
                    result += newPath[i];
                    sIndex.push(result.length() - 1);//not push 'i'
                    i = i + 1;
                }
                else
                {
                    //never happen
                    i = i + 1;
                }
            }
            else//normal charactor
            {
                result += newPath[i];
                i = i + 1;
            }
        }
        if(result == "")
        {
            result = "/";
        }
        return result;
    }
};

int main()
{
	return 0;
}
