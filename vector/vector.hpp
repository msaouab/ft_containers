/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:09 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/01 22:13:38 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP_
# define __VECTOR_HPP_

#include "../iterators/iterator.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef	typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef iterators<pointer> iterator;
			typedef iterators<const_pointer> const_iterator;
			typedef reverse_iterator<const_iterator> const_reverse_iterator;
			typedef reverse_iterator<iterator> reverse_iterator;
			typedef std::ptrdiff_t difference_type;
			typedef std::size_t size_type;

		private:
			value_type	*_data;
			size_type	_size;
			size_type	_cap;
			Alloc		_allocate;
		
		public:
			void	copy(size_type n, const value_type& val = value_type()) {
				value_type* tmp;

				tmp = _allocate.allocate(_cap);
				for (size_type i = 0; i < _size ; i++)
					tmp[i] = _data[i];
				for (size_type i = _size; i < n ; i++)
					tmp[i] = val;
				if (_size >= 0)
					_allocate.deallocate(_data, _size);
				_size = n;
				_data = tmp;
			}

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
			_allocate = _allocate.allocate(_cap);
			int	i = 0;
			for (InputIterator it = first; it < last; it++)
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
				_data[i] = rhs._data[i];
		}

/* ******************************* Destructor ******************************* */
		~vector() {
			_allocate.deallocate(_data, _cap);
		}

/* ******************************** Operator ******************************** */
		vector& operator= (const vector& rhs) {
			if (this != &rhs) {
				_allocate.deallocate(_data, _cap);
				_allocate = rhs._allocate;
				_data = _allocate.allocate(rhs._data);
				_cap = rhs._cap;
				_size = rhs._size;
				for (int i = 0; i < _size; i++)
					_data[i] = rhs._data[i];
			}
			return (*this);
		}

/* ******************************** Iterators ******************************** */
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

/* ********************************* Capacity ******************************** */
		size_type size() const {
			return (_size);
		}
		size_type max_size() const {
			return (_allocate.size_max());
		}
		void resize (size_type n, value_type val = value_type()) {
			
		}
		size_type capacity() const {
			return (_cap);
		}
		bool empty() const {
			if (_size > 0)
				return (TRUE);
			return (FALSE);
		}
		void reserve( size_type new_cap ) {
			if (_cap > new_cap)
				return ;
			_cap = new_cap;
			return (_size);
		}

/* ***************************** Element access ****************************** */
		reference at( size_type pos ) {
			if (pos < 0 || pos > _size)
				throw std::out_of_range("Vector at");
			return (_data[pos]);
		}
		const_reference operator[] (size_type n) const {
			if (n < 0 || n > _size)
				throw std::out_of_range("Vector at");
			return (_data[n]);
		}
		reference operator[] (size_type n) {
			return (_data[n]);
		}
		reference front() {
			return (_data[0]);
		}
		const_reference front() const {
			return (_data[0]);
		}
		reference back() {
			return (_data[_size - 1]);
		}
		const_reference back() const {
			return (_data[_size - 1]);
		}

/* ******************************** Modifiers ******************************** */
		template <class InputIterator>
		void	assign (InputIterator first, InputIterator last) {
			int	i = 0;
			this->clear();
			if (_cap < last - first) {
				_cap = last - first;
				_allocate.deallocate(_data, _size);
				_allocate.allocate(_cap);
			}
			for (InputIterator it = first; it < last; it++)
				_data[i++] = *it;
		}
		void	assign (size_type n, const value_type& val) {
			this->clear();
			if (_cap < n) {
				_cap = n;
				_allocate.deallocate(_data, _size);
				_allocate.allocate(_cap);
			}
			for (size_type i = 0; i < n; i++)
				_data[i] = val;
		}
		void	push_back( const T& value ) {
			if (_cap == 0)
				_cap++;
			if (_cap <= _size)
				_cap *= 2;
			copy(_size + 1, value);
		}
		void	pop_back() {
			_data[_size] = ~value_type();
			_size--;
		}
		void	clear() {
			for (int i = 0; i < _size; i++)
				_data[i].~value_type();
			_size = 0;
		}
		iterator insert (iterator pos, const value_type& value) {
			size_type	i;
			if (_cap > _size) {
				i = _size;
				_size++;
				for (iterator it = end() - 1; it > pos; it--) {
					_data[i + 1] = _data[i];
					i--;
				}
				_data[pos] = value;
			}
			else {
				value_type	*tmp;
				_cap *= 2;
				if (_cap == 0)
					_cap++;
				tmp = _allocate.allocate(_cap);
				i = 0;
				for (iterator it = begin(); it < pos; it++) {
					tmp[i] = _data[i];
					i++;
				}
				tmp[i] = value;
				for (iterator it = pos; it < end(); it++) {
					tmp[i] = _data[i - 1];
					i++;
				}
				_allocate.deallocate(_data, _size);
				_data = tmp;
			}
			return (begin() + pos);
		}
		void insert (iterator pos, size_type n, const value_type& val) {
			size_type	i;
			if (_cap >= _size + n) {
				i = _size;
				_size += n;
				for (iterator it = end() - 1; it > pos; it--) {
					_data[i + n] = _data[i];
					i--;
				}
				for (iterator it = pos; it < pos + n; it++) {
					_data[pos + i] = val;
					i++;
				}
			}
			else {
				value_type	*tmp;
				if (_cap == 0)
					_cap = n;
				if (_cap <= _size + n)
					_cap = _size + n;
				tmp = _allocate.allocate(_cap);
				i = 0;
				for (iterator it = begin(); it < pos; it++) {
					tmp[i] = _data[i];
					i++;
				}
				for (iterator it = pos; it < pos + n; it++) {
					tmp[i] = val;
					i++;
				}
				for (iterator it = pos; it < end(); it++) {
					tmp[i] = _data[i - n];
					i++;
				}
				_allocate.deallocate(_data, _size);
				_data = tmp;
			}
		}
		template <class InputIterator>
		void insert (iterator pos, InputIterator first, InputIterator last) {
			size_type	i;
			size_type	n;
			n = last - first;
			if (_cap >= _size + n) {
				i = _size;
				_size += n;
				for (iterator it = end() - 1; it > pos; it--) {
					_data[i + n] = _data[i];
					i--;
				}
				for (iterator it = first; it < last; it++) {
					_data[pos + i] = it;
					i++;
				}
			}
			else {
				value_type	*tmp;
				if (_cap == 0)
					_cap = n;
				if (_cap <= _size + n)
					_cap = _size + n;
				tmp = _allocate.allocate(_cap);
				i = 0;
				for (iterator it = begin(); it < pos; it++) {
					tmp[i] = _data[i];
					i++;
				}
				for (iterator it = first; it < last; it++) {
					tmp[i] = it;
					i++;
				}
				for (iterator it = pos; it < end(); it++) {
					tmp[i] = _data[i - n];
					i++;
				}
				_allocate.deallocate(_data, _size);
				_data = tmp;
			}
		}
		iterator erase (iterator pos) {
			for (iterator it = pos; it < end() - 1; it++) {
				_data[i] = *it;
			}
			_size--;
			return (pos);
		}
		iterator erase (iterator first, iterator last) {
			size_type n;
			n = last - first;
			if (last < end()) {
				for (iterator it = first; it < end(); it++)
					*it = *(it + n);
			}
			_size -= n;
			return first;
		}
		void swap (vector& x) {
			value_type		*new_data = x._data;
			allocator_type	new_allocate = x._allocate;
			size_type		new_size = x._size;
			size_type		new_cap = x._cap;

			x._data = this->_data;
			x._allocate = this->_allocate;
			x._size = this->_size;
			x._cap = this->_cap;

			this->_data = new_data;
			this->_allocate = new_allocate;
			this->_size = new_size;
			this->_cap = new_cap;
		}

/* ******************************** Allocator ******************************** */
		allocator_type get_allocator() const {
			return (_allocate);
		}
	};

/* ********************** Non-member function overloads ********************** */
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size() && !ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
			return (FALSE);
		return (TRUE);
	}
	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs == rhs);
	}
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}
	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs < rhs);
	}
	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return !(lhs < rhs);
	}
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
		x.swap(y);
	}
}

#endif // __VECTOR_HPP_
