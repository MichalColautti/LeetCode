/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *head = NULL;    
    struct ListNode *tail = NULL;
    int remainder = 0;

    while(l1 != NULL || l2 != NULL || remainder != 0) {
        int val1 = 0;
        if(l1 != NULL) {
            val1 = l1->val;
        }
        int val2 = 0;
        if(l2 != NULL) {
            val2 = l2->val;
        }
        int sum = val1 + val2 + remainder;
        remainder = sum / 10;

        struct ListNode *newNode = (struct ListNode *)calloc(1, sizeof(struct ListNode));
        newNode->val = sum % 10;

        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = tail->next;
        }
        
        if(l1 != NULL) {
            l1 = l1->next;
        }
        if(l2 != NULL) {
            l2 = l2->next;
        }
    }

    return head;
}