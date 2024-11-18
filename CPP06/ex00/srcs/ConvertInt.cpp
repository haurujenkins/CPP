/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConvertInt.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:02:20 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/18 17:13:21 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

int stringToInt(const std::string& str)
{
    int result = 0, sign = 1;
    std::size_t i = 0, len = ft_strlen(str);

    if (str[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for (; i < len; ++i)
    {
        if (str[i] >= '0' && str[i] <= '9')
            result = result * 10 + (str[i] - '0');
        else
        {
            std::cerr << "Erreur : caractère non numérique trouvé !" << std::endl;
            return 0;
        }
    }

    return result * sign;
}

bool is_int(const std::string str)
{
    if (str[0] == '\0') return false;
    int i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;

    while (str[i])
    {
        if (!my_isdigit(str[i]))
            return false;
        i++;
    }
    return true;
}

void toInt(const std::string str)
{
    std::cout << "str : " << "int" << std::endl;
    int i = stringToInt(str);
    
    char charValue = static_cast<char>(i + 0);
    float floatValue = static_cast<float>(i);
    double doubleValue = static_cast<double>(i);

    if (charValue < 32 || charValue > 126)
        std::cout << "char : " << "Non displayable" << std::endl;
    else
        std::cout << "char : " << charValue << std::endl;
    std::cout << "int : " << i << std::endl;
    std::cout << "float : " << floatValue << std::endl;
    std::cout << "double : " << doubleValue << std::endl;
}