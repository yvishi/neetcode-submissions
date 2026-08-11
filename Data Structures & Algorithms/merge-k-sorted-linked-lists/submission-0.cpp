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
    ListNode* mergeKLists(vector<ListNode*>& list) {
        if(list.empty()) return NULL;
        int n=list.size();
        for(int i=1;i<n;++i){
            list[i]=merge(list[i-1],list[i]);
        }
        return list[n-1];
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* head=new ListNode(0);
        ListNode* temp=head;
        while(l1 && l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
            }else{
                temp->next=l2;
                l2=l2->next;
            }
            temp=temp->next;
        }
        if(l1){
            temp->next=l1;
        }else{
            temp->next=l2;
        }
        return head->next;
    }
};
