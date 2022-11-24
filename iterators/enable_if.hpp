/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaouab <msaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:28:23 by msaouab           #+#    #+#             */
/*   Updated: 2022/11/17 16:45:21 by msaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ENABLE_IF_HPP__
# define _ENABLE_IF_HPP__

# include "../containers.hpp"

namespace ft {
	template <bool Cond, class T = void>
	struct enable_if {};
	template <class T>
	struct enable_if <true, T> {
		typedef T type;
	};
}

#endif // _ENABLE_IF_HPP__