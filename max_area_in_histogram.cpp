# include <iostream>
# include <stack>

using namespace std;

int pop_c=0, push_c=0, *arr;

int do_it(int size) {
	
	int * areas = new int[size];
	stack<int> st;
	int i;
	for (i=0;i<size;i++) {
		while(!st.empty() && (arr[st.top()] >= arr[i])) {
			st.pop();
			pop_c++;
		}
		if (st.empty()) {
			areas[i]=arr[i]*i;
		} else areas[i]=(i-st.top())*arr[i]; // Area of i + valid area on the left
		st.push(i);
		push_c++;
	}

	while(!st.empty()) {
		st.pop();
		pop_c++;
	}
	
	for (i=size-1; i>=0; i--) {
		while(!st.empty() && (arr[st.top()] >= arr[i])) {
			st.pop();
			pop_c++;
		}
		if (st.empty()) {
			areas[i]+=arr[i]*(size-i-1);
		} else areas[i]+=(st.top()-i-1)*arr[i]; // Valid area on the right
		st.push(i);
		push_c++;
	}

	while(!st.empty()) {
		st.pop();
		pop_c++;
	}
	
	int max_area=areas[0];
	for (i=1;i<size;i++) {
		if(areas[i] > max_area) max_area=areas[i];
	}
	
	return max_area;
}

int main () {
	int n;
	cout<<"Enter length\n";
	cin>>n;
	arr=new int[n];
	cout<<"Enter values.\n";
	for (int i=0;i<n;i++) cin>>arr[i];
	
	cout<<do_it(n)<<"\n";
	cout<<"Pop count= "<<pop_c<<" Push count= "<<push_c<<"\n";
	
	return 0;
}
