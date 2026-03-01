#include <stdlib.h>
struct ListNode* insertionSortList(struct ListNode* head) 
{
    if (head == NULL || head->next == NULL)
        return head;

    // Dummy node for sorted list
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = NULL;
    struct ListNode* current = head;
    while (current != NULL) 
    {
        struct ListNode* nextNode = current->next;

        // Find insertion position
        struct ListNode* prev = dummy;
        while (prev->next != NULL && prev->next->val < current->val) 
        {
            prev = prev->next;
        }

        // Insert current between prev and prev->next
        current->next = prev->next;
        prev->next = current;
        current = nextNode;
    }

    struct ListNode* sortedHead = dummy->next;
    free(dummy);
    return sortedHead;
}
