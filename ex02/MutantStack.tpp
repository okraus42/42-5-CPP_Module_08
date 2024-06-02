/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/02 14:31:58 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include "colours.hpp"

template<typename T> MutantStack<T>::MutantStack(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Default constructor of the MutantStack class called.";
	ft_uncolorize();
	std::cout << std::endl;
}

template<typename T> MutantStack<T>::MutantStack(const MutantStack& copy)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Copy constructor of the MutantStack class called.";
	ft_uncolorize();
	std::cout << std::endl;
	*this = copy;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator = (const MutantStack<T> &src)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Assigment operator of the MutantStack class called.";
	ft_uncolorize();
	std::cout << std::endl;
	if (this != &src)
	{
		this->c = src.c;
	}
	return (*this);
}

template<typename T> MutantStack<T>::~MutantStack(void)
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Destructor of the MutantStack class called.";
	ft_uncolorize();
	std::cout << std::endl;
}


/********************* Iterators Methods ***********************************/
template<typename T> typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Iterator begin.";
	ft_uncolorize();
	std::cout << std::endl;
	return (this->c.begin());
}

template<typename T> typename MutantStack<T>::iterator MutantStack<T>::end()
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Iterator end.";
	ft_uncolorize();
	std::cout << std::endl;
	return (this->c.end());
}

template<typename T> typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Const iterator begin.";
	ft_uncolorize();
	std::cout << std::endl;
	return (this->c.begin());
}

template<typename T> typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	ft_colorize(reinterpret_cast<uintptr_t>(this));
	std::cout << "Const iterator end.";
	ft_uncolorize();
	std::cout << std::endl;
	return (this->c.end());
}
