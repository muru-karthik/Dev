//============================================================================
// Name        : Threads.cpp
// Author      : Muruganand K
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <thread>
#include <string>

using namespace std;

void thread_run(string &s)
{
	cout << "Inside thread: " << s << endl;
	s += " Kart";
}

int main() {
	string s = "Muru";
	thread t(&thread_run, std::ref(s));
	t.join();

	cout << "String: " << s << endl;
	return 0;
}
