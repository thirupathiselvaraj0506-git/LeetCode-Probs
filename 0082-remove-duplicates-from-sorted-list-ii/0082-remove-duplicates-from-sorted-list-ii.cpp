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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *temp=head;
        ListNode *prev=dummy;
        while(temp && temp->next){
            if(temp->val==temp->next->val){
                while(temp->next && temp->val==temp->next->val){
                    temp->next=temp->next->next;
                }
                prev->next=temp->next;
            }else{
                prev=prev->next;
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};