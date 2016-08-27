# include <iostream>

typedef struct {
	int idx;
	int weight;
} vertex;

class min_priority_queue {
	vertex * q;
	int s;
	
	void min_heapify(int i);
	void propagate_upwards(int cur);
	
	public:
	min_priority_queue (int max) {
		q = new vertex[max];
		s = 0;
	}
	
	void add_to_heap (int v, int w);
	vertex pop_min();
	int is_empty() {return (s == 0);}
	void change_weight(int v, int w);
	
	void dump();
};
