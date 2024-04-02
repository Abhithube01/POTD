#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    return 0;
}
struct Node {
    int data;
    Node *left;
    Node *right;

};
class Solution
{
    int minAbsDiff = INT_MAX;
    Node* prevNode = NULL;
    
    public:
    int absolute_diff(Node *root)
    {
        if(root == NULL)
        {
            return minAbsDiff;
        }
        absolute_diff(root->left);
        
        if(prevNode != NULL)
        {
            minAbsDiff = min(minAbsDiff,abs(root->data - prevNode->data));
        }
        prevNode = root;
        
        absolute_diff(root->right);
        
        return minAbsDiff;
        //Your code here
    }
};