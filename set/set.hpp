/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:00:31 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/20 17:55:29 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SET_HPP__
# define _SET_HPP__

# include "../map/map.hpp"
# include <set>

namespace ft {
	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set {
		public:
			typedef T											key_type;
			typedef T											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Alloc										allocator_type;
			typedef std::size_t									size_type;
			typedef std::ptrdiff_t								difference_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename RedBlackTree<value_type, key_compare, allocator_type>::iterator				iterator;
			typedef typename RedBlackTree<value_type, key_compare, allocator_type>::const_iterator			const_iterator;
			typedef typename RedBlackTree<value_type, key_compare, allocator_type>::reverse_iterator		reverse_iterator;
			typedef typename RedBlackTree<value_type, key_compare, allocator_type>::const_reverse_iterator	const_reverse_iterator;
		private:
			typedef	RedBlackTree<value_type, value_compare, allocator_type> rbt;
			rbt				mytree;
			allocator_type	_allocate;
			key_compare		_compare;
		public:
/* **************************** Member functions **************************** */
			explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : mytree(value_compare(comp), alloc), _allocate(alloc), _compare(comp) { }
			template <class InputIterator>
			set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : mytree(value_compare(comp), alloc), _compare(comp) {
				while (first != last) {
					mytree.insert(*first);
					first++;
				}
			}
			set (const set& x) {
				*this = x;
			}
			~set() { }
			set& operator= (const set& x) {
				if (this != &x) {
					mytree = x.mytree;
					_allocate = x._allocate;
					_compare = x._compare;
				}
				return (*this);
			}
/* ******************************* Iterators ******************************** */
			iterator begin() {
				return (iterator(mytree.begin()));
			}
			const_iterator begin() const {
				return (const_iterator(mytree.begin()));
			}
			iterator end() {
				return (iterator(mytree.end()));
			}
			const_iterator end() const {
				return (const_iterator(mytree.end()));
			}
			reverse_iterator rbegin() {
				return (reverse_iterator(mytree.rbegin()));
			}
			const_reverse_iterator rbegin() const {
				return (const_reverse_iterator(mytree.rbegin()));
			}
			reverse_iterator rend() {
				return (reverse_iterator(mytree.rend()));
			}
			const_reverse_iterator rend() const {
				return (const_reverse_iterator(mytree.rend()));
			}
/* ******************************** Capacity ******************************** */
			bool empty() const {
				return (mytree.size() == 0);
			}
			size_type size() const {
				return (mytree.size());
			}
			size_type max_size() const {
				return (mytree.max_size());
			}
/* ******************************* Modifiers ******************************** */
			pair<iterator,bool> insert (const value_type& val) {
				typename	rbt::nodePtr node = mytree.find(val);
				bool	add	= false;
				if (!node) {
					mytree.insert(val);
					add = true;
					node = mytree.find(val);
				}
				return (ft::pair<iterator, bool>(iterator(node), add));
			}
			iterator insert (iterator position, const value_type& val) {
				(void)position;
				typename	rbt::nodePtr node = mytree.find(val);
				if (!node) {
					mytree.insert(val);
					node = mytree.find(val);
				}
				return (iterator(node));
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last) {
				typename rbt::nodePtr	node;
				while (first != last) {
					node = mytree.find(*first);
					if (!node)
						mytree.insert(*first);
					first++;
				}
			}
			void erase (iterator position) {
				mytree.deleteNode(*position);
			}
			size_type erase (const value_type& val) {
				typename rbt::nodePtr	node = mytree.find(val);
				if (node) {
					mytree.deleteNode(val);
					return (1);
				}
				return (0);
			}
			void erase (iterator first, iterator last) {
				while (first != last) {
					erase(first++);
				}
			}
			void swap (set& x) {
				set	y = x;
				x = *this;
				*this = y;
			}
			void clear() {
				mytree.clear();
			}
/* ******************************* Observers ******************************** */
			value_compare value_comp() const {
				return (value_compare(_compare));
			}
			key_compare key_comp() const {
				return (_compare);
			}
/* ****************************** Operations ******************************** */
			iterator find (const value_type& val) const {
				typename rbt::nodePtr	node = mytree.find(val);
				return (iterator(node));
			}
			size_type count (const value_type& val) const {
				typename rbt::nodePtr	node = mytree.find(val);
				if (node)
					return (1);
				return (0);
			}
			iterator lower_bound (const value_type& val) const {
				typename rbt::nodePtr	node = nullptr;
				typename rbt::nodePtr	current = mytree.getroot();

				while (current != mytree.gettnil()) {
					if (_compare(current->data, val))
						current = current->right;
					else {
						node = current;
						current = current->left;
					}
				}
				return (iterator(node));
			}
			iterator upper_bound (const value_type& val) const {
				typename rbt::nodePtr	node = nullptr;
				typename rbt::nodePtr	current = mytree.getroot();

				while (current != mytree.gettnil()) {
					if (_compare(val, current->data)) {
						node = current;
						current = current->left;
					}
					else
						current = current->right;
				}
				return (iterator(node));
			}
			pair<iterator,iterator> equal_range (const value_type& val) const {
				return (ft::pair<iterator,iterator>(lower_bound(val), upper_bound(val)));
			}
/* ************************************* Allocator ************************************* */
			allocator_type get_allocator() const {
				return (_allocate);
			}
	};
}

#endif // _SET_HPP__