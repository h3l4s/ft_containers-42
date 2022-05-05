#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>


#ifndef NAMESPACE_DEFINED
 using namespace std;
#endif



void test_construtor(std::ofstream &stream1)
{
  stream1 << "test constructeur" << std::endl;
  std::vector<int> first;                                // empty vector of ints
  std::vector<int>  second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third  
  int myints[] = {16,2,77,29};
  std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );
  stream1 << "The contents of fifth are:";
  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
    stream1 << ' ' << *it;
  stream1 << '\n';
}



void test_iterator(std::ofstream &stream1)
{
 
    // begin
  {
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    stream1 << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      stream1 << ' ' << *it;
    stream1 << '\n';
  }

    // end
  {
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    stream1 << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
      stream1 << ' ' << *it;
    stream1 << '\n';
  }

    // rbegin
  {
    std::vector<int> myvector (5);  // 5 default-constructed ints

    int i=0;

    std::vector<int>::reverse_iterator rit = myvector.rbegin();
    for (; rit!= myvector.rend(); ++rit)
      *rit = ++i;

    stream1 << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      stream1 << ' ' << *it;
    stream1 << '\n';
  }

    // rend
  {
    std::vector<int> myvector (5);  // 5 default-constructed ints

    std::vector<int>::reverse_iterator rit = myvector.rbegin();

    int i=0;
    for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
      *rit = ++i;

    stream1 << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
      stream1 << ' ' << *it;
    stream1 << '\n';
  }

    // casting iterators
  {
    std::vector<int> myvector;
    for (int i=1; i<=5; i++) myvector.push_back(i);

    std::vector<int>::iterator it = myvector.begin();
    std::vector<int>::iterator const_it = it;

    stream1 << "myvector contains:";
    for (; const_it != myvector.end(); ++const_it)
      stream1 << ' ' << *const_it;
    stream1 << '\n';
  }

}

 void test_operator(std::ofstream &stream1)  
{
  std::vector<int> foo (3,0);
  std::vector<int> bar (5,0);

  bar = foo;
  foo = std::vector<int>();

  stream1 << "Size of foo: " << int(foo.size()) << '\n';
  stream1 << "Size of bar: " << int(bar.size()) << '\n';
}

void test_size(std::ofstream &stream1)
{
    // size
  std::vector<int> myints;
  stream1 << "0. size: " << myints.size() << '\n';

  for (int i=0; i<10; i++) myints.push_back(i);
  stream1 << "1. size: " << myints.size() << '\n';

  myints.insert (myints.end(),10,100);
  stream1 << "2. size: " << myints.size() << '\n';

  myints.pop_back();
  stream1 << "3. size: " << myints.size() << '\n';
}

 void max_size(std::ofstream &stream1)
{
  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  stream1 << "size: " << myvector.size() << "\n";
  stream1 << "capacity bg: " << myvector.capacity() << "\n";
  stream1 << "max_size: " << myvector.max_size() << "\n";

  return ;
}


void resize(std::ofstream &stream1)
{
  std::vector<int> myvector;

  // set some initial content:
  for (int i=1;i<10;i++) myvector.push_back(i);

  myvector.resize(5);
  myvector.resize(8,100);
  myvector.resize(12);

  stream1 << "myvector contains:";
  for (unsigned i=0;i<myvector.size();i++)
    stream1 << ' ' << myvector[i];
  stream1 << '\n';
}

void  capacity(std::ofstream &stream1)
{
  std::vector<int> myvector;

  // set some content in the vector:
  for (int i=0; i<100; i++) myvector.push_back(i);

  stream1 << "size: " << (int) myvector.size() << '\n';
  stream1 << "capacity test: " << (int) myvector.capacity() << '\n';
  stream1 << "max_size: " << (int) myvector.max_size() << '\n';
}

void  empty(std::ofstream &stream1)
{
  std::vector<int> myvector;
  int sum (0);

  for (int i=1;i<=10;i++) myvector.push_back(i);
    stream1 << "empty = " << myvector.empty() << std::endl;

  while (!myvector.empty())
  {
     sum += myvector.back();
     myvector.pop_back();
  }
    stream1 << "empty = " << myvector.empty() << std::endl;

  stream1 << "total: " << sum << '\n';

}

void  reserve(std::ofstream &stream1)
{
    std::vector<int> foo;
    stream1 << "making foo grow:\n";
    for (int i=0; i<100; ++i) {
      foo.push_back(i);
    }

    std::vector<int> bar;
    bar.reserve(100);   // this is the only difference with foo above
    stream1 << "making bar grow:\n";
    for (int i=0; i<100; ++i) {
      bar.push_back(i);
    }
}


 void   operator_croche(std::ofstream &stream1)
{
  std::vector<int> myvector (10);   // 10 zero-initialized elements

  std::vector<int>::size_type sz = myvector.size();

  // assign some values:
  for (unsigned i=0; i<sz; i++) myvector[i]=i;

  // reverse vector using operator[]:
  for (unsigned i=0; i<sz/2; i++)
  {
    int temp;
    temp = myvector[sz-1-i];
    myvector[sz-1-i]=myvector[i];
    myvector[i]=temp;
  }

  stream1 << "myvector contains:";
  for (unsigned i=0; i<sz; i++)
    stream1 << ' ' << myvector[i];
  stream1 << '\n';
}

void at(std::ofstream &stream1)
{
    std::vector<int> myvector (10);   // 10 zero-initialized ints

  // assign some values:
  for (unsigned i=0; i<myvector.size(); i++)
    myvector.at(i)=i;

  stream1 << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    stream1 << ' ' << myvector.at(i);
  stream1 << '\n';
}

void  front(std::ofstream &stream1)
{
  std::vector<int> myvector;

  myvector.push_back(78);
  myvector.push_back(16);

  // now front equals 78, and back 16

  myvector.front() -= myvector.back();

  stream1 << "myvector.front() is now " << myvector.front() << '\n';

}

void  back(std::ofstream &stream1)
{
  std::vector<int> myvector;

  myvector.push_back(10);

  while (myvector.back() != 0)
  {
    myvector.push_back ( myvector.back() -1 );
  }

  stream1 << "myvector contains:";
  for (unsigned i=0; i<myvector.size() ; i++)
    stream1 << ' ' << myvector[i];
  stream1 << '\n';
}

 ///////////////     MODIFIERS     ////////////////////////////////////////

int test_assign (std::ofstream &stream1)
{
	std::vector<int> first;
	std::vector<int> second;
	std::vector<int> third;

	first.assign (7,100);						// 7 ints with a value of 100

	std::vector<int>::iterator it = first.begin();
    std::vector<int>::iterator ite = first.end();
    it+=1;

	second.assign (it, --ite);		// the 5 central values of first
	int myints[] = {1776,7,4};
	third.assign (myints,myints+3);     // assigning from array.

	stream1 << "Size of first: " << int (first.size()) << '\n';
	stream1 << "Size of second: " << int (second.size()) << '\n';
	stream1 << "Size of third: " << int (third.size()) << '\n';
	return (0);
}

int test_begin (std::ofstream &stream1)
{
	std::vector<int> myvector;
  for (int i=1; i<=5; i++) myvector.push_back(i);

  stream1 << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    stream1 << ' ' << *it;
  stream1 << '\n';
  return 0;
}

int push_back(std::ofstream &stream1)
{
  std::vector<int> myvector;
  myvector.push_back (3);
  myvector.push_back (-2);
  myvector.push_back (5);
  myvector.push_back (7);
  myvector.push_back (42);

  stream1 << "myvector stores " << int(myvector.size()) << " numbers: ";
  for (unsigned int i = 0; i < myvector.size(); i++)
      stream1 << myvector[i] << " ";
  stream1 << std::endl;
	return (0);
}

int pop_back(std::ofstream &stream1)
{
  std::vector<int> myvector;
  int sum (0);
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  while (!myvector.empty())
  {
    sum+=myvector.back();
    myvector.pop_back();
  }

  stream1 << "The elements of myvector add up to " << sum << '\n';
	return (0);
}

  int	insert(std::ofstream &stream1)
{
  std::vector<int> myvector (3,100);
  std::vector<int>::iterator it;

  it = myvector.begin();
  it = myvector.insert ( it , 200 );

  myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
  it = myvector.begin();

  std::vector<int> anothervector (2,400);
  it+=2;
  myvector.insert(it,anothervector.begin(),anothervector.end());

  int myarray [] = { 501,502,503 };
  myvector.insert (myvector.begin(), myarray, myarray+3);

  stream1 << "myvector contains:";
  for (it=myvector.begin(); it<myvector.end(); it++)
    stream1 << ' ' << *it;
  stream1 << '\n';
  return (0);
}

  int erase(std::ofstream &stream1)
{
  std::vector<int> myvector;

  // set some values (from 1 to 10)
  for (int i=1; i<=10; i++) myvector.push_back(i);

  // erase the 6th element
  std::vector<int>::iterator it = myvector.begin();
  it+=5;
  myvector.erase (it);

  // erase the first 3 elements:
  it-=2;
  myvector.erase (myvector.begin(),it);

  stream1 << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    stream1 << ' ' << myvector[i];
  stream1 << '\n';
	return (0);
}

  int swap(std::ofstream &stream1)
{
  std::vector<int> foo (3,100);   // three ints with a value of 100
  std::vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  stream1 << "foo contains:";
  for (unsigned i=0; i<foo.size(); i++)
    stream1 << ' ' << foo[i];
  stream1 << '\n';

  stream1 << "bar contains:";
  for (unsigned i=0; i<bar.size(); i++)
    stream1 << ' ' << bar[i];
  stream1 << '\n';
	return (0);
}

 int clear(std::ofstream &stream1)
{
  std::vector<int> myvector;
  myvector.push_back (100);
  myvector.push_back (200);
  myvector.push_back (300);

  stream1 << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    stream1 << ' ' << myvector[i];
  stream1 << '\n';

  myvector.clear();
  myvector.push_back (1101);
  myvector.push_back (2202);

  stream1 << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); i++)
    stream1 << ' ' << myvector[i];
  stream1 << '\n';
  return (0);
}

  ////////////////     SWAP (vector)         //////////////////////////////


int	main()
{
	std::ofstream stream1;
	std::string filename = "output1";
	stream1.open(filename.c_str());
     test_iterator(stream1);
      test_operator(stream1);
     test_size(stream1);
     max_size(stream1);
     resize(stream1);
     capacity(stream1);
     empty(stream1);
     reserve(stream1);
     operator_croche(stream1);
     at(stream1);
     front(stream1);
     back(stream1);
	 test_assign(stream1);
	 test_begin(stream1);
     push_back(stream1);
     pop_back(stream1);
     insert(stream1);
     erase(stream1);
    swap(stream1);
     clear(stream1);
	// stream1 << "salut" << std::endl;
	return 0;
}