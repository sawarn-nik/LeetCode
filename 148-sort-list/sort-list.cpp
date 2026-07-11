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
private:
    ListNode * merge(ListNode *a,ListNode * b){
        ListNode * dummy = new ListNode(-1);
        ListNode * tail = dummy;
        while(a&&b){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }
            else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if(a){
            tail->next = a;
        }
        else{
            tail->next = b;
        }

        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode * mid = slow->next;
        slow->next = NULL;

        ListNode * left = sortList(head);
        ListNode * right = sortList(mid);

        return merge(left,right);
    }
};