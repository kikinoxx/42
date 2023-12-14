/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:55:10 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/14 17:29:24 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(void)
{
	std::cout << std::endl;

	/*	CHAR	*/

	std::cout << "Conversion of a char 'a':" << std::endl;
	ScalarConverter::convert("a");
	std::cout << std::endl;

	std::cout << "Conversion of a char 'z':" << std::endl;
	ScalarConverter::convert("z");
	std::cout << std::endl;

	/*	INT	*/

	// std::cout << "Conversion of an int '0':" << std::endl;
	// ScalarConverter::convert("0");
	// std::cout << std::endl;

	// std::cout << "Conversion of an int '42':" << std::endl;
	// ScalarConverter::convert("42");
	// std::cout << std::endl;

	// std::cout << "Conversion of an int '-42':" << std::endl;
	// ScalarConverter::convert("-42");
	// std::cout << std::endl;

	/*	FLOAT	*/

	// std::cout << "Conversion of a float '0.0f':" << std::endl;
	// ScalarConverter::convert("0.0f");
	// std::cout << std::endl;

	// std::cout << "Conversion of a float '42.0f':" << std::endl;
	// ScalarConverter::convert("42.0f");
	// std::cout << std::endl;

	// std::cout << "Conversion of a float '-42.0f':" << std::endl;
	// ScalarConverter::convert("-42.0f");
	// std::cout << std::endl;

	// std::cout << "Conversion of a float pseudo literal '-inff':" << std::endl;
	// ScalarConverter::convert("-inff");
	// std::cout << std::endl;

	// std::cout << "Conversion of a float pseudo literal '+inff':" << std::endl;
	// ScalarConverter::convert("+inff");
	// std::cout << std::endl;

	/*	DOUBLE	*/

	// std::cout << "Conversion of a double '0.0':" << std::endl;
	// ScalarConverter::convert("0.0");
	// std::cout << std::endl;

	// std::cout << "Conversion of a double '42.0':" << std::endl;
	// ScalarConverter::convert("42.0");
	// std::cout << std::endl;

	// std::cout << "Conversion of a double '-42.0':" << std::endl;
	// ScalarConverter::convert("-42.0");
	// std::cout << std::endl;

	// std::cout << "Conversion of a double pseudo literal '-inf':" << std::endl;
	// ScalarConverter::convert("-inf");
	// std::cout << std::endl;

	// std::cout << "Conversion of a double pseudo literal '+inf':" << std::endl;
	// ScalarConverter::convert("+inf");
	// std::cout << std::endl;

	// std::cout << "Conversion of a double pseudo literal 'nan':" << std::endl;
	// ScalarConverter::convert("nan");
	// std::cout << std::endl;

	/*	INVALID INPUT	*/

	// std::cout << "Invalid input test with 'fdas':" << std::endl;
	// ScalarConverter::convert("fdas");
	// std::cout << std::endl;

	// std::cout << "Invalid input test with '1+':" << std::endl;
	// ScalarConverter::convert("1+");
	// std::cout << std::endl;

	// std::cout << "Invalid input test with '-1-':" << std::endl;
	// ScalarConverter::convert("-1-");
	// std::cout << std::endl;

	// std::cout << "Invalid input test with '0.0.':" << std::endl;
	// ScalarConverter::convert("0.0.");
	// std::cout << std::endl;

	return (0);
}
