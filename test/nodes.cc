#include "Node.h"

int main()
{
  xml4cpp::TextNode text(L"hejsan");
  for ( auto const & n : text.childNodes() )
    ;

}
