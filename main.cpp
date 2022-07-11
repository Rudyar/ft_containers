/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/11 10:41:47 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iostream>

// #define STD__VECTOR    // A commenter pour avoir ft::vector
// #ifndef STD__VECTOR
// # include "vector.hpp"
// # define __MACRO ft
// #else
// # include <vector>
// # include <stack>
// # include <iterator>
// # include <memory>
// # define __MACRO std
// #endif

// #include <iostream>
// #include <string>
// #include <stdio.h>

int	main(void)
{
	ft::vector<int> test;
	test.push_back(34);
	test.push_back(100);
	test.push_back(456);
	test.push_back(67);
	test.push_back(30);
	test.push_back(1);
	test.printVec();
	test.clear();
	test.printVec();
	test.push_back(42);
	test.push_back(42);
	test.push_back(42);
	test.push_back(42);
	test.push_back(42);
	test.printVec();
	std::cout << "Capacity : " << test.capacity() << std::endl;
	std::cout << "Size : " << test.size() << std::endl;

	return 0;
}

// int	main(void)
// {
// 	std::vector<int> test;
// 	test.push_back(34);
// 	test.push_back(33);
// 	test.push_back(32);
// 	test.push_back(31);
// 	test.push_back(30);
// 	test.push_back(35);
// 	std::cout << &test << std::endl;
// 	test.resize(7, 42);
// 	std::cout << &test << std::endl;
// 	for (size_t i = 0; i < test.size(); i++)
// 		std::cout << test[i] << std::endl;
// 	std::cout << "Capacity : " << test.capacity() << std::endl;
	// std::cout << "Size : " << test.size() << std::endl;
// 	return 0;
// }
