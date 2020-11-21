/* Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	
Revision History
-----------------------------------------------------------
Date        Reason
2020/11/17  Preliminary release
2020/11/17  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#include <iostream>
#include "IOAble.h"
namespace sdds {
    std::ostream& operator<<(std::ostream& os, const IOAble& IO)
    {
        return IO.write(os);
    }
    std::istream& operator>>(std::istream& istr, IOAble& IO)
    {
        return IO.read(istr);
    }
    IOAble::~IOAble(){}
}