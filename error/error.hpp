/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>
#include <exception>

class error : public std::exception
{
    public:
        error(std::string error_msg) noexcept;
        char const *what() const noexcept override;

    private:
        std::string m_error_msg;

};

#endif /* !ERROR_HPP_ */