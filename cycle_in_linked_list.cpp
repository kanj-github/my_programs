#include <iostream>

using namespace std;

// Solve https://www.interviewbit.com/problems/list-cycle/

struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode * detectFirstNodeInACycleInLinkedList(ListNode * A) {
	ListNode * slow, * fast;
	slow = fast = A;
	int cycleLen = 0;
	bool found = false;
	while(true) {
		if (slow -> next != NULL) {
			slow = slow -> next;
		} else {
			break;
		}
		if (fast -> next != NULL && fast->next->next != NULL) {
			fast = fast->next->next;
		} else {
			break;
		}
		cycleLen++;
		if (slow == fast) {
			found = true;
			break;
		}
	}

	if (found) {
		// Need to find the starting node of cycle
		ListNode * ptr1, * ptr2;
		ptr2 = ptr1 = A;
		for (int i = 0; i < cycleLen - 1; i++) {
			ptr2 = ptr2 -> next;
		}

		while (ptr2 -> next != ptr1) {
			ptr2 = ptr2 -> next;
			ptr1 = ptr1 -> next;
		}
		return ptr1;
	}

	return NULL;
}

int main() {
	// I don't have time for this shit; test on the website
	return 0;
}
