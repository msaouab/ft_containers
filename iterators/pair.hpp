/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:06 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/19 12:00:39 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PAIR_HPP__
# define _PAIR_HPP__

# include "../containers.hpp"

namespace ft {
	template <class T1, class T2>
	class pair {
		private:
			typedef T1 first_type;
			typedef T2 second_type;
		public:
			first_type	first;
			second_type	second;
			pair() : first(), second() {
				std::cout << "pair called the Default Constructor" << std::endl;
			}
			template <class U, class V>
			pair (const pair<U, V>& pr) : first(pr.first), second(pr.second) {
				std::cout << "pair called the Default Constructor" << std::endl;
			}
			pair (const first_type& a, const second_type& b) : first(a), second(b) {
				std::cout << "pair called the Copy Constructor" << std::endl;
			}
			~pair() {
				std::cout << "pair called the Destructor" << std::endl;
			}
			pair& operator= (const pair& pr) {
				if (this != &pr) {
					first_type = pr.first_type;
					second_type = pr.second_type;
				}
				return *this;
			}
	};

	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y) {
		return ( pair<T1, T2>(x, y) );
	}

	template <class T1, class T2>
	bool operator== (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first==rhs.first && lhs.second==rhs.second;
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs==rhs);
	}
	template <class T1, class T2>
	bool operator<  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	}
	template <class T1, class T2>
	bool operator<= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(rhs<lhs);
	}
	template <class T1, class T2>
	bool operator>  (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return rhs<lhs;
	}
	template <class T1, class T2>
	bool operator>= (const pair<T1, T2>& lhs, const pair<T1, T2>& rhs) {
		return !(lhs<rhs);
	}
}

#endif // _PAIR_HPP__