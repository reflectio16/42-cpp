/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 15:32:07 by meelma            #+#    #+#             */
/*   Updated: 2026/04/22 16:26:09 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _signed;
        const int           _signGrade;
        const int           _execGrade;
        
    public:

        Form();
        Form(const std::string& name, int signGrade, int execGrade);
        Form(const Form& other);
        Form& operator=(const Form& other);
        ~Form();

        const std::string&  getName() const;
        bool                isSigned() const;
        int                 getSignGrade() const;
        int                 getExecGrade() const;

        void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
        
};

std::ostream& operator<<(std::ostream& os, const Form& f);


#endif