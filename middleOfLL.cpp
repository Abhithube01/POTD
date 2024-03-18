#include <iostream>
using namespace std;
//slow fast approach 
//find middle of linked list if there are two then return second middle

  struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* middleNode(ListNode* head) 
    {
        ListNode* slow = head;
        ListNode* fast = fast;

         while(fast!=NULL && fast->next !=NULL)
         {
            slow =  slow->next;
            fast = (fast->next)->next;
         }

         return slow;
        
    }
};

int main()
{

    
    return 0;
}