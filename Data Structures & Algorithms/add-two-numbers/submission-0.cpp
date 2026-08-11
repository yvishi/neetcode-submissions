/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head=new ListNode(0);
        ListNode* ans=head;
        int carry=0;
        while(l1 || l2){
            int first=0,second=0;
            if(l1){
                first=l1->val;
                l1=l1->next;
            }
            if(l2){
                second=l2->val;
                l2=l2->next;
            }
            int sum=first+second+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* node=new ListNode(sum);
            ans->next=node;
            ans=ans->next;
        }
        if(carry){
            ListNode* node=new ListNode(carry);
            ans->next=node;
        }
        return head->next;
    }
};
