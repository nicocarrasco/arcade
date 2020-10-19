/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** error
*/

#include "error.hpp"

error::error(std::string error_msg) noexcept
{
    m_error_msg = error_msg;
}

const char* error::what() const noexcept
{
    return m_error_msg.c_str();
}