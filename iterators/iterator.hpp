/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:39:49 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/30 15:45:07 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ITERATOR_HPP__
# define _ITERATOR_HPP__

# define TRUE 1
# define FALSE 0

# include <iostream>
# include <string>
# include <memory>
# include "./enable_if.hpp"
# include "./equal.hpp"
# include "./is_integral.hpp"
# include "./iterator_traits.hpp"
# include "./lexicographical_compare.hpp"
# include "./pair.hpp"
# include "./reverse_iterator.hpp"

namespace ft {
	template <class T>
	class iterators : public ft::iterator<std::random_access_iterator_tag,T>
	{
		public:
			typedef std::size_t											size_type;
			typedef typename ft::iterator_traits<T>::difference_type	difference_type;
			typedef typename ft::iterator_traits<T>::value_type			value_type;
			typedef typename ft::iterator_traits<T>::pointer			pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::iterator_category	iterator_category;
		private:
			pointer p;

		public:
			iterators() {
				// std::cout << "iterators called the Default Constructor" << std::endl;
			}
			iterators(pointer addr) : p(addr) {
				// std::cout << "iterators called the Default Constructor" << std::endl;
			}
			iterators(const iterators& copy) {
				// std::cout << "Copy iterators the called Constructor" << std::endl;
				*this = copy;
			}
			~iterators() {
				// std::cout << "iterators called the Destructor" << std::endl;
			}
			iterators & operator=(const iterators& rhs) {
				if (this != &rhs)
					p = rhs.p;
				return *this;
			}
			iterators & operator++() {
				p++;
				return *this;
			}
			iterators operator++(int) {
				iterators tmp = *this;
				p++;
				return tmp;
			}
			iterators & operator--() {
				p--;
				return *this;
			}
			iterators operator--(int) {
				iterators tmp = *this;
				p--;
				return tmp;
			}
			iterators operator+(const difference_type& val) {
				iterators tmp = *this;
				tmp.p += val;
				return tmp;
			}
			iterators operator+=(const difference_type& val) {
				p += val;
				return *this;
			}
			iterators operator-(const difference_type& val) {
				iterators tmp = *this;
				tmp.p -= val;
				return tmp;
			}
			iterators operator-=(const difference_type& val) {
				p -= val;
				return *this;
			}
			reference operator[](size_type index) {
				return *(p + index); // TODO check if it's correct
			}
			pointer operator->() {
				return p;
			}
			reference operator*() {
				return *p;
			}
			pointer base() const{
				return p;
			}
			bool operator==(const iterators &rhs) const {
				return p == rhs.p;
			}
			bool operator!=(const iterators &rhs) const {
				return p != rhs.p;
			}
			bool operator<(const iterators &rhs) const {
				return p < rhs.p;
			}
			bool operator<=(const iterators &rhs) const {
				return p <= rhs.p;
			}
			bool operator>(const iterators &rhs) const {
				return p > rhs.p;
			}
			bool operator>=(const iterators &rhs) const {
				return p >= rhs.p;
			}
			difference_type operator-(const iterators &rhs) {
				return (p - rhs.p);
			}
	};
	template <class T>
	iterators<T> operator+(const typename iterators<T>::difference_type &val, const iterators<T> &I){
		iterators<T> tmp(I.base() + val) ;
		return tmp;
	}
}

#endif // _ITERATOR_HPP__