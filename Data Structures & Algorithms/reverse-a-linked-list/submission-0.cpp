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
    int i=0;
    ListNode* traverse(ListNode* curr,ListNode* prev){
        if(curr== nullptr){return prev;}
        ListNode* temp = curr->next;

        curr->next = prev;
        cout<<curr->val<<" ";

        ListNode* ans = traverse(temp,curr);
        

        return  ans;   
    }
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr){return head;}
        ListNode* ans = traverse(head,nullptr);

        return ans;   
    }
};
