/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:29:24 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/27 16:35:04 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <cstdlib>

bool	isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }
    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;
    return true;
}

bool	isValidValue(const std::string& value)
{
    std::istringstream iss(value);
    float f;

    if (iss >> f && f >= 0 && f <= 1000)
    {
        return true;
    }
    return false;
}

bool	loadDataFromCSV(std::map<std::string, float>& dataMap)
{
	std::ifstream file("data.csv");
	if (!file)
	{
		std::cerr << "Error : can't open data.csv" << std::endl;
		return false;
	}

	std::string line;
	while (std::getline(file, line))
	{
		if (line == "date,exchange_rate")
			continue ;
		std::istringstream ss(line);
		std::string date, valueStr;
		std::getline(ss, date, ',');
		std::getline(ss, valueStr);
		float value = std::stof(valueStr);
		dataMap[date] = value;
	}
	return true;
}

void	isFileValid(std::ifstream& file)
{
	std::string line;
	while (std::getline(file, line))
	{
		size_t separatorPos = line.find(" | ");
    	if (separatorPos == std::string::npos)
        	std::cerr << "Erreur : Séparateur manquant dans la ligne -> " << line << std::endl;

		std::istringstream ss(line);
		std::string date, valueStr;
		date = line.substr(0, separatorPos);
		valueStr = line.substr(separatorPos + 3);
		float value = std::stof(valueStr);
		if (isValidDate(date) && isValidValue(valueStr)) {
            continue;
        } else
            std::cerr << "Ligne invalide : " << line << std::endl;

	}
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cerr << "just one arg pls" << std::endl;
        return 1;
    }
    std::ifstream file(argv[1]);
    if (!file)
    {
        std::cerr << "arg need to be a file" << std::endl;
        return 1;
    }
    std::map<std::string, float> bitcoinData;
    loadDataFromCSV(bitcoinData);
	isFileValid(file);
    file.close();
    return 0;
}