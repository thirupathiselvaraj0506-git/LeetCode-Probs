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
    int pairSum(ListNode* head) {
        if(head->next->next==NULL){
            return head->val+head->next->val;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* prev=NULL;
        ListNode* curr=slow;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        int maxans=INT_MIN;
        ListNode* newNode=head;
        // while(head){
        //     cout<<head->val<<endl;
        //     head=head->next;
        // }
        // cout<<endl;
        // while(prev){
        //     cout<<prev->val<<endl;
        //     prev=prev->next;
        // }
        while(prev){
            int sum=newNode->val+prev->val;
            maxans=max(maxans,sum);
            newNode=newNode->next;prev=prev->next;
        }
        return maxans;
    }
};