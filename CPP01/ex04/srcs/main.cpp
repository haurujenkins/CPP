/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:47:21 by lle-pier          #+#    #+#             */
/*   Updated: 2024/07/24 19:51:52 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

int main(int argc, char **argv)
{
	if (argc != 4)
		return ((std::cerr << "bad number of args" << std::endl), 0);
	
	std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

	if (s1 == "")
		return ((std::cerr << "empty string not allowed for s1" << std::endl), 1);
	if (s1 == s2)
		return ((std::cerr << "nothing to replace" << std::endl), 1);

	std::ifstream input_file(filename.c_str());
	if (!input_file.is_open())
		return ((std::cerr << "error opening input file" << std::endl), 1);
	
	std::ofstream out_file((filename + ".replace").c_str());
	
	std::string line;
	while (std::getline(input_file, line))
	{
		std::size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.erase(pos, s1.length());
            line.insert(pos, s2);
		}
		out_file << line << std::endl;
	}
	input_file.close();
	out_file.close();
}