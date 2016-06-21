#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <array>
#include <iostream>
#include <queue>

#include "PFD.h"

using namespace std;

std::queue<int> do_pfd(istream &r, int& tasks, int& rules)
{
	//setup begins
	int matrix[101][101];
	for(int i=0;i <= 100;++i)
	{
		for(int j = 0;j<=100;++j)
			matrix[i][j]=0;
	}
	//setup ends

	//reading in rules begins
	for(int j=0;j<rules;++j)
	{
		int target=0;									//gets the target for the rule
		r >> target;
		int num_dependents=0;							//gets the number of dependencies
		r >> num_dependents;
		matrix[target][0]=num_dependents;			//sets the number of dependencies to the zeroth spot
		for(int i=0;i<num_dependents;++i)
		{
			int dependent=0;							//gets the dependent task
			r >> dependent;
			matrix[target][dependent]=1;		//marks that target need dependent
		}
		
	}
	//reading in rules ends

	//solving topological sort begins
	std::queue<int> order;							//holds the order 
	int i = 1;
	//printf("%d\n",tasks);
	while((int)order.size()!=(int)tasks)						//will terminate when every task has been placed in the order
	{
		if(matrix[i][0]==0)							//if the task has no dependents
		{
			order.push(i);							//adds the task to the order
			for(int j=1;j<=tasks;++j)				//goes through all the tasks to see if "i" is a dependent
			{
				if(matrix[j][i]==1)					//see if task j has task i as a dependent
				{
					if(matrix[j][0]>0)
						matrix[j][0]-=1;
					matrix[j][i] = 0;
				}									//if so decrease the number of dependents
			}
			matrix[i][0]=-1;						//makes sure we dont recount task i
			i=1;									//resets the lookup

		}
		else
		{
			++i;									//moves to the next task
		}

	}
	//solving topological sort ends
	
	return order;

}

void print_pfd(std::queue<int> &queue, ostream	&w)
{
	while(!queue.empty())
	{
		w << queue.front() << " ";
		queue.pop();
	}
	w << endl;
}

void pfd_solve(istream& r, ostream &w)
{
	int tasks=0;
	int rules=0;
	while(pfd_read(r,tasks,rules))
	{
		std::queue<int> queue (do_pfd(r,tasks,rules));
		print_pfd(queue,w);
	}
}

bool pfd_read(istream& r, int& i, int& j)
{
	if(!(r >> i))				//is there read value for i
		return false;
	if(i>100) 					//there can only be at max 100 tasks
		return false;
	r >> j;
	if(j>i)
		return false;		//there cant more rules than tasks

	return true;
}




















