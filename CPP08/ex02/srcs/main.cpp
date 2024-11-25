/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/25 17:56:10 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "../includes/MutantStack.hpp"

int main() {

    std::cout << "Test avec MutantStack:" << std::endl;
    
    MutantStack<int> stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    stack.push(20);
    stack.push(25);
    
    std::cout << "MutantStack (avec itérateurs standard): ";
    for (MutantStack<int>::iterator it = stack.begin(); it != stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "MutantStack (avec itérateurs inverses): ";
    for (MutantStack<int>::reverse_iterator it = stack.rbegin(); it != stack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "\nTest avec std::list:" << std::endl;
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(10);
    lst.push_back(15);
    lst.push_back(20);
    lst.push_back(25);
    
    std::cout << "std::list (avec itérateurs standard): ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "std::list (avec itérateurs inverses): ";
    for (std::list<int>::reverse_iterator it = lst.rbegin(); it != lst.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}