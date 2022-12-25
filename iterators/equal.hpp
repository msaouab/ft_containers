/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:14 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/25 13:41:56 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _EQUAL_HPP__
# define _EQUAL_HPP__

# include "./iterator.hpp"

namespace ft {
	template <class InputIterator1, class InputIterator2>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) {
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred) {
		while (first1 != last1) {
			if (pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
}

#endif // _EQUAL_HPP__