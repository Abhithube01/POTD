#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
class Solution
{
public:

    pair<int, int> findLongestPathSum(Node *root) {
    if (root == NULL)
        return make_pair(0, 0);

    pair<int, int> left = findLongestPathSum(root->left);
    pair<int, int> right = findLongestPathSum(root->right);

    if (left.first > right.first)
        return make_pair(left.first + 1, left.second + root->data);
    else if (right.first > left.first)
        return make_pair(right.first + 1, right.second + root->data);
    else // If both paths are of equal length, choose the one with maximum sum
        return make_pair(left.first + 1, max(left.second, right.second) + root->data);
}
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code herezz
    pair<int, int> result = findLongestPathSum(root);
    return result.second;
    }
};
int main()
{
    return 0;
}