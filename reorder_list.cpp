# include <iostream>
# include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

 ListNode* reorder(ListNode* A) {
 	stack<ListNode *> stack;
 	ListNode * fast, * slow, * curr;
 	fast = slow = A;
 	while(fast != NULL && fast -> next != NULL) { // can be while(true)
 		slow = slow -> next;
 		fast = fast -> next;
 		if (fast != NULL && fast -> next != NULL) fast = fast -> next;
 		else break;
 		//cout<<"slow="<<slow->val<<", fast="<<fast->val<<"\n";
 	}

 	if (fast == slow) { // 1 or 2 items in the list; no need to do anything
 		return A;
 	} else {
 		// slow will become the last element. put slow + 1 to end in a stack for later use
 		curr = slow -> next;
 		slow -> next = NULL;
 		while (curr != NULL) {
 			stack.push(curr);
 			curr = curr ->next;
 		}

 		// Now interleave the link list and stack
 		curr = A;
 		while (curr != NULL) {
 			if (!stack.empty()) {
 				ListNode * top = stack.top();
 				stack.pop();
 				top -> next = curr -> next;
 				curr -> next = top;
 				curr = top -> next;
 			} else {
 				curr = curr -> next;
 			}
 		}

 		return A;
 	}

 }

 int main() {
 	ListNode * head = new ListNode(1);

  	ListNode * curr = head, * next;
  	for (int i = 2; i< 4; i++) {
    	next = new ListNode(i);
    	curr -> next = next;
    	curr = next;
  	}

  	curr = head;
  	while (curr != NULL) {
    	cout<<curr->val<<"\t";
    	curr = curr->next;
  	}
  	cout << "\n";

  	ListNode * r = reorder(head);
  	
  	curr = r;
  	while (curr != NULL) {
    	cout<<curr->val<<"\t";
    	curr = curr->next;
  	}
  	cout << "\n";
 }