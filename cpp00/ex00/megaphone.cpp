/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcosta <hcosta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 21:20:18 by hcosta            #+#    #+#             */
/*   Updated: 2026/11/13 20:41:59 by hcosta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::string palavra = argv[i];
		for (std::size_t j = 0; j < palavra.length(); j++)
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(palavra[j])));
	}
	std::cout << std::endl;
	return (0);
}
