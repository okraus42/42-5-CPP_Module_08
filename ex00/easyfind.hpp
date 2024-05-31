/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/31 16:35:49 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

//# include <cstddef>
# include <iostream>
# include <algorithm>
# include <exception>
# include <string>
# include <sstream>

template<typename container>
typename container::iterator easyfind(container& ctr, int n);

# include "easyfind.tpp"

#endif