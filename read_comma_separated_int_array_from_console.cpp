#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char ** argv) {
    string str;
    int len, * numbers, count = 0;
    char * char_array;
    getline(cin, str);
    len = str.length();
    for (int i = 0; i < len; i++) {
      if (str[i] == ',') {
        count++;
      }
    }
    count++; // There is one more number

    numbers = new int[count];
    int pos = 0;

    char_array = new char[len + 1];
    strcpy(char_array, str.c_str());
    char * token = strtok(char_array, " ,");
    while(token && pos < count) {
      numbers[pos++] = atoi(token);
      token = strtok(NULL, " ,");
    }

    cout<<"---------------------------------\n";
    for (int i = 0; i<count; i++) {
      cout<<numbers[i]<<"\n";
    }
    return 0;
}
