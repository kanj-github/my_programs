#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* A, int m, int n) {
    if (m == n) {
        return A;
    }

    int i = 0;
    ListNode* curr, *head, *x, *y, *prev, *curr1;
    curr = A;
    x = NULL;
    while (i < m - 1) {
      x = curr;
      curr = curr->next;
      i++;
    }
    prev = y = curr;

    // set x->next = last node in reversed section
    // set y->next = next of the last node in reversed section
    curr = curr->next;
    curr1 = curr->next;
    while (i < n-1 && curr != NULL && curr1 != NULL) {
        curr->next = prev;
        prev = curr;
        curr = curr1;
        curr1 = curr1 -> next;
        i++;
    }

    if (i != n-1) {
        // Loop terminated due to curr1 being null. Case when need to reverse till the last element
        curr->next = prev;
        prev = curr;
        curr = NULL;
    }

    y->next = curr;
    if (x != NULL) {
        x->next = prev;
        return A;
    } else {
        return prev;
    }
}

int main (int argc, char ** argv) {
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

  ListNode * reversed = reverseBetween(head, 2, 3);

  while (reversed != NULL) {
    cout<<reversed->val<<"\t";
    reversed = reversed->next;
  }
  cout << "\n";
  return 0;
}
