// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
	
	if (head == NULL || head->next == NULL)
        	return head;

    	struct ListNode* newHead = head->next;   // After first swap, this becomes head
    	struct ListNode* prev = NULL;
    	struct ListNode* first = head;

    	while (first != NULL && first->next != NULL) {

        	struct ListNode* second = first->next;
        	struct ListNode* nextPair = second->next;

        	// Swap
        	second->next = first;
        	first->next = nextPair;

        	// Connect previous pair
        	if (prev != NULL)
            		prev->next = second;

        	// Move prev forward
        	prev = first;
        	first = nextPair;
    	}

    	return newHead;
  
	
}
