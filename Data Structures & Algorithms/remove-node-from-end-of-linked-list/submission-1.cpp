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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp);
            temp = temp->next;
        }
        int size = arr.size();
        cout<<size<<" "<<n<<" "<<size-n<<endl;
        if(n==1){if(size>=2){arr[size-2]->next = nullptr;return head;}
        else{ return nullptr;}}
        if(n==size){head = head->next; return head;}

        arr[size-n-1]->next = arr[size-n+1];
        return head;
    }
};
