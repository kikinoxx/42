/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:52:58 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 14:32:17 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#include "Color.hpp"
#include "Brain.hpp"

class Animal {

	protected:
		std::string	_type;

	public:
		//Canonical class functions
		Animal(void);
		Animal(const Animal& src);
		Animal&	operator=(const Animal& rhs);
		virtual ~Animal(void);

		//Member Function
		virtual void	makeSound(void) const;

		//Getter
		std::string		getType(void) const;
};

#endif //ANIMAL_HPP
