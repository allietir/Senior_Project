#include <iostream>
#include <cstdio>
#include <stdio.h>
using namespace std;
void print_to_console() {
		printf( "Hello from print_to_console()\n" );
}

void foo(){
	printf("hello world\n");
	print_to_console(); // this could be printed from anything
}

int main()
{
		char buffer[1024];
		FILE *fp = fmemopen(buffer, 1024, "w");
		printf("reached this\n");
		if ( !fp ) { printf("the error"); return 0; }
		printf("failed here 1;");
		FILE *old = stdout;
		printf("failed here 2;");
		stdout = fp;
		printf("failed here 3;");
		
		foo(); //all the printf goes to buffer (using fp);
		printf("failed here 4;");
		fclose(fp);
		printf("failed here 5;");
		stdout = old; //reset
		printf("failed here 6;");
		printf("<redirected-output>\n%s</redirected-output>", buffer);
		printf("failed here 7;");
}