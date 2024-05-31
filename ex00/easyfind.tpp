/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/05/31 16:36:34 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "colours.hpp"

template<typename container>
typename container::iterator easyfind(container& ctr, int n)
{
	typename container::iterator found;
	found = find(ctr.begin(), ctr.end(), n);
	if (found != ctr.end())
		return (found);
	// declaring output string stream
	std::ostringstream oss;
 
	// Sending a number as a stream into output
	// string
	oss << n;
 
	// the str() converts number into string
	std::string numstr = oss.str();
	std::string error = ERROR_COLOUR "no occurrence of " + numstr + " found" NO_COLOUR;
	throw std::logic_error(error);
}
