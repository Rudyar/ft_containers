/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/11 17:21:36 by arudy            ###   ########.fr       */
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
	ft::vector<int> test (3, 100);

	test.printVec();
	std::cout << "Capacity : " << test.capacity() << std::endl;
	std::cout << "Size : " << test.size() << std::endl;
	ft::vector<int> bla(test);
	bla.push_back(10000000);
	test.printVec();
	bla.printVec();
	std::cout << "Capacity : " << bla.capacity() << std::endl;
	std::cout << "Size : " << bla.size() << std::endl;
	return 0;
}

// int	main(void)
// {
// 	std::vector<int> test;
// 	test.push_back(78);
// 	test.push_back(100);
// 	test.push_back(456);
// 	test.push_back(67);
// 	test.push_back(30);
// 	test.push_back(16);

// 	for (size_t i = 0; i < test.size(); i++)
// 		std::cout << test[i] << std::endl;

// 	std::cout << "Capacity : " << test.capacity() << std::endl;
// 	std::cout << "Size : " << test.size() << std::endl;
// 	std::vector<int> bla(test);
// 	test[0] = 10000000;

// 	for (size_t i = 0; i < bla.size(); i++)
// 		std::cout << bla[i] << std::endl;
// 	std::cout << "Capacity : " << bla.capacity() << std::endl;
// 	std::cout << "Size : " << bla.size() << std::endl;
// 	return 0;
// }
