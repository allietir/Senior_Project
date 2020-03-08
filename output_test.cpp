#include <sstream>
#include <iostream>

void print_to_console() {
		std::cout << "Hello from print_to_console()" << std::endl;
}

void foo(){
	std::cout<<"hello world"<<std::endl; 
	print_to_console(); // this could be printed from anything
}
int main()
{
		std::stringstream ss;

		//change the underlying buffer and save the old buffer
		auto old_buf = std::cout.rdbuf(ss.rdbuf()); 

		foo(); //all the std::cout goes to ss

		std::cout.rdbuf(old_buf); //reset

		std::cout << "<redirected-output>\n" 
							<< ss.str() 
							<< "</redirected-output>" << std::endl;
}
