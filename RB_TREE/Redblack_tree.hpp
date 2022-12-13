/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redblack_tree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:26:21 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/13 13:48:54 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_TREE_CPP
# define REDBLACK_TREE_CPP

# include <iostream>
# include "../stack/stack.hpp"
# define BLACK 0
# define RED 1

namespace ft {
	template<class T>
	struct	node
	{
		T			data;
		int			color;
		node<T>*	parent;
		node<T>*	right;
		node<T>*	left;

		explicit	node() : data(NULL), color(RED), parent(NULL), left(NULL), right(NULL) {}
		explicit	node(T data) : data(data), color(RED), parent(NULL), left(NULL), right(NULL) {}
		
		~node() {}
	};

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class RedBlackTree {
		public:
			typedef	std::size_t	size_type;
			typedef	T	value_type;
			typedef	node<value_type>	node_type;
			typedef	node_type*			nodePtr;
			typedef	node_type&			node_reference;
			typedef	Alloc allocator_type;
			typedef	std::allocator<node_type> node_allocator_type;
			typedef Compare	key_compare;
			// typedef size_t	size_type;
			typedef ptrdiff_t	differnce_type;
		// typedef treeIterator
		private:
			nodePtr	root;
			nodePtr	tnil;
			size_type		_size;
			allocator_type	_allocate;
			node_allocator_type	_node_allocate;
			key_compare			_compare;
		public:
			explicit	RedBlackTree() {
				tnil = _node_allocate.allocate(1);
				_node_allocate.construct(tnil, node_type(value_type()));
				tnil->color = BLACK;
				root = tnil;
				_size = 0;
			}
			RedBlackTree(const RedBlackTree &rhs) : tnil(nullptr), root(nullptr) {
				*this = rhs;
			}
			~RedBlackTree() {
				clear();
				_node_allocate.destroy(tnil);
				_node_allocate.deallocate(tnil, 1);
			}

			void	clear() {
				if (root == tnil)
					return ;
				ft_free(root);
				root = tnil;
				_size = 0;
			}

			nodePtr	getroot() const {
				return root;
			}
			nodePtr	gettnil() const {
				return tnil;
			}

			void	leftrotate(nodePtr node)
			{
				nodePtr	tmp;

				tmp = node->right;
				node->right = tmp->left;
				if (tmp->left != tnil)
					tmp->left->parent = node;
				tmp->parent = node->parent;
				if (node->parent == nullptr)
					this->root = tmp;
				else if (node == node->parent->left)
					node->parent->left = tmp;
				else
					node->parent->right = tmp;
				tmp->left = node;
				node->parent = tmp;
			}

			void	rightrotate(nodePtr node)
			{
				nodePtr	tmp;

				tmp = node->left;
				node->left = tmp->right;
				if (tmp->right != tnil)
					tmp->right->parent = node;
				tmp->parent = node->parent;
				if (node->parent == nullptr)
					this->root = tmp;
				else if (node == node->parent->right)
					node->parent->right = tmp;
				else
					node->parent->left = tmp;
				tmp->right = node;
				node->parent = tmp;
			}

			void	recolor(nodePtr node) {
				nodePtr	tmp;

				while (node->parent->color == RED) {
					if (node->parent == node->parent->parent->right) {
						tmp = node->parent->parent->left;
						if (tmp->color == RED) {
							tmp->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else {
							if (node == node->parent->left) {
								node = node->parent;
								rightrotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							leftrotate(node->parent->parent);
						}
					}
					else {
						tmp = node->parent->parent->right;
						if (tmp->color == RED) {
							tmp->color = BLACK;
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							node = node->parent->parent;
						}
						else {
							if (node == node->parent->right) {
								node = node->parent;
								leftrotate(node);
							}
							node->parent->color = BLACK;
							node->parent->parent->color = RED;
							rightrotate(node->parent->parent);
						}
					}
					if (node == root)
						break ;
				}
				root->color = BLACK;
			}

			void	insert(int value) {
				nodePtr new_node = _node_allocate.allocate(1);
				_node_allocate.construct(new_node, node_type(value));
				new_node->left = tnil;
				new_node->right = tnil;
				new_node->parent = nullptr;
				new_node->data = value;
				new_node->color = RED;

				nodePtr parent = nullptr;
				nodePtr curr = this->root;
				while (curr != tnil) {
					parent = curr;
					if (new_node->data < curr->data)
						curr = curr->left;
					else
						curr = curr->right;
				}
				new_node->parent = parent;
				if (parent == nullptr)
					root = new_node;
				else if (new_node->data < parent->data)
					parent->left = new_node;
				else
					parent->right = new_node;
				if (new_node->parent == nullptr) {
					new_node->color = BLACK;
					return ;
				}
				if (new_node->parent->parent == nullptr)
					return ;
				recolor(new_node);
			}

			void	ft_free(nodePtr node) {
				if (node == tnil)
					return ;
				_node_allocate.destroy(node);
				_node_allocate.deallocate(node, 1);
			}

			nodePtr	minRight(nodePtr node) {
				if (node == nullptr)
					return (nullptr);
				while (node->left != tnil)
					node = node->left;
				return node;
			}

			nodePtr	maxRight(nodePtr node) {
				if (node == nullptr)
					return (nullptr);
				while (node->right != tnil)
					node = node->right;
				return node;
			}

			void	rbTransplant(nodePtr first, nodePtr second) {
				if (first->parent == nullptr)
					root = second;
				else if (first == first->parent->left)
					first->parent->left = second;
				else
					first->parent->right = second;
				second->parent = first->parent;
			}

			void	fixdelete(nodePtr node) {
				nodePtr	tmp;

				while (node != root && node->color == BLACK) {
					if (node == node->parent->left) {
						tmp = node->parent->right;
						if (tmp->color == RED) {
							tmp->color = BLACK;
							node->parent->color = RED;
							leftrotate(node->parent);
							tmp = node->parent->right;
						}
						if (tmp->left->color == BLACK && tmp->right->color == BLACK) {
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->right->color == BLACK) {
								tmp->left->color = BLACK;
								tmp->color = RED;
								rightrotate(tmp);
								tmp = node->parent->right;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->right->color = BLACK;
							leftrotate(node->parent);
							node = root;
						}
					}
					else {
						tmp = node->parent->left;
						if (tmp->color == RED) {
							tmp->color = BLACK;
							node->parent->color = RED;
							rightrotate(node->parent);
							tmp = node->parent->left;
						}
						if (tmp->right->color == BLACK && tmp->left->color == BLACK) {
							tmp->color = RED;
							node = node->parent;
						}
						else {
							if (tmp->left->color == BLACK) {
								tmp->right->color = BLACK;
								tmp->color = RED;
								leftrotate(tmp);
								tmp = node->parent->left;
							}
							tmp->color = node->parent->color;
							node->parent->color = BLACK;
							tmp->left->color = BLACK;
							rightrotate(node->parent);
							node = root;
						}
					}
				}
				node->color = BLACK;
			}

			void	deleteNode(int value) {
				nodePtr	node;
				nodePtr	current;
				nodePtr	tmp1;
				nodePtr	tmp2;

				node = this->root;
				// current = tnil;
				while (node != tnil) {
					if (node->data == value)
						current = node;
					if (node->data <= value)
						node = node->right;
					else
						node = node->left;
				}
				if (current == tnil) {
					std::cout << "this " << value << " not found in the Tree" << std::endl;
					return ;
				}
				tmp2 = current;
				int	oldcolor = tmp2->color;
				if (current->left == tnil) {
					tmp1 = current->right;
					rbTransplant(current, current->right);
				}
				else if (current->right == tnil) {
					tmp1 = current->left;
					rbTransplant(current, current->left);
				}
				else {
					tmp2 = minRight(current->right);
					oldcolor = tmp2->color;
					tmp1 = tmp2->right;
					if (tmp2->parent == current)
						tmp1->parent = tmp2;
					else {
						rbTransplant(tmp2, tmp2->right);
						tmp2->right = current->right;
						tmp2->right->parent = tmp2;
					}
					rbTransplant(current, tmp2);
					tmp2->left = current->left;
					tmp2->left->parent = tmp2;
					tmp2->color = current->color;
				}
				ft_free(current);
				if (oldcolor == BLACK)
					fixdelete(tmp1);
				// tnil->parent = nullptr;
				// _size--;
			}

			void printer(nodePtr root, std::string indent, bool last) {
				if (root != tnil) {
					std::cout << indent;
					if (last) {
						std::cout << "R----";
						indent += "     ";
					}
					else {
						std::cout << "L----";
						indent += "|\t";
					}
					std::string scolor = root->color ? "Red" : "Black";
					std::cout << root->data << "(" << scolor << ")" << std::endl;
					printer(root->left, indent, false);
					printer(root->right, indent, true);
				}
			}

			void	printTree() {
				if (root)
					printer(this->root, "", true);
				std::cout << "|---------------------------------|\n";
			}
			
	};
}	// namespace ft

#endif