
#ifndef ITERACTION_HPP
#define ITERACTION_HPP

#include <cstring>
#include <istream>

#include <Date.hpp>

struct Iteraction
{
    int id, responses[6];
    Date date;

    Iteraction()
    { }

    Iteraction(const int& _id, const int * _responses, const Date& _date): id(_id), date(_date)
    {
        std::memcpy(responses, _responses, 6*sizeof(int));
    }
};

std::istream& operator>>(std::istream &infile, Iteraction it);

#endif
