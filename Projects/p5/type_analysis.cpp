#include "ast.hpp"
#include "symbol_table.hpp"

namespace LILC{

bool ASTNode::typeAnalysis(){
	throw std::runtime_error("Internal Error: \n"
		"We should never see this, as it\n"
		"is supposed to be overridden in any\n"
		"subclass at which it is encountered");
}

bool ProgramNode::typeAnalysis(){
	//TODO: recurse down the AST, making sure to
	// uncover any type errors as detailed in the
	// project 5 spec
	/*
	std::cerr << "[DELETE ME]: program node typeAnalysis\n"
	" should probably check for some children typing before\n"
	" declaring victory here.\n";
	*/

	return myDeclList->typeAnalysis();
}

bool DeclListNode::typeAnalysis(){
	for (DeclNode * decl : *myDecls){
		if (!decl->typeAnalysis()) {
			return Error;
		}
	}

	return Accept;
}

bool ExpNode::typeAnalysis() {

}

bool IdNode::typeAnalysis() {

}

bool StmtNode::typeAnalysis() {

}

bool FormalsListNode::typeAnalysis() {

}

bool ExpListNode::typeAnalysis() {

}

bool StmtListNode::typeAnalysis() {

}

bool FnBodyNode::typeAnalysis() {

}

bool FnDeclNode::typeAnalysis() {

}

bool FormalDeclNode::typeAnalysis() {

}

bool StructDeclNode::typeAnalysis() {

}

bool IntNode::typeAnalysis() {

}

bool BoolNode::typeAnalysis() {
	return Bool;
}

bool VoidNode::typeAnalysis() {
	return Void;
}

bool StructNode::typeAnalysis() {
	return Struct;
}

bool IntLitNode::typeAnalysis() {
	return Int;
}

bool StrLitNode::typeAnalysis() {
	return String;
}

bool TrueNode::typeAnalysis() {
	return Bool;
}

bool FalseNode::typeAnalysis() {
	return Bool;
}

bool DotAccessNode::typeAnalysis() {

}

bool AssignNode::typeAnalysis() {

}

bool CallExpNode::typeAnalysis() {
	if (myId->typeAnalysis() != "Function") {
		//TODO: reporrt error
		return false;
	} else if (myExpList->typeAnalysis() == Error) {
		//TODO: reporrt error
		return false;
	}

	//check that the number of arguments matches up
	if (myExpList->myExps.size() != dynamic_cast<FuncSymbol*>(mySymbol)->formalSymbols->size()) {
		//TODO: report error
		return false;
	}

	//check that the type of arguments matches up
	for (int i=0; i < myExpList->myExps.size();i++) {
		std::list<ExpNode>::iterator it = myExpList->myExps.begin();
		std::list<VarSymbol>::iterator jt = dynamic_cast<FuncSymbol*>(mySymbol)->formalSymbols->begin();

		if (dynamic_cast<IdNode*>((*it)).getString() != (*jt).getTypeString()) {
			return false;
		}

		std::advance(it, i);
		std::advance(jt, i);
	}

	return true;
}

bool UnaryMinusNode::typeAnalysis() {

}

bool NotNode::typeAnalysis() {

}

bool BinaryExpNode::typeAnalysis() {

}

bool PlusNode::typeAnalysis() {

}

bool MinusNode::typeAnalysis() {

}

bool TimesNode::typeAnalysis() {

}

bool DivideNode::typeAnalysis() {

}

bool AndNode::typeAnalysis() {

}

bool OrNode::typeAnalysis() {

}

bool EqualsNode::typeAnalysis() {

}

bool NotEqualsNode::typeAnalysis() {

}

bool LessNode::typeAnalysis() {

}

bool GreaterNode::typeAnalysis() {

}

bool LessEqNode::typeAnalysis() {

}

bool GreaterEqNode::typeAnalysis() {

}

bool AssignStmtNode::typeAnalysis() {

}

bool PostIncStmtNode::typeAnalysis() {

}

bool PostDecStmtNode::typeAnalysis() {

}

bool ReadStmtNode::typeAnalysis() {
	if (myExp->typeAnalysis() == Function) {
		return Error;
	} else if (myExp->typeAnalysis() == Struct /*TYPE?*/) {
		//TODO report error
		return Error;
	} else if (myExp->typeAnalysis() == Struct /*VARIABLE?*/) {
		//TODO report error
		return Error;
	}
}

bool WriteStmtNode::typeAnalysis() {
	if (myExp->typeAnalysis() == Function) {
		//TODO report error
		return Error;
	} else if (myExp->typeAnalysis() == Struct /*TYPE?*/) {
		//TODO report error
		return Error;
	} else if (myExp->typeAnalysis() == Struct /*VARIABLE?*/) {
		//TODO report error
		return Error;
	} else if (myExp->typeAnalysis() == Void) {
		//TODO report error
		return Error;
	}

	return myExp->typeAnalysis();
}

bool IfStmtNode::typeAnalysis() {

}

bool IfElseStmtNode::typeAnalysis() {

}

bool WhileStmtNode::typeAnalysis() {

}

bool CallStmtNode::typeAnalysis() {

}

bool ReturnStmtNode::typeAnalysis() {

}

bool VarDeclNode::typeAnalysis() {

}



/*
* Creates a comma-separated string listing the types of formals.
* This function mostly serves as a helper for
* FnDeclNode::getTypeString() in building a function
* type signature for unparsing.
*/
std::string FormalsListNode::getTypeString(){
	std::string res = "";
	bool first = true;
	for (FormalDeclNode * decl : *myFormals){
		if (first){ first = false; }
		else { res += ","; }
		res += decl->getTypeString();
	}
	return res;
}

/*
* Create a string representing the type signature of a
* function.  This function is used for building a function
* type signature for unparsing.
*/
std::string FnDeclNode::getTypeString(){
	return myFormals->getTypeString()
		+ "->"
		+ myRetType->getTypeString();
}

/*
* The type of a declaration is that of the
* type it declares
*/
std::string FormalDeclNode::getTypeString(){
	return myType->getTypeString();
}

} // End namespace LILC
