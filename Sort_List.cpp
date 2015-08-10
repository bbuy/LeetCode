Question: Sort a linked list in O(n log n) time using constant space complexity.

chop the list to two part recurisive both side, and use mergeSort to link them.


class Solution {
public:
    ListNode* mergeSort(ListNode* head1, ListNode* head2)
    {
        ListNode fakeHead(0);
        ListNode* it = &fakeHead;

        while(head1!=NULL && head2!=NULL)
        {
            if(head1->val<=head2->val)
                {
                    it->next = head1;
                    head1= head1->next;
                    it = it->next;
                }
            else
                {
                    it->next = head2;
                    head2= head2->next;
                    it = it->next;
                }
        }

        it->next = head1==NULL?head2:head1;
        return fakeHead.next;
    }

    ListNode* sortList(ListNode* head) {
        if(!head)
            return NULL;

        if(!head->next)
            return head;

        //Find the mid node and divide
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* pre = NULL;
        while(fast&&fast->next)
        {
            fast=fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        pre->next = NULL;
        return mergeSort(sortList(head),sortList(slow));
    }
};
