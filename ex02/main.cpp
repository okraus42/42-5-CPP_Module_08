/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okraus <okraus@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:36:16 by okraus            #+#    #+#             */
/*   Updated: 2024/06/02 16:23:01 by okraus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <list>

int main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "MutantStack<int>::iterator it = mstack.begin(); : "
		<< *it << std::endl;
		++it;
		std::cout << "++it; : "
		<< *it << std::endl;
		--it;
		std::cout << "--it; : "
		<< *it << std::endl;
		while (it != ite)
		{
		std::cout << "++it: " << *it << std::endl;
		++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::list<int> mlist;
		mlist.push_back(5);
		mlist.push_back(17);
		std::cout << mlist.back() << std::endl;
		mlist.pop_back();
		std::cout << mlist.size() << std::endl;
		mlist.push_back(3);
		mlist.push_back(5);
		mlist.push_back(737);
		//[...]
		mlist.push_back(0);
		std::list<int>::iterator it = mlist.begin();
		std::list<int>::iterator ite = mlist.end();
		std::cout << "std::list<int>::iterator it = mlist.begin(); : "
		<< *it << std::endl;
		++it;
		std::cout << "++it; : "
		<< *it << std::endl;
		--it;
		std::cout << "--it; : "
		<< *it << std::endl;
		while (it != ite)
		{
		std::cout << "++it: " << *it << std::endl;
		++it;
		}
		std::list<int> s(mlist);
	}
	return (0);
}