/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:04 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/02 22:01:03 by msaouab          ###   ########.fr       */
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
				s = ctnr;
			}
			bool empty() const {
				return (s.empty());
			}
			size_type size() const {
				return (s.size());
			}
			value_type& top() {
				return (s.back());
			}
			const value_type& top() const{
				return (s.back());
			}
			void push (const value_type& val) {
				s.push_back(val);
			}
			void pop() {
				s.pop_back();
			}
		protected:
			container_type	s;
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs == rhs);
	}
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs != rhs);
	}
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs < rhs);
	}
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs <= rhs);
	}
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs > rhs);
	}
	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs >= rhs);
	}
}

#endif // __FT_STACK_HPP_