/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:32:14 by meelma            #+#    #+#             */
/*   Updated: 2026/04/23 14:26:50 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Deafult"), _signed(false), _signGrade(150), _execGrade(150) {}

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();        
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed),
     _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        _signed = other._signed; // Only this member can be changed by operator=
    return *this;
}

Form::~Form() {}

const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getSignGrade() const { return _signGrade; }
int Form::getExecGrade() const { return _execGrade; }

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form \"" << f.getName() << "\""
        << ", signed: " << (f.isSigned() ? "yes" : "no")
        << ", sign grade: " << f.getSignGrade()
        << ", exec grade: " << f.getExecGrade();
    return os;
}
