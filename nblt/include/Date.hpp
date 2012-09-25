
#ifndef DATE_HPP
#define DATE_HPP

#include <cstdlib>
#include <istream>

struct Date
{
    int day, month, year;

    Date(const Date& _dat): day(_dat.day), month(_dat.month), year(_dat.year)
    { }

    Date(int _day = 0, int _month = 0, int _year = 0): day(_day), month(_month), year(_year)
    { }

    /**
     * Formato de entrada dd/mm/yyyy
     */
    Date(const char * szDate)
    {
        year = std::atoi(szDate + 6);
        month = std::atoi(szDate + 3);
        day = std::atoi(szDate);
    }
};

std::istream& operator>>(std::istream &infile, Date date);

#endif
