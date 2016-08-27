# include <iostream>
# include <unistd.h>

# define RET_FORK {\
	return fork();\
	}

# define LOG_RET_FORK(N) {\
	pid_t t = fork();\
	if (t != 0) cout<<t<<" is child of "<<getpid()<<" using frk"<<N<<".\n";\
	return t;\
}

using namespace std;

pid_t frk1() LOG_RET_FORK(1)

pid_t frk2() LOG_RET_FORK(2)

pid_t frk3() LOG_RET_FORK(3)

int main() {
	frk1() && frk2() || frk3();
	//cout<<"Crap!!\n";
	return 0;
}
