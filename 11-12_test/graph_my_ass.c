#include <stdio.h>

char tree[10000];
int k;
int AnswerN;

int main(void)
{
	int test_case;
	int T;
	int pos = 0;
	int num, depth;
	freopen("sample_input.txt", "r", stdin);
	/*
	   If you remove the statement below, your program's output may not be recorded
	   when your program is aborted due to the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	//setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	   Read each test case from standard input.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		// Read data from input.txt file
		depth = AnswerN = 0;
		scanf("%d", &k);
		scanf("%s", tree);

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			Please, implement your algorithm from 'Code here' sections.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		pos=0;
		
		while(tree[pos] != '\0')
		{
			if(tree[pos] == '(')
			{
				depth++;
			}
			else if(tree[pos] == ')')
			{
				depth--;
			}
			else
			{
				num = tree[pos] - '0';
				if (depth == k+1) AnswerN += num;
			}

			pos++;
		}

		
		// Print the answer to standard output(screen). 
		printf("#%d %d\n", test_case, AnswerN);
	}
	return 0; //Your program should return 0 on normal termination.
}
