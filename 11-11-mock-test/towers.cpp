#include<iostream>
#include<cstdio>

using namespace std;

int AnswerN, N;

void mark (char ** mat, int i, int j, int level) {
	if ((j-level)>=0 && mat[i][j-level] == 'H') {
		mat[i][j-level] = 'Z';
		AnswerN--;
	}
	
	if ((i-level)>=0 && mat[i-level][j] == 'H') {
		mat[i-level][j] = 'Z';
		AnswerN--;
	}
	
	if ((i+level)<N && mat[i+level][j] == 'H') {
		mat[i+level][j] = 'Z';
		AnswerN--;
	}
	
	if ((j+level)<N && mat[i][j+level] == 'H') {
		mat[i][j+level] = 'Z';
		AnswerN--;
	}
	
	if (level>=2) mark(mat, i, j, level-1);
}

int main(int argc, char** argv)
{
	int test_case, i,j,T,towers;
	freopen("sample_input.txt", "r", stdin);
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;
        towers = AnswerN = 0;
		char** map = new char*[N];
		for(i = 0; i < N ; i++) {
			map[i] = new char[N];
			for(j = 0 ; j < N ; j++) {
				cin >> map[i][j];
				if(map[i][j] == ' ' || map[i][j] == '\n')
					cin >> map[i][j];
                if (map[i][j] == 'H') AnswerN++; //Count houses
				else if (map[i][j] > 64 && map[i][j] < 68) towers++; //count towers
			}
		}
		//cout<<"houses = "<<AnswerN<<"\n";

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			Please, implement your algorithm from this section.
			Your solution is to be stored in a variable called 'AnswerN'.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		
        for (i=0; i< N && towers > 0; i++) for (j=0; j<N && towers>0; j++) {
			switch (map[i][j]) {
			    case 'X' : break;
				case 'H' : break;
				case 'A': mark(map, i,j, 1);
						  towers--;
						  break;
				case 'B': mark(map, i, j, 2);
						  towers--;
						  break;
				case 'C': mark(map, i, j, 3);
						  towers--;
						  break;
				default: break;
			};
		}

        // Print the answer to standard output(screen). 
		cout<<"#"<<test_case<<" "<<AnswerN<<endl;

		for(int i = 0; i < N ; i++) {
			delete[] map[i];
		}
		delete[] map;

	}
	return 0;//Your program should return 0 on normal termination.
}
