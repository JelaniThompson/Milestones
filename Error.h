// compilation safegaurds

#include <iostream>
namespace ict {
   class Error {
      char* m_message;
   public:
   // constructors
	   Error();
	   Error(const char* errorMessage);
   // destructor
	   ~Error();
   // deleted constructor and operator=
	   Error(const Error& em) = delete;
	   Error& operator=(const Error& em) = delete;
   // operator= for c-style strings
	   void operator=(const char* errorMessage);
   // methods
	   virtual ~Error();
	   void clear();
	   bool isClear()const;
	   void message(const char* value);
	   operator const char*() const;
	   operator bool()const;
   // cast overloads

   };
   // operator << overload prototype for cout
   std::ostream& operator<<(std::ostream& os, const Student& s);
}
