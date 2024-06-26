/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:08:58 by okraus            #+#    #+#             */
/*   Updated: 2024/06/02 14:32:25 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

//# include <cstddef>
# include <iostream>
# include <stack>


template<typename T> class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		
		MutantStack(void);
		MutantStack(const MutantStack& copy);
		MutantStack &operator	= (const MutantStack<T> &src);
		~MutantStack(void);

		iterator	end(void);
		iterator	begin(void);
		const_iterator	end(void) const;
		const_iterator	begin(void) const;
};

# include "MutantStack.tpp"

#endif