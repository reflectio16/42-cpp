/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meelma <meelma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:47:11 by meelma            #+#    #+#             */
/*   Updated: 2026/01/13 16:01:02 by meelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    std::string   _firstName;
    std::string   _lastName;
    std::string   _nickname;
    std::string   _phoneNumber;
    std::string   _darkestSecret;
public:
    void setFirstName(std::string _firstName);
    void setLastName(std::string _lastName);
    void setNickname(std::string _nickname);
    void setPhoneNum(std::string _phoneNumber);
    void setDarkestSecret(std::string _darkestSecret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNum() const;
    std::string getDarkestSecret() const;        
};

#endif