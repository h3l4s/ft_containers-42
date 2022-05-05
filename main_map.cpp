#include <map>
#include "map.hpp"
#include <iostream>
#include <string>
#include <fstream>
typedef unsigned char           unchar;
typedef unsigned short          ushort;
typedef unsigned int            uint;
typedef unsigned long           ulong;

int test_insert (std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap.insert ( ft::pair<char,int>('a',100) );
  mymap.insert ( ft::pair<char,int>('z',200) );

	stream1 << "first insert function version (single parameter):" << std::endl;
	for (ft::map<char, int>::iterator it = mymap.begin(); it !=mymap.end(); it++)
    stream1 << it->first << " => " << it->second << '\n';
  ft::pair<ft::map<char, int>::iterator,bool> ret;
  ret = mymap.insert ( ft::pair<char,int>('z',500) );
  if (ret.second==false) 
  {
 	stream1 << "element 'z' already existed";
	stream1 << " with a value of " << ret.first->second << '\n';
  }

//   // second insert function version (with hint position):
  ft::map<char, int>::iterator it = mymap.begin();
  mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
  mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
	stream1 << "second insert function version (with hint position):" << std::endl;
	for (ft::map<char, int>::iterator it = mymap.begin(); it !=mymap.end(); it++)
    stream1 << it->first << " => " << it->second << '\n';

  // third insert function version (range insertion):
  ft::map<char, int> anothermap;
  anothermap.insert(mymap.begin(),mymap.find('c'));

//   // showing contents:
  stream1 << "mymap contains:\n";
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';

  stream1 << "anothermap contains:\n";
  for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';

  return 0;
}

int test_swap (std::ostream &stream1)
{
  ft::map<char, int> foo,bar;

  foo['x']=100;
  foo['y']=200;

  bar['a']=11;
  bar['b']=22;
  bar['c']=33;

  foo.swap(bar);

  stream1 << "foo contains:\n";
  for (ft::map<char, int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';

  stream1 << "bar contains:\n";
  for (ft::map<char, int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';

  return 0;
}


int test_erase (std::ostream &stream1)
{
	ft::map<char, int> mymap;
	ft::map<char, int>::iterator it;

  // insert some values:
	mymap['a']=10;
	mymap['b']=20;
	mymap['c']=30;
	mymap['d']=40;
	mymap['e']=50;
	mymap['f']=60;

 it=mymap.find('b');
  mymap.erase (it);                   // erasing by iterator

  mymap.erase ('c');                  // erasing by key

  it=mymap.find ('e');
  mymap.erase ( it, mymap.end() );    // erasing by range

  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';
	return 0;
}



int test_clear(std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap['x']=100;
  mymap['y']=200;
  mymap['z']=300;

  stream1 << "mymap contains:\n";
  for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';

  mymap.clear();
  mymap['a']=1101;
  mymap['b']=2202;

  stream1 << "mymap contains:\n";
  for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';
  return 0;
}

int test_find (std::ostream &stream1)
{
  ft::map<char, int> mymap;
  ft::map<char, int>::iterator it;

  mymap['a']=50;
  mymap['b']=100;
  mymap['c']=150;
  mymap['d']=200;

  it = mymap.find('b');
  if (it != mymap.end())
    mymap.erase (it);

  // print content:
  stream1 << "elements in mymap:" << '\n';
  stream1 << "a => " << mymap.find('a')->second << '\n';
  stream1 << "c => " << mymap.find('c')->second << '\n';
  stream1 << "d => " << mymap.find('d')->second << '\n';

  return 0;
}


int test_count (std::ostream &stream1)
{
  ft::map<char, int> mymap;
  char c;

  mymap ['a']=101;
  mymap ['c']=202;
  mymap ['f']=303;

  for (c='a'; c<'h'; c++)
  {
    stream1 << c;
    if (mymap.count(c)>0)
      stream1 << " is an element of mymap.\n";
    else 
      stream1 << " is not an element of mymap.\n";
  }

  return 0;
}

int test_lower_bound (std::ostream &stream1)
{
  ft::map<char, int> mymap;
  ft::map<char, int>::iterator itlow,itup;

 mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;
  itlow=mymap.lower_bound ('b');  // itlow points to b
  itup=mymap.upper_bound ('d');   // itup points to e (not d!)
  // if (itlow == mymap.end())
  // {
  //   stream1 << "THE END" << std::endl;
  //   return 0;
  // }
  stream1 << "itlow : first = " << itlow->first << " second = " << itlow->second << std::endl;
  stream1 << "itup : first = " << itup->first << " second = " << itup->second << std::endl;
  mymap.erase(itlow,itup);        // erases [itlow,itup)
  // print content:
  for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';
  return 0;
}

int test_equal_range (std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap['c']=60;
  mymap['d']=80;
  mymap['a']=20;
  mymap['e']=100;
  mymap['b']=40;

  ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> ret;
  ret = mymap.equal_range('a');

  stream1 << "lower bound points to: ";
  stream1 << ret.first->first << " => " << ret.first->second << '\n';

  stream1 << "upper bound points to: ";
  stream1 << ret.second->first << " => " << ret.second->second << '\n';

  return 0;
}

int test_empty (std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap['a']=20;
  mymap['b']=40;
  mymap['c']=60;
  mymap['d']=80;
  mymap['e']=100;

  while (!mymap.empty())
  {
    stream1 << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    mymap.erase(mymap.begin());
  }

  return 0;
}

int test_operator (std::ostream &stream1)
{
  ft::map<char, int> first;
  ft::map<char, int> second;

  first['x']=8;
  first['y']=16;
  first['z']=32;

  stream1 << "first:" << std::endl;
  for (ft::map<char, int>::iterator it = first.begin(); it !=first.end(); it++)
    stream1 << it->first << " => " << it->second << '\n';
  second=first;                // second now contains 3 ints
  first=ft::map<char, int>();  // and first is now empty
  stream1 << "second:" << std::endl;
  // print_map(first);

  stream1 << "Size of first: " << first.size() << '\n';
  stream1 << "Size of second: " << second.size() << '\n';
  return 0;
}

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

int test_constructeur(std::ostream &stream1)
{
  ft::map<char, int> first;

  first['a']=10;
  first['b']=30;
  first['c']=50;
  first['d']=70;

  ft::map<char, int> second (first.begin(),first.end());

stream1 << "first:" << std::endl;
	for (ft::map<char, int>::iterator it = first.begin(); it !=first.end(); it++)
    stream1 << it->first << " => " << it->second << '\n';
  ft::map<char, int> third (second);

  ft::map<char,int,classcomp> fourth;                 // class as Compare

  bool(*fn_pt)(char,char) = fncomp;
  ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  return 0;
}

int test_begin (std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap['b'] = 100;
  mymap['a'] = 200;
  mymap['c'] = 300;

  // show content:
  for (ft::map<char, int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    stream1 << it->first << " => " << it->second << '\n';

  return 0;
}


int test_rbegin(std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap['x'] = 100;
  mymap['y'] = 200;
  mymap['z'] = 300;

  // show content:
//   ft::map<char, int>::reverse_iterator rit = mymap.rbegin();
  ft::map<char, int>::reverse_iterator rit ;
  for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
    stream1 << rit->first << " => " << rit->second << '\n';

  return 0;
}

int test_size (std::ostream &stream1)
{
  ft::map<char, int> mymap;
  mymap['a']=101;
  mymap['b']=202;
  mymap['c']=302;

  stream1 << "mymap.size() is " << mymap.size() << '\n';

  return 0;
}

int test_max (std::ostream &stream1)
{
  int i;
  ft::map<int,int> mymap;

  if (mymap.max_size()>1000)
  {
    for (i=0; i<1000; i++) mymap[i]=0;
    stream1 << "The map contains 1000 elements.\n";
  }
  else stream1 << "The map could not hold 1000 elements.\n";

  return 0;
}


int test_operator_croche(std::ostream &stream1)
{
  ft::map<char,std::string> mymap;

  mymap['a']="an element";
  mymap['b']="another element";
  mymap['c']=mymap['b'];

  stream1 << "mymap['a'] is " << mymap['a'] << '\n';
  stream1 << "mymap['b'] is " << mymap['b'] << '\n';
  stream1 << "mymap['c'] is " << mymap['c'] << '\n';
  stream1 << "mymap['d'] is " << mymap['d'] << '\n';

  stream1 << "mymap now contains " << mymap.size() << " elements.\n";

  return 0;
}

int test_key_comp (std::ostream &stream1)
{
  ft::map<char, int> mymap;

  ft::map<char, int>::key_compare mycomp = mymap.key_comp();

  mymap['a']=100;
  mymap['b']=200;
  mymap['c']=300;

  stream1 << "mymap contains:\n";

  char highest = mymap.rbegin()->first;     // key value of last element

  ft::map<char, int>::iterator it = mymap.begin();
  do {
    stream1 << it->first << " => " << it->second << '\n';
  } while ( mycomp((*it++).first, highest) );

  stream1 << '\n';

  return 0;
}

int test_value (std::ostream &stream1)
{
  ft::map<char, int> mymap;

  mymap['x']=1001;
  mymap['y']=2002;
  mymap['z']=3003;

  stream1 << "mymap contains:\n";

	ft::pair<char,int> highest = *mymap.rbegin();          // last element

  ft::map<char, int>::iterator it = mymap.begin();
  do {
    stream1 << it->first << " => " << it->second << '\n';
  } while ( mymap.value_comp()(*it++, highest) );

  return 0;
}

int test_pair (std::ostream &stream1) 
{
  ft::pair <int,int> foo;
  ft::pair <int,int> bar;
  foo = ft::make_pair(10,20);
  bar = ft::make_pair (10,45); // ok: implicit conversion from ft::pair<double,char>

  stream1 << "foo: " << foo.first << ", " << foo.second << '\n';
  stream1 << "bar: " << bar.first << ", " << bar.second << '\n';

  return 0;
}

int  main(int argc, const char** argv)
{
	std::ofstream stream1;
	std::string filename = "output3";
	stream1.open(filename.c_str());
	  test_erase(stream1);
	 test_insert(stream1);
	 test_clear(stream1);
	 test_find(stream1);
   test_count(stream1);
   test_lower_bound(stream1);
   test_equal_range(stream1);
 test_empty(stream1);
   test_operator(stream1);
  test_swap(stream1);
	 test_constructeur(stream1);
	 test_begin(stream1);
	 test_rbegin(stream1);
	 test_size (stream1);
	 test_max(stream1);
	 test_operator_croche(stream1);
	 test_key_comp(stream1);
	 test_value(stream1);
	test_pair(stream1);
  (void)argc;
  (void)argv;
	return 0;
}