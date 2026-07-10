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
// private:
//     int ComputeGCD(int a,int b){

//     }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp1=head,* temp2=head->next;
        while(temp2){
            int gcdval=gcd(temp1->val,temp2->val);
            ListNode* newNode=new ListNode(gcdval);
            temp1->next=newNode;
            newNode->next=temp2;

            temp1=temp2;
            temp2=temp2->next;
        }
        return head;
    }
};