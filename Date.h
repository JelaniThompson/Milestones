// compilation safegaurds
#ifndef DATE_H
#define DATE_H
#include <iostream>
// ict namespace 
namespace ict {
   // Date defined Error values
	int NO_ERROR = 0;
	int CIN_FAILED = 1;
	int YEAR_ERROR = 2;
	int MON_ERROR = 3;
	int DAY_ERROR = 4;
	int HOUR_ERROR = 5;
	int MIN_ERROR = 6;
	// Only true if the object is to only hold the date and not the time
	bool m_dateOnly = false;
   class Date {
   private:
      // member variables
	   int m_year;
	   int m_mon;
	   int m_day;
	   int m_hour;
	   int m_min;
	   int m_readErrorCode;

     // private methods

	   /* Return a unique integer number based on the date-time. 
	   Use the value to compare two dates. If the value() one one date-time is larger than the other,
	   then the former date-time follows the second */
      int value() const;

	  // Set the m_readErrorCode member variable to one of the possible values listed above
	  void errCode(int errorCode);

	  // This function returns the number of days in the month based on m_year and m_mon values
	  int mdays() const;

	  // Set the date and time to the current date and time of the system
	  void set();

	  // Sets the member variables to the corresponing arguments and then sets the m_readErrorCode to NO_ERROR
	  void set(int year, int mon, int day, int hour, int min);

   public:
	// constructors

	   // Set the m_dateOnly attribute to false and then sets the date and time to current system's date and time using set()
	   Date();

	   /* Set m_dateOnly attribute to true and accepts three integer arguments to set their values
	   Also set m_hour and m_min to zero. Set m_readErrorCode to NO_ERROR*/
	   Date(int m_year, int m_mon, int m_day);
	   
	   /* Same thing as above but with extra arguments. m_min should 
	   also have a default value of 0 so the constructor can be called with four arguments as well*/
	   Date(int m_year, int m_mon, int m_day, int m_hour, int m_min);
      
	   void set();

      // operator overloads
	   /* Return the result of comparing the left operand to the right operand
	   these operators use the value() member function in their comparison. For example,
	   operator< returns true if this->value() is less than D.value(); otherwise return false*/
	   bool operator==(const Date& D)const;
	   bool operator!=(const Date& D)const;
	   bool operator<(const Date& D)const;
	   bool operator>(const Date& D)const;
	   bool operator<=(const Date& D)const;
	   bool operator>=(const Date& D)const;

      // methods
	   // Return the value of m_readErrorCode
	   int errCode() const;
	   
	   // Returns true if m_readErrorCode is not equal to zero
	   bool bad() const;

	   // Returns the m_dateOnly attribute
	   bool dateOnly() const;

	   /* Sets the m_dateOnly attribute to the "value" argument.
	   Also if the "value" is true, then it will set m_hour and m_min to zero*/
	   void dateOnly(bool value);

	   int mdays()const;

      // input stream  and output stream read and write methods
	   std::istream& read(std::istream& is = std::cin);
	   std::ostream& write(std::ostream& ostr = std::cout) const;
   };
}
#endif
