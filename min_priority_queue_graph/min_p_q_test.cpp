# include "mpq.h"

using namespace std;

int main() {
	min_priority_queue mpq = min_priority_queue(10);
	mpq.add_to_heap(0,10);
	mpq.add_to_heap(1,11);
	mpq.add_to_heap(2,9);
	mpq.dump();
	mpq.change_weight(1,8);
	mpq.dump();
	mpq.add_to_heap(3,7);
	mpq.dump();
	vertex v = mpq.pop_min();
	cout<<v.idx<<" with weight "<<v.weight<<" popped.\n";
	mpq.dump();
	return 0;
}
