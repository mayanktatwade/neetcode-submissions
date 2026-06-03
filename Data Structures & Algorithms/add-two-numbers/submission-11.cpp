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
// BTW ALL BELOW WAS HANDWRITTEN BY MEE!!, basic sum problem XD
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* anshead = ans;
        int carry = 0;

        while(l1 && l2){
            ListNode* temp = new ListNode((l1->val+l2->val+carry)%10);
            ans->next = temp;
            ans = ans->next;
            if((l1->val+l2->val+carry)/10){carry=1;}
            else{carry=0;}
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            ListNode* temp = new ListNode((l1->val+carry)%10);
            ans->next = temp;
            ans = ans->next;
            if((l1->val+carry)/10){carry=1;}
            else{carry=0;}
            l1 = l1->next;
        } 
        while(l2){
            ListNode* temp = new ListNode((l2->val+carry)%10);
            ans->next = temp;
            ans = ans->next;
            if((l2->val+carry)/10){carry=1;}
            else{carry=0;}
            l2 = l2->next;
        } 
        if(carry){
            ListNode* temp = new ListNode(1);
            ans->next = temp;
            ans->next->next = nullptr;
        }
        else{
            ans->next = nullptr;
        }
        return anshead->next;
    }
};
