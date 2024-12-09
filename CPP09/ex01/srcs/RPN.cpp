/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:27:29 by lle-pier          #+#    #+#             */
/*   Updated: 2024/12/09 11:49:41 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RPN.hpp"

int stringToInt(const std::string &str)
{
    std::istringstream iss(str);
    int result;
    if (!(iss >> result))
    {
        throw std::runtime_error("Error: Invalid number format");
    }
    if (result > 9)
        throw std::runtime_error("Error: numbers must be lower than 10");
    return(result);
}

int RPN::evaluate(const std::string &expression)
{
    std::stack<int> stack;
    std::istringstream iss(expression);
    std::string token;
    
    while (iss >> token)
    {
        if (std::isdigit(token[0]) || (token.size() > 1 && token[0] == '-'))
        {
            stack.push(stringToInt(token));
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (stack.size() < 2)
                throw std::runtime_error("Error: not enough operands");
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            if (token == "+")
                stack.push(a + b);
            else if (token == "-")
                stack.push(b - a);
            else if (token == "*")
                stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                    throw std::runtime_error("Error: Division by zero");
                stack.push(b / a);
            }
        }
        else 
            throw std::runtime_error("Error: invalid token");
        
    }
    if (stack.size() != 1)
    {
        throw std::runtime_error("Error: invalid expression");
    }
    return (stack.top());
}