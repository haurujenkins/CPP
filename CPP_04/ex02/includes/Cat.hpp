/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 20:32:08 by lle-pier          #+#    #+#             */
/*   Updated: 2024/10/15 21:47:47 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
    public:
        Cat();
        ~Cat();
        Cat(Cat const & cat);
        Cat & operator=(Cat const & cat);
        void makeSound() const;
        void setIdea(int index, std::string idea);
        std::string getIdea(int index) const;
    private:
        Brain* brain;
};

#endif