#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
using namespace std;
#include "Date.h"
#include "POS.h"

// Draw a diagram of the problem
namespace ict{
	void Date::errCode(int errorCode) {
		switch (errorCode) {
			case 0:
				errorCode = NO_ERROR;
				break;
			case 1:
				errorCode = CIN_FAILED;
				break;
			case 3:
				errorCode = YEAR_ERROR;
				break;
			case 4:
				errorCode = DAY_ERROR;
				break;
			case 5:
				errorCode = HOUR_ERROR;
				break;
			case 6:
				errorCode = MIN_ERROR;
				break;
		}
	}

	void Date::set(int year, int mon, int day, int hour, int min) {
		m_year = year;
		m_mon = mon;
		m_day = day;
		m_hour = hour;
		m_min = min;
		m_readErrorCode = NO_ERROR;
	}

	void Date::set(){
    time_t t = time(NULL);
    tm lt = *localtime(&t);
    m_day = lt.tm_mday;
    m_mon = lt.tm_mon + 1;
    m_year = lt.tm_year + 1900;
    if (dateOnly()){
      m_hour = m_min = 0;
    }
    else{
      m_hour = lt.tm_hour;
      m_min = lt.tm_min;
    }
  }

  bool Date::operator==(const Date & D) const {
	  if (this->value() == D.value()) { return true; }
	  else { return false; }
  }

  bool Date::operator!=(const Date & D) const {
	  if (this->value() != D.value()) { return true; }
	  else { return false; }
  }

  bool Date::operator<(const Date & D) const {
	  if (this->value() < D.value()) { return true; }
	  else { return false; }
  }

  bool Date::operator>(const Date & D) const {
	  if (this->value() > D.value()) { return true; }
	  else { return false; }
  }

  bool Date::operator<=(const Date & D) const {
	  if (this->value() <= D.value()) { return true; }
	  else { return false; }
  }

  bool Date::operator>=(const Date & D) const {
	  if (this->value() >= D.value()) { return true; }
	  else { return false; }
  }

  int Date::value()const{
    return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
    mon--;
    return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
  }
}
