# include <iostream>

using namespace std;

struct node {
	int value;
	node* next;
}

void segregate (node** head) {
	node * temp = NULL;
	node * curr = head;
	node * prev = NULL;
	while (curr != NULL) {
		
		if (curr->value % 2 == 0 && prev != NULL) {
			// Remove from original position. Ignore if even is found at prev = NULL because that means head is even.
			prev-> next = curr -> next;

			// Add in new position
			if (temp != NULL) {
				curr->next = temp-> next;
				temp-> next = curr;
			} else {
				// New position is head
				curr->next = head;
				head = curr;
			}
			// Move temp ahead now
			temp = curr;
		}
		prev = curr;
		curr = curr->next;
	}
}