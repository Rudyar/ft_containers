/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/08/31 10:17:31 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STD__VECTOR    // A commenter pour avoir ft::vector
#ifndef STD__VECTOR
# include "vector.hpp"
# include "stack.hpp"
# define __MACRO ft
#else
# include <vector>
# include <stack>
# include <map>
# include <iterator>
# include <memory>
# define __MACRO std
#endif

#include <iostream>
#include <string>
#include <stdio.h>
#include <deque>
#include <list>

void vector_tests();
void stack_tests();

void print_vec(__MACRO::vector<int> vec)
{
	if (vec.empty())
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Vec's empty !" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	else
	{
		__MACRO::vector<int>::iterator it = vec.begin();
		__MACRO::vector<int>::iterator ite = vec.end();
		std::cout << "-----------------" << std::endl;
		std::cout << "Size : " << vec.size() << std::endl;
		std::cout << "Capacity : " << vec.capacity() << std::endl;
		for (; it != ite; it++)
			std::cout << *it << " ";
		std::cout << std::endl << "-----------------" << std::endl;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	__MACRO::map<int, std::string> test;
	test.insert(std::pair<int, std::string>(1, "coucou"));
	test.insert(std::pair<int, std::string>(10, "salut"));
	test.insert(std::pair<int, std::string>(-10, "salut"));

	__MACRO::map<int, std::string>::iterator it;
	for (it = test.begin(); it != test.end(); it++)
		std::cout << "Key : " << it->first << " Value : " << it->second << std::endl;

	// vector_tests();
	// stack_tests();
	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////

void	stack_tests(void)
{
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "---------------             STACK TESTS            ---------------" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
	{
		std::cout << "                          CONSTRUCTORS                      " << std::endl;
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		__MACRO::vector<int> myvector (2,200);        // vector with 2 elements

		__MACRO::stack<int> first;                    // empty stack
		__MACRO::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

		__MACRO::stack<int,__MACRO::vector<int> > third;  // empty stack using vector
		__MACRO::stack<int,__MACRO::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          EMPTY                      " << std::endl;
		__MACRO::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++)
			mystack.push(i);
		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}
		std::cout << "total: " << sum << '\n';
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          SIZE                      " << std::endl;
		__MACRO::stack<int> myints;

		std::cout << "0. size: " << myints.size() << '\n';
		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          TOP                      " << std::endl;
		__MACRO::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          PUSH & POP                      " << std::endl;
		__MACRO::stack<int> mystack;

		for (int i=0; i<5; ++i)
			mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          RELATIONAL OPERATOR                      " << std::endl;
		__MACRO::stack<int> foo;
		__MACRO::stack<int> bar;

		foo.push(100);
		foo.push(100);
		foo.push(100);

		bar.push(200);
		bar.push(200);

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
}

void	vector_tests(void)
{
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "---------------            VECTOR TESTS            ---------------" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
	{
		std::cout << "                          CONSTRUCTORS                      " << std::endl;
		__MACRO::vector<int> first;                                // empty vector of ints
		__MACRO::vector<int> second (4,100);                       // four ints with value 100
		__MACRO::vector<int> third (second.begin(),second.end());  // iterating through second
		__MACRO::vector<int> fourth (third);                       // a copy of third


		int myints[] = {16,2,77,29};
		__MACRO::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

		std::cout << "The contents of fifth are:";
		for (__MACRO::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	}
	{
		std::cout << "                          OPERATOR =                      " << std::endl;
		__MACRO::vector<int> foo (3,0);
		__MACRO::vector<int> bar (5,0);

		bar = foo;
		foo = __MACRO::vector<int>();

		std::cout << "Size of foo: " << int(foo.size()) << '\n';
		std::cout << "Size of bar: " << int(bar.size()) << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	std::cout << "---------------       VECTOR ITERATORS TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          BEGIN                      " << std::endl;
		__MACRO::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (__MACRO::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          END                      " << std::endl;
		__MACRO::vector<int> myvector;
		for (int i=1; i<=5; i++) myvector.push_back(i);

		std::cout << "myvector contains:";
		for (__MACRO::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          RBEGIN                      " << std::endl;
		__MACRO::vector<int> myvector (5);  // 5 default-constructed ints

		int i=0;

		__MACRO::vector<int>::reverse_iterator rit = myvector.rbegin();
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (__MACRO::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          REND                      " << std::endl;
		__MACRO::vector<int> myvector (5);  // 5 default-constructed ints

		__MACRO::vector<int>::reverse_iterator rit = myvector.rbegin();

		int i=0;
		for (; rit!= myvector.rend(); ++rit)
			*rit = ++i;

		std::cout << "myvector contains:";
		for (__MACRO::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	std::cout << "---------------        VECTOR CAPACITY TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          SIZE                      " << std::endl;
		__MACRO::vector<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<10; i++) myints.push_back(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.insert (myints.end(),10,100);
		std::cout << "2. size: " << myints.size() << '\n';

		myints.pop_back();
		std::cout << "3. size: " << myints.size() << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          MAX_SIZE                      " << std::endl;
		__MACRO::vector<int> myvector;

		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << myvector.size() << "\n";
		std::cout << "capacity: " << myvector.capacity() << "\n";
		std::cout << "max_size: " << myvector.max_size() << "\n";
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          RESIZE                      " << std::endl;
		__MACRO::vector<int> myvector;

		for (int i=1;i<10;i++) myvector.push_back(i);

		myvector.resize(5);
		myvector.resize(8,100);
		myvector.resize(12);

		std::cout << "myvector contains:";
		for (size_t i=0;i<myvector.size();i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                        CAPACITY                      " << std::endl;
		__MACRO::vector<int> myvector;

		// set some content in the vector:
		for (int i=0; i<100; i++) myvector.push_back(i);

		std::cout << "size: " << (int) myvector.size() << '\n';
		std::cout << "capacity: " << (int) myvector.capacity() << '\n';
		std::cout << "max_size: " << (int) myvector.max_size() << '\n';
	}
	{
		std::cout << "                          EMPTY                      " << std::endl;
		__MACRO::vector<int> myvector;
		int sum (0);

		for (int i=1;i<=10;i++) myvector.push_back(i);

		while (!myvector.empty())
		{
			sum += myvector.back();
			myvector.pop_back();
		}

		std::cout << "total: " << sum << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          RESERVE                      " << std::endl;
		__MACRO::vector<int>::size_type sz;

		__MACRO::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i)
		{
			foo.push_back(i);
			if (sz!=foo.capacity())
			{
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}

		__MACRO::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i)
		{
			bar.push_back(i);
			if (sz!=bar.capacity())
			{
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << '\n';
			}
		}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	std::cout << "---------------    VECTOR ELEMENTS ACCESS TESTS    ---------------" << std::endl << std::endl;

	{
		std::cout << "                          OPERATEUR[]                      " << std::endl;
		__MACRO::vector<int> myvector (10);   // 10 zero-initialized elements

		__MACRO::vector<int>::size_type sz = myvector.size();

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

		std::cout << "myvector contains:";
		for (unsigned i=0; i<sz; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          AT                      " << std::endl;
		__MACRO::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
			myvector.at(i)=i;

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector.at(i);
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          FRONT                      " << std::endl;
		__MACRO::vector<int> myvector;

		myvector.push_back(78);
		myvector.push_back(16);

		// now front equals 78, and back 16

		myvector.front() -= myvector.back();

		std::cout << "myvector.front() is now " << myvector.front() << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          BACK                      " << std::endl;
		__MACRO::vector<int> myvector;

		myvector.push_back(10);

		while (myvector.back() != 0)
		{
			myvector.push_back ( myvector.back() -1 );
		}

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size() ; i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	std::cout << "---------------       VECTOR MODIFIERS TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          ASSIGN                      " << std::endl;
		__MACRO::vector<int> first;
		__MACRO::vector<int> second;
		__MACRO::vector<int> third;

		first.assign (7,100);             // 7 ints with a value of 100

		__MACRO::vector<int>::iterator it;
		it=first.begin()+1;

		second.assign (it,first.end()-1); // the 5 central values of first

		int myints[] = {1776,7,4};
		third.assign (myints,myints+3);   // assigning from array.

		std::cout << "Size of first: " << int (first.size()) << '\n';
		std::cout << "Size of second: " << int (second.size()) << '\n';
		std::cout << "Size of third: " << int (third.size()) << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          PUSH_BACK                      " << std::endl;
		__MACRO::vector<int> myvector;

		for (int i = 0; i < 10; i++)
		{
			myvector.push_back(i);
		}
		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          POP_BACK                      " << std::endl;
		__MACRO::vector<int> myvector;
		int sum (0);
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		while (!myvector.empty())
		{
			sum+=myvector.back();
			myvector.pop_back();
		}

		std::cout << "The elements of myvector add up to " << sum << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          INSERT                      " << std::endl;
		__MACRO::vector<int> myvector (3,100);
		__MACRO::vector<int>::iterator it;

		it = myvector.begin();
		it = myvector.insert ( it , 200 );

		myvector.insert (it,2,300);

		// "it" no longer valid, get a new one:
		it = myvector.begin();

		__MACRO::vector<int> anothervector (2,400);
		myvector.insert (it+2,anothervector.begin(),anothervector.end());

		int myarray [] = { 501,502,503 };
		myvector.insert (myvector.begin(), myarray, myarray+3);

		std::cout << "myvector contains:";
		for (it=myvector.begin(); it<myvector.end(); it++)
			std::cout << ' ' << *it;
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          ERASE                      " << std::endl;
		__MACRO::vector<int> myvector;

		// set some values (from 1 to 10)
		for (int i=1; i<=10; i++) myvector.push_back(i);

		// erase the 6th element
		myvector.erase (myvector.begin()+5);

		// erase the first 3 elements:
		myvector.erase (myvector.begin(),myvector.begin()+3);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); ++i)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          SWAP                      " << std::endl;
		__MACRO::vector<int> foo (3,100);   // three ints with a value of 100
		__MACRO::vector<int> bar (5,200);   // five ints with a value of 200

		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << '\n';

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          CLEAR                      " << std::endl;
		__MACRO::vector<int> myvector;
		myvector.push_back (100);
		myvector.push_back (200);
		myvector.push_back (300);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';

		myvector.clear();
		myvector.push_back (1101);
		myvector.push_back (2202);

		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
			std::cout << ' ' << myvector[i];
		std::cout << '\n';
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	{
		std::cout << "                          RELATIONAL OPERATOR                      " << std::endl;
		__MACRO::vector<int> foo (3,100);   // three ints with a value of 100
		__MACRO::vector<int> bar (2,200);   // two ints with a value of 200

		if (foo==bar) std::cout << "foo and bar are equal\n";
		if (foo!=bar) std::cout << "foo and bar are not equal\n";
		if (foo< bar) std::cout << "foo is less than bar\n";
		if (foo> bar) std::cout << "foo is greater than bar\n";
		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;

	}
	std::cout << "\n\n";
	std::cout << "==================================================================" << std::endl;
	std::cout << "==================================================================";
	std::cout << "\n\n\n";
}
