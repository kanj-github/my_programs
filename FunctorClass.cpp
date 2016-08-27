#include <iostream>

using namespace std;

class funk {
	int& var;
	public:
		funk (int& num) : var(num) {cout<<"Constructor\n";}
		/*funk () {
			var = 
			cout<<"I am blank\n";
		}*/
		void operator () (int n) const {
			cout<<"This is the operator printing -"<<n<<"\n";
			var++;
		}
		/*funk& operator = (const funk& tmp) {
			cout<<"fake = operator\n";
		}*/
};

int main() {
	int n = 10;
	funk crap = funk (n);
	crap (n);
	crap (n);
	return 0;
}
