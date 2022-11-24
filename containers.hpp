/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:50:00 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/24 11:14:09 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __CONTAINERS_HPP_
# define __CONTAINERS_HPP_

# define false 0
# define true 1
# define MAX_RAM 4294967296
# define BUFFER_SIZE 4096
# define COUNT (MAX_RAM / (int)sizeof(Buffer))

# include <iostream>
# include <string>
# include <deque>
# include <stdlib.h>
# include <type_traits>
# include <memory>
# include "./map/ft_map.hpp"
# include "./stack/ft_stack.hpp"
# include "./vector/ft_vector.hpp"
# include "./iterators/pair.hpp"
# include "./iterators/equal.hpp"
# include "./iterators/iterator.hpp"
# include "./iterators/enable_if.hpp"
# include "./iterators/is_integral.hpp"
# include "./iterators/iterator_traits.hpp"
# include "./iterators/reverse_iterator.hpp"
# include "./iterators/lexicographical_compare.hpp"

#endif // __CONTAINERS_HPP_