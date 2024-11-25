/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:07:25 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/25 17:54:05 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> 
{
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator const_reverse_iterator; // Ajout d'un alias reverse_const_iterator

        MutantStack() : std::stack<T>() {}
        MutantStack(const MutantStack& other) : std::stack<T>(other) {}
        MutantStack& operator=(const MutantStack& other) {
            if (this != other)
                std::stack<T>::operator=(other);
            return *this;
        }
        ~MutantStack() {}

        iterator begin() {
            return this->c.begin();
        }
        
        iterator end() {
            return this->c.end();
        }

        reverse_iterator rbegin() {
            return this->c.rbegin();
        }

        reverse_iterator rend() {
            return this->c.rend();
        }

        const_iterator begin() const {
            return this->c.begin();
        }

        const_iterator end() const {
            return this->c.end();
        }

        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }
        const_reverse_iterator rend() const {
            return this->c.rend(); 
        }
};

#endif