#include <iostream>
#include <vector>
#include <stack>
using namespace std;

enum Tag {Left, Right};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Element
{
    TreeNode *pointer;
    Tag tag;
    Element(){} 
    Element(TreeNode *p) : pointer(p) {}
};
 
/*
Recursive solution: visit left, visit right, visit root
Iterative solution: push root, visit left, pop root, check tag:
if 'Left', then change it to 'Right', push root and visit right.
if 'right', visit root. It also means the whole left-sub-tree is over, so continue pop another 'root'
*/
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        stack<Element> s;
        TreeNode *pointer = root;

        while(!s.empty() || pointer)//in case pointer == root
        {
            if(pointer) //pointer != NULL, then push it and visit LEFT child
            {
                Element ele;
                ele.pointer = pointer;
                ele.tag = Left;//which means visiting left child
                s.push(ele);
                pointer = pointer->left;
            }
            else
            { //pointer == NULL, which means that it returns from left or right
                Element ele = s.top();
                s.pop();//get the top element and pop it.
                pointer = ele.pointer;
                if(ele.tag == Left)//if it returns from left, then push it again and visit RIGHT child
                {
                    ele.tag = Right;//modify tag
                    s.push(ele);
                    pointer = pointer->right;
                }
                else//if it returns from right, visit root, it also means the whole left-sub-tree is over, so pointer --> NULL
                {
                    result.push_back(pointer->val);
                    pointer = NULL;
                }
            }
        }
        return result;
    }
};

int main()
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode *p = &t1;
    p->right = &t2;
    p->right->left = &t3;

    Solution s;
    vector<int> result;
    result = s.postorderTraversal(p);
    
    vector<int>::iterator i;
    for(i = result.begin(); i!= result.end(); i++)
    {
        cout << *i << " ";
    }
    cout << endl;
    return 0;
}
