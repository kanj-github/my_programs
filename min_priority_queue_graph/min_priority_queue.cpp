// Min priority queue using heap.

# include "mpq.h"

using namespace std;

void min_priority_queue::min_heapify(int i) {
	int smallest = i;
	
	if (2*i+1 < s && q[2*i+1].weight < q[i].weight) smallest = 2*i+1;
	if (2*i+2 < s && q[2*i+2].weight < q[2*i+1].weight) smallest = 2*i+2;
	
	if (smallest == i) return;
	
	vertex temp = q[i];
	q[i] = q[smallest];
	q[smallest] = temp;
	
	min_heapify(smallest);
}

void min_priority_queue::propagate_upwards(int cur) {
	vertex temp;
	while (cur > 0 && q[cur].weight < q[(cur-1)/2].weight) {
		temp = q[cur];
		q[cur] = q[(cur-1)/2];
		q[(cur-1)/2] = temp;
		cur = (cur-1)/2;
	}
}

vertex min_priority_queue::pop_min() {
	vertex ret = q[0];
	q[0] = q[--s];
	min_heapify(0);
	return ret;
}

void min_priority_queue::add_to_heap(int v, int w) {
	//q[s++] = {v,w};
	vertex vert;
	vert.idx=v;
	vert.weight=w;
	q[s++] = vert;
	propagate_upwards(s-1);
}

void min_priority_queue::change_weight(int v, int w) {
	// first find the vertex in heap
	int loc=-1;
	for (int i=0; i<s; i++) {
		if (q[i].idx == v) {
			loc = i;
			break;
		}
	}
	
	if (loc == -1 || q[loc].weight == w) return;
	
	if (w > q[loc].weight) {
		q[loc].weight = w;
		// Move the node down in tree using min_heapify
		min_heapify(loc);
	} else {
		q[loc].weight = w;
		// Move the node up in tree
		propagate_upwards(loc);
	}
}

void min_priority_queue::dump() {
	for(int i=0; i<s; i++) cout<<"("<<q[i].idx<<","<<q[i].weight<<") ";
	cout<<"\n";
}