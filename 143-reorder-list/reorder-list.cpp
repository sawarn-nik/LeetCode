class Solution {
private:
    ListNode* rev(ListNode* head){
        ListNode * prev = NULL;
        ListNode * curr = head;
        while(curr){
            ListNode * nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next)
            return;
        ListNode* s = head;
        ListNode* bs = head;
        ListNode* f = head;

        while(f && f->next){
            bs = s;
            s = s->next;
            f = f->next->next;
        }
        bs->next = NULL;
        ListNode * hb = rev(s);
        ListNode * temp  = head;
        while(temp && hb){
            ListNode * t1 = temp->next;
            ListNode * t2 = hb->next;
            temp->next = hb;
            if(!t1){
                break;
            }
            hb->next = t1;
            temp = t1;
            hb = t2;
        }
    }
};