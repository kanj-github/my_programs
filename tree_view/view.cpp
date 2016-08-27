//# include <iostream>
//# include <vector>
# include "tree.h"

using namespace std;

int main() {
	node* tree_root = get_input_and_build();
	cout<<"---------------------------\n";
	print_bfs(tree_root);
	cout<<"++++++++++++++++++++++++++++++++\n";
	vector<q_node> * view;
	get_views(tree_root, view);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<"Top view from left is - \n";
	for (auto qn : view[0]) cout<<qn.n->get_data()<<" ";
	cout<<"\nRight view from top is - \n";
	for (auto qn : view[1]) cout<<qn.n->get_data()<<" ";
	cout<<"\nBottom view from left is - \n";
	for (auto qn : view[2]) cout<<qn.n->get_data()<<" ";
	cout<<"\nLeft view from top is - \n";
	for (auto qn : view[3]) cout<<qn.n->get_data()<<" ";
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	return 0;
}
