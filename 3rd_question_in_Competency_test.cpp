#include<iostream>

using namespace std;

int** Map;
int N;
int Answer;

int search () {
	for (int i=0; i<N; i++) {
	 for (int j=0; j<N; j++) if (Map[i][j] < 2) {
		cout<<i*N+j;
		return i*N+j;
		}
	}
	return -1;
}

void expand (int p, int c) {
	int i = p/N;
	int j = p%N;
	if (Map[i][j] > 2) return;
	Map[i][j] = 2;
	cout<<"\n"<<i<<"\t"<<j;
	if (i>=1) if (Map[i-1][j] == c) expand ((i-1)*N+j,c);
	if (i<N-1) if (Map[i+1][j] == c) expand ((i+1)*N+j,c);
	if (j>=1) if (Map[i][j-1] == c) expand (i*N+j-1,c);
	if (j<N-1) if (Map[i][j+1] == c) expand (i*N+j+1,c);
}

int main(int argc, char** argv)
{
	int test_case;
	/*
  	  freopen function below opens input.txt file in read only mode, and afterward,
 	  the program will read from input.txt file instead of standard(keyboard) input.
	  To test your program, you may save input data in input.txt file,
	  and use freopen function to read from the file when using scanf function.
	  You may remove the comment symbols(//) in the below statement and use it.
	  But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	// freopen("input.txt", "r", stdin);


	/*
	  Your program should handle 20 test cases given.
	 */
	for(test_case = 1; test_case <= 20; ++test_case)
	{
		int i, j;

		/*
		   Read each test case from standard input.
		   A cell information of i-th row and j-th column is stored in Map[i][j].
		   (ex. If a number in the second row and the third column is one, one is stored in Map[2][3].)
		 */
		
		cin >> N;
		Map = new int*[N];
		for(i = 0; i < N; i++)
		{
			Map[i] = new int [N];
			for (j = 0; j < N; j++)
			{

				cin >> Map[i][j];
			}
		}
		
for (i = 0; i < N; i++) for (j = 0; j < N; j++) cout<<Map[i][j]<<"\t";

int p;
Answer = 0;
p=search();
while (p != -1) {
	Answer++;
	expand(p,Map[p/N][p%N]);
	p=search();
}

		// Print the answer to standard output(screen).
		cout << "#" << test_case << " " << Answer << endl;
	}

	return 0; //Your program should return 0 on normal termination.
}
