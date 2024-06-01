/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/01 15:59:46 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

//# include <cstddef>
# include <iostream>
# include <iterator>
# include <set>
# include <climits>

class Span
{
	public:
		Span(void);
		Span(unsigned int size);
		Span(const Span& copy);
		Span &operator	= (const Span &src);
		~Span(void);

		unsigned int	size(void) const;
		void			addNumber(int n);
		void			addNumbers(unsigned int n, int (*func)(unsigned int));
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;
		void			putSpan(void) const;
		class IndexOutOfBoundsException : public std::exception
		{
			public:
				const char*		what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				const char*		what() const throw();
		};
	
	private:
		std::multiset<int>	_numSet;
		unsigned int		_size;
};

#endif