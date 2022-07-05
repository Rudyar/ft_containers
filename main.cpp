/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:25:13 by arudy             #+#    #+#             */
/*   Updated: 2022/07/05 17:45:10 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
// #include <iostream>

int	main(void)
{
	ft::vector<int> test;
	test.push_back(34);
	test.push_back(33);
	test.push_back(32);
	test.push_back(31);
	test.push_back(30);
	test.push_back(35);
	test.printVec();
	std::cout << "Capacity : " << test.capacity() << std::endl;
	std::cout << "Max size : " << test.max_size() << std::endl;
	return 0;
}

// int	main(void)
// {
// 	std::vector<int> test;
// 	test.push_back(34);
// 	test.push_back(34);
// 	test.push_back(34);
// 	test.push_back(34);
// 	test.push_back(34);
// 	// test.push_back(34);
// 	std::cout << test.capacity() << std::endl;
// 	return 0;
// }
