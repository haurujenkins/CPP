/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:52:39 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/18 17:07:23 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Main.hpp"

std::size_t ft_strlen(const std::string str)
{
    std::size_t i = 0;

    while (str[i])
        i++;
    return i;
    
}

bool my_isdigit(char c) {
    return c >= '0' && c <= '9';
}

bool caseInsensitiveCompare(const std::string& str1, const std::string& str2) {
    if (ft_strlen(str1) != ft_strlen(str2)) {
        return false;
    }

    for (size_t i = 0; i < ft_strlen(str1); ++i) {
        char c1 = str1[i];
        char c2 = str2[i];

        // Convertir chaque caractère en minuscules manuellement pour comparaison
        if (c1 >= 'A' && c1 <= 'Z') {
            c1 = c1 + ('a' - 'A');
        }
        if (c2 >= 'A' && c2 <= 'Z') {
            c2 = c2 + ('a' - 'A');
        }

        if (c1 != c2) {
            return false;
        }
    }

    return true;
}
