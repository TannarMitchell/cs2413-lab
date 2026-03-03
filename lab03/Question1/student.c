//   Implement reverseList(head) to reverse a singly linked list.
//
// Rules:
// - Do not allocate new nodes.
// - Do not use recursion.
// - Return the new head pointer.
// ------------------------------------------------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include "student.h"

struct ListNode* reverseList(struct ListNode* head) {
    

	struct ListNode* prev = NULL;
	struct ListNode* current = head;
	struct ListNode* next = NULL;

	while(current != NULL){
	
	next = current -> next; //Setting next equal to the current nodes next value
	current -> next = prev; //the current nodes next pointer is now equal to the previous value
	prev = current; //setting previous equal to current
	current = next; // current equal to next

	}
	return prev;
}
