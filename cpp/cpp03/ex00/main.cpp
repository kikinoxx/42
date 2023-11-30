/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:55:35 by kmorin            #+#    #+#             */
/*   Updated: 2023/11/30 12:35:06 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	bob("bob");
	ClapTrap	joe("joe");
	std::cout << std::endl;

	bob.attack("joe");
	joe.takeDamage(bob.getAttackDamage());

	// ClapTrap	rien;
	// std::cout << std::endl;


	// rien.attack("joe");
	// joe.takeDamage(10);

	// joe.beRepaired(2);

	// rien.setName("rien");

	// rien.attack("joe");
	// joe.takeDamage(1);
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.attack("joe");
	// rien.beRepaired(1);
	// rien.attack("joe");

	return (0);
}
