#pragma once
#include <iostream>
#include <limits>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "Layout.h"
#include "Functions.h"
using namespace std;

namespace Date
{
    struct stDate
    {
        short year, month, day;
    };

    bool isLeapYear(short year)
    {
        return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
    }

    short NumbersOfDaysInMonth(short month, bool isLeapYear = 1)
    {
        if (month < 1 || month > 12)
            return 0;
        short Days__Of__Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return (month == 2) ? (isLeapYear ? 29 : 28) : Days__Of__Month[month - 1];
        return 31;
    }

    short DayOfTheYear(short year, short month, short day)
    {
        short Total__Days = 0;
        for (short i = 1; i < month; i++)
        {
            Total__Days += NumbersOfDaysInMonth(i, isLeapYear(year));
        }

        Total__Days += day;
        return Total__Days;
    }

    stDate ReadFullDate()
    {
        stDate Date;
        Date.day = Functions::ReadPositiveNumber("Please Enter A Day : ");
        Date.month = Functions::ReadPositiveNumber("Please Enter A Month : ");
        Date.year = Functions::ReadPositiveNumber("Please Enter A Year : ");

        return Date;
    }

    stDate GetSystemDate()
    {
        stDate Date;
        time_t current__time = time(0);
        tm *current__Date = localtime(&current__time);
        Date.day = current__Date->tm_mday;
        Date.month = current__Date->tm_mon + 1;
        Date.year = current__Date->tm_year + 1900;

        return Date;
    }

    short GetDayOrder(short day, short month, short year)
    {
        short a = 0, y = 0, m = 0, d = 0;
        a = (14 - month) / 12;
        y = year - a;
        m = month + (12 * a) - 2;
        // Gorgian Calinder : 0: Sunday, 1: Tuseday etc..
        d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

        return d;
    }

    short GetDayOrder(stDate Date)
    {
        return GetDayOrder(Date.day, Date.month, Date.year);
    }

    bool isLastMonth(short month)
    {
        return ((month == 12)) ? 1 : 0;
    }
    bool isLastDay(stDate Date1)
    {
        return (Date1.day == NumbersOfDaysInMonth(Date1.month, isLeapYear(Date1.year))) ? 1 : 0;
    }

    bool isDateEqual(stDate Date1, stDate Date2)
    {
        return Date1.year != Date2.year ? 0 : Date1.month != Date2.month ? 0
                                          : Date1.day != Date2.day       ? 0
                                                                         : 1;
    }

    bool isDateBefore(stDate Date1, stDate Date2)
    {
        return (Date1.year < Date2.year) ? 1 : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? 1 : (Date1.month == Date2.month ? Date1.day < Date2.day : 0)) : 0);
    }
    stDate AddOneDay(stDate Date)
    {

        if (isLastDay(Date) && isLastMonth(Date.month))
        {
            Date.day = 1;
            Date.month = 1;
            Date.year++;
        }
        else if (isLastDay(Date) && !(isLastMonth(Date.month)))
        {
            Date.day = 1;
            Date.month++;
        }
        else
        {
            Date.day++;
        }

        return Date;
    }

    stDate AddXDays(stDate Date, short Days)
    {
        for (short i = 0; i < Days; i++)
        {
            Date = AddOneDay(Date);
        }

        return Date;
    }
    stDate AddOneweek(stDate Date, short week = 7)
    {
        for (short i = 0; i < week; i++)
        {
            Date = AddOneDay(Date);
        }

        return Date;
    }
    stDate AddXweek(stDate Date, short week)
    {

        for (short i = 0; i < week; i++)
        {
            Date = AddOneweek(Date);
        }

        return Date;
    }
    stDate AddOneMonth(stDate Date, short month = 1)
    {

        if (isLastMonth(Date.month))
        {
            Date.month = 1;
            Date.year++;
        }
        else
        {
            Date.month++;
        }
        // To Fix Error If Date 31/1
        short NumberOfDaysInCurrentMonth = NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year));
        if (Date.day > NumberOfDaysInCurrentMonth)
        {
            Date.day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }
    stDate AddXMonth(stDate Date, short month)
    {

        for (short i = 0; i < month; i++)
        {
            Date = AddOneMonth(Date);
        }

        return Date;
    }
    stDate AddOneYear(stDate Date, short year = 1)
    {
        if ((Date.month == 2 && Date.day == 29) && isLeapYear(Date.year))
        {
            Date.day--;
        }
        Date.year++;

        return Date;
    }
    stDate AddXYear(stDate Date, short year)
    {
        for (short i = 0; i < year; i++)
        {
            Date = AddOneYear(Date);
        }
        return Date;
    }
    stDate AddXYearF(stDate Date, short year)
    {

        Date.year += year;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate AddOneDecade(stDate Date, short Decade = 1)
    {
        Decade *= 10;
        Date.year += Decade;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate AddXDecade(stDate Date, short Decade)
    {
        for (short i = 0; i < Decade; i++)
        {
            Date = AddOneDecade(Date);
        }
        return Date;
    }
    stDate AddXDecadeF(stDate Date, short Decade)
    {
        Decade *= 10;
        Date.year += Decade;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate AddOneCentury(stDate Date, short Cetury = 1)
    {
        Cetury *= 100;
        Date.year += Cetury;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate AddOneMillennium(stDate Date, short Millennium = 1)
    {
        Millennium *= 1000;
        Date.year += Millennium;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }

    bool isFirstMonth(short month)
    {
        return ((month == 1)) ? 1 : 0;
    }
    bool isFirstDay(short day)
    {
        return (day == 1) ? 1 : 0;
    }
    stDate SubtractOneDay(stDate Date)
    {

        if (isFirstDay(Date.day) && isFirstMonth(Date.month))
        {
            Date.day = 31;
            Date.month = 12;
            Date.year--;
        }
        else if (isFirstDay(Date.day) && !(isFirstMonth(Date.month)))
        {
            Date.month--;
            Date.day = NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year));
        }
        else
        {
            Date.day--;
        }

        return Date;
    }

    stDate SubtractXDays(stDate Date, short Days)
    {
        for (short i = 0; i < Days; i++)
        {
            Date = SubtractOneDay(Date);
        }

        return Date;
    }
    stDate SubtractOneweek(stDate Date, short week = 7)
    {
        for (short i = 0; i < week; i++)
        {
            Date = SubtractOneDay(Date);
        }

        return Date;
    }
    stDate SubtractXweek(stDate Date, short week)
    {

        for (short i = 0; i < week; i++)
        {
            Date = SubtractOneweek(Date);
        }

        return Date;
    }
    stDate SubtractOneMonth(stDate Date, short month = 1)
    {

        if (isFirstMonth(Date.month))
        {
            Date.month = 12;
            Date.year--;
        }
        else
        {
            Date.month--;
        }
        // To Fix Error If Date 31/3
        short NumberOfDaysInCurrentMonth = NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year));
        if (Date.day > NumberOfDaysInCurrentMonth)
        {
            Date.day = NumberOfDaysInCurrentMonth;
        }

        return Date;
    }
    stDate SubtractXMonth(stDate Date, short month)
    {

        for (short i = 0; i < month; i++)
        {
            Date = SubtractOneMonth(Date);
        }

        return Date;
    }
    stDate SubtractOneYear(stDate Date, short year = 1)
    {
        if ((Date.month == 2 && Date.day == 29) && isLeapYear(Date.year))
        {
            Date.day--;
        }
        Date.year--;

        return Date;
    }
    stDate SubtractXYear(stDate Date, short year)
    {
        for (short i = 0; i < year; i++)
        {
            Date = SubtractOneYear(Date);
        }
        return Date;
    }
    stDate SubtractXYearF(stDate Date, short year)
    {

        Date.year -= year;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate SubtractOneDecade(stDate Date, short Decade = 1)
    {
        Decade *= 10;
        Date.year -= Decade;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate SubtractXDecade(stDate Date, short Decade)
    {
        for (short i = 0; i < Decade; i++)
        {
            Date = SubtractOneDecade(Date);
        }
        return Date;
    }
    stDate SubtractXDecadeF(stDate Date, short Decade)
    {
        Decade *= 10;
        Date.year -= Decade;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate SubtractOneCentury(stDate Date, short Cetury = 1)
    {
        Cetury *= 100;
        Date.year -= Cetury;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }
    stDate SubtractOneMillennium(stDate Date, short Millennium = 1)
    {
        Millennium *= 1000;
        Date.year -= Millennium;
        if ((Date.month == 2 && Date.day == 29) && !isLeapYear(Date.year))
        {
            Date.day--;
        }
        return Date;
    }

    void swap(stDate &Date01, stDate &Date02)
    {
        stDate temp;
        temp = Date01;
        Date01 = Date02;
        Date02 = temp;
    }
    int DiffInDays(stDate Date01, stDate Date02, bool lastDay = false)
    {
        int Diff__Days = 0;
        short SwipFlag = 1;
        if (!isDateBefore(Date01, Date02))
        {
            swap(Date01, Date02);
            SwipFlag = -1;
        }

        while (isDateBefore(Date01, Date02))
        {
            Diff__Days++;
            Date01 = AddOneDay(Date01);
        }

        return lastDay ? ++Diff__Days * SwipFlag : Diff__Days * SwipFlag;
    }
}