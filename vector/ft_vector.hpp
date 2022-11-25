/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:09 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/25 19:52:07 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_VECTOR_HPP_
# define __FT_VECTOR_HPP_

# include "../containers.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef	typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef typename iterator<pointer>					iterator;
		typedef typename iterator<const_pointer>			const_iterator;
		typedef typename reverse_iterator<pointer>			reverse_iterator;
		typedef typename const_reverse_iterator<pointer>	const_reverse_iterator;
		typedef typename std::ptrdiff_t						difference_type;
		typedef typename std::size_t						size_type;

/* ****************************** Constructors ****************************** */
		explicit vector (const allocator_type& alloc = allocator_type()) {
			_size = 0;
			_cap = 0;
			_data = nullptr;
			_allocate = alloc;
		}
		explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {
			_size = n;
			_cap = n;
			_allocate = alloc;
			_data = _allocate.allocate(_cap);
			for (size_type i = 0; i < _cap; i++) {
				_data = val;
			}
		}
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {
			_size = last - first;
			_cap = last - first;
			_allocate = alloc;
			int	i = 0;
			for (InputIterator *it = first; it < last; it++)
				_data[i++] = *it;
		}
		vector (const vector& rhs) {
			if (_cap > 0)
				_allocate.deallocate(_data, _cap);
			_allocate = rhs._allocate;
			_cap = rhs._cap;
			_size = rhs._size;
			_allocate.allocate(_data, _cap);
			for (int i = 0; i < _size; i++)
				_data[i] = rhs._data;
		}

/* ******************************* Destructor ******************************* */
		~vector() {
			_allocate.deallocate(_data, _cap);
		}

/* ******************************** Operator ******************************** */
		vector& operator= (const vector& rhs) {
			if (this != &rhs) {
				_allocate.deallocate(_data, _cap);
				_allocate = x._allocate;
				_data = _allocate.allocate(x._data);
				_cap = x._cap;
				_size = rhs._size;
				for (int i = 0; i < _size; i++)
					_data[i] = rhs._data[i];
			}
			return (*this);
		}

/* ********************************** Iterators ********************************** */
		iterator begin() {
			return (_data);
		}
		const_iterator begin() const {
			return (_data);
		}
		iterator end() {
			return (_data + _size);
		}
		const_iterator end() const {
			return (_data + _size);
		}
		reverse_iterator rbegin() {
			return (reverse_iterator(end()));
		}
		const_reverse_iterator rbegin() const {
			return (const_reverse_iterator(end()));
		}
		reverse_iterator rend() {
			return (reverse_iterator(begin()));
		}
		const_reverse_iterator rend() const {
			return (const_reverse_iterator(begin()));
		}
		size_type size() const {
			return (_size);
		}
		size_type max_size() const {
			return (_allocate.size_max());
		}
		void resize (size_type n, value_type val = value_type()) {
			
		}
	};
}

#endif // __FT_VECTOR_HPP_