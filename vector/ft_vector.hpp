/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:57:09 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/24 19:07:19 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_VECTOR_HPP_
# define __FT_VECTOR_HPP_

# include "../containers.hpp"

namespace ft {
	template < class T, class Alloc = std::allocator<T> >
	class vector {
		private:
		public:
			typedef	T 											value_type;
			typedef	allocator									allocator_type;
			typedef	typename::allocator_type::pointer			pointer;
			typedef	typename::allocator_type::reference			reference;
			typedef	typename::allocator_type::const_pointer		const_pointer;
			typedef	typename::allocator_type::const_reference	const_reference;
			typedef	iterator<pointer>							iterator;
			typedef	iterator<pointer>							const_iterator;
			typedef	reverse_iterator<iterator>					reverse_iterator;
			typedef	reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef	std::ptrdiff_t								difference_type;
			typedef	std::size_t									size_type;
			
			explicit vector (const allocator_type& alloc = allocator_type()) {
				_val = nullptr;
				_size = 0;
				_cap = 0;
			}
			vector &operator=(const vector &rhs);
			~vector();
	};

	vector::vector() {
	}
	vector::~vector() {
	}
}

#endif // __FT_VECTOR_HPP_