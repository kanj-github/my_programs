# include <iostream>

using namespace std;

# define MASK(shift) 1<<shift

int main () {
	int arr [1004];
	int n=1,idx=0,temp,i,digits=1,j;
	
	for (; idx<1004 ; n++) {
		if (n == (1<<digits)) digits++;
		
		for (j=digits-1; j>=0; j--) {
			
			temp= n & (1<<j);
			
			temp=temp>>j;
			
			arr[idx++] = temp & 1;
		}
	}
	
	int Answer = 0, N;
	//N--;
	int inp[] = {1,6,37,94,95,186,356,476, 999, 1000};
	
    for (int x=0; x<=10; x++) {
	N=inp[x];
	N--;
	Answer=0;
	for (j =4; j>=0;j--) {
        temp = arr[N++];
		//cout<<"value in array is "<<temp<<"\n";
        if (temp) {
			temp = temp << j;
			//cout<<"after shifting "<<temp<<"\n";
			Answer = Answer | temp;
			//cout<<"after OR "<<Answer<<"\n";
			}
        
    }
	//for (i=0; i<11; i++ ) cout<<arr[i]<<" ";
	cout<<Answer<<"\n";
	
	}
	return 0;
}

