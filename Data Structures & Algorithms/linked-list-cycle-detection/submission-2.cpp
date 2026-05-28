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
    bool hasCycle(ListNode* head) {
     if(head == NULL){return false;}
     map<ListNode*, int> mp;
     while(true){
        if(head == NULL){return false;}
        if(mp.count(head)){return true;}
        mp[head]++;
        head = head->next;
     }
     return true;

    }
};
