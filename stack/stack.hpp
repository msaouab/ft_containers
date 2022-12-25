/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:04 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/23 13:06:50 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_STACK_HPP_
# define __FT_STACK_HPP_

#include "../vector/vector.hpp"

namespace ft {
	template <class T, class Container = ft::vector<T> >
	class stack {
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef std::size_t	size_type;

			template <class U, class V>
			friend bool operator== (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator!= (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator< (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator<= (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator> (const stack<U,V>& lhs, const stack<U,V>& rhs);
			template <class U, class V>
			friend bool operator>= (const stack<U,V>& lhs, const stack<U,V>& rhs);

			explicit stack (const container_type& ctnr = container_type()) {
				c = ctnr;
			}
			bool empty() const {
				return (c.empty());
			}
			size_type size() const {
				return (c.size());
			}
			value_type& top() {
				return (c.back());
			}
			const value_type& top() const{
				return (c.back());
			}
			void push (const value_type& val) {
				c.push_back(val);
			}
			void pop() {
				c.pop_back();
			}
		protected:
			container_type	c;
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c == rhs.c);
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c != rhs.c);
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c < rhs.c);
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c <= rhs.c);
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c > rhs.c);
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c >= rhs.c);
	}
}

#endif // __FT_STACK_HPP_