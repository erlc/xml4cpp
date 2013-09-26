#ifndef NODE_H
#define NODE_H
#include <vector>
#include <memory>
#include <string>
#include "DOM.h"
namespace xml4cpp
{

  class NodeList : private std::vector<std::shared_ptr<class Node>>
  {
  public:
    NodeList() = default;
    
    using vector::cbegin;
    using vector::cend;
    using vector::begin;
    using vector::end;
    class Node & item(const unsigned long) const;
    std::size_t length() const;
  
  private:
    friend class Node;
  };

  enum class Node_Type : unsigned short
  {
      ELEMENT_NODE = 1,
      ATTRIBUTE_NODE = 2,
      TEXT_NODE = 3,
      CDATA_SECTION_NODE = 4,
      ENTITY_REFERENCE_NODE = 5,
      ENTITY_NODE = 6,
      PROCESSING_INSTRUCTION_NODE = 7,
      COMMENT_NODE = 8,
      DOCUMENT_NODE = 9,
      DOCUMENT_TYPE_NODE = 10,
      DOCUMENT_FRAGMENT_NODE = 11,
      NOTATION_NODE = 12
  };
  class Node
  {
  public:
    NodeList childNodes() const;
    Node & appendChild(const Node &);
    Node & parentNode() const;
    virtual Node_Type nodeType() const = 0;
  protected:
    Node(const Node &) = default;
  private:
    virtual Node* clone() const = 0; // allways send to shared_ptr!
    NodeList children;
    std::shared_ptr<Node> parent;
  };
  
  class TextNode : public Node
  {
  public:
    TextNode(const DOMString & d)
      : Node{}, data{d}
    {}
    Node & appendChild(const Node &) = delete;
    Node_Type nodeType() const;
  private:
    TextNode(const TextNode &) = default;
    TextNode * clone() const override;
    DOMString data;
  };
}


#endif
