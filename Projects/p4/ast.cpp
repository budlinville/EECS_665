// Use this file if you'd like to implement any auxilary functions in your
// AST nodes
#include "ast.hpp"

namespace LILC{
    std::string StructNode::toString() {
        return myId->myStrVal; 
    }
}   //end namespace LILC
