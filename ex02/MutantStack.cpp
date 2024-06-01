/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/01 16:24:14 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "colours.hpp"

Span::Span(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the Span class called.";
	ft_uncolorize();
	std::cout << std::endl;
	this->_size = 0;
}

Span::Span(unsigned int size)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "unsigned int constructor of the Span class called.";
	ft_uncolorize();
	std::cout << std::endl;
	this->_size = size;
}

Span::Span(const Span& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the Span class called.";
	ft_uncolorize();
	std::cout << std::endl;
	*this = copy;
}

Span &Span::operator = (const Span &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assigment operator of the Span class called.";
	ft_uncolorize();
	std::cout << std::endl;
	if (this != &src)
	{
		this->_numSet = src._numSet;
		this->_size = src._size;
	}
	return (*this);
}
Span::~Span(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the Span class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

unsigned int	Span::size(void) const
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "size of the Span class called.";
	ft_uncolorize();
	std::cout << std::endl;
	return (this->_size);
}

void	Span::addNumber(int n)
{
	this->_numSet.insert(n);
}

void	Span::addNumbers(unsigned int n, int (*func)(unsigned int))
{
	for (unsigned int u = 0; u < n; ++u)
		this->_numSet.insert((*func)(u));
}

unsigned int	Span::shortestSpan(void) const
{
	unsigned int	shortest = UINT_MAX;
	if (this->_numSet.size() < 2)
		throw (NoSpanException());
	for (std::multiset<int>::iterator it = (this->_numSet.begin());
		++it != this->_numSet.end(); ++it)
		if (shortest > (unsigned int)(*it - *(--it)))
			shortest = *(++it) - *(--it);
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Shortest span is: <" << shortest << ">.";
	ft_uncolorize();
	std::cout << std::endl;
	return (shortest);
}

unsigned int	Span::longestSpan(void) const
{
	unsigned int	longest;
	if (this->_numSet.size() < 2)
		throw (NoSpanException());
	longest = *(this->_numSet.rbegin()) - *(this->_numSet.begin());
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Longest span is: <" << longest << ">.";
	ft_uncolorize();
	std::cout << std::endl;
	return (longest);
}

void	Span::putSpan(void) const
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	for (std::multiset<int>::iterator it = this->_numSet.begin(); it != this->_numSet.end(); ++it)
		(it == --(this->_numSet.end()))	? std::cout << *it
										: std::cout << *it << ", ";
	ft_uncolorize();
	std::cout << std::endl;
}

const char*	Span::IndexOutOfBoundsException::what() const throw()
{
	return (ERROR_COLOUR "Index out of bounds." NO_COLOUR);
}

const char*	Span::NoSpanException::what() const throw()
{
	return (ERROR_COLOUR "Not enough numbers to detect span" NO_COLOUR);
}
