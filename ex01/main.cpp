/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:16 by okraus            #+#    #+#             */
/*   Updated: 2024/06/01 16:13:14 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib> 
#include "Span.hpp"

#define MAX_VAL 210001

int	adder_double(unsigned int u)
{
	return (u * 2);
}

int main(void)
{
	Span numbers(MAX_VAL);
	// for (int i = 0; i < MAX_VAL; ++i)
	// 	numbers.addNumber(i);
	// numbers.addNumber(0);
	// numbers.addNumber(INT_MIN);
	// numbers.addNumber(INT_MAX);
	numbers.addNumbers(MAX_VAL, &adder_double);
	numbers.putSpan();
	numbers.shortestSpan();
	numbers.longestSpan();
	return (0);
}