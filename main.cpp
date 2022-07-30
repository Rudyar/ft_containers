/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/30 11:56:55 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STD__VECTOR    // A commenter pour avoir ft::vector
#ifndef STD__VECTOR
# include "vector.hpp"
# define __MACRO ft
#else
# include <vector>
# include <stack>
# include <iterator>
# include <memory>
# define __MACRO std
#endif

#include <iostream>
#include <string>
#include <stdio.h>


void print_vec(__MACRO::vector<int> vec);

int	main(void)
{
	__MACRO::vector<int> test;

	test.push_back(100);
	test.push_back(200);
	test.push_back(300);
	test.push_back(400);
	test.push_back(500);
	__MACRO::vector<int>::iterator it = test.begin();
	__MACRO::vector<int>::iterator ite = test.end();
	it++;
	it++;
	// ite--;
	test.erase(it, ite);
	print_vec(test);


	// test.pop_back();
	// test.pop_back();
	// test.pop_back();
	// std::cout << "print 1" << std::endl;
	// std::cout << "Capacity : " << test.capacity() << std::endl;
	// std::cout << "Size : " << test.size() << std::endl;
	// print_vec(test);
	// std::cout << "print 2" << std::endl;
	// test.push_back(200);
	// std::cout << "print 3" << std::endl;
	// print_vec(test);

	return 0;
}

void print_vec(__MACRO::vector<int> vec)
{
	if (vec.empty())
	{
		std::cout << "-----------------" << std::endl;
		std::cout << "Vec's empty !" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "End empty vec" << std::endl;
		return ;
	}
	else
	{
		__MACRO::vector<int>::iterator it = vec.begin();
		__MACRO::vector<int>::iterator ite = vec.end();
		std::cout << "-----------------" << std::endl;
		for (; it != ite; it++)
			std::cout << "Vec : " << *it << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << "Size : " << vec.size() << std::endl;
		std::cout << "Capacity : " << vec.capacity() << std::endl;
	}
	std::cout << "End print vec" << std::endl;
}
