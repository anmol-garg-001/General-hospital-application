/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
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
#include "Ticket.h"
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_
namespace sdds {
	class Patient: public IOAble {
		char* m_patient_name;
		int m_ohip;
		Ticket m_ticket;
		bool m_fileIO;
	public:
		Patient(int ticketNumber = 0, bool fileIO = false);
		Patient(const Patient& P) = delete;
		Patient& operator=(const Patient& P) = delete;
		virtual char type() const = 0;
		bool fileIO()const;
		void fileIO(bool fileIO);
		void setArrivalTime();
		operator Time()const;
		int number()const;
		std::ostream& csvWrite(std::ostream& os)const;
		std::istream& csvRead(std::istream& istr);
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& istr);
		~Patient();
	};
	bool operator==(const Patient& P, char character);
	bool operator==(const Patient& LO, const Patient& RO);
}
#endif // !SDDS_PATIENT_H_


