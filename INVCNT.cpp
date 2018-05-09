#include <iostream>
#include <vector>

using namespace std;

// Try to solve http://www.spoj.com/problems/INVCNT/

// Make a binary tree such that l->val < n.val < r->val.
struct node {
  int val;
  int right_pop; // Population under right side of this node. Number of nodes that have larger value than this.
  node * l;
  node * r;

  node(int v) : val(v) {
    right_pop = 0;
    l = r = NULL;
  }
};

long get_invert_count(vector<int> arr) {
  long count = 0;
  node root = node(arr[0]);
  for (int i = 1; i<arr.size(); i++) {
    node * curr = &root;
    node * element = new node(arr[i]);

    while (arr[i] > curr-> val) {
      curr->right_pop++;
      if (curr->r != NULL) {
        curr = curr -> r;
      } else {
        curr->r = element;
        curr = NULL; // To mark that this element didn't cause any inversions
        break;
      }
    }

    if (curr != NULL) {
      // This element is smaller than curr and all the curr's right population
      count += (curr->right_pop + 1);

      // Find a place for this element now and check for more inversion down the left branch
      if (curr -> l == NULL) {
        // Left branch is empty
        curr -> l = element;
      } else {
        // Find a place in the left branch
        curr = curr -> l;
        while (curr != NULL) { // Might even use while(true)
          if (curr->val > arr[i]) {
            count += (curr->right_pop + 1);
            if (curr->l == NULL) {
              curr -> l = element;
              break;
            } else {
              curr = curr -> l;
            }
          } else {
            curr->right_pop++;
            if (curr -> r == NULL) {
              curr -> r = element;
              break;
            } else {
              curr = curr -> r;
            }
          }
        }
      }
    }
  }

  return count;
}

int main() {
	int tests, size;
	cin>>tests;
	while(tests > 0) {
		cin>>size;
		vector<int> array(size);
		for (int i=0; i<size; i++) {
			cin>>array[i];
		}

		cout<<get_invert_count(array)<<"\n";

		tests--;
	}
	return 0;
}
