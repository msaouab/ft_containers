/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:05 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/19 15:20:56 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _REVERSE_ITERATOR_HPP__
# define _REVERSE_ITERATOR_HPP__

# include "../containers.hpp"

namespace ft {
	template <class Iterator>
	class reverse_iterator
	{
		private:
			iterator_type p;
		public:
			typedef std::size_t														size_type;
			typedef Iterator														iterator_type;
			typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
			typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
			typedef typename ft::iterator_traits<iterator_type>::reference			reference;
			typedef typename ft::iterator_traits<iterator_type>::iterator_category	iterator_category;

			reverse_iterator() {
				std::cout << "reverse_iterator called the Default Constructor" << std::endl;
			}
			reverse_iterator (iterator_type it) {
				std::cout << "reverse_iterator called the Default Constructor" << std::endl;
				p = it;
			}
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it) {
				p = rev_it.base();
			}
			~reverse_iterator() {
				std::cout << "reverse_iterator called the Destructor" << std::endl;
			}
			reverse_iterator & operator=(const reverse_iterator &rhs) {
				if (this != &rhs)
					p = rhs.p;
				return *this;
			}
			iterator_type base() const {
				return p.base();
			}
			reverse_iterator operator+ (difference_type n) const {
				return reverse_iterator(p.base() - n);
			}
			reverse_iterator & operator++() {
				p--;
				return *this;
			}
			reverse_iterator operator++(int) {
				reverse_iterator tmp = *this;
				p--;
				return tmp;
			}
			reverse_iterator& operator+= (difference_type n) {
				p -= n;
				return *this;
			}
			reverse_iterator operator- (difference_type n) const {
				return  reverse_iterator(p.base() + n);
			}
			reverse_iterator & operator--() {
				p++;
				return *this;
			}
			reverse_iterator operator--(int) {
				reverse_iterator tmp = *this;
				p++;
				return tmp;
			}
			reverse_iterator& operator-= (difference_type n) {
				p += n;
				return *this;
			}

			reference operator[](size_type index) {
				return p.base()[-index - 1];
			}
			reference operator*() {
				return *(p.base() - 1);
			}
			pointer operator->() {
				return &(operator*());
			}
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() == rhs.base();
	}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() != rhs.base();
	}
	template <class Iterator>
	bool operator< (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() > rhs.base();
	}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() >= rhs.base();
	}
	template <class Iterator>
	bool operator> (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() < rhs.base();
	}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return lhs.base() <= rhs.base();
	}
	template <class Iterator>
	reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n,
				const reverse_iterator<Iterator>& rev_it) {
		return rev_it  + n;
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator- (
		const reverse_iterator<Iterator>& lhs,
		const reverse_iterator<Iterator>& rhs) {
		return lhs.base() - rhs.base();
	}
}

#endif // _REVERSE_ITERATOR_HPP__