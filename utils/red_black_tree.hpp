/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:32:46 by arudy             #+#    #+#             */
/*   Updated: 2022/09/10 12:38:05 by arudy            ###   ########.fr       */
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
	template <typename T, class Compare> // T is a pair
	class red_black_tree
	{
		private :
			typedef T	value_type;

			// Private nested struct, for each nodes
			struct Node
			{
				value_type	data;
				e_color		color;
				Node		*left;
				Node		*right;
				Node		*parent;

				Node(const value_type& p = value_type()) : data(p), left(NULL), right(NULL), parent(NULL) {}
			};

			typedef size_t							size_type;
			typedef Compare							compare_type;
			typedef value_type*						pointer;
			typedef	Node*							node_pointer;
			typedef const value_type&				const_reference;
			typedef typename std::allocator<Node>	node_allocator;
			typedef const Node*						const_node_pointer;

			node_pointer		_root;
			node_pointer		_end;
			size_type			_size;
			node_allocator		_node_alloc;
			compare_type		_comp;

		public :
			// Define Iterators here
			typedef typename ft::tree_iterator<value_type, node_pointer, compare_type>			iterator;
			typedef typename ft::tree_iterator<const value_type, node_pointer, compare_type>	const_iterator;

			red_black_tree(const compare_type& comp = compare_type(), const node_allocator& node_alloc = node_allocator())
			{
				_node_alloc = node_alloc;
				_end = create_node();
				_root = _end;
				_size = 0;
				_comp = comp;
			}

			~red_black_tree()
			{
				if (_size)
					clear();
				// _destroy_node(_end);
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

			void	print_red_black_tree()
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
		iterator	begin()
		{
			return iterator(_min_node());

		}

		const_iterator	begin() const
		{
			return const_iterator(_min_node());
		}

		iterator	end()
		{
			return iterator(_end);
		}

		const_iterator	end() const
		{
			return const_iterator(_end);
		}

		// ==================== Modifiers

		ft::pair<iterator, bool>	insert(const_reference val)
		{
			node_pointer node = create_node(val);
			node_pointer tmp = _root;
			node_pointer parent = NULL;

			if (empty())
				return _insert_empty(node);
			while (tmp != NULL && tmp != _end) // Find if already a node with the same key, if not, give pos for new node
			{
				parent = tmp;
				if (_comp(val.first, tmp->data.first))
					tmp = tmp->left;
				else if (_comp(tmp->data.first, val.first))
					tmp = tmp->right;
				else
				{
					_destroy_node(node);
					_assign_end();
					return ft::make_pair(iterator(tmp), false); // already a node
				}
			}
			node->parent = parent;
			if (_comp(val.first, parent->data.first))
				parent->left = node;
			else
				parent->right = node;
			_bst_fix_insert(node);
			_assign_end();
			_size++;
			return ft::make_pair(iterator(node), true);
		}

		void	clear()
		{
			_clear(_root);
			_root = _end;
			_size = 0;
		}

	// Private helpers
	private :

		// node_pointer	_bst_find(const_reference to_find, node_pointer *x) const // Maybe not enough
		// {
		// 	node_pointer tmp = _root;
		// 	// (void)x;
		// 	// node_pointer min = _min_node();
		// 	node_pointer max = _max_node();

		// 	while (tmp != NULL)
		// 	{
		// 		*x = tmp;
		// 		if (_comp(tmp->data.first, to_find.first))
		// 			tmp = tmp->right;
		// 		else if (_comp(to_find.first, tmp->data.first))
		// 			tmp = tmp->left;
		// 		else
		// 			return tmp;
		// 	}
		// 	return max;
		// }

		ft::pair<iterator, bool>	_insert_empty(node_pointer node)
		{
			_root = node;
			_root->left = NULL;
			_root->right = _end;
			_end->parent = _root;
			_root->color = BLACK;
			_size++;
			return ft::make_pair(iterator(_root), true);
		}

		void	_bst_fix_insert(node_pointer node)
		{
			while (node->parent && node->parent->color == RED)
			{
				if (node->parent->parent->left == node->parent) // if node parent is a left node
				{
					if (node->parent->parent->right && node->parent->parent->right->color == RED) // if uncle right is red
						node = _fix_red_uncle(node->parent, node->parent->parent, node->parent->parent->right); // p gp u
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							_left_rotate(node);
						}
						_assign_colors_p_gp(node->parent, node->parent->parent);
						_right_rotate(node->parent->parent);
					}
				}
				else // if node is a right node
				{
					if (node->parent->parent->left && node->parent->parent->left->color == RED) // if uncle left is red
						node = _fix_red_uncle(node->parent, node->parent->parent, node->parent->parent->left); // p gp u
					else
					{
						if (node == node->parent->left)
						{
							node = node->parent;
							_right_rotate(node);
						}
						_assign_colors_p_gp(node->parent, node->parent->parent);
						_left_rotate(node->parent->parent);
					}
				}
			}
			_root->color = BLACK;
		}

		void	_left_rotate(node_pointer node)
		{
			node_pointer tmp = node->right;

			node->right = tmp->left;

			if (tmp->left)
				tmp->left->parent = node;

			tmp->parent = node->parent;

			if (!node->parent)
				_root = tmp;
			else if (node == node->parent->left)
				node->parent->left = tmp;
			else
				node->parent->right = tmp;
			tmp->left = node;
			node->parent = tmp;
		}

		void	_right_rotate(node_pointer node)
		{
			node_pointer tmp = node->left;

			node->left = tmp->right;

			if (tmp->right)
				tmp->right->parent = node;

			tmp->parent = node->parent;

			if (!node->parent)
				_root = tmp;
			else if (node == node->parent->left)
				node->parent->left = tmp;
			else
				node->parent->right = tmp;
			tmp->right = node;
			node->parent = tmp;
		}

		// void	_swap_colors(node_pointer x, node_pointer y)
		// {
		// 	node_pointer tmp = x;

		// 	x->color = y->color;
		// 	y->color = tmp->color;
		// }

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

		void	_clear(node_pointer node)
		{
			if (!node || node == _end)
				return ;
			_clear(node->left);
			_clear(node->right);
			_destroy_node(node);
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

			while (max && max->right != NULL && max->right != _end)
				max = max->right;
			return max;
		}

		void	_assign_colors_p_gp(node_pointer p, node_pointer gp)
		{
			p->color = BLACK;
			gp->color = RED;
		}

		void	_assign_end()
		{
			node_pointer max_node = _max_node();

			max_node->right = _end;
			_end->parent = max_node;
			_end->right = NULL;
			_end->color = BLACK;
		}

	};
} // namespace ft


#endif
