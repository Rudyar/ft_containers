/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudy <arudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:32:46 by arudy             #+#    #+#             */
/*   Updated: 2022/09/07 15:40:34 by arudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// INTRO : https://www.geeksforgeeks.org/red-black-tree-set-1-introduction-2/?ref=gcse
// INSERT : https://www.geeksforgeeks.org/c-program-red-black-tree-insertion/
// ERASE : https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
// REBIND : https://stackoverflow.com/questions/14148756/what-does-template-rebind-do
// https://www.programiz.com/dsa/insertion-in-a-red-black-tree

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

			~red_black_tree()
			{
				// Destroy tree
			}

			node_pointer	create_node(const_reference value = value_type())
			{
				node_pointer node = _node_alloc.allocate(1);
				_node_alloc.construct(node, Node(value));
				node->color = RED;
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
			std::cout << root->data.second << "(" << sColor << ")" << std::endl;
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
			if (empty())
				return end();
			return iterator(_start->parent);
		}

		iterator	end() // Recheck
		{
			return iterator(_end);
		}

		// ==================== Modifiers

		ft::pair<iterator, bool>	insert(const_reference val)
		{
			node_pointer node = create_node(val);
			node_pointer tmp;

			// std::cout << "Start before : " << _start->data.second << std::endl;
			// std::cout << "End before : " << _end->data.second << std::endl;

			if (empty())
				return _insert_empty(node);
			_bst_find(node->data, &tmp);
			if (tmp->data.first == node->data.first) // If a node with the same key already exist, destroy
			{
				std::cout << "Already a node : " << tmp->data.first << std::endl;
				_destroy_node(node);
				return ft::make_pair(iterator(tmp), false);
			}
			_bst_insert(node, &tmp);
			_bst_fix_insert(tmp);
			// find new _start and new _end with most left or riught funct ?

			// std::cout << "Start after : " << _start->data.second << std::endl;
			// std::cout << "End after : " << _end->data.second << std::endl;
			_size++;
			return ft::make_pair(iterator(tmp), false);
		}

	// Private helpers
	private :

		node_pointer	_bst_find(const_reference to_find, node_pointer *x) const // Maybe not enough
		{
			node_pointer tmp = _root;

			while (tmp && tmp != _start && tmp != _end)
			{
				*x = tmp;
				if (_comp(tmp->data.first, to_find.first))
					tmp = tmp->right;
				else if (_comp(to_find.first, tmp->data.first))
					tmp = tmp->left;
				else
					return tmp;
			}
			return NULL;
		}

		ft::pair<iterator, bool>	_insert_empty(node_pointer node)
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
			node_pointer p; // parent
			node_pointer gp; // grand parent
			node_pointer u; // uncle

			while (node != _root && node->parent->color == RED)
			{
				p = node->parent;
				gp = node->parent->parent;

				if (p == gp->left) // 1. if node p is node gp left child (<)
				{
					u = gp->right;
					if (u && u->color == RED) // 1.1 if u is also red, need only a recolor
						node = _fix_red_uncle(p, gp, u);
					else // u is black
					{
						if (node == p->right) // 1.2 node is right child, left rotate
						{
							_left_rotate(p);
							node = p;
							p = node->parent; // Not sur
						}
						_right_rotate(gp);
						_swap_colors(p, gp);
						node = p;
					}
				}
				else // 2. node p is node gp right child (>)
				{
					u = gp->left;
					if (u && u->color == RED) // 2.1 if u is also red, need only a recolor
						node = _fix_red_uncle(p, gp, u);
					else // u is black
					{
						if (node == p->left) // 2.2 node is left child, right rotate
						{
							_right_rotate(p);
							node = p;
							p = node->parent; // Not sur
						}
						_left_rotate(gp);
						_swap_colors(p, gp);
						node = p;
					}
				}
			}
			_root->color = BLACK;
		}

		void	_left_rotate(node_pointer node)
		{
			(void)node;
		}

		void	_right_rotate(node_pointer node)
		{
			(void)node;
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
			gp->color = RED;
			u->color = BLACK;
			return gp;
		}

		void	_destroy_node(node_pointer node)
		{
			_node_alloc.destroy(node);
			_node_alloc.deallocate(node, 1);
		}

	};

} // namespace ft


#endif
