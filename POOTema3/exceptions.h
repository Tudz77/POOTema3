#pragma once

#include <exception>

class wrongDate : public std::exception
{
public:
    wrongDate() noexcept {}
    wrongDate(const wrongDate&) noexcept = default;
    wrongDate& operator= (const wrongDate&) noexcept = default;
    virtual ~wrongDate() noexcept = default;
    virtual const char* what() const noexcept {
        return "nonTriunghiulara";
    }
};


class negative : public std::exception
{
public:
    negative() noexcept {}
    negative(const negative&) noexcept = default;
    negative& operator= (const negative&) noexcept = default;
    virtual ~negative() noexcept = default;
    virtual const char* what() const noexcept {
        return "dimensiuniDiferite";
    }
};

class cardNumber : public std::exception
{
public:
    cardNumber() noexcept {}
    cardNumber(const cardNumber&) noexcept = default;
    cardNumber& operator= (const cardNumber&) noexcept = default;
    virtual ~cardNumber() noexcept = default;
    virtual const char* what() const noexcept {
        return "dimensiuniDiferite";
    }
};