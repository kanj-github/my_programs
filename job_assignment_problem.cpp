#include <iostream>
#include <cstring>

using namespace std;

int N, ** d;
bool v = false;
bool analyze = false;

class node {
    public:
    int score; // Popularity in a sense
    node* next;
    int* used_nodes;
    
    node (int* u, int s): used_nodes(u), score(s) {
        next = NULL;
    }
    
    ~node () {
		if (v) cout<<"Node destructor called...";
        delete next;
        delete used_nodes;
		if (v) cout<<"done\n";
    }
};

class list {
    public:
    int size;
    node* head;
    node* last;
    int score;
    
    list() {
        size = score = 0;
        head = NULL;
        last = NULL;
    }
    
    // Use this constructor to initialise list.
    // This will ensure correct list score.
    list (node* first) {
        head = last = first;
        size = 1;
        score = first->score;
    }
    
    ~list() {
		if (v) cout<<"List destructor called...";
        delete head; // Nodes will be destroyed in cascade.
		if (v) cout<<"done\n";
    }
    
    void add_node_to_list(node* n) {
        if (score != n->score) return;
        if (size == 0){
            head = last = n;
            size = 1;
        } else {
            size++;
            last->next = n;
            last = n;
        }
    }
    
    void add_list_to_list (list* l) {
		if (score != l->score) return;
		else {
            node* ptr = l->head;
            while (ptr!=NULL) {
                add_node_to_list(ptr);
                ptr = ptr->next;
            }
        }
    }
    
	/* Overload + operator instead. It will kick ass.
    
    list operator + (list l) {
        if (score != l.score) return *this;
        else {
            node* ptr = l.head;
            for (int i=0; i<(l.size); i++) {
                add_node_to_list(ptr);
                ptr = ptr->next;
            }
        }
    }
	*/
	void display() {
		node* ptr = head;
		int i = 0;
		cout<<"List is:-\n";
		while (ptr!=NULL) {
			cout<<"Entry "<<++i<<"\n";
			for (int l=0; l<N; l++) cout<<l+1<<"\t"<<(ptr->used_nodes[l])+1<<"\n";
			ptr = ptr->next;
		}
		cout<<"Score is "<<score<<"\n\n";
	}
};

list* next_level_node (node* n, int level) {
	if (v) cout<<"next_level_node begin, level "<<level<<"\n";
    int var, max_pop_yet = n->score, * p;
    // p will become used_nodes for child nodes
    list* temp = NULL;
    for (int i=0; i<N; i++){
        if ((n->used_nodes)[i] != -1) continue; // Employee already used
        else {
            var = d[i][level]+(n->score);
            if (var > max_pop_yet) {
                max_pop_yet = var;
                //Create new temp list
                if (temp != NULL) delete temp;
                p = new int[N];
                for (int j=0; j<N; j++) p[j]=(n->used_nodes)[j];
                p[i] = level;
                temp = new list(new node(p,var));
                
            } else if (var == max_pop_yet) {
                //Add node to temp list
                p = new int[N];
                for (int j=0; j<N; j++) p[j]=(n->used_nodes)[j];
                p[i] = level;
                if (temp == NULL) temp = new list(new node(p,var));
				else temp->add_node_to_list(new node(p,var));
            }
        }
    }
	if (v) temp->display();
	if (v) cout<<"next_level_node end, level "<<level<<"\n";
    return temp;
}

list* next_level_list (list* l, int level) {
    if (v) cout<<"next_level_list begin, level "<<level<<"\n";
    int max_pop_yet = l->score;
	if (v) cout<<"max_pop_yet = "<<max_pop_yet<<"\n";
    node* ptr = l->head;
    list* temp = new list(), * result = NULL, sum;
    while (ptr!=NULL) {
        temp = next_level_node(ptr, level);
        if ((temp->score) > max_pop_yet) {
            max_pop_yet = temp->score;
            //Create new result list
            if (result != NULL) delete result;
            result = temp;
        } else if ((temp->score) == max_pop_yet) {
            // Add temp list to reslut list
            if (result == NULL) result = temp;
			else result->add_list_to_list(temp);
        }
        ptr = ptr->next;
    }
    if (v) cout<<"next_level_list done, level "<<level<<"\n";
	if (v) result->display();
	//delete l;
    return result;
}

int main (int argc, char* argv[]) {
    
    int n, * used, ** temp_for_analyze=NULL;
    node* root;
    list* temp, * result;
	
	if (argc == 2) {
		if (strcmp(argv[1],"-v") == 0) v = true;
		else if (strcmp(argv[1],"-a") == 0) analyze = true;
	}
    
    cout<<"Enter N.\n";
    cin>>N;
    d = new int*[N];
    for (int i=0; i<N; i++){
        cout<<"Enter job preference of employee "<<i+1<<"\n";
        d[i] = new int[N];
		for (int num=0 ; num<N; num++) d[i][num] = 0;
        for (int j=N ; j>0; j--) {
            cin>>n;
            if (n!=0 && n<=N) d[i][n-1] = j;
        }
    }
    used = new int[N];
    for (int j=0; j<N; j++) used[j]=-1;
    
    temp = next_level_node(new node(used,0), 0);
    if (v) cout<<"Root node done\n";
    
    for (int k=1; k<N; k++) {
        if (v) cout<<"Begin loop "<<k<<"\n";
        result = next_level_list(temp,k);
        delete temp;
        temp = result;
    }
    
    cout<<"Size of result is "<<result->size<<"\n";
    temp_for_analyze = new int*[result->size];
	
	n=0;
    node* ptr = result->head;
    while (ptr!=NULL) {
        cout<<"Assignment "<<++n<<"is:-\n";
        cout<<"Emp\tJob\n";
		temp_for_analyze[n-1] = new int[N];
		for (int l=0; l<N; l++) {
			cout<<l+1<<"\t"<<(ptr->used_nodes[l])+1<<"\n";
			temp_for_analyze[n-1][l] = (ptr->used_nodes[l]);
		}
        ptr = ptr->next;
    }
	
	int temp_var1 = -1, temp_var2 = -1;
	if (analyze) {
		cout<<endl<<endl<<"Analysis is:-\n";
		for (int m=0; m<n; m++) {
			cout<<"\nAssignment "<<m+1<<":-\n";
			for (int o=0; o<N; o++) {
				cout<<o+1<<" would prefer assignment ";
				for (int pq=0; pq<n; pq++) if (temp_for_analyze[pq][o] > temp_for_analyze[m][o]) cout<<pq+1;
				cout<<"\n";
			}
		}
	}
    
    return 0;
}
