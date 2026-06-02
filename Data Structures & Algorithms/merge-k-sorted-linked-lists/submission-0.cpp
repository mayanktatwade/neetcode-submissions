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
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0){return nullptr;}
        vector<pair<int,ListNode*>>main;
        for(ListNode* i:lists){
            while(i){
                main.push_back({i->val,i});
                i = i->next;
            }
        }
        sort(main.begin(),main.end());

        ListNode* ans = main[0].second;
        ListNode* head = ans;
        for(int i = 1; i<main.size(); i++ ){
            ans->next = main[i].second;
            ans = ans->next;
        }ans->next = nullptr;

        return head;
    }
};
