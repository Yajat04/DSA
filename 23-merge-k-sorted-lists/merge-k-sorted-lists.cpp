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
        int k = lists.size();
        priority_queue <pair< int, ListNode*>, vector<pair< int, ListNode*>>, 
            greater<pair< int, ListNode*>>> pq;
        for(int i = 0; i < k; i++){
            if(lists[i] != NULL) pq.push({lists[i] -> val, lists[i]});
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()){
            auto top = pq.top();
            auto ptr = top.second;
            pq.pop();

            temp -> next = ptr;
            temp = ptr;

            if(ptr -> next != NULL){
                ptr = ptr -> next;
                pq.push({ptr-> val, ptr});
            }
        }

        return dummy -> next;
    }
};