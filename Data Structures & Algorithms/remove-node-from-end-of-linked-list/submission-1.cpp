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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head || !head->next){
            return NULL;
        }
        ListNode* temp=head;
        int len=0;
        while(temp){
            ++len;
            temp=temp->next;
        }
        len=len-n;
        temp=head;
        ListNode* prev=NULL;
        while(temp){
            if(len==0){
                if(prev){
                    prev->next=temp->next;
                }else{
                    head=head->next; 
                }
                return head;
            }
            prev=temp;
            temp=temp->next;
            --len;
        }
        return head;
    }
};
