/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author
Revision History
-----------------------------------------------------------
Date        Reason
2020/11/20  Preliminary release
2020/11/20  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds {
    Patient::Patient(int ticketNumber, bool fileIO): m_ticket(ticketNumber)
    {
        m_patient_name = nullptr;
        m_ohip = 0;
        m_fileIO = fileIO;
    }
    bool Patient::fileIO()const
    {
        return m_fileIO;
    }
    void Patient::fileIO(bool fileIO)
    {
        m_fileIO = fileIO;
    }
    void Patient::setArrivalTime()
    {
        m_ticket.resetTime();
    }
    Patient::operator Time() const
    {
        return Time(m_ticket);
    }
    int Patient::number() const
    {
        return m_ticket.number();
    }
    std::ostream& Patient::csvWrite(std::ostream& os) const
    {
        os << type() << "," << m_patient_name << "," << m_ohip << ",";
        return m_ticket.csvWrite(os);
    }
    std::istream& Patient::csvRead(std::istream& istr)
    {
        char patientName[51]{};
        istr.get(patientName, 51, ',');
        delete[] m_patient_name;
        m_patient_name = new char[strlen(patientName) + 1];
        strcpy(m_patient_name, patientName);
        istr.ignore(2000, ',');
        istr >> m_ohip;
        istr.ignore(2000,',');
        return m_ticket.csvRead(istr);
    }
    std::ostream& Patient::write(std::ostream& os) const
    {
        return os << m_ticket << endl << m_patient_name << ", OHIP: " << m_ohip;
    }
    std::istream& Patient::read(std::istream& istr)
    {
        cout << "Name: ";
        char patientName[51]{};
        istr.get(patientName, 51, '\n');
        delete[] m_patient_name;
        m_patient_name = new char[strlen(patientName) + 1];
        strcpy(m_patient_name, patientName);
        istr.ignore(2000, '\n');
        cout << "OHIP: ";
        m_ohip = getIntInRange(100000000, 999999999);
        return istr;
    }
    Patient::~Patient()
    {
        delete[] m_patient_name;
    }
    bool operator==(const Patient& P, char character)
    {
        return P.type() == character;
    }
    bool operator==(const Patient& LO, const Patient& RO)
    {
        return LO.type() == RO.type();
    }
}