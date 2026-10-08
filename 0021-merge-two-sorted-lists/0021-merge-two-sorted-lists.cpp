class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        int len1 = 0, len2 = 0;
        
        if(list1 == nullptr) {
            return list2;
        }
        else {
            len1 = 0;
            ListNode* tmp = list1;
            while(tmp != nullptr) {
                len1++;
                tmp = tmp->next;
            }
        }

        if(list2 == nullptr) {
            return list1;
        }
        else {
            len2 = 0;
            ListNode* tmp = list2;
            while(tmp != nullptr) {
                len2++;
                tmp = tmp->next;
            }
        }

        ListNode* head;
    
        if(list1->val < list2->val) {
            head = list1;
            list1 = list1->next;
        }
        else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* result = head;

        for (int i = 1; i < len1 + len2; i++)
        {
            if(list1 == nullptr) {
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
            else if(list2 == nullptr) {
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            }
            else {
                if(list1->val < list2->val) {
                    head->next = list1;
                    head = head->next;
                    list1 = list1->next;
                }
                else {
                    head->next = list2;
                    head = head->next;
                    list2 = list2->next;
                }
            }
            
        }
        
        return result;
    }
};