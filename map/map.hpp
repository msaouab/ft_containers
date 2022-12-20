/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:56:58 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/20 15:39:58 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_MAP_HPP_
# define __FT_MAP_HPP_

# include "../RB_TREE/Redblack_tree.hpp"
# include "../iterators/pair.hpp"
// # include "../iterators/enable_if.hpp"
// # include "../iterators/equal.hpp"
// # include "../iterators/is_integral.hpp"
// # include "../iterators/iterator_traits.hpp"
// # include "../iterators/lexicographical_compare.hpp"
// # include "../iterators/reverse_iterator.hpp"

#include <map>

namespace ft {
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map {
		public:
			class	value_compare;
			typedef Key												key_type;
			typedef Compare											key_compare;
			typedef T												mapped_type;
			typedef ft::pair<const key_type,mapped_type>			value_type;
			typedef Alloc											allocator_type;
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
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
			explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : mytree(value_compare (comp), alloc), _allocate(alloc), _compare(comp) { }
			template <class InputIterator>
			map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : mytree(value_compare(comp), alloc), _compare(comp) {
				while (first != last) {
					mytree.insert(*first);
					first++;
				}
			}
			map (const map& x) {
				*this = x;
			}
			~map() { }
			map& operator= (const map& rhs) {
				if (this != &rhs) {
					mytree = rhs.mytree;
					_allocate = rhs._allocate;
					_compare = rhs._compare;
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
				typename rbt::nodePtr	node = mytree.find(key);
				if (node) {
					mytree.deleteNode(key);
					return (1);
				}
				return (0);
			}
			void erase (iterator first, iterator last) {
				while (first != last) {
					erase(first++);
				}
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
			class value_compare : std::binary_function<value_type, value_type, bool>
            {
                protected:
                    key_compare _compare;

                public:
                    typedef bool result_type;
                    typedef value_type first_argument_type;
                    typedef value_type second_argument_type;
                    bool operator()(const value_type &rhs, const value_type &ths) const
                    {
                        return _compare(rhs.first, ths.first);
                    }
                    value_compare(const key_compare &c = key_compare()) : _compare(c) {}
            };
			value_compare value_comp() const {
				return (value_compare(_compare));
			}
			key_compare key_comp() const {
				return (_compare);
			}
/* ******************************* Observers ******************************** */
			iterator find (const key_type& k) {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(key);
				return (iterator(node));
			}
			const_iterator find (const key_type& k) const {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(key);
				return (const_iterator(node));
			}
			size_type count (const key_type& k) const {
				value_type key(k, mapped_type());
				typename rbt::nodePtr	node = mytree.find(key);
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
				return (ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}
			ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
				return (ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
			}
/* ************************************* Allocator ************************************* */
			allocator_type get_allocator() const {
				return (_allocate);
			}
/* ************************************************************************** */
	};
}

# endif // __FT_MAP_HPP_