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
	return this->myDeclList->nameAnalysis(symTab);
}

bool DeclListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<DeclNode *>::iterator
		it=myDecls->begin();
		it != myDecls->end(); ++it){

	  DeclNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);

	}
	return result;
}

//add information from subtree to symbol table as new entry in current scope table
bool VarDeclNode::nameAnalysis(SymbolTable * symTab){
	std::string type = myType->toString();
	std::string id = myId->myStrVal;
	int size = mySize;
	bool ret = true;

	if (symTab->getEntry(id) != nullptr) {
		//TODO stderr("Multiply declared identifier", id);
		ret = false;
	}

	if (type == "void") {
		//TODO stderr("Non-function declared void", id);
		ret = false;
	}

	if (ret) {
		VarSymbolEntry * entry = new VarSymbolEntry(type, id, size);
		symTab->addEntry(entry);
	}

	return ret;
}

//add information to current scope table. Also add and make new scope table for body.
bool FnDeclNode::nameAnalysis(SymbolTable * symTab){
	std::string type = myType->toString();
	std::string id = myId->myStrVal;
	std::list<VarSymbolEntry*>* pars = new std::list<VarDefSymbol*>();

	for (std::list<FormalDeclNode *>::iterator it=myFormals->GetFormals()->begin(); it != myFormals->GetFormals()->end(); ++it){
	    FormalDeclNode * elt = *it;
		std::string type = elt->GetType()->toString();
		std::string id = elt->GetId()->myStrVal;
		VarSymbolEntry* var = new VarDefSymbol(type, id, VarSymbolEntry::NOT_STRUCT);
		pars->push_back(var);
	}

	FnSymbolEntry * entry = new FnSymbolEntry(type, id, pars);

	symTab->addEntry(entry);
	symTab->enterNewScope();

	for (std::list<VarSymbolEntry *>::iterator it=pars->begin(); it != pars->end(); ++it){
	  	VarSymbolEntry * elt = *it;
	  	symTab->addEntry(elt);

	}


	return true;
}

bool FormalsListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;
	for (std::list<FormalDeclNode *>::iterator
		it=myFormals->begin();
		it != myFormals->end(); ++it){

	  FormalDeclNode * elt = *it;
	  result = result && elt->nameAnalysis(symTab);
	}
	return result;
}

bool FnBodyNode::nameAnalysis(SymbolTable * symTab){

}

bool ExpListNode::nameAnalysis(SymbolTable * symTab){

}

bool StmtListNode::nameAnalysis(SymbolTable * symTab){

}

bool StmtNode::nameAnalysis(SymbolTable * symTab){

}

bool FormalDeclNode::nameAnalysis(SymbolTable * symTab){

}

bool StructDeclNode::nameAnalysis(SymbolTable * symTab){

}

bool AssignStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool PostIncStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool PostDecStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool ReadStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool WriteStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool IfStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool IfElseStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool WhileStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool CallStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool ReturnStmtNode::nameAnalysis(SymbolTable * symTab){

}

bool IdNode::nameAnalysis(SymbolTable * symTab){

}

bool IntNode::nameAnalysis(SymbolTable * symTab){

}

bool BoolNode::nameAnalysis(SymbolTable * symTab){

}

bool VoidNode::nameAnalysis(SymbolTable * symTab){

}

bool StructNode::nameAnalysis(SymbolTable * symTab){

}

bool IntLitNode::nameAnalysis(SymbolTable * symTab){

}

bool StrLitNode::nameAnalysis(SymbolTable * symTab){

}

bool TrueNode::nameAnalysis(SymbolTable * symTab){

}

bool FalseNode::nameAnalysis(SymbolTable * symTab){

}

bool DotAccessNode::nameAnalysis(SymbolTable * symTab){

}

bool AssignNode::nameAnalysis(SymbolTable * symTab){

}

bool CallExpNode::nameAnalysis(SymbolTable * symTab){

}

bool UnaryMinusNode::nameAnalysis(SymbolTable * symTab){

}

bool NotNode::nameAnalysis(SymbolTable * symTab){

}

bool PlusNode::nameAnalysis(SymbolTable * symTab){

}

bool MinusNode::nameAnalysis(SymbolTable * symTab){

}

bool TimesNode::nameAnalysis(SymbolTable * symTab){

}

bool DivideNode::nameAnalysis(SymbolTable * symTab){

}

bool AndNode::nameAnalysis(SymbolTable * symTab){

}

bool OrNode::nameAnalysis(SymbolTable * symTab){

}

bool EqualsNode::nameAnalysis(SymbolTable * symTab){

}

bool NotEqualsNode::nameAnalysis(SymbolTable * symTab){

}

bool LessNode::nameAnalysis(SymbolTable * symTab){

}

bool GreaterNode::nameAnalysis(SymbolTable * symTab){

}

bool LessEqNode::nameAnalysis(SymbolTable * symTab){

}

bool GreaterEqNode::nameAnalysis(SymbolTable * symTab){

}

} // End namespace LIL' C
