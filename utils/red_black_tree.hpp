/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:32:46 by arudy             #+#    #+#             */
/*   Updated: 2022/09/01 12:22:17 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INTRO : https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/?ref=gcse
// INSERT : https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
// ERASE : https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
// REBIND : https://stackoverflow.com/questions/14148756/what-does-template-rebind-do

#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <memory>
#include <iostream>
#include <functional>
#include "pair.hpp"

enum e_color
{
	RED,
	BLACK
};

namespace ft
{
	template <typename T, class Compare, class Alloc> // T is a pair
	class red_black_tree
	{
		private : // Private nested struct, can't access outside tree, for each nodes
			struct Node
			{
				T			data;
				e_color		color;
				Node		*left;
				Node		*right;
				Node		*parent;

				// Constructor, need to modif maybe
				Node() : data(), left(NULL), right(NULL), parent(NULL) {}
			};

			typedef T												value_type;
			typedef size_t											size_type;
			typedef Alloc											allocator_type;
			typedef allocator_type::template rebind<Node>::other	node_allocator; // rebind is for allocating mem for a type that diff from the element type of the class being implemented
			typedef	Compare											compare_type;
			// More typedef ??

			Node				*_root;
			Node				*_start;
			Node				*_end;
			size_type			_size;
			allocator_type		_alloc;
			node_allocator		_node_alloc;
			compare_type		_comp;


	};



} // namespace ft


#endif
