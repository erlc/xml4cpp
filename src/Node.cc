#include "Node.h"
#include "DOMException.h"
namespace xml4cpp
{
  NodeList Node::childNodes() const
  {
    return children;
  }
  Node & Node::appendChild(const Node & other)
  {
    std::shared_ptr<Node> new_node { other.clone() };
    children.push_back(new_node);
    return *(new_node);
    
  }
  Node & Node::parentNode() const
  {
    if ( parent == nullptr )
      throw DOMException(Exception_Code::NOT_FOUND_ERR);
    return *parent;
  }

  Node & NodeList::item(const unsigned long index) const
  {
    if ( index >= size() )
      throw DOMException(Exception_Code::NOT_FOUND_ERR);

    return *(vector::at(index));
  }

  std::size_t NodeList::length() const 
  {
    return vector::size();
  }

  TextNode * TextNode::clone() const
  {
    return new TextNode(*this);
  }

  Node_Type TextNode::nodeType() const
  {
    return Node_Type::TEXT_NODE;
  }

}
