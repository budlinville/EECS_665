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
	std::list<VarSymbolEntry*>* pars = new std::list<VarSymbolEntry*>();

	for (std::list<FormalDeclNode *>::iterator it=myFormals->myFormals->begin(); it != myFormals->myFormals->end(); ++it){
	    FormalDeclNode * elt = *it;
		std::string type = elt->myType->toString();
		std::string id = elt->myId->myStrVal;
		VarSymbolEntry* var = new VarSymbolEntry(type, id, -1);
		pars->push_back(var);
	}

	FnSymbolEntry * entry = new FnSymbolEntry(type, id, pars);

	symTab->addEntry(entry);
	symTab->enterNewScope();

	for (std::list<VarSymbolEntry *>::iterator it=pars->begin(); it != pars->end(); ++it){
	  	VarSymbolEntry * elt = *it;
	  	symTab->addEntry(elt);

	}


	return myBody->nameAnalysis(symTab);
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
	bool ret = myDeclList->nameAnalysis(symTab)
		|| myStmtList->nameAnalysis(symTab);
	symTab->leaveCurrentScope();
	return ret;
}

bool ExpListNode::nameAnalysis(SymbolTable * symTab){
	bool result = true;

	for (std::list<ExpNode *>::iterator it=myExps->begin(); it != myExps->end(); ++it){
	  	ExpNode * elt = *it;
	  	result = elt->nameAnalysis(symTab) && result;
	}

	return result;
}

bool StmtListNode::nameAnalysis(SymbolTable * symTab){
	bool ret = true;

	for (std::list<StmtNode *>::iterator it=myStmts->begin(); it != myStmts->end(); ++it){
	  	StmtNode * elt = *it;
	  	ret = elt->nameAnalysis(symTab) && ret;
	}

	return ret;
}

bool FormalDeclNode::nameAnalysis(SymbolTable * symTab){
	std::string type = myType->toString();
	std::string id = myId->myStrVal;
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
		VarSymbolEntry * entry = new VarSymbolEntry(type, id, -1);
		symTab->addEntry(entry);
	}

	return ret;
}

bool StructDeclNode::nameAnalysis(SymbolTable * symTab){
	std::string id = myId->myStrVal;
	std::list<VarSymbolEntry*>* items = new std::list<VarSymbolEntry*>();
	bool ret = true;

	for (std::list<DeclNode*>::iterator it=myDeclList->myDecls->begin(); it != myDeclList->myDecls->end(); ++it){
		DeclNode * elt = *it;
		std::string itemType = elt->getType()->toString();
		std::string itemId = elt->getId()->myStrVal;

		if(itemType == "void") {
			//TODO: error("Invalid name of struct type", id);
			return false;
		}

		items->push_back(new VarSymbolEntry(itemType, itemId, -1));
	}

	StructSymbolEntry * entry = new StructSymbolEntry(id, items);

	if (symTab->getEntry(id) == nullptr) {
		symTab->addEntry(entry);
	} else {
		//TODO: error("Multiply declared identifier", id);
		ret = false;
	}

	return ret;


}

bool AssignStmtNode::nameAnalysis(SymbolTable * symTab){
	return myAssign->nameAnalysis(symTab);
}

bool PostIncStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool PostDecStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool ReadStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool WriteStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool IfStmtNode::nameAnalysis(SymbolTable * symTab){
	symTab->enterNewScope();
	bool result = myExp->nameAnalysis(symTab);
	result = result && myDecls->nameAnalysis(symTab);
	result = result && myStmts->nameAnalysis(symTab);
	symTab->leaveCurrentScope();
	return result;
}

bool IfElseStmtNode::nameAnalysis(SymbolTable * symTab){
	symTab->enterNewScope();
	bool result = myExp->nameAnalysis(symTab);
	result = result && myDeclsT->nameAnalysis(symTab);
	result = result && myStmtsT->nameAnalysis(symTab);
	symTab->leaveCurrentScope();
	symTab->enterNewScope();
	result = result && myDeclsF->nameAnalysis(symTab);
	result = result && myStmtsF->nameAnalysis(symTab);
	symTab->leaveCurrentScope();
	return result;
}

bool WhileStmtNode::nameAnalysis(SymbolTable * symTab){
	symTab->enterNewScope();
	bool result = myExp->nameAnalysis(symTab);
	result = result && myDecls->nameAnalysis(symTab);
	result = result && myStmts->nameAnalysis(symTab);
	symTab->leaveCurrentScope();
	return result;
}

bool CallStmtNode::nameAnalysis(SymbolTable * symTab){
	return myCallExp->nameAnalysis(symTab);
}

bool ReturnStmtNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool IdNode::nameAnalysis(SymbolTable * symTab){
	myEntry = symTab->getEntry(myStrVal);
	if (myEntry == nullptr) {
		error("Undeclared identifier", myStrVal);
		return false;
	}
	return true;
}

/*
bool IntNode::nameAnalysis(SymbolTable * symTab){

}

bool BoolNode::nameAnalysis(SymbolTable * symTab){

}

bool VoidNode::nameAnalysis(SymbolTable * symTab){

}

bool StructNode::nameAnalysis(SymbolTable * symTab){

}
*/

bool IntLitNode::nameAnalysis(SymbolTable * symTab){
	return true;
}

bool StrLitNode::nameAnalysis(SymbolTable * symTab){
	return true;
}

bool TrueNode::nameAnalysis(SymbolTable * symTab){
	return true;
}

bool FalseNode::nameAnalysis(SymbolTable * symTab){
	return true;
}

bool DotAccessNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp->nameAnalysis(symTab);
	IdNode * n = dynamic_cast<IdNode *>(myExp);
	if (n == nullptr) {
		error("Dot-access of non-struct type", n->myStrVal);
		return false;
	}

	StructSymbolEntry * entry = dynamic_cast<StructSymbolEntry *>(symTab->getEntry(n->myEntry->getType()));

	if (entry == nullptr) {
		error("Dot-access of non-struct type", n->myStrVal);
		return false;
	}

	VarSymbolEntry * varEntry = entry->find(myId->myStrVal);
	if (varEntry) {
		myId->myEntry = varEntry;
		return true;
	}
	error("Invalid struct field name", myId->myStrVal);
	return false;
}

bool AssignNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExpLHS->nameAnalysis(symTab);
	result = result && myExpRHS->nameAnalysis(symTab);
	return result;
}

bool CallExpNode::nameAnalysis(SymbolTable * symTab){
	bool result = myId->nameAnalysis(symTab);
	result = result && myExpList->nameAnalysis(symTab);
	return result;
}

bool UnaryMinusNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool NotNode::nameAnalysis(SymbolTable * symTab){
	return myExp->nameAnalysis(symTab);
}

bool PlusNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool MinusNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool TimesNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool DivideNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool AndNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool OrNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool EqualsNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool NotEqualsNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool LessNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool GreaterNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;
}

bool LessEqNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;

}

bool GreaterEqNode::nameAnalysis(SymbolTable * symTab){
	bool result = myExp1->nameAnalysis(symTab);
	result = result && myExp2->nameAnalysis(symTab);
	return result;

}

} // End namespace LIL' C
