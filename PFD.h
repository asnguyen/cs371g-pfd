#ifndef PFD_h
#define PFD_h

#include <iostream>
#include <string>
#include <utility>
#include <queue>

using namespace std;

std::queue<int> do_pfd(istream &r, int tasks, int rules);
void print_pfd(std::queue<int> &queue, ostream	&w);
void pfd_solve(istream& r, ostream &w);
bool pfd_read(istream& r, int& i, int& j);

#endif //PFD_h
/*
Parameters:
	istream &r			a reference to a istream for input
	int tasks			an int representing the number of tasks
	int rules			an int representing the number of rules
Output:
	std::queue<int>		this queue will be the solution to the pfd
Description:
	this method does the bulk of the pfd work using the indegree method of 
	topological sorting and stores the asnswer in std::queue<int>


void print_pfd(std::queue<int> &queue, ostream &w);

Parameters:
	std::queue<int> &queue		a reference to a queue
	ostream &w 					a reference to a ostream used to write to
Output:
	None
Description:
	this method will read from the queue and write toward w


bool pfd_read(istream& r, int& i, int& j);

Parameters:
	istream& r 					a reference to a istream for input
	int& i 						reference to an int
	int& j						referecne to an int
Output:
	bool						result of the read
Description:
	this method will read in the number of task and the number of rules.
	it returns true if successful and false if it fails

void pfd_solve(istream& r, ostream &w);

Parameter:
	istream& r 					input for reading
	ostream& w 					output for writing
Output:
	None
Description:
	this method calls the other methods that wil solve the pfd

*/
