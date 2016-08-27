# include <iostream>
# include <string>

using namespace std;

string str1;
string str2;
char ** mat;
int count,len;

void fill_0_1() {
	char c1, c2, c3;
	for (int i=0; i<len-2; i++) {
		c1 = str.at(i);
		c2 = str.at(i+1);
		c3 = str.at(i+2);
		mat[i][0] = ((c1 == c2)? 'y':'n');
		mat[i][1] = ((c1 == c3)? 'y':'n');
	}
	mat[len-2][0] = ((c3 == c2)? 'y':'n');
}

void fill_column(int col) {
	int i;
	for (i=0; i<len-1-col; i++) {
		if (mat[i+1][col-2] == 'y' && str2.at(i) == str2.at(i+col+1))
			mat[i][col] = 'y';
		else mat[i][col] = 'n';
	}
}

void match_pattern(int start, int j) {
	// increment count if matches.
	int i,end,idx1=0,idx2=0;
	end = start+j+1;
	char ch1 = str1.at(idx1), ch2 = str2.at(idx2);
	
	if (ch1 != '#' && ch1 != ch2) return;
	//else if (str.at(str.length()-1))
	
}

int main() {
	int i,j;
	cin>>str1;
	cin>>str2;
	len = str2.length();
	mat = new char * [len-1];
	for (i=0;i<len-1;i++) {
		mat[i] = new char [len-1-i];
		
	}
	
	// fill up columns 0 & 1 corresponding to lengths 2 & 3 respectively.
	fill_0_1();
	
	// fill other columns
	for (i=2; i<len-1; i++) fill_column(i);
	
	count = 0;
	// check if the palindromes can match the pattern
	for (i=0; i<len-1; i++) for (j=0; j<len-1-i; j++)
		if (mat[i][j] == 'y') match_pattern(i,j);
	
	return 0;
}

