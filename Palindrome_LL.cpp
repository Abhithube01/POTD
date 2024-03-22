#include<iostream>
#include<vector>
using namespace std;
int main()
{
    return 0;
}
//reverse LL
//moiddle Node (slow fast approach)
//consider for both odd and even linked list
//using recursion print reverse linked list


  struct ListNode {
      int val;
      ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        //handling with array/vector is easy
        vector<int> values;

        while(head != NULL)
        {
            values.push_back(head->val);
            head = head->next;
        }
        int start = 0;
        int end = values.size() - 1;

        while(start < end)
        {
            if(values[start] != values[end])
              {
                return false;
              }
              start++;
              end--;
        }
        return true;
    }
};