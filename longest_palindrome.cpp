# include <iostream>
# include <cstring>

using namespace std;

int **table;
int max_len=1, max_centre=-1, max_start=-1, cost;

/*
					length(n) ----->
start of substring
		|			0,2   -----    0,n
		|
		|
		|
		|			n-2,2 -----	   n-2,n
n-1 columns & n-1 rows store => centre of corresponding palindrome if length of
								palindrome == length of substring
							 => length(n) + centre of palindrome if length of
								palindrome < length of substring

Kanj is a jackass because dynamic programming should not be used here.
Subproblems are not common.

*/

void do_column_1_and_2(char * str, int n) {
	for (int i=1;i<n;i++) {
		cost++;
		if (str[i] == str [i-1]) table[i-1][0] = i-1;
		if (i == 1) continue
		else {
			if (str[i-2] == str[i]) table[i-2][1] = i-1;
		}
	}
}

void DP_method(char* str, int n) {
	for (int i=2; i<n-1; i++) {
		for (int j=0; j<n-i-1; j++) {
			cost++;
			if (table[j+1][i-2] == -1) table[j][i] = -1;
			else if (table[j+1][i-2] >= n || str[j] == str[j+i])
												table[j][i] = table[j+1][i-2];
			else table[j][i] = n+table[j+1][i-2];
		}
	}
}

void show_output(char* str, int n) {
	int i, end, start, centre;
	start = centre = table[0][n-2];
	end = ((n%2 == 0)?centre+1:centre);
	
	while (start>0 && end<n-2 && str[--start] == str[++end]) ;
	
	char* palindrome = new char[end-start+2];
	memcpy(str+start,palindrome,end-start+1);
	palindrome[end-start+2]='\0';
	
	cout<<"Answer is "<<palindrome<<"\n";
}

void check_this_out_man(char* str, int len, int c) {
	int s=c,e;
	// Even lenth
	e=c+1;
	while (s>-1 && e<len && str[s--] == str[e++]) {
		cost++;
		if (e-s+1 > max_len) {
			max_len = e-s+1;
			max_centre = c;
			max_start = s;
		}
	}
	// Odd length
	e=s=c;
	while (s>-1 && e<len && str[s--] == str[e++]) {
		cost++;
		if (e-s+1 > max_len) {
			max_len = e-s+1;
			max_centre = c;
			max_start = s;
		}
	}
}

int how_is_it_going(char* str, int len, int c) {
	//cost++;
	int retvalue = 0, targ_len, i, j;
	// Even case
	targ_len = ((max_len%2 == 0)?max_len+2:max_len+1);
	i = c-targ_len/2+1;
	j = i+targ_len-1;
	if (i>-1 && j<len && str[i] == str[j]) retvalue+=2;
	
	// Odd case
	targ_len = ((max_len%2 == 0)?max_len+1:max_len+2);
	i = c-targ_len/2;
	j = i+targ_len-1;
	if (i>-1 && j<len && str[i] == str[j]) retvalue+=1;
	
	return retvalue;
}

/*
void really(char* str, int len, int c, int go) {
	if (go & 1 == 1) {
		
	}
	
	if (go & 2 == 2) {
		
	}
}*/

int main (int argc, char* argv[]) {
	
	if (argc != 2) return 0;
	
	int i,j;
	int len = strlen(argv[1]);
	table = new int * [len-1];
	for (i=0;i<len;i++) {
		table[i] = new int [len-1];
		for (j=0;j<len-1;j++) table[i][j] = -1;
	}
	cost=0;
	do_column_1_and_2(argv[1], len);
	DP_method(argv[1], len);
	show_output(argv[1], len);
	cout<<"Cost of Dynamic Programming is "<<cost<<"\n";
	
	// Use Kanj method now
	cost=0;
	int going;
	if (len%2 != 0) {
		check_this_out_man(argv[1], len, len/2);
		i=len/2 - 1;
		j=i+2;
	} else {
		i=l/2 - 1;
		j=i+1;
	}
	while (i>-1 && j<len) {
		if (max_len != 1) {
			going = how_is_it_going(argv[1], len, i);
			if (going != 0) check_this_out_man (argv[1], len, i);
			going = how_is_it_going(argv[1], len, j);
			if (going != 0) check_this_out_man (argv[1], len, j);
			i--; j--;
			break;//Make you have considered both i & j as centre.
		}
		check_this_out_man(argv[1], len, i--);
		check_this_out_man(argv[1], len, j++);
	}
	
	char* palindrome = new char[max_len+1];
	memcpy(argv[1]+max_start, palindrome, max_len);
	palindrome[max_len]='\0';
	
	cout<<"Answer is "<<palindrome<<"\n";
	
	cout<<"Cost of Kanj method is "<<cost<<"\n";
	return 1;
}