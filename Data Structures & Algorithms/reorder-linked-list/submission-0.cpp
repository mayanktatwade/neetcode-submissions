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
    vector<ListNode*> temp;
    void rearrange(vector<ListNode*>arr,int l,int r){
        if(l>r){return;}
        if(l==r){temp.push_back(arr[l]); return;}

        temp.push_back(arr[l]);
        temp.push_back(arr[r]);
        rearrange(arr,l+1,r-1);
        return;
    }

    void reorderList(ListNode* head) {
        if(head == nullptr) return;
        vector<ListNode*> arr;
        ListNode* temp0 = head;
        while(temp0){
            arr.push_back(temp0);
            temp0 = temp0->next;
        }

        rearrange(arr,0,arr.size()-1);
        
        for(int i = 0; i < temp.size()-1; i++){
            temp[i]->next = temp[i+1];
        }

        temp.back()->next = nullptr;
                


    }
};
