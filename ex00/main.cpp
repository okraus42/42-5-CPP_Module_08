/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:16 by okraus            #+#    #+#             */
/*   Updated: 2024/05/31 16:27:14 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "easyfind.hpp"
#include <vector>
#include <list>
#include <limits>
#include <deque>
#include <queue>
#include <stack>
#include <cstdlib> 
#include <ctime>


/*
receive an empty non-associative container and a size, 
fill it with random values (modulo max char to be potential int, float, char)
then randomly either return a number that is guarantee to be inside the container 
or not
*/
template <typename T>
typename T::value_type seqctr_loader(T& ctr, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		typename T::value_type val = static_cast<typename T::value_type>(rand() % std::numeric_limits<char>::max());
		ctr.push_back(val);
	}
	int idx = rand() % std::numeric_limits<char>::max();
	if (idx % 2)
	{
		idx = idx % size;
		typename T::iterator it = ctr.begin();
		for (int i = 0; i < idx; ++i)
			it++;
		std::cout << "look for : " << *it << std::endl;
		return (*it);
	}
	else
	{
		std::cout << "NO FOUND GUARANTEE :look for : " << static_cast<typename T::value_type>(idx) << std::endl;
		return (static_cast<typename T::value_type>(idx));
	}
}

template <typename T>
void find_wrapper(T ctr, int n)
{
	 try 
	{
		typename T::iterator r = easyfind(ctr, n);
		std::cout << "found : " << *r << " in the cointainer\n";
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

template <typename Container>
void printContainer(const Container& container) 
{
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	std::vector<int> vec;
	std::list<char> lst;
	std::deque<float> dq;
	std::vector<int> empt;

	int i = seqctr_loader(vec, 20);
	float f = seqctr_loader(lst, 10);
	double d = seqctr_loader(dq, 42);

	std::cout << "\nprinting the container content\n";
	printContainer(vec);
	printContainer(lst);
	printContainer(dq);
	printContainer(empt);
			
	find_wrapper(vec, i);
	find_wrapper(lst, f);
	find_wrapper(dq, d);

	std::cout << "\nTest : looking for 100 in empty container\n";
	find_wrapper(empt, 100);
			
	std::cout << "\nAll test done\n";
}
