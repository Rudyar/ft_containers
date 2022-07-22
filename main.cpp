/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/22 14:34:22 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define STD__VECTOR    // A commenter pour avoir ft::vector
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

int	main(void)
{
	__MACRO::vector<int> test;
	test.push_back(1);
	test.push_back(34);
	test.push_back(300);
	test.push_back(400);

	__MACRO::vector<int>::reverse_iterator iter = test.rbegin();
	__MACRO::vector<int>::iterator iter2 = test.end();
	// __MACRO::vector<int>::reverse_iterator iter2 = test.rbegin();
	// --iter;
	std::cout << *iter << std::endl;
	std::cout << *iter2 << std::endl;

	// static_cast<void>(iter);
	// test.printVec();
	// std::cout << "Capacity : " << test.capacity() << std::endl;
	// std::cout << "Size : " << test.size() << std::endl;
	// ft::vector<int> bla(test);
	// bla.push_back(10000000);
	// test.printVec();
	// bla.printVec();
	// std::cout << "Capacity : " << bla.capacity() << std::endl;
	// std::cout << "Size : " << bla.size() << std::endl;
	return 0;
}
