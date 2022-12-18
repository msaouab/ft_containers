/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:56:58 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/18 12:13:52 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_MAP_HPP_
# define __FT_MAP_HPP_

# include "../RB_TREE/Redblack_tree.hpp"
# include "../iterators/pair.hpp"
# include "../iterators/enable_if.hpp"
# include "../iterators/equal.hpp"
# include "../iterators/is_integral.hpp"
# include "../iterators/iterator_traits.hpp"
# include "../iterators/lexicographical_compare.hpp"
# include "../iterators/reverse_iterator.hpp"

#include <map>

namespace ft {
	template < class Key,						// map::key_type
    class T,									// map::mapped_type
    class Compare = std::less<Key>,					// map::key_compare
    class Alloc = std::allocator<ft::pair<const Key,T> >	// map::allocator_type
    >
	class map {
		public:
			class	value_compare;
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type,mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;	
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::iterator				iterator;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::const_iterator			const_iterator;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::reverse_iterator		reverse_iterator;
            typedef typename RedBlackTree<value_type, key_compare, allocator_type>::const_reverse_iterator	const_reverse_iterator;

		private:
			typedef	RedBlackTree<value_type, value_compare, allocator_type> rbt;
			rbt				mytree;
			key_compare		_compare;
			allocator_type	_allocate;

		public:

/* **************************** Member functions **************************** */
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : mytree(value_compare (comp), alloc), _allocate(alloc), _compare(comp) {}
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) {
				while (first != last) {
					mytree.insert(*first);
					first++;
				}
			}
			map (const map& x) {
				*this = x;
			}
			~map() {
			}
			map& operator= (const map& rhs) {
				if (this != &rhs) {
					this->mytree = rhs.mytree;
					this->_allocate = rhs._allocate;
					this->_compare = rhs._compare;
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
/* ***************************** Element access ***************************** */
			mapped_type& operator[] (const key_type& k) {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(key);
				if (!node) {
					mytree.insert(key);
					node = mytree.find(key);
				}
				return (node->data.second);
			}
/* ******************************* Modifiers ******************************** */
			ft::pair<iterator,bool> insert (const value_type& val) {
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
			size_type erase (const key_type& k) {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(k);
				if (node) {
					mytree.deleteNode(key);
					return (1);
				}
				return (0);
			}
			void erase (iterator first, iterator last) {
				while (first != last)
					erase(first++);
			}
			void swap (map& x) {
				map	y = x;
				x = *this;
				*this = y;
			}
			void clear() {
				mytree.clear();
			}
/* ******************************* Observers ******************************** */
			value_compare value_comp() const {
				return (_compare);
			}
			key_compare key_comp() const {
				return (value_compare(_compare));
			}
/* ******************************* Observers ******************************** */
			iterator find (const key_type& k) {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(k);
				return (iterator(node));
			}
			const_iterator find (const key_type& k) const {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(k);
				return (const_iterator(node));
			}
			size_type count (const key_type& k) const {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(k);
				if (node)
					return (1);
				return (0);
			}
			iterator lower_bound (const key_type& k) {
				typename rbt::nodePtr	node = nullptr;
				typename rbt::nodePtr	current = mytree.getroot();

				while (current != mytree.gettnil()) {
					if (_compare(current->data.first, k))
						current = current->right;
					else {
						node = current;
						current = current->left;
					}
				}
				return (iterator(node));
			}
			const_iterator lower_bound (const key_type& k) const {
				typename rbt::nodePtr	node = nullptr;
				typename rbt::nodePtr	current = mytree.getroot();

				while (current != mytree.gettnil()) {
					if (_compare(current->data.first, k))
						current = current->right;
					else {
						node = current;
						current = current->left;
					}
				}
				return (const_iterator(node));
			}
			iterator upper_bound (const key_type& k) {
				typename rbt::nodePtr	node = nullptr;
				typename rbt::nodePtr	current = mytree.getroot();

				while (current != mytree.gettnil()) {
					if (_compare(k, current->data.first)) {
						node = current;
						current = current->left;
					}
					else
						current = current->right;
				}
				return (iterator(node));
			}
			const_iterator upper_bound (const key_type& k) const {
				typename rbt::nodePtr	node = nullptr;
				typename rbt::nodePtr	current = mytree.getroot();

				while (current != mytree.gettnil()) {
					if (_compare(k, current->data.first)) {
						node = current;
						current = current->left;
					}
					else
						current = current->right;
				}
				return (const_iterator(node));
			}
			ft::pair<iterator,iterator> equal_range (const key_type& k) {
				return (ft::pair<iterator,iterator>(lower_bound(), upper_bound()));
			}
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::pair<const_iterator,const_iterator>(lower_bound(), upper_bound()));
			}
/* ************************************* Allocator ************************************* */
			allocator_type get_allocator() const {
				return (_allocate);
			}
/* ************************************************************************** */
	};
}

# endif // __FT_MAP_HPP_