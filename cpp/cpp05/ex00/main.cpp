/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:51:26 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/12 11:27:45 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	creationOK(void)
{
	try {
		Bureaucrat	ok("ok", 23);
		std::cout << ok << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	creationNO(void)
{
	try {
		Bureaucrat	no("no", 0);
		// Bureaucrat	no("no", 151);
		std::cout << no << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	incOK(void)
{
	Bureaucrat	bob("Bob", 150);
	std::cout << std::endl;

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.incGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

void	decOK(void)
{
	Bureaucrat	bob("Bob", 1);
	std::cout << std::endl;

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.decGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

void	incNO(void)
{
	Bureaucrat	bob("Bob", 1);
	std::cout << std::endl;

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.incGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

void	decNO(void)
{
	Bureaucrat	bob("Bob", 150);
	std::cout << std::endl;

	std::cout << COLOR("Initial values: ", WHITE) << bob << std::endl;

	try {
		bob.decGrade();
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << COLOR("After values: ", WHITE) << bob << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << std::endl;

	creationOK();
	creationNO();

	incOK();
	decOK();
	incNO();
	decNO();

	return (0);
}
