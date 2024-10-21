/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:26 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/16 13:24:43 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "iostream"

int main()
{
    Animal* animals[6];
    for (int i = 0; i < 6; i++)
    {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    std::cout << "\n";
    std::cout << "-- sound test --" << std::endl;
    std::cout << "\n";
    for (int i = 0; i < 6; i++)
    {
        animals[i]->makeSound();
        delete animals[i];
    }
    std::cout << "\n";
    std::cout << "-- deep copy test --" << std::endl;
    std::cout << "\n";
    Cat* a = new Cat();
    Cat* b = new Cat(*a);
    Cat c;
    c = *a;

    std::cout << "\n";
    a->setIdea(0, "I am a cat");
    c.setIdea(0, "I am a cat too");
    std::cout << "a idea 1: " << a->getIdea(0) << std::endl;
    std::cout << "c idea 1: " << c.getIdea(0) << "\n" << std::endl;
    b->setIdea(0, "I am a dog");
    std::cout << "a idea 1: " << a->getIdea(0) << std::endl;
    std::cout << "b idea 1: " << b->getIdea(0) << std::endl;
    std::cout << "\n";
    a->setIdea(1, "I stay a cat");
    std::cout << "a idea 2: " << a->getIdea(1) << std::endl;
    std::cout << "b idea 2: " << b->getIdea(1) << std::endl;
    std::cout << "c idea 2: " << c.getIdea(1) << std::endl;
    std::cout << "\n";
    delete a;
    delete b;
    return 0;
}