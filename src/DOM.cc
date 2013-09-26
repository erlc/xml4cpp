#include "DOM.h"

namespace xml4cpp
{
  DOMString::DOMString(const std::string & str)
    : std::wstring{str.begin(), str.end() } {}

  DOMString::DOMString(const char * data)
    : DOMString{std::string{data}} {}

  DOMString::operator std::string () const { 
    return std::string{ begin(), end() };
  }
}
