/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:29:48 by lle-pier          #+#    #+#             */
/*   Updated: 2024/11/28 16:15:47 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

int stringToInt(const std::string& str)
{
    std::istringstream iss(str);
    int number;
    iss >> number;
    if (iss.fail())
    {
        throw std::runtime_error("Invalid integer format");
    }
    return number;
}

float stringToFloat(const std::string& str)
{
    std::istringstream iss(str);
    float number;
    iss >> number;
    if (iss.fail())
    {
        throw std::runtime_error("Invalid float format: " + str);
    }
    return number;
}

bool isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.size(); ++i) {
        if ((i == 4 || i == 7) && date[i] == '-') continue;
        if (!std::isdigit(date[i])) return false;
    }

    try {
        int year = stringToInt(date.substr(0, 4));
        int month = stringToInt(date.substr(5, 2));
        int day = stringToInt(date.substr(8, 2));

        if (month < 1 || month > 12) return false;

        int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            daysInMonth[1] = 29;
        }

        if (day < 1 || day > daysInMonth[month - 1]) return false;
        return true;
    } catch (...) {
        return false;
    }
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

bool loadDataFromCSV(std::map<std::string, float>& dataMap)
{
    std::ifstream file("data.csv");
    if (!file)
    {
        std::cerr << "Error: can't open data.csv" << std::endl;
        return false;
    }
    std::string line;
    while (std::getline(file, line))
    {
        if (line == "date,exchange_rate")
            continue;

        std::istringstream ss(line);
        std::string date, valueStr;
        std::getline(ss, date, ',');
        std::getline(ss, valueStr);

        try {
            float value = stringToFloat(valueStr);  // Remplacement de std::stof
            dataMap[date] = value;
        } catch (const std::exception& e) {
            std::cerr << "Error converting value: " << e.what() << std::endl;
        }
    }
    return true;
}

float BitcoinExchange::getValueAtDate(const std::string& date)
{
    // Recherche dans la map si la date exacte existe
    std::map<std::string, float> bitcoinData;
    if (!loadDataFromCSV(bitcoinData)) {
        std::cerr << "Error loading CSV data." << std::endl;
        return -2.0f;
    }
    std::map<std::string, float>::const_iterator it = bitcoinData.find(date);
    
    if (it != bitcoinData.end())  // Si la date exacte est trouvée
    {
        return it->second;  // Retourne la valeur associée à cette date
    }

    // Si la date n'est pas trouvée, on cherche la date précédente la plus proche
    it = bitcoinData.lower_bound(date);  // Trouve le premier élément qui n'est pas inférieur à 'date'

    if (it == bitcoinData.begin())  // Si on est déjà au début de la map
        return -1.0f;  // Retourne une valeur par défaut si aucune date précédente n'est disponible

    // On revient à l'élément précédent dans la map (c'est la date la plus proche avant la donnée recherchée)
    --it;

    return it->second;  // Retourne la valeur associée à la date précédente la plus proche
}

void BitcoinExchange::convFromFile(std::ifstream& file)
{
    if (!file) 
    {
        std::cerr << "arg need to be a file" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line))
    {
        size_t separatorPos = line.find(" | ");
        if (separatorPos == std::string::npos) {
            std::cerr << "Error : missing separator -> " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, separatorPos);
        std::string valueStr = line.substr(separatorPos + 3);

        try {
            // Convertir la valeur en float (ou gérer l'erreur de conversion)
            float value = stringToFloat(valueStr);  // Conversion de la chaîne en float

            // Vérifier si la date est valide et si la valeur est correcte
            if (!isValidDate(date) || !isValidValue(valueStr)) {
                std::cerr << "Invalid line: " << line << std::endl;
                continue;
            }

            // Rechercher le taux de change pour la date dans la map
            float exchangeRate = BitcoinExchange::getValueAtDate(date);

            // Si un taux de change a été trouvé, afficher la ligne avec le taux de change
            if (exchangeRate != -1.0f && exchangeRate != -2.0f) {
                std::cout << date << " => " << value << " = " << exchangeRate * value << std::endl;
            } else {
                std::cerr << date << ", can't find exchange rate"<< std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error : " << e.what() << " in line -> " << line << std::endl;
        }
    }
}

void BitcoinExchange::convFromArg(int argc, char *argv[])
{
    if (argc != 2) {
        std::cerr << "just one arg pls" << std::endl;
        return;
    }
    std::ifstream file(argv[1]);
    BitcoinExchange::convFromFile(file);
}
