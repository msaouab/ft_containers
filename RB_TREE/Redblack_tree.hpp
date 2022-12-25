/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Redblack_tree.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 22:26:21 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/25 13:34:11 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_TREE_CPP
# define REDBLACK_TREE_CPP

# include <iostream>
# include <functional>
# include "../stack/stack.hpp"
// # include "../iterators/iterator.hpp"
# include "../iterators/pair.hpp"
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

		explicit	node() : data(nullptr), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
		explicit	node(T data) : data(data), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
		
		~node() {}
	};

	template<class T>
	class TreeIterator;

	template <class Iterator>
	class TreeReverseIterator;

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
			typedef TreeIterator<value_type> iterator;
			typedef TreeIterator<value_type> const_iterator;
			typedef TreeReverseIterator<iterator> reverse_iterator;
			typedef TreeReverseIterator<const_iterator> const_reverse_iterator;
		private:
			nodePtr				root;
			nodePtr				tnil;
			nodePtr				past_the_end;
			nodePtr				before_the_begin;
			size_type			_size;
			key_compare			_compare;
			allocator_type		_allocate;
			node_allocator_type	_node_allocate;
		public:
			explicit	RedBlackTree(
				const key_compare &comp = key_compare(),
                const allocator_type &alloc = allocator_type()) : _allocate(alloc), _compare(comp) {
				tnil = _node_allocate.allocate(1);
				_node_allocate.construct(tnil, node_type(value_type()));
				tnil->color = BLACK;
				root = tnil;
				_size = 0;
				before_the_begin = _node_allocate.allocate(1);
				_node_allocate.construct(before_the_begin, node_type(value_type()));
				before_the_begin->color = BLACK;
				before_the_begin->left = tnil;
				before_the_begin->right = tnil;
				past_the_end = _node_allocate.allocate(1);
				_node_allocate.construct(past_the_end, node_type(value_type()));
				past_the_end->color = BLACK;
				past_the_end->left = tnil;
				past_the_end->right = tnil;
			}
			RedBlackTree(const RedBlackTree &rhs) : tnil(nullptr), root(nullptr) {
				*this = rhs;
			}
			~RedBlackTree() {
				clear();
				_node_allocate.destroy(tnil);
				_node_allocate.deallocate(tnil, 1);
				_node_allocate.destroy(before_the_begin);
				_node_allocate.deallocate(before_the_begin, 1);
				_node_allocate.destroy(past_the_end);
				_node_allocate.deallocate(past_the_end, 1);
			}
			RedBlackTree	&operator=(const RedBlackTree &rhs) {
				if (this != &rhs) {
					_size = rhs._size;
					_allocate = rhs._allocate;
					_compare = rhs._compare;
					_node_allocate = rhs._node_allocate;
					root = copy(rhs.root, rhs.tnil, rhs.before_the_begin, rhs.past_the_end);
					set_end();
				}
				return (*this);
			}
			nodePtr	copy(nodePtr _root, nodePtr _tnil, nodePtr _before, nodePtr _past) {
				if (_root == _tnil || _root == _before || _root == _past)
					return (tnil);
				nodePtr newnode = _node_allocate.allocate(1);
				_node_allocate.construct(newnode, node_type(_root->data));
				newnode->color = _root->color;
				newnode->left = copy(_root->left, _tnil, _before, _past);
				newnode->right = copy(_root->right, _tnil, _before, _past);
				newnode->parent = nullptr;
				if (newnode->left != tnil)
					newnode->left->parent = newnode;
				if (newnode->right != tnil)
					newnode->right->parent = newnode;
				return (newnode);
			}
			void	clear() {
				if (root == tnil)
					return ;
				ft_free(root);
				root = tnil;
				_size = 0;
			}
			nodePtr	getroot() const {
				return (root);
			}
			nodePtr	gettnil() const {
				return (tnil);
			}
			void set_begin() {
				nodePtr _min = min(root);
				nodePtr _max = max(root);

				if (_min == before_the_begin)
					_min = before_the_begin->parent;
				if (_min)
					_min->left = tnil;
				if (_max == past_the_end)
					_max = past_the_end->parent;
				if (_max)
					_max->right = tnil;
			}
			void set_end() {
				nodePtr _min = min(root);
				nodePtr _max = max(root);

				if (_min)
					_min->left = before_the_begin;
				before_the_begin->parent = _min;
				if (_max)
					_max->right = past_the_end;
				past_the_end->parent = _max;
			}
			nodePtr	find (const value_type& k) const {
				nodePtr	current = root;
				nodePtr	node;

				node = nullptr;
				while (current != tnil) {
					if (!(_compare(current->data, k) || _compare(k, current->data)))
						node = current;
					if (_compare(current->data, k))
						current = current->right;
					else
						current = current->left;
				}
				return (node);
			}
			nodePtr	begin() const {
				if (root == tnil)
					return (past_the_end);
				nodePtr	_min = min(root);
				if (_min == before_the_begin)
					return (_min->parent);
				return (_min);
			}
			nodePtr	rbegin() const {
				if (root == tnil)
					return (before_the_begin);
				nodePtr	_max = max(root);
				if (_max == past_the_end)
					return (_max->parent);
				return (_max);
			}
			nodePtr	end() const {
				return (past_the_end);
			}
			nodePtr	rend() const {
				return (before_the_begin);
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

				if (node->parent == nullptr) {
					node->color = BLACK;
					return ;
				}
				if (node->parent->parent == nullptr)
					return ;
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
			void	insert(const value_type & value) {
				set_begin();
				nodePtr new_node = _node_allocate.allocate(1);
				_node_allocate.construct(new_node, node_type(value));
				new_node->left = tnil;
				new_node->right = tnil;
				// new_node->parent = nullptr;
				// new_node->data = value;
				// new_node->color = RED;

				nodePtr parent = nullptr;
				nodePtr curr = this->root;
				while (curr != tnil) {
					parent = curr;
					if (_compare(new_node->data, curr->data))
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
				_size++;
				// if (new_node->parent == nullptr) {
				// 	new_node->color = BLACK;
				// 	return ;
				// }
				// if (new_node->parent->parent == nullptr)
				// 	return ;
				recolor(new_node);
				set_end();
			}

			void	freeNode(nodePtr node) {
				if (node == tnil)
					return ;
				_node_allocate.destroy(node);
				_node_allocate.deallocate(node, 1);
			}
			void	ft_free(nodePtr node) {
				if (node == tnil || node == before_the_begin || node == past_the_end)
					return ;
				ft_free(node->left);
				ft_free(node->right);
				freeNode(node);
			}
			static nodePtr	min(nodePtr node) {
				if (!node || !node->left)
					return (nullptr);
				while (node->left->parent)
					node = node->left;
				return (node);
			}
			static nodePtr	max(nodePtr node) {
				if (!node || !node->right)
					return (nullptr);
				while (node->right->parent)
					node = node->right;
				return (node);
			}
			static nodePtr	successor(nodePtr node) {
				if (node->right && node->right->parent)
					return (min(node->right));
				nodePtr	current = node->parent;
				while (current && node == current->right) {
					node = current;
					current = current->parent;
				}
				return (current);
			}
			static nodePtr	predecessor(nodePtr node) {
				if (node->left && node->left->parent)
					return (max(node->left));
				nodePtr	current = node->parent;
				while (current && node == current->left) {
					node = current;
					current = current->parent;
				}
				return (current);
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
			void	deleteNode(const value_type &value) {
				set_begin();
				nodePtr	current;
				nodePtr	tmp1;
				nodePtr	tmp2;

				current = find(value);
				if (!current || current == tnil)
					return ;
				tmp2 = current;
				int	oldcolor = current->color;
				if (current->left == tnil) {
					tmp1 = current->right;
					rbTransplant(current, current->right);
				}
				else if (current->right == tnil) {
					tmp1 = current->left;
					rbTransplant(current, current->left);
				}
				else {
					tmp2 = min(current->right);
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
				freeNode(current);
				if (oldcolor == BLACK)
					fixdelete(tmp1);
				tnil->parent = nullptr;
				_size--;
				set_end();
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
			size_type	size() const {
				return (_size);
			}
			size_type	max_size() const {
				return (_node_allocate.max_size());
			}
	};

	template<class T>
	class TreeIterator
	{
		public:
			typedef std::size_t						size_type;
			typedef T								value_type;
			typedef value_type&						reference;
			typedef value_type*						pointer;
			typedef std::ptrdiff_t					difference_type;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef node<value_type>*				nodePtr;
		private:
			nodePtr	node;
		public:
			// TreeIterator() {}
			TreeIterator(nodePtr _node = nullptr) : node(_node) {}
			TreeIterator(const TreeIterator &rhs) {
				*this = rhs;
			}
			TreeIterator &operator=(const TreeIterator &rhs) {
				if (this != &rhs)
					node = rhs.node;
				return (*this);
			}
			~TreeIterator() {}
			reference operator*() const {
				return (node->data);
			}
			pointer operator->() const {
				return &(node->data);
			}
			TreeIterator & operator++() {
				node = RedBlackTree<value_type>::successor(node);
				return (*this);
			}
			TreeIterator operator++(int) {
				TreeIterator tmp(*this);
				++*this;
				return (tmp);
			}
			TreeIterator & operator--() {
				node = RedBlackTree<value_type>::predecessor(node);
				return (*this);
			}
			TreeIterator operator--(int) {
				TreeIterator tmp(*this);
				--*this;
				return (tmp);
			}
			nodePtr base() const{
				return (node);
			}
			bool operator==(const TreeIterator &rhs) const {
				return (node == rhs.node);
			}
			bool operator!=(const TreeIterator &rhs) const {
				return (node != rhs.node);
			}
	};

	template <class Iterator>
	class TreeReverseIterator {
		public:
			typedef Iterator iterator_type;
			typedef typename iterator_traits<iterator_type>::iterator_category iterator_category;
			typedef typename iterator_traits<iterator_type>::value_type value_type;
			typedef typename iterator_traits<iterator_type>::difference_type difference_type;
			typedef typename iterator_traits<iterator_type>::pointer pointer;
			typedef typename iterator_traits<iterator_type>::reference reference;
		
		private:
			iterator_type it;

		public:
			// TreeReverseIterator() {}
			explicit TreeReverseIterator (iterator_type _it) : it(_it) { }

			template <class Iter>
			TreeReverseIterator (const TreeReverseIterator<Iter>& rev) : it(rev.it){
			}
			TreeReverseIterator & operator=(const TreeReverseIterator &rhs) {
				if (this != &rhs)
					it = rhs.it;
				return *this;
			}
			~TreeReverseIterator() {}
			iterator_type base() const {
                return it;
            }
            reference operator*() const {
                return *it;
            }
			pointer operator->() const {
                return &(*it);
            }
            TreeReverseIterator &operator++() {
                --it;
                return *this;
            }
            TreeReverseIterator operator++(int) {
                TreeReverseIterator tmp(*this);
                ++*this;
                return (tmp);
            }
            TreeReverseIterator &operator--() {
                ++it;
                return (*this);
            }
            TreeReverseIterator operator--(int) {
                TreeReverseIterator tmp(*this);
                --*this;
                return (tmp);
            }
            bool operator==(const TreeReverseIterator &rhs) const {
                return (it == rhs.it);
            }
            bool operator!=(const TreeReverseIterator &rhs) const {
                return (it != rhs.it);
            }
	};
}	// namespace ft

#endif