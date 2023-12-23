#include <stdio.h>
  //Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1); //哑节点
        ListNode* cur = dummy;  //当前处理的节点
        while(p1 || p2){
            int n1 = (p1==NULL)? 0:p1->val;
            int n2 = (p2==NULL)? 0:p2->val;
            int sum = n1+n2+carry;
            carry = sum/10;
            cur->next = new ListNode(sum%10);
            cur = cur->next; 
            if(p1) p1=p1->next;
            if(p2) p2=p2->next;
        }
        if(carry>0) cur->next = new ListNode(carry);
        return dummy->next;
    }
};

