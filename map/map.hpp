/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:56:58 by msaouab           #+#    #+#             */
/*   Updated: 2022/12/03 16:21:46 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_MAP_HPP_
# define __FT_MAP_HPP_

# include "../stack/stack.hpp"

namespace ft {
	template < class Key,						// map::key_type
    class T,									// map::mapped_type
    class Compare = less<Key>,					// map::key_compare
    class Alloc = allocator<pair<const Key,T> >	// map::allocator_type
    > class map {
		public:
			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const key_type,mapped_type>			value_type;
			typedef Compare											key_compare;
			typedef Alloc											allocator_type;
			typedef typename	allocator_type::reference			reference;
			typedef typename	allocator_type::const_reference		const_reference;
			typedef typename	allocator_type::pointer				pointer;
			typedef typename	allocator_type::const_pointer		const_pointer;	
			typedef std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
	}
}

# endif // __FT_MAP_HPP_