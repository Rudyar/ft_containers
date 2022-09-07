/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:32:46 by arudy             #+#    #+#             */
/*   Updated: 2022/09/07 10:23:34 by arudy            ###   ########.fr       */
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
#include "../iterators/tree_iterator.hpp"


#include <map>

enum e_color
{
	RED,
	BLACK
};

namespace ft
{
	template <typename T, typename K, class Compare, class Alloc> // T is a pair, do I need to keep K (key type of map) ?
	class red_black_tree
	{
		private :
			typedef T						value_type;
			typedef size_t					size_type;
			typedef Alloc					allocator_type;
			typedef Compare					compare_type;
			typedef value_type*				pointer;
			typedef const value_type&		const_reference;

			// Private nested struct, can't access outside tree, for each nodes
			struct Node
			{
				value_type	data;
				e_color		color;
				Node		*left;
				Node		*right;
				Node		*parent;

				Node(const T& p = T()) : data(p), left(NULL), right(NULL), parent(NULL) {}
			};
 			// rebind is for allocating mem for a type that diff from the element type of the class being implemented
			typedef typename allocator_type::template rebind<Node>::other	node_allocator;
			typedef	Node*													node_pointer;
			// typedef typename node_allocator::pointer						node_pointer; // From les boss, need to erase i think

			node_pointer		_root;
			node_pointer		_start;
			node_pointer		_end;
			size_type			_size;
			allocator_type		_alloc;
			node_allocator		_node_alloc;
			compare_type		_comp;
			K					_key; // Not sur if needed ?

		public :
			// Define Iterators here
			typedef typename ft::tree_iterator<value_type, node_pointer, compare_type>			iterator;

			red_black_tree(const compare_type& comp = compare_type(), const allocator_type& alloc = allocator_type())
			{
				_alloc = alloc;
				_node_alloc = node_allocator();
				_start = create_node();
				_end = create_node();
				_start->color = BLACK; // Maybe red
				_end->color = BLACK; // Maybe red
				_root = _end;
				_size = 0;
				_comp = comp;
			}

			node_pointer create_node(const_reference value = value_type())
			{
				node_pointer node = _node_alloc.allocate(1);
				_node_alloc.construct(node, Node(value));
				return node;
			}

///////////////////////////////////////////////////////////////////////////////////////

	void printHelper(node_pointer root, std::string indent, bool last)
	{
		if (root != NULL)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R----";
				indent += "   ";
			}
			else
			{
				std::cout << "L----";
				indent += "|  ";
			}

			std::string sColor = "BLACK";
			if (root->color == RED)
				sColor = "RED";
			std::cout << root->data.second << "(" << sColor << ")" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

	void printRBTree()
	{
		if (_root)
			printHelper(_root, "", true);
	}

///////////////////////////////////////////////////////////////////////////////////////


		// ==================== Capacity
			bool empty() const
			{
				return _size == 0;
			}

			size_type size() const
			{
				return _size;
			}

			size_type max_size() const
			{
				return _node_alloc.max_size();
			}

		// ==================== Accessor
		iterator begin()
		{
			if (empty())
				return end();
			return iterator(_start->parent);
		}

		iterator end()
		{
			return iterator(_end); // To change
		}

		// ==================== Modifiers

		ft::pair<iterator, bool>	insert(const_reference val) // Check ret value
		{
			node_pointer node = create_node(val);
			node_pointer tmp;

			if (empty())
				return insert_empty(node);
			tmp = bst_find(node->data);
			if (tmp)
			{
				// Delete node ?
				std::cout << "Already a node\n";
				return ft::make_pair(iterator(tmp), false);
			}
			std::cout << "tmp : " << &tmp << std::endl;
			bst_insert(node, &tmp);

			// Fix violations
			_size++;
			return ft::make_pair(iterator(tmp), false);
		}

	private :

		node_pointer bst_find(const_reference to_find) const // Maybe not enough
		{
			node_pointer tmp = _root;

			while (tmp && tmp != _start && tmp != _end)
			{
				if (_comp(to_find.first, tmp->data.first))
					tmp = tmp->left;
				else if (_comp(tmp->data.first, to_find.first))
					tmp = tmp->right;
				else
					return tmp;
			}
			return NULL;
		}

		ft::pair<iterator, bool> insert_empty(node_pointer node)
		{
			_root = node;
			_root->left = _start;
			_root->right = _end;
			_start->parent = _root;
			_end->parent = _root;
			_root->color = BLACK;
			_size++;
			return ft::make_pair(iterator(_root), true);
		}

		void bst_insert(node_pointer to_insert, Node **parent)
		{
			std::cout << "bst insert\n";
			std::cout << "PArent : " << &parent << std::endl;
			// to_insert->parent = parent;
			// if (_comp(to_insert->data.first, parent->data.first))
			// {
			// 	parent->left = to_insert;
			// }
			// else
			// 	parent->right = to_insert;
			(void)to_insert;
		}

	};

} // namespace ft


#endif
