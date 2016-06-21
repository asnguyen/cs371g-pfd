#ifndef PFD_h
#define PFD_h

#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct Task
{
	int target;							//the target for the rule
	int num_dependents;					//the number of dependents that target has
	Task(const int& a, const int& b)	//constructor
	{
		target=a;				
		num_dependents=b;
	}
};

struct LessDependents												//structed used for changine how make_heap sorts the vector
	{
		bool operator()(const Task& lhs,const Task& rhs)			
		{
			if(lhs.num_dependents == rhs.num_dependents)			//if the number of dependents are equal, look at the value of target
				return lhs.target > rhs.target;
			else
				return lhs.num_dependents > rhs.num_dependents;		//compares the number of dependents
		}
	};

std::queue<int> do_pfd(istream &r, int& tasks, int& rules);
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
*/

void print_pfd(std::queue<int> &queue, ostream	&w);
/*
Parameters:
	std::queue<int> &queue		a reference to a queue
	ostream &w 					a reference to a ostream used to write to
Output:
	None
Description:
	this method will read from the queue and write toward w
*/

void pfd_solve(istream& r, ostream &w);
/*
Parameter:
	istream& r 					input for reading
	ostream& w 					output for writing
Output:
	None
Description:
	this method calls the other methods that wil solve the pfd

*/

bool pfd_read(istream& r, int& i, int& j);
/*
Parameters:
	istream& r 					a reference to a istream for input
	int& i 						reference to an int
	int& j						referecne to an int
Output:
	bool						result of the read
Description:
	this method will read in the number of task and the number of rules.
	it returns true if successful and false if it fails
*/

#endif //PFD_h