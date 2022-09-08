/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:32:46 by arudy             #+#    #+#             */
/*   Updated: 2022/09/08 10:50:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INTRO : https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/?ref=gcse
// INSERT : https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
// ERASE : https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
// REBIND : https://stackoverflow.com/questions/14148756/what-does-template-rebind-do
// https://www.programiz.com/dsa/insertion-in-a-red-black-tree
// ROTATION : https://www.codesdope.com/course/data-structures-red-black-trees-insertion/

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
			// node_pointer		_start;
			// node_pointer		_end;
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
				// _start = create_node();
				// _end = create_node();
				// _start->color = BLACK; // Maybe red
				// _end->color = BLACK; // Maybe red
				// _root = _end;
				_root = create_node();
				_size = 0;
				_comp = comp;
			}

			~red_black_tree()
			{
				// Destroy tree
			}

			node_pointer	create_node(const_reference value = value_type())
			{
				node_pointer node = _node_alloc.allocate(1);
				_node_alloc.construct(node, Node(value));
				node->color = RED;
				node->left = NULL;
				node->right = NULL;
				node->parent = NULL;
				return node;
			}

///////////////////////////////////////////////////////////////////////////////////////

	void	printHelper(node_pointer root, std::string indent, bool last)
	{
		if (root != NULL)
		{
			std::cout << indent;
			if (last)
			{
				std::cout << "R---- ";
				indent += "   ";
			}
			else
			{
				std::cout << "L---- ";
				indent += "|  ";
			}

			std::string sColor = "BLACK";
			if (root->color == RED)
				sColor = "RED";
			std::cout << root->data.second << " (" << sColor << ")" << std::endl;
			printHelper(root->left, indent, false);
			printHelper(root->right, indent, true);
		}
	}

	void	printRBTree()
	{
		if (_root)
			printHelper(_root, "", true);
	}

///////////////////////////////////////////////////////////////////////////////////////


		// ==================== Capacity
			bool	empty() const
			{
				return _size == 0;
			}

			size_type	size() const
			{
				return _size;
			}

			size_type	max_size() const
			{
				return _node_alloc.max_size();
			}

		// ==================== Accessor
		iterator	begin() // Recheck, use a funct "most left and return the parent"
		{
			// if (empty())
			// 	return end();
			// return iterator(_start->parent);
			return(iterator(_min_node()));

		}

		iterator	end() // Recheck
		{
			// return iterator(_end);
			return iterator(_max_node());
		}

		// ==================== Modifiers

		ft::pair<iterator, bool>	insert(const_reference val)
		{
			// node_pointer node = create_node(val);
			// // node_pointer tmp;

			// node_pointer y = NULL;
			// node_pointer x = _root;

			// if (empty())
			// 	return _insert_empty(node);

			// // _bst_find(node->data, &tmp);
			// // tmp = _bst_find(node->data, &tmp);

			// while (x != NULL)
			// {
			// 	y = x;
			// 	if (_comp(node->data.first, x->data.first))
			// 		x = x->left;
			// 	else if (_comp(x->data.first, node->data.first))
			// 		x = x->right;
			// 	else
			// 		return ft::make_pair(iterator(x), false);
			// }

			// node->parent = y;
			// if (_comp(y->data.first, x->data.first))
			// 	y->right  = x;
			// else
			// 	y->left = x;




			// if (tmp->data.first == node->data.first) // If a node with the same key already exist, destroy
			// {
			// 	std::cout << "Already a node : " << tmp->data.first << std::endl;
			// 	_destroy_node(node);
			// 	// _assign_leaves();
			// 	return ft::make_pair(iterator(tmp), false);
			// }

			// _bst_insert(node, &tmp);

			_bst_fix_insert(node);
			// _assign_leaves();
			_size++;
			return ft::make_pair(iterator(tmp), false);
		}

	// Private helpers
	private :

		node_pointer	_bst_find(const_reference to_find, node_pointer *x) const // Maybe not enough
		{
			node_pointer tmp = _root;
			// (void)x;
			// node_pointer min = _min_node();
			node_pointer max = _max_node();

			while (tmp != NULL)
			{
				*x = tmp;
				if (_comp(tmp->data.first, to_find.first))
					tmp = tmp->right;
				else if (_comp(to_find.first, tmp->data.first))
					tmp = tmp->left;
				else
					return tmp;
			}
			return max;
		}

		ft::pair<iterator, bool>	_insert_empty(node_pointer node)
		{
			// _root = node;
			// _root->left = _start;
			// _root->right = _end;
			// _start->parent = _root;
			// _end->parent = _root;
			// _root->color = BLACK;

			_root = node;
			_root->left = NULL;
			_root->right = NULL;
			_root->color = BLACK;

			_size++;
			return ft::make_pair(iterator(_root), true);
		}

		void	_bst_insert(node_pointer to_insert, node_pointer *parent)
		{
			to_insert->parent = *parent;
			if (_comp(to_insert->data.first, (*parent)->data.first))
				(*parent)->left = to_insert;
			else
				(*parent)->right = to_insert;
		}

		void	_bst_fix_insert(node_pointer node)
		{
			node_pointer u;

			while (node->parent && node->parent->color == RED)
			{
				if (node->parent == node->parent->parent->right) // if node parent is a right child
				{
					u = node->parent->parent->left;
					if (u && u->color == RED) // if uncle is RED
						node = _fix_red_uncle(node->parent, node->parent->parent, u);
					else // if uncle is black
					{
						if (node == node->parent->left) // if node is < node parent = right rotate
						{
							node = node->parent;
							_right_rotate(node);
						}
						_swap_colors(node->parent, node->parent->parent);
						_left_rotate(node->parent->parent);
					}
				}
				else // if node parent is a left child
				{
					u = node->parent->parent->right;
					if (u && u->color == RED) // if uncle is red
						node = _fix_red_uncle(node->parent, node->parent->parent, u);
					else
					{
						if (node == node->parent->right) // if node is > node parent = left rotate
						{
							node = node->parent;
							_left_rotate(node);
						}
						node->parent->color = BLACK;
						node->parent->parent->color = RED;
						// _swap_colors(node->parent->parent, node->parent); // Need to check
						_right_rotate(node->parent->parent);
					}
				}
				if (node == _root)
					break;
			}
			_root->color = BLACK;
		}

		void	_left_rotate(node_pointer node)
		{
			node_pointer n_right = node->right;

			node->right = n_right->left;

			if (node->right)
				node->right->parent = node;

			n_right->parent = node->parent;

			if (!node->parent)
				_root = n_right;
			else if (node == node->parent->left)
				node->parent->left = n_right;
			else
				node->parent->right = n_right;
			n_right->left = node;
			node->parent = n_right;
		}

		void	_right_rotate(node_pointer node)
		{
			node_pointer n_left = node->left;

			node->left = n_left->right;

			if (node->left)
				node->left->parent = node;

			n_left->parent = node->parent;

			if (!node->parent)
				_root = n_left;
			else if (node && node->parent && node == node->parent->left)
				node->parent->left = n_left;
			else
				node->parent->right = n_left;
			n_left->right = node;
			node->parent = n_left;
		}

		void	_swap_colors(node_pointer x, node_pointer y)
		{
			node_pointer tmp = x;

			x->color = y->color;
			y->color = tmp->color;
		}

		node_pointer	_fix_red_uncle(node_pointer p, node_pointer gp, node_pointer u)
		{
			p->color = BLACK;
			u->color = BLACK;
			gp->color = RED;
			return gp;
		}

		void	_destroy_node(node_pointer node)
		{
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}

	node_pointer	_min_node() const
	{
		node_pointer min = _root;

		while (min && min->left != NULL)
			min = min->left;
		return min;
	}

	node_pointer	_max_node() const
	{
		node_pointer max = _root;

		while (max && max->right != NULL)
			max = max->right;
		return max;
	}

	void	_assign_leaves()
	{
		node_pointer min = _min_node();
		node_pointer max = _max_node();

		std::cout << "Min : " << min->data.second << std::endl;
		std::cout << "Max : " << max->data.second << std::endl;
	}

	};
} // namespace ft


#endif
