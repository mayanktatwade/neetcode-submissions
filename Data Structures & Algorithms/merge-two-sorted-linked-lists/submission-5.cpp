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
    void helper(ListNode* list1, ListNode* list2,ListNode* ans){
        if(list1 == nullptr && list2 == nullptr){return;}
        if(list1 == nullptr){ans->next = list2;return;}
        if(list2 == nullptr){ans->next = list1;return;}

        if(list1->val >= list2->val){
            ans->next = list2;
            list2 = list2->next;
            ans = ans->next;
        }
        else{
            ans->next = list1;
            list1 = list1->next;
            ans = ans->next;
        }
        helper(list1,list2,ans);
        return;
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        helper(list1,list2,ans);

        return temp->next;
    }
};
