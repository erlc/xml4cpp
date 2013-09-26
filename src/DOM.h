#ifndef DOM_H
#define DOM_H
#include <string>

namespace xml4cpp
{
  class DOMString : public std::wstring
  {
  public:
    using std::wstring::wstring;
    DOMString(const std::string &);
    DOMString(const char *);
    operator std::string() const;
  };
}
#endif
