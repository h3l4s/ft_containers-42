#include "stack.hpp"
#include <stack>
#include <vector>
#include <fstream>

int test_stack(std::ofstream &stream1)
{
	ft::vector<int> mydeque (3,100);          // deque with 3 elements
	ft::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack
	ft::stack<int, ft::vector<int> > second (mydeque);         // stack initialized to copy of deque

	ft::stack<int,ft::vector<int> > third;  // empty stack using vector
	ft::stack<int,ft::vector<int> > fourth (myvector);


  stream1 << "size of first: " << first.size() << '\n';
  stream1 << "size of second: " << second.size() << '\n';
  stream1 << "size of third: " << third.size() << '\n';
  stream1 << "size of fourth: " << fourth.size() << '\n';

  return 0;
}

int test_pop(std::ofstream &stream1)
{
	ft::stack<int> mystack;

  for (int i=0; i<5; ++i) mystack.push(i);

  stream1 << "Popping out elements...";
  while (!mystack.empty())
  {
     stream1 << ' ' << mystack.top();
     mystack.pop();
  }
  stream1 << '\n';

  return 0;
}

int test_top (std::ofstream &stream1)
{
  ft::stack<int> mystack;

  mystack.push(10);
  mystack.push(20);

 mystack.top() -= 5;

 stream1 << "mystack.top() is now " << mystack.top() << '\n';

  return 0;
}

int	main()
{
	std::ofstream stream1;
	std::string filename = "output5";
	stream1.open(filename.c_str());
	test_stack(stream1);
	test_pop(stream1);
	test_top(stream1);
	ft::stack<char> trezor;
    ft::stack<char> trezor2(trezor);
	return (0);
}