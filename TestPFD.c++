#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <queue>

#include "gtest/gtest.h"

#include "PFD.h"

using namespace std;

//read test begin
TEST(PFDFixture, read_1)
{
	istringstream r("100 99\n");
	int i;
	int j;
	const bool b = pfd_read(r,i,j);
	ASSERT_TRUE(b);
	ASSERT_EQ(100,i);
	ASSERT_EQ(99, j);
}
TEST(PFDFixture, read_2)
{
	istringstream r("");
	int i;
	int j;
	const bool b = pfd_read(r,i,j);
	ASSERT_FALSE(b);
}
TEST(PFDFixture, read_3)
{
	istringstream r("101 3\n");
	int i;
	int j;
	const bool b = pfd_read(r,i,j);
	ASSERT_FALSE(b);
}
TEST(PFDFixture, read_4)
{
	istringstream r("50 75\n");
	int i;
	int j;
	const bool b = pfd_read(r,i,j);
	ASSERT_FALSE(b);
}
//read test end

//print test begin
TEST(PFDFixture, print_1)
{
	ostringstream w;
	std::queue<int> q({1,2,3});
	print_pfd(q,w);
	ASSERT_EQ("1 2 3 \n",w.str());
}
TEST(PFDFixture, print_2)
{
	ostringstream w;
	std::queue<int> q({1,2,3,4,5,6,7,8,9});
	print_pfd(q,w);
	ASSERT_EQ("1 2 3 4 5 6 7 8 9 \n",w.str());
}
TEST(PFDFixture, print_3)
{
	ostringstream w;
	std::queue<int> q({5,1,2,4,3});
	print_pfd(q,w);
	ASSERT_EQ("5 1 2 4 3 \n",w.str());
}
//print test end

//solve test begin
TEST(PFDFixture,solve_1)
{
	istringstream r("4 0\n");
	ostringstream w;
	pfd_solve(r,w);
	ASSERT_EQ("1 2 3 4 \n",w.str());
}
TEST(PFDFixture,solve_2)
{
	istringstream r("5 4\n3 2 1 5\n2 2 5 3\n4 1 3\n5 1 1\n");
	ostringstream w;
	pfd_solve(r,w);
	ASSERT_EQ("1 5 3 2 4 \n",w.str());
}
TEST(PFDFixture,solve_3)
{
	istringstream r("6 2\n1 2 2 3\n4 2 5 6\n");
	ostringstream w;
	pfd_solve(r,w);
	ASSERT_EQ("2 3 1 5 6 4 \n",w.str());
}
//solve test end

//do_pfd test begin
TEST(PFDFixture, do_pfd_1)
{
	istringstream r("3 2 1 5\n2 2 5 3\n4 1 3\n5 1 1\n");
	int i = 5;
	int j = 4;
	std::queue<int> queue(do_pfd(r,i,j));
	ASSERT_EQ(queue.size(),5);	
}
TEST(PFDFixture, do_pfd_2)
{
	istringstream r("1 2 2 3\n4 2 5 6\n");
	int i = 6;
	int j = 2;
	std::queue<int> queue(do_pfd(r,i,j));
	ASSERT_EQ(queue.size(),6);	
}
TEST(PFDFixture, do_pfd_3)
{
	istringstream r("");
	int i = 4;
	int j = 0;
	std::queue<int> queue(do_pfd(r,i,j));
	ASSERT_EQ(queue.size(),4);	
}
//do_pfd test end































