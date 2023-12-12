/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:35:32 by kmorin            #+#    #+#             */
/*   Updated: 2023/12/12 15:05:56 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

//In private since we have a constructor to set all values
AForm::AForm(void) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
	if (SHOWMSG)
		std::cout << COLOR("AForm ", GREEN) << COLOR(this->_name, MAGENTA) << \
			COLOR(" Default constructor called", GREEN) << std::endl;
}

AForm::AForm(const AForm& src) : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	if (SHOWMSG)
		std::cout << COLOR("AForm ", GREEN) << COLOR(this->_name, MAGENTA) << \
			COLOR(" Copy constructor called", GREEN) << std::endl;
}

//In private since _name, _gradeToSign and _gradeToExec are const
AForm&	AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	if (SHOWMSG)
		std::cout << COLOR("AForm ", GREEN) << COLOR(this->_name, MAGENTA) << \
			COLOR(" Assignation operator called", GREEN) << std::endl;
	return (*this);
}

AForm::~AForm(void)
{
	if (SHOWMSG)
		std::cout << COLOR("AForm ", RED) << COLOR(this->_name, MAGENTA) << \
			COLOR(" destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                          PARAMETRIC CONSTRUCTORS                           */
/* ************************************************************************** */

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : _name(name), _signed(false), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
	checkValidValue(gradeSign);
	checkValidValue(gradeExec);
	if (SHOWMSG)
		std::cout << COLOR("AForm ", GREEN) << COLOR(this->_name, MAGENTA) << \
			COLOR(" Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                              MEMBERS FUNCTIONS                             */
/* ************************************************************************** */

const std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getGradeSign(void) const
{
	return (this->_gradeToSign);
}

int	AForm::getGradeExec(void) const
{
	return (this->_gradeToExec);
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void	AForm::checkValidValue(int grade)
{
	if (grade < 1)
	{
		std::cout << COLOR("AForm: ", MAGENTA);
		throw GradeTooHighException();
	}
	else if (grade > 150)
	{
		std::cout << COLOR("AForm: ", MAGENTA);
		throw GradeTooLowException();
	}
}
/*
	execute is a virtual pure so implementation is in each derived classes of Form
*/

/* ************************************************************************** */
/*                      NESTED CLASSES MEMBERS FUNCTIONS                      */
/* ************************************************************************** */

const char*	AForm::GradeTooHighException::what() const throw()
{
	return (RED "Grade is too high !" RESET);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (RED "Grade is too low !" RESET);
}

const char* AForm::NotSignedException::what() const throw()
{
	return (RED "Form is not signed. It cannot be executed." RESET);
}

/* ************************************************************************** */
/*                             EXTERNAL FUNCTIONS                             */
/* ************************************************************************** */

std::ostream&	operator<<(std::ostream& o, const AForm& src)
{
	if (src.getSigned() == true)
		o << COLOR(src.getName(), MAGENTA) << COLOR(" AForm is ", CYAN) << COLOR("signed", GREEN) <<
			COLOR(", his required grade to sign it is ", CYAN) << COLOR(src.getGradeSign(), GREEN) << \
			COLOR(" and his required grade to execute it is ", CYAN) << COLOR(src.getGradeExec(), GREEN) << \
			COLOR(".", CYAN) << RESET;
	else
		o << COLOR(src.getName(), MAGENTA) << COLOR(" AForm is ", CYAN) << COLOR("not signed", GREEN) <<
			COLOR(", his required grade to sign it is ", CYAN) << COLOR(src.getGradeSign(), GREEN) << \
			COLOR(" and his required grade to execute it is ", CYAN) << COLOR(src.getGradeExec(), GREEN) << \
			COLOR(".", CYAN) << RESET;
	return (o);
}
