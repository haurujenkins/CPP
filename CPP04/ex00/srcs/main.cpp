/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:08:26 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/16 13:36:43 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "iostream"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << std::endl;
    j->makeSound(); //should output the cat sound!
    i->makeSound();
    meta->makeSound();
    std::cout << "\n" << "j is a " << j->getType() << std::endl;
    std::cout << "i is a " << i->getType() << std::endl;
    std::cout << "meta is a " << meta->getType() << "\n" << std::endl;
    delete meta;
    delete j;
    delete i;
    
    std::cout << "\n----- test with wrong classes -----\n" << std::endl;
    
    const WrongAnimal* meta2 = new WrongAnimal();
    const WrongAnimal* j2 = new WrongCat();

    std::cout << std::endl;
    j2->makeSound(); //should output the cat sound!
    meta2->makeSound();
    std::cout << "\n" << "j2 is a " << j2->getType() << std::endl;
    std::cout << "meta2 is a " << meta2->getType() << "\n" << std::endl;
    delete meta2;
    delete j2;
    return 0;
}