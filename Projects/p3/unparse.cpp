#include "ast.hpp"

namespace LILC{

void ProgramNode::unparse(std::ostream& out, int indent){
	myDeclList->unparse(out, indent);
}

void DeclListNode::unparse(std::ostream& out, int indent){
	for (std::list<DeclNode *>::iterator it=myDecls.begin();
		it != myDecls.end(); ++it){
	    DeclNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void VarDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myType->unparse(out, 0);
	out << " ";
	myId->unparse(out, 0);
	out << "\n";
}

void StructDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "struct " << myId << " {\n";
	myStructBody->unparse(out, indent + 1);
	doIndent(out, indent);
	out << "\n};";
}

void StructBodyNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	for (std::list<VarDeclNode *>::iterator it=myVarDecls.begin();
		it != myVarDecls.end(); ++it){
	    VarDeclNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void FnDeclNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myType->unparse(out, indent);
	out << " ";
	myId->unparse(out, indent);
	myFormals->unparse(out, indent);
	myFnBody->unparse(out, (indent+1));
}

void FormalsNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "(";
	myFormalsList->unparse(out, indent);
	out << ")";
}

void FormalDeclNode::unparse(std::ostream& out, int indent){
	myType->unparse(out, 0);
	out << " ";
	myId->unparse(out, 0);
}

void FormalsListNode::unparse(std::ostream& out, int indent){
	for (std::list<FormalDeclNode *>::iterator it=myFormalDecls->begin();
		it != myFormalDecls->end(); ++it){
	    FormalDeclNode * elt = *it;
	    elt->unparse(out, indent);
		if (std::next(it) != myFormalDecls->end()) {
			out << ", ";
		}
	}
}

void FnBodyNode::unparse(std::ostream& out, int indent){
	out << "{";
	myDeclList->unparse(out, (indent+1));
	myStmtList->unparse(out, (indent+1));
	out << "\n";
	doIndent(out, indent);
	out << "}\n\n";
}

void IdNode::unparse(std::ostream& out, int indent){
	out << myStrVal;
}

void IntNode::unparse(std::ostream& out, int indent){
	out << "int";
}

void BoolNode::unparse(std::ostream& out, int indent){
	out << "bool";
}

void StmtListNode::unparse(std::ostream& out, int indent){
	for (std::list<StmtNode *>::iterator it=myStmtNodes->begin();
		it != myStmtNodes->end(); ++it){
	    StmtNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void ExpListNode::unparse(std::ostream& out, int indent){
	for (std::list<ExpNode *>::iterator it=myExpNodes->begin();
		it != myExpNodes->end(); ++it){
	    ExpNode * elt = *it;
	    elt->unparse(out, indent);
	}
}

void ExpNode::unparse(std::ostream& out, int indent){

}

void AssignNode::unparse(std::ostream& out, int indent){
	myExpNode1->unparse(out, indent);
	out << " = ";
	myExpNode2->unparse(out, indent);
}

void AssignStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myAssignNode->unparse(out, 0);
	out << ";\n";
}

void PostIncStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myExpNode->unparse(out, 0);
	out << "++;\n";
}

void PostDecStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myExpNode->unparse(out, 0);
	out << "--;\n";
}

void ReadStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "cin >> ";
	myExpNode->unparse(out, 0);
	out << ";\n";
}

void WriteStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "cout <<";
	myExpNode->unparse(out, 0);
	out << ";\n";
}

void IfStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "if (";
	myExpNode->unparse(out, 0);
	out << "){\n";
	myDeclList->unparse(out, indent);
	myStmtList->unparse(out, indent);
	out << "\n";
	doIndent(out, indent);
	out << "}\n";
}

void IfElseStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "if (";
	myExpNode->unparse(out, 0);
	out << "){\n";
	myDeclList1->unparse(out, indent);
	myStmtList1->unparse(out, indent);
	doIndent(out, indent);
	out << "\n} else {\n";
	myDeclList2->unparse(out, indent);
	myStmtList2->unparse(out, indent);
	doIndent(out, indent);
	out << "\n}\n";
}

void WhileStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "while (";
	myExpNode->unparse(out, 0);
	out << "){\n";
	myDeclList->unparse(out, indent);
	myStmtList->unparse(out, indent);
	out << "\n";
	doIndent(out, indent);
	out << "}\n";
}

void CallExpNode::unparse(std::ostream& out, int indent){
	myIdNode->unparse(out, 0);
	out << "(";
	myExpList->unparse(out, 0);
	out << ")";
}

void CallStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myCallExp->unparse(out, 0);
}

void ReturnStmtNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "return";
	if (myExpNode != nullptr) {
		out << " ";
		myExpNode->unparse(out, 0);
		out << " ";
	}
	out << ";\n";
}

void IntLitNode::unparse(std::ostream& out, int indent){
	out << val;
}

void StrLitNode::unparse(std::ostream& out, int indent){
	out << "\"" << val << "\"";
}

void TrueNode::unparse(std::ostream& out, int indent){
	out << "true";
}


void FalseNode::unparse(std::ostream& out, int indent){
	out << "false";
}

void DotAccessNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	myExpNode->unparse(out, 0);
	out << ".";
	myIdNode->unparse(out, 0);
}

void UnaryExpNode::unparse(std::ostream& out, int indent){
	myExp->unparse(out, indent);
}

void UnaryMinusNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "-";
	myExp->unparse(out, 0);
}

void NotNode::unparse(std::ostream& out, int indent){
	doIndent(out, indent);
	out << "!";
	myExp->unparse(out, 0);
}

void BinaryExpNode::unparse(std::ostream& out, int indent){/* virtual */}

void PlusNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " + ";
	myExp2->unparse(out, indent);

}
void MinusNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " - ";
	myExp2->unparse(out, indent);
}

void TimesNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " * ";
	myExp2->unparse(out, indent);
}

void DivideNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " / ";
	myExp2->unparse(out, indent);
}

void AndNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " && ";
	myExp2->unparse(out, indent);
}

void OrNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " || ";
	myExp2->unparse(out, indent);
}

void EqualsNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " == ";
	myExp2->unparse(out, indent);
}


void NotEqualsNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " != ";
	myExp2->unparse(out, indent);
}

void LessNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " < ";
	myExp2->unparse(out, indent);
}

void GreaterNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " > ";
	myExp2->unparse(out, indent);
}

void LessEqNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " <= ";
	myExp2->unparse(out, indent);
}

void GreaterEqNode::unparse(std::ostream& out, int indent){
	myExp1->unparse(out, indent);
	out << " >= ";
	myExp2->unparse(out, indent);
}

} // End namespace LIL' C
