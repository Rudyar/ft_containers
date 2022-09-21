/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/09/21 15:46:01 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define STD    // A commenter pour avoir ft
#ifndef STD
# include "include/vector.hpp"
# include "include/stack.hpp"
# include "include/map.hpp"
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

#define T1 char
#define T2 int

void vector_tests();
void stack_tests();
void map_tests();
void print_vec(__MACRO::vector<int> vec);
void print_map(__MACRO::map<T1, T2> map);

///////////////////////////////////////////////////////////////////////////////////////////////

int	main(void)
{
	// Recheck friend keywords
	// Recheck all !
	vector_tests();
	stack_tests();
	map_tests();

	return 0;
}


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

void print_map(__MACRO::map<T1, T2> map)
{
	if (map.empty())
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Map empty !" << std::endl;
		std::cout << "-----------------" << std::endl;
	}
	else
	{
		__MACRO::map<T1, T2>::iterator it = map.begin();
		__MACRO::map<T1, T2>::iterator ite = map.end();
		std::cout << "=====================================" << std::endl;
		std::cout << "Size : " << map.size() << std::endl;
		std::cout << "Max size : " << map.max_size() << std::endl;
		for (; it != ite; it++)
			std::cout << it->second << " | ";
		std::cout << std::endl << "=====================================" << std::endl;
	}
}

// Functions from cpp ref for tests
bool fncomp (char lhs,char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void	map_tests(void)
{
	std::cout << "------------------------------------------------------------------" << std::endl;
	std::cout << "---------------             MAP TESTS            ---------------" << std::endl;
	std::cout << "------------------------------------------------------------------" << std::endl;
	{
		std::cout << "                          CONSTRUCTORS                      " << std::endl;

		__MACRO::map<T1, T2> first; // Default ctor

		first['a']=10;
		first['b']=30;
		first['c']=50;
		first['d']=70;

		__MACRO::map<T1, T2> second (first.begin(),first.end()); // Range ctor

		__MACRO::map<T1, T2> third (second); // Cpy ctor

		__MACRO::map<T1, T2,classcomp> fourth;                 // add class as Compare

		bool(*fn_pt)(char,char) = fncomp;
		__MACRO::map<T1, T2, bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
		print_map(first);
		print_map(second);
		print_map(third);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          OPERATOR =                      " << std::endl;

		__MACRO::map<T1, T2> first; // Default ctor
		__MACRO::map<T1, T2> second; // Default ctor

		first['x']=8;
		first['y']=16;
		first['z']=32;

		second = first; // second now contains 3 ints from first
		first = __MACRO::map<T1, T2>();
		print_map(first);
		print_map(second);
	}
	std::cout << "---------------       MAP ITERATORS TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          BEGIN                      " << std::endl;

		__MACRO::map<T1, T2> map; // Default ctor

		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		__MACRO::map<T1, T2>::iterator it = map.begin();
		std::cout << "it begin : " << it->first << std::endl;
		for (; it != map.end(); it++)
			std::cout << "it->first : " << it->first << " it->second : " << it->second << std::endl;

		std::cout << "\nTest it = const it\n";
		it = map.begin();
		__MACRO::map<T1, T2>::const_iterator cit = map.begin();
		std::cout << "it begin : " << it->first << std::endl;
		std::cout << "cit begin : " << cit->first << std::endl;
		std::cout << "it == cit ? : " << (it == cit) << std::endl;
		cit++;
		std::cout << "it == cit ? : " << (it == cit) << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          END                      " << std::endl;

		__MACRO::map<T1, T2> map; // Default ctor

		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		__MACRO::map<T1, T2>::iterator ite = map.end();
		// May be have diff between it from ft and std when pointing to end(), mine is NULL and std is EOT
		for (; ite != map.begin(); --ite)
			std::cout << "ite->first : " << ite->first << " ite->second : " << ite->second << std::endl;


		std::cout << "\nTest ite = const ite\n";
		ite = map.end();
		__MACRO::map<T1, T2>::const_iterator cite = map.end();
		ite--;
		cite--;
		std::cout << "ite : " << ite->first << std::endl;
		std::cout << "cite : " << cite->first << std::endl;
		std::cout << "ite == cite ? : " << (ite == cite) << std::endl;
		cite--;
		std::cout << "ite == cite ? : " << (ite == cite) << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          RBEGIN & REND                      " << std::endl;
		__MACRO::map<T1, T2> map; // Default ctor

		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		__MACRO::map<T1, T2>::reverse_iterator rit = map.rbegin();
		__MACRO::map<T1, T2>::reverse_iterator rite = map.rend();
		for (; rit != rite; ++rit)
			std::cout << "rit->first : " << rit->first << " rit->second : " << rit->second << std::endl;

		__MACRO::map<T1, T2>::const_reverse_iterator crit = map.rbegin();

		std::cout << "rit == crit ? : " << (rit == crit) << std::endl;
		rit = map.rbegin();
		rit++;
		crit++;
		std::cout << "rit == crit ? : " << (rit == crit) << std::endl;

	}
	std::cout << "---------------       MAP CAPACITY TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          EMPTY                      " << std::endl;
		__MACRO::map<T1, T2> map; // Default ctor

		std::cout << "Map is empty ? " << map.empty() << std::endl;

		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		std::cout << "Map is empty ? " << map.empty() << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          SIZE                      " << std::endl;
		__MACRO::map<T1, T2> map; // Default ctor

		std::cout << "Map size : " << map.size() << std::endl;

		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		std::cout << "Map size : " << map.size() << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          MAX_SIZE                      " << std::endl;
		__MACRO::map<T1, T2> map; // Default ctor

		std::cout << "Map max_size : " << map.max_size() << std::endl;

		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		std::cout << "Map max_size : " << map.max_size() << std::endl;
	}
	std::cout << "---------------       MAP ELEMENTS ACCES TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          OP []                      " << std::endl;
		__MACRO::map<T1, T2> map; // Default ctor
		map['w'] = 4;
		map['x'] = 8;
		map['y'] = 16;
		map['z'] = 32;

		std::cout << "map['w'] : " << map['w'] << std::endl;
		std::cout << "map['x'] : " << map['x'] << std::endl;
		std::cout << "map['y'] : " << map['y'] << std::endl;
		std::cout << "map['z'] : " << map['z'] << std::endl;
		std::cout << "map['a'] : " << map['a'] << std::endl;
	}
	std::cout << "---------------       MAP MODIFIERS TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          INSERT (single param)                      " << std::endl;
		__MACRO::map<T1, T2> map;
		map.insert(__MACRO::pair<T1, T2> ('1', 1));
		map.insert(__MACRO::pair<T1, T2> ('2', 22));
		map.insert(__MACRO::pair<T1, T2> ('3', 333));
		map.insert(__MACRO::pair<T1, T2> ('4', 4444));
		map.insert(__MACRO::pair<T1, T2> ('5', 55555));
		__MACRO::pair<__MACRO::map<T1, T2>::iterator, bool> ret;
		ret = map.insert(__MACRO::pair<T1, T2> ('2', 22));
		if (ret.second == false)
			std::cout << "Elem : " << ret.first->second << " is already in map\n";
		print_map(map);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          INSERT (pos + param)                      " << std::endl;
		__MACRO::map<T1, T2> map;
		__MACRO::map<T1, T2>::iterator it = map.begin();

		map.insert(it, __MACRO::pair<T1, T2> ('1', 1));
		map.insert(it, __MACRO::pair<T1, T2> ('2', 22));
		map.insert(it, __MACRO::pair<T1, T2> ('3', 333));
		it++;
		it++;
		map.insert(it, __MACRO::pair<T1, T2> ('4', 4444));
		it--;
		map.insert(it, __MACRO::pair<T1, T2> ('5', 55555));
		__MACRO::pair<__MACRO::map<T1, T2>::iterator, bool> ret;
		ret = map.insert(__MACRO::pair<T1, T2> ('2', 22));
		if (ret.second == false)
			std::cout << "Elem : " << ret.first->second << " is already in map\n";
		print_map(map);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          INSERT (range it)                      " << std::endl;
		__MACRO::map<T1, T2> map;
		__MACRO::map<T1, T2> mapp;

		map.insert(__MACRO::pair<T1, T2> ('1', 1));
		map.insert(__MACRO::pair<T1, T2> ('2', 22));
		map.insert(__MACRO::pair<T1, T2> ('3', 333));
		map.insert(__MACRO::pair<T1, T2> ('4', 4444));
		map.insert(__MACRO::pair<T1, T2> ('5', 55555));
		__MACRO::map<T1, T2>::iterator it = map.end();
		--(--it);
		mapp.insert(map.begin(), it);
		print_map(map);
		print_map(mapp);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          ERASE (pos)                      " << std::endl;
		__MACRO::map<T1, T2> map;

		map.insert(__MACRO::pair<T1, T2> ('1', 1));
		map.insert(__MACRO::pair<T1, T2> ('2', 22));
		map.insert(__MACRO::pair<T1, T2> ('3', 333));
		map.insert(__MACRO::pair<T1, T2> ('4', 4444));
		map.insert(__MACRO::pair<T1, T2> ('5', 55555));
		print_map(map);
		__MACRO::map<T1, T2>::iterator it = map.begin();
		map.erase(it);
		it = map.begin();
		map.erase(it);
		print_map(map);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          ERASE (key)                      " << std::endl;
		__MACRO::map<T1, T2> map;

		map.insert(__MACRO::pair<T1, T2> ('1', 1));
		map.insert(__MACRO::pair<T1, T2> ('2', 22));
		map.insert(__MACRO::pair<T1, T2> ('3', 333));
		map.insert(__MACRO::pair<T1, T2> ('4', 4444));
		map.insert(__MACRO::pair<T1, T2> ('5', 55555));
		print_map(map);
		std::cout << "Ret from erase by key : " << map.erase('1') << std::endl;
		std::cout << "Ret from erase by key : " << map.erase('9') << std::endl;
		print_map(map);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          ERASE (range it)                      " << std::endl;
		__MACRO::map<T1, T2> map;

		map.insert(__MACRO::pair<T1, T2> ('1', 1));
		map.insert(__MACRO::pair<T1, T2> ('2', 22));
		map.insert(__MACRO::pair<T1, T2> ('3', 333));
		map.insert(__MACRO::pair<T1, T2> ('4', 4444));
		map.insert(__MACRO::pair<T1, T2> ('5', 55555));
		print_map(map);
		__MACRO::map<T1, T2>::iterator it = map.begin();
		__MACRO::map<T1, T2>::iterator ite = map.end();
		map.erase(++it, --ite);
		print_map(map);
		map.erase(map.begin(), map.end());
		print_map(map);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          SWAP (member function)                      " << std::endl;
		__MACRO::map<T1, T2> foo;
		__MACRO::map<T1, T2> bar;

		foo['1'] = 1;
		foo['2'] = 22;

		bar['7'] = 7777777;
		bar['8'] = 88888888;
		bar['9'] = 999999999;

		std::cout << "Print foo before swap\n";
		print_map(foo);
		std::cout << "Print bar before swap\n";
		print_map(bar);
		foo.swap(bar);
		std::cout << "Print foo after swap\n";
		print_map(foo);
		std::cout << "Print bar after swap\n";
		print_map(bar);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          SWAP (function template)                      " << std::endl;
		__MACRO::map<T1, T2> foo;
		__MACRO::map<T1, T2> bar;

		foo['1'] = 1;
		foo['2'] = 22;

		bar['7'] = 7777777;
		bar['8'] = 88888888;
		bar['9'] = 999999999;

		std::cout << "Print foo before swap\n";
		print_map(foo);
		std::cout << "Print bar before swap\n";
		print_map(bar);
		swap(foo, bar);
		std::cout << "Print foo after swap\n";
		print_map(foo);
		std::cout << "Print bar after swap\n";
		print_map(bar);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          CLEAR                      " << std::endl;
		__MACRO::map<T1, T2> map;

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;

		std::cout << "Print map before clear\n";
		print_map(map);
		map.clear();
		std::cout << "Print map after clear\n";
		print_map(map);
		map['6'] = 666666;
		map['7'] = 7777777;
		map['8'] = 88888888;
		std::cout << "Print map after add some elem\n";
		print_map(map);
	}
	std::cout << "---------------       MAP OBSERVERS TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          KEY_COMP                      " << std::endl;
		// Key comp return copy object used by the container
		__MACRO::map<T1, T2> map;
		__MACRO::map<T1, T2>::key_compare comp = map.key_comp();

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;

		std::cout << "Map contains :\n";

		char highest = map.rbegin()->first;
		__MACRO::map<T1, T2>::iterator it = map.begin();

		while (comp((*it++).first, highest))
			std::cout << "it first : " << it->first << " it second : " << it->second << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          VALUE_COMP                      " << std::endl;
		// Val comp return object to compare two keys
		__MACRO::map<T1, T2> map;

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;

		std::cout << "Map contains :\n";

		__MACRO::pair<T1, T2> highest = *map.rbegin();
		__MACRO::map<T1, T2>::iterator it = map.begin();

		while (map.value_comp()(*it++, highest))
			std::cout << "it first : " << it->first << " it second : " << it->second << std::endl;
	}
	std::cout << "---------------       MAP OPERATIONS TESTS       ---------------" << std::endl << std::endl;
	{
		std::cout << "                          FIND                      " << std::endl;
		__MACRO::map<T1, T2> map;

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;
		__MACRO::map<T1, T2>::iterator it = map.find('5');
		std::cout << "Classic Iterator\n";

		if (it != map.end())
			std::cout << it->first << " found in map\n";
		else
			std::cout << "Not found in map\n";
		it = map.find('0');
		if (it != map.end())
			std::cout << it->first << " found in map\n";
		else
			std::cout << "Not found in map\n";

		std::cout << "Const Iterator\n";

		__MACRO::map<T1, T2>::const_iterator cit = map.find('1');
		if (cit != map.end())
			std::cout << cit->first << " found in map\n";
		else
			std::cout << "Not found in map\n";
		cit = map.find('9');
		if (cit != map.end())
			std::cout << cit->first << " found in map\n";
		else
			std::cout << "Not found in map\n";
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          COUNT                      " << std::endl;
		__MACRO::map<T1, T2> map;

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;

		for (char c = '1'; c < '9'; c++)
		{
			if (map.count(c) > 0)
				std::cout << c << " is an element of map\n";
			else
				std::cout << c << " is not an element of map\n";
		}
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          LOWER & UPPER BOUNDS                      " << std::endl;
		// Lower ret it to first elem whose key is not going before k, end() if all keys go before k
		// Upper ret it to first elem whose key is going after k
		__MACRO::map<T1, T2> map;
		__MACRO::map<T1, T2>::iterator itlow, itup;

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;
		itlow = map.lower_bound('2');
		itup = map.upper_bound('4');

		std::cout << "Erase from lower_bound (2) to upper_bound(4)\n";
		map.erase(itlow, itup);
		print_map(map);
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          EQUAL_RANGE                      " << std::endl;
		// Ret pair of it that includes elems which have key == k
		__MACRO::map<T1, T2> map;
		__MACRO::pair<__MACRO::map<T1, T2>::iterator, __MACRO::map<T1, T2>::iterator> ret;

		map['1'] = 1;
		map['2'] = 22;
		map['3'] = 333;
		map['4'] = 4444;
		map['5'] = 55555;
		ret = map.equal_range('3');
		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          RELATIONAL OP                      " << std::endl;
		__MACRO::map<T1, T2> map, map1, map2;

		map['5'] = 55555;
		map['0'] = 0;
		map['9'] = 999999999;

		map1['6'] = 666666;
		map1['0'] = 0;
		map1['8'] = 88888888;

		map2 = map;
		std::cout << "map" << std::endl;
		print_map(map);
		std::cout << "map1" << std::endl;
		print_map(map1);
		std::cout << "map2" << std::endl;
		print_map(map2);

		std::cout << "map == map1 = " << (map == map1) << std::endl;
		std::cout << "map != map1 = " << (map != map1) << std::endl;
		std::cout << "map < map1 = " << (map < map1) << std::endl;
		std::cout << "map <= map1 = " << (map <= map1) << std::endl;
		std::cout << "map > map1 = " << (map > map1) << std::endl;
		std::cout << "map >= map1 = " << (map >= map1) << std::endl << std::endl;

		std::cout << "map == map2 = " << (map == map2) << std::endl;
		std::cout << "map != map2 = " << (map != map2) << std::endl;
		std::cout << "map < map2 = " << (map < map2) << std::endl;
		std::cout << "map <= map2 = " << (map <= map2) << std::endl;
		std::cout << "map > map2 = " << (map > map2) << std::endl;
		std::cout << "map >= map2 = " << (map >= map2) << std::endl;
	}
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          INSERT 1000000 elems                      " << std::endl;
		__MACRO::map<int, int> map;
		for (int i = 0; i < 1000000; i++)
			map[i] = i;
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
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

/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////


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
	std::cout << "------------------------------------------------------------------" << std::endl << std::endl;
	{
		std::cout << "                          INSERT 1000000 elems                      " << std::endl;
		__MACRO::vector<int> vec;
		for (int i = 0; i < 1000000; i++)
			vec.push_back(i);
	}
}
