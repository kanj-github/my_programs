# include <iostream>

using namespace std;

class a {

	public:
	class b {
		int useless;
		
		public:
		b (int n, int * pt) {
			cout<<"Begin b's constructor\n";
			*pt = n;
			useless = n;
		}
		
		b () { // Needed for line 27
			cout<<"Don't do anything\n";
		}
	};
	
	private:
	int* var;
	
	public:
	b bus;
	
	a(int n) {
		cout<<"Begin a's constructor\n";
		var = new int();
		bus = b(n, var);
	}
	
	void show_var () {
		cout<<*var<<"\n";
	}
};

int main () {
	a aus = a(7);
	aus.show_var();
	return 0;
}