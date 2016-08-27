# include <iostream>

using namespace std;

struct term {
	int c;
	int p;
	term* n;
	
	term (int c, int p) : c(c), p(p) {
		n = NULL;
	}
};

term * get_poly() {
	cout<<"Enter number of terms\n";
	int n,x,y;
	cin>>n;
	cout<<"Enter sequence of coeffs & powers\n";
	cin>>x>>y;
	term * head = new term(x,y);
	term * curr = head;
	n--;
	while((n--) > 0) {
		cin>>x>>y;
		curr->n = new term(x,y);
		curr=curr->n;
	}
	return head;
}

term * add_poly(term *a, term *b) {
	term * curr, * head;
	curr = head = NULL;
	int max_power, sum;
	if (a->p > b->p) max_power = a->p;
	else max_power = b->p;
	
	while (max_power >=0) {
		sum = 0;
		
		if (a!=NULL && a->p == max_power) {
			sum+=a->c;
			a=a->n;
		}
		
		if (b!=NULL && b->p == max_power) {
			sum+=b->c;
			b=b->n;
		}
		
		if (sum!=0) {
			if (head==NULL) {
				// head & curr are uninitialised for the first term.
				curr = head = new term(sum,max_power);
			} else {
				curr->n = new term(sum,max_power);
				curr=curr->n;
			}
		}
		
		max_power--;
	}
	return head;
}

void print_poly(term * p) {
	while (p!=NULL) {
		cout<<p->c;
		if (p->p != 0) cout<<"x^"<<p->p;
		p = p->n;
		if (p!=NULL && p->c > 0) cout<<" +";
		else if (p!=NULL) cout<<" ";
		else cout<<"\n";
	}
}

int main() {
	term * p1=get_poly();
	term * p2=get_poly();
	cout<<"Polynomial 1 is: ";
	print_poly(p1);
	cout<<"Polynomial 2 is: ";
	print_poly(p2);
	term * p3 = add_poly(p1,p2);
	cout<<"Sum is: ";
	print_poly(p3);
	return 0;
}