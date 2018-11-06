#include "ast.hpp"
#include "symbol_table.hpp"

namespace LILC{

bool ASTNode::nameAnalysis(SymbolTable * symTab){
	/*std::cout << "[DELETE ME] Whoops, I'm the ASTNode"
		" base class nameAnalysis function."
		" I should have been overridden."
		" My function declaration should have"
		" probably even been pure virtual.\n";*/
	return true;
}

bool ProgramNode::nameAnalysis(SymbolTable * symTab){
	this->myDeclList->nameAnalysis(symTab);
}

bool DeclListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<DeclNode *>::iterator
		it=myDecls->begin();
		it != myDecls->end(); ++it){

	  DeclNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
}

bool VarDeclNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a varDecl. "
		" you should add the information from my"
		" subtree to the to the symbol table"
		" as a new entry in the current scope table\n";
	return true;
}

bool FnDeclNode::nameAnalysis(SymbolTable * symTab){
	std::cout << "[DELETE ME] I'm a fnDecl. "
		" you should add my information to"
		" the current scope table.\n";
		" you should also add and make current"
		" a new scope table for my body\n";
	return true;
}

void FormalsListNode::nameAnalysis(SymbolTable * symTab){

}

void FnBodyNode::nameAnalysis(SymbolTable * symTab){

}

void ExpListNode::nameAnalysis(SymbolTable * symTab){

}

void StmtListNode::nameAnalysis(SymbolTable * symTab){

}

void StmtNode::nameAnalysis(SymbolTable * symTab){

}

void FormalDeclNode::nameAnalysis(SymbolTable * symTab){

}

void StructDeclNode::nameAnalysis(SymbolTable * symTab){

}

void AssignStmtNode::nameAnalysis(SymbolTable * symTab){

}

void PostIncStmtNode::nameAnalysis(SymbolTable * symTab){

}

void PostDecStmtNode::nameAnalysis(SymbolTable * symTab){

}

void ReadStmtNode::nameAnalysis(SymbolTable * symTab){

}

void WriteStmtNode::nameAnalysis(SymbolTable * symTab){

}

void IfStmtNode::nameAnalysis(SymbolTable * symTab){

}

void IfElseStmtNode::nameAnalysis(SymbolTable * symTab){

}

void WhileStmtNode::nameAnalysis(SymbolTable * symTab){

}

void CallStmtNode::nameAnalysis(SymbolTable * symTab){

}

void ReturnStmtNode::nameAnalysis(SymbolTable * symTab){

}

void IdNode::nameAnalysis(SymbolTable * symTab){

}

void IntNode::nameAnalysis(SymbolTable * symTab){

}

void BoolNode::nameAnalysis(SymbolTable * symTab){

}

void VoidNode::nameAnalysis(SymbolTable * symTab){

}

void StructNode::nameAnalysis(SymbolTable * symTab){

}

void IntLitNode::nameAnalysis(SymbolTable * symTab){

}

void StrLitNode::nameAnalysis(SymbolTable * symTab){

}

void TrueNode::nameAnalysis(SymbolTable * symTab){

}

void FalseNode::nameAnalysis(SymbolTable * symTab){

}

void DotAccessNode::nameAnalysis(SymbolTable * symTab){

}

void AssignNode::nameAnalysis(SymbolTable * symTab){

}

void CallExpNode::nameAnalysis(SymbolTable * symTab){

}

void UnaryMinusNode::nameAnalysis(SymbolTable * symTab){

}

void NotNode::nameAnalysis(SymbolTable * symTab){

}

void PlusNode::nameAnalysis(SymbolTable * symTab){

}

void MinusNode::nameAnalysis(SymbolTable * symTab){

}

void TimesNode::nameAnalysis(SymbolTable * symTab){

}

void DivideNode::nameAnalysis(SymbolTable * symTab){

}

void AndNode::nameAnalysis(SymbolTable * symTab){

}

void OrNode::nameAnalysis(SymbolTable * symTab){

}

void EqualsNode::nameAnalysis(SymbolTable * symTab){

}

void NotEqualsNode::nameAnalysis(SymbolTable * symTab){

}

void LessNode::nameAnalysis(SymbolTable * symTab){

}

void GreaterNode::nameAnalysis(SymbolTable * symTab){

}

void LessEqNode::nameAnalysis(SymbolTable * symTab){

}

void GreaterEqNode::nameAnalysis(SymbolTable * symTab){

}

} // End namespace LIL' C
