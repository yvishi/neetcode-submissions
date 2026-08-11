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
    void reorderList(ListNode* head) {
       if(head==NULL || head->next==NULL)
            return;
       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* prev=NULL;
       while(fast!=NULL && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
       }
        prev->next=NULL;
        prev=NULL;
        while(slow!=NULL){
            ListNode* temp1=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp1;
        }
        ListNode* temp=head;
        fast=head->next;;
        while(fast!=NULL && prev!=NULL){
            temp->next=prev;
            prev=prev->next;
            temp=temp->next;
            temp->next=fast;
            fast=fast->next;
            temp=temp->next;
        }
        if(prev){
            temp->next=prev;
        }
        
    }
};





