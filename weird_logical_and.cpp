#include <cstdio>
#include <cstring>

using namespace std;

char * test_func () {

char *po = new char[5];
printf("Kanj -1\n");
sprintf(po, "very_long");
printf("Kanj -2\n");
return po;
}

int main() {
	/*char *cp = new char[10];
	strcpy(cp, "string");
	int *ip = new int;
	*ip = 64;*/
	char c = 0x80;
	int n = (int)c;// & 0x000000ff;
	printf("%02x\n",n);
	//if (!(cp && *cp && ip && *ip) < 32000) printf("It's true\n");
	//printf("Weird value id %s - %02x\n",cp, *ip);
	//printf("Kanj -3\n");
	char *cp;
	cp = test_func();
	printf("Kanj -4 %s\n",cp);
	unsigned char addr[6]={0x91,0x22,0x33,0x84,0x55,0x66};
	char bdstr[18]={0};

    
    sprintf((char*)bdstr, "%02x:%02x:%02x:%02x:%02x:%02x",
                       (int)addr[0],(int)addr[1],(int)addr[2],
                       (int)addr[3],(int)addr[4],(int)addr[5]);
	printf("%s",bdstr);

	return 0;
}

