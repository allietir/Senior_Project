#include <iostream>
#include <cstdio>
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
		if ( !fp ) { printf("error"); return 0; }

		FILE *old = stdout;
		stdout = fp;

		foo(); //all the printf goes to buffer (using fp);

		fclose(fp);
		stdout = old; //reset

		printf("<redirected-output>\n%s</redirected-output>", buffer);
}