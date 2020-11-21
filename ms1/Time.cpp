/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Time.cpp
Version 1.0
Author	Anmol Garg
Revision History
-----------------------------------------------------------
Date        Reason
2020/11/11  Preliminary release
2020/11/11  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::reset()
	{
		m_min = getTime();
		return *this;
	}

	Time::Time(unsigned int min)
	{
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const
	{
		ostr << setfill('0') << setw(2) << right << m_min / 60 << ":" << setw(2) << m_min % 60;
		ostr.unsetf(ios::right);
		return ostr;
	}

	std::istream& Time::read(std::istream& istr)
	{
		int hours = 0, minutes = 0;
		char colon = 'X';
		istr >> hours;
		istr >> colon;
		if (colon != ':') istr.setstate(ios::failbit);
		istr >> minutes;
		m_min = hours * 60 + minutes;
		return istr;
	}

	Time::operator int() const
	{
		return m_min;
	}

	Time& Time::operator*=(int val)
	{
		m_min *= val;
		return *this;
	}

	Time& Time::operator-=(const Time& D)
	{
		if (D.m_min > m_min) m_min += 24 * 60;
		m_min -= D.m_min;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Time& T)
	{
		return T.write(os);
	}

	std::istream& operator>>(std::istream& istr, Time& T)
	{
		return T.read(istr);
	}
}