class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 1;
        ListNode* tmp = head;
        while(tmp->next != nullptr) {
            length++;
            tmp = tmp->next;
        }

        if(length == 1) {
            return nullptr;
        }
        else if (length - n == 0)
        {
            return head->next;
        }
        

        ListNode* headPtr = head;
        for (int i = 1; i < length - n; i++)
        {
            head = head->next;
        }
        
        if(n == 1) {
            head->next = nullptr;
        }
        else {
            head->next = head->next->next;
        }

        return headPtr;
    }
};