#ifndef LILC_AST_HPP
#define LILC_AST_HPP

#include <ostream>
#include <list>
#include "symbols.hpp"

//Here is a suggestion for all the different kinds of AST nodes
// and what kinds
// of children they have. All of these kinds of AST nodes are
// subclasses of ASTNode.
// Indentation indicates further subclassing:
//
//     Subclass		Children
//     --------		------
//     ProgramNode	DeclListNode
//     DeclListNode	linked list of DeclNode
//     DeclNode
//       VarDeclNode	TypeNode, IdNode, int
//       FnDeclNode	TypeNode, IdNode, FormalsListNode, FnBodyNode
//       FormalDeclNode    TypeNode, IdNode
//       StructDeclNode    IdNode, DeclListNode
//
//     FormalsListNode     linked list of FormalDeclNode
//     FnBodyNode          DeclListNode, StmtListNode
//     StmtListNode        linked list of StmtNode
//     ExpListNode         linked list of ExpNode
//
//     TypeNode:
//       IntNode           -- none --
//       BoolNode          -- none --
//       VoidNode          -- none --
//       StructNode        IdNode
//
//     StmtNode:
//       AssignStmtNode      AssignNode
//       PostIncStmtNode     ExpNode
//       PostDecStmtNode     ExpNode
//       ReadStmtNode        ExpNode
//       WriteStmtNode       ExpNode
//       IfStmtNode          ExpNode, DeclListNode, StmtListNode
//       IfElseStmtNode      ExpNode, DeclListNode, StmtListNode,
//                                    DeclListNode, StmtListNode
//       WhileStmtNode       ExpNode, DeclListNode, StmtListNode
//       CallStmtNode        CallExpNode
//       ReturnStmtNode      ExpNode
//
//     ExpNode:
//       IntLitNode          -- none --
//       StrLitNode          -- none --
//       TrueNode            -- none --
//       FalseNode           -- none --
//       IdNode              -- none --
//       DotAccessNode       ExpNode, IdNode
//       AssignNode          ExpNode, ExpNode
//       CallExpNode         IdNode, ExpListNode
//       UnaryExpNode        ExpNode
//         UnaryMinusNode
//         NotNode
//       BinaryExpNode       ExpNode ExpNode
//         PlusNode
//         MinusNode
//         TimesNode
//         DivideNode
//         AndNode
//         OrNode
//         EqualsNode
//         NotEqualsNode
//         LessNode
//         GreaterNode
//         LessEqNode
//         GreaterEqNode
//
//
// Here are the different kinds of AST nodes again, organized according to
// whether they are leaves, internal nodes with linked lists of kids, or
// internal nodes with a fixed number of kids:
//
// (1) Leaf nodes:
//        IntNode,   BoolNode,  VoidNode,  IntLitNode,  StrLitNode,
//        TrueNode,  FalseNode, IdNode
//
// (2) Internal nodes with (possibly empty) linked lists of children:
//        DeclListNode, FormalsListNode, StmtListNode, ExpListNode
//
// (3) Internal nodes with fixed numbers of kids:
//        ProgramNode,     VarDeclNode,     FnDeclNode,     FormalDeclNode,
//        StructDeclNode,  FnBodyNode,      StructNode,     AssignStmtNode,
//        PostIncStmtNode, PostDecStmtNode, ReadStmtNode,   WriteStmtNode
//        IfStmtNode,      IfElseStmtNode,  WhileStmtNode,  CallStmtNode
//        ReturnStmtNode,  DotAccessNode,   CallExpNode,
//        UnaryExpNode,    BinaryExpNode,   UnaryMinusNode, NotNode,
//        PlusNode,        MinusNode,       TimesNode,      DivideNode,
//        AndNode,         OrNode,          EqualsNode,     NotEqualsNode,
//        LessNode,        GreaterNode,     LessEqNode,     GreaterEqNode
//
// **********************************************************************

// **********************************************************************
// ASTnode class (base class for all other kinds of nodes)
// **********************************************************************

namespace LILC{

class SymSymbol;
class DeclListNode;
class DeclNode;
class TypeNode;
class IdNode;
class StmtNode;
class ExpNode;

class ASTNode{
public:
	ASTNode(){}
	virtual void unparse(std::ostream& out, int indent) = 0;
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
};

class ProgramNode : public ASTNode{
public:
	ProgramNode(DeclListNode * L) : ASTNode(){
		myDeclList = L;
	}
	void unparse(std::ostream& out, int indent);
private:
	DeclListNode * myDeclList;

};

class DeclListNode : public ASTNode{
public:
	DeclListNode(std::list<DeclNode *> * decls) : ASTNode(){
		myDecls = *decls;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<DeclNode *> myDecls;
};

class DeclNode : public ASTNode{
public:
	virtual void unparse(std::ostream& out, int indent) = 0;
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
};

class VarDeclListNode : public ASTNode{
public:
	VarDeclListNode(std::list<VarDeclNode *> * varDecls) : ASTNode(){
		myVarDecls = *varDecls;
	}
	void unparse(std::ostream& out, int indent);
private:
	std::list<VarDeclNode *> myVarDecls;
};

class VarDeclNode : public DeclNode{
public:
	VarDeclNode(TypeNode * type, IdNode * id, int size) : DeclNode(){
		myType = type;
		myId = id;
		mySize = size;
	}
	void unparse(std::ostream& out, int indent);
	static const int NOT_STRUCT = -1; //Use this value for mySize
					  // if this is not a struct type
private:
	TypeNode * myType;
	IdNode * myId;
	int mySize;
};

class FormalDeclNode : public DeclNode{
public:
	FormalDeclNode(TypeNode * type, IdNode * id) : DeclNode(){
		myType = type;
		myId = id;
		//mySize = size;
	}
	void unparse(std::ostream& out, int indent);

private:
	TypeNode * myType;
	IdNode * myId;
	//int mySize;

};


class FormalsListNode : public ASTNode{
public:
	FormalsListNode(std::list<FormalDeclNode *> * formalDecls) : ASTNode(){
		myFormalDecls = formalDecls;
	}
	void unparse(std::ostream& out, int indent);


	std::list<FormalDeclNode *> * myFormalDecls;

};


class StmtNode : public ASTNode{
public:
	StmtNode() : ASTNode(){

	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
};



class StmtListNode : public ASTNode{
public:
	StmtListNode(std::list<StmtNode *> * stmtNodes) : ASTNode(){
		myStmtNodes = stmtNodes;
	}
	void unparse(std::ostream& out, int indent);

	std::list<StmtNode *> * myStmtNodes;
};


class FnBodyNode : public ASTNode{
public:
	FnBodyNode(DeclListNode * declList, StmtListNode * stmtList) : ASTNode(){
		myDeclList = declList;
		myStmtList = stmtList;
		//mySize = size;
	}
	void unparse(std::ostream& out, int indent);

private:
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
	//int mySize;
};



class FormalsNode : public ASTNode{
public:
	FormalsNode(FormalsListNode * formalsList) : ASTNode(){
		myFormalsList = formalsList;
	}
	void unparse(std::ostream& out, int indent);

private:
	FormalsListNode * myFormalsList;
};


class FnDeclNode : public DeclNode{
public:
	FnDeclNode(TypeNode * type, IdNode * id, FormalsNode * formals, FnBodyNode * fnBody) : DeclNode(){
		myType = type;
		myId = id;
		myFormals = formals;
		myFnBody = fnBody;
		//mySize = size;
	}
	void unparse(std::ostream& out, int indent);

private:
	TypeNode * myType;
	IdNode * myId;
	FormalsNode * myFormals;
	FnBodyNode * myFnBody;
	//int mySize;
};

class StructBodyNode : public DeclNode{
public:
	StructBodyNode(std::list<VarDeclNode *> * varDecls) : DeclNode(){

	}
	void unparse(std::ostream& out, int indent);

	std::list<VarDeclNode *> myVarDecls;
};


class StructDeclNode : public DeclNode{
public:
	StructDeclNode(IdNode * id, StructBodyNode * str) : DeclNode(){
		myId = id;
		myStructBody = str;
		//mySize = size;
	}
	void unparse(std::ostream& out, int indent);

private:
	IdNode * myId;
	StructBodyNode * myStructBody;
	//int mySize;
};

class ExpListNode : public ASTNode{
public:
	ExpListNode(std::list<ExpNode *> * expNodes) : ASTNode(){
		myExpNodes = expNodes;
	}
	void unparse(std::ostream& out, int indent);

	std::list<ExpNode *> * myExpNodes;
};

class ExpNode : public ASTNode{
public:
	ExpNode() : ASTNode(){

	}
	void unparse(std::ostream& out, int indent);
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
};

class AssignNode : public ExpNode{
public:
	AssignNode(ExpNode * expNode1, ExpNode * expNode2) : ExpNode(){
		myExpNode1 = expNode1;
		myExpNode2 = expNode2;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExpNode1;
	ExpNode * myExpNode2;
};

class AssignStmtNode : public StmtNode{
public:
	AssignStmtNode(AssignNode * assignNode) : StmtNode(){
		myAssignNode = assignNode;
	}
	void unparse(std::ostream& out, int indent);

	AssignNode * myAssignNode;
};

class PostIncStmtNode : public StmtNode{
public:
	PostIncStmtNode(ExpNode * expNode) : StmtNode(){
		myExpNode = expNode;
	}

	void unparse(std::ostream& out, int indent);
	ExpNode * myExpNode;
};

class PostDecStmtNode : public StmtNode{
public:
	PostDecStmtNode(ExpNode * expNode) : StmtNode(){
		myExpNode = expNode;
	}

	void unparse(std::ostream& out, int indent);
	ExpNode * myExpNode;
};

class ReadStmtNode : public StmtNode{
public:
	ReadStmtNode(ExpNode * expNode) : StmtNode(){
		myExpNode = expNode;
	}

	void unparse(std::ostream& out, int indent);
	ExpNode * myExpNode;
};


class WriteStmtNode : public StmtNode{
public:
	WriteStmtNode(ExpNode * expNode) : StmtNode(){
		myExpNode = expNode;
	}

	void unparse(std::ostream& out, int indent);
	ExpNode * myExpNode;
};

class IfStmtNode : public StmtNode{
public:
	IfStmtNode(ExpNode * expNode, DeclListNode * declList, StmtListNode * stmtList) : StmtNode(){
		myExpNode = expNode;
		myDeclList = declList;
		myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExpNode;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};

class IfElseStmtNode : public StmtNode{
public:
	IfElseStmtNode(ExpNode * expNode, DeclListNode * declList1, StmtListNode * stmtList1, DeclListNode * declList2, StmtListNode * stmtList2) : StmtNode(){
		myExpNode = expNode;
		myDeclList1 = declList1;
		myStmtList1 = stmtList1;
		myDeclList2 = declList2;
		myStmtList2 = stmtList2;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExpNode;
	DeclListNode * myDeclList1;
	StmtListNode * myStmtList1;
	DeclListNode * myDeclList2;
	StmtListNode * myStmtList2;
};

class WhileStmtNode : public StmtNode{
public:
	WhileStmtNode(ExpNode * expNode, DeclListNode * declList, StmtListNode * stmtList) : StmtNode(){
			myExpNode = expNode;
			myDeclList = declList;
			myStmtList = stmtList;
	}
	void unparse(std::ostream& out, int indent);


	ExpNode * myExpNode;
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};


class CallExpNode : public ExpNode{
public:
	CallExpNode(IdNode * idNode, ExpListNode * expList) : ExpNode(){
		myIdNode = idNode;
		myExpList = expList;
	}
	void unparse(std::ostream& out, int indent);

	IdNode * myIdNode;
	ExpListNode * myExpList;
};

class CallStmtNode : public StmtNode{
public:
	CallStmtNode(CallExpNode * callExp) : StmtNode(){
		myCallExp = callExp;
	}
	void unparse(std::ostream& out, int indent);

	CallExpNode * myCallExp;
};

class ReturnStmtNode : public StmtNode{
public:
	ReturnStmtNode(ExpNode * expNode) : StmtNode(){
		myExpNode = expNode;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExpNode;
};



class IntLitNode : public ExpNode{
public:
	IntLitNode(IntLitToken * v) : ExpNode(){
		val = v;
	}
	void unparse(std::ostream& out, int indent);
private:
	IntLitToken * val;
};

class StrLitNode : public ExpNode{
public:
	StrLitNode(StringLitToken * v) : ExpNode(){
		val = v;
	}
	void unparse(std::ostream& out, int indent);
private:
	StringLitToken * val;
};

class TrueNode : public ExpNode{
public:
	TrueNode() : ExpNode(){

	}
	void unparse(std::ostream& out, int indent);
};

class FalseNode : public ExpNode{
public:
	FalseNode() : ExpNode(){

	}
	void unparse(std::ostream& out, int indent);
};

/*
class IdNode : public ExpNode{
public:
	IdNode() : ExpNode(){

	}
	void unparse(std::ostream& out, int indent);
};
*/

class DotAccessNode : public ExpNode{
public:
	DotAccessNode(ExpNode * expNode, IdNode * idNode) : ExpNode(){
		myExpNode = expNode;
		myIdNode = idNode;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExpNode;
	IdNode * myIdNode;
};





class UnaryExpNode : public ExpNode{
public:
	UnaryExpNode(ExpNode * expNode) : ExpNode(){
		myExp = expNode;
	}
	virtual void unparse(std::ostream& out, int indent);

	ExpNode * myExp;
};

class UnaryMinusNode : public ExpNode{
public:
	UnaryMinusNode(ExpNode * expNode) : ExpNode(){
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp;
};

class NotNode : public ExpNode{
public:
	NotNode(ExpNode * expNode) : ExpNode(){
		myExp = expNode;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp;
};

class BinaryExpNode : public ExpNode{
public:
	BinaryExpNode() : ExpNode(){

	}
	virtual void unparse(std::ostream& out, int indent);


};

class PlusNode : public BinaryExpNode{
public:
	PlusNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class MinusNode : public BinaryExpNode{
public:
	MinusNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);


	ExpNode * myExp1;
	ExpNode * myExp2;
};

class TimesNode : public BinaryExpNode{
public:
	TimesNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class DivideNode : public BinaryExpNode{
public:
	DivideNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class AndNode : public BinaryExpNode{
public:
	AndNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class OrNode : public BinaryExpNode{
public:
	OrNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};


class EqualsNode : public BinaryExpNode{
public:
	EqualsNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class NotEqualsNode : public BinaryExpNode{
public:
	NotEqualsNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class LessNode : public BinaryExpNode{
public:
	LessNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class GreaterNode : public BinaryExpNode{
public:
	GreaterNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class LessEqNode : public BinaryExpNode{
public:
	LessEqNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};

class GreaterEqNode : public BinaryExpNode{
public:
	GreaterEqNode(ExpNode * exp1, ExpNode * exp3) : BinaryExpNode(){
		myExp1 = exp1;
		myExp2 = exp3;
	}
	void unparse(std::ostream& out, int indent);

	ExpNode * myExp1;
	ExpNode * myExp2;
};


class TypeNode : public ASTNode{
public:
	TypeNode() : ASTNode(){
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
};

class IdNode : public TypeNode{
public:
	IdNode(IDToken * token) : TypeNode(){
	}
	void unparse(std::ostream& out, int indent);
private:
	std::string myStrVal;
};

class IntNode : public TypeNode{
public:
	IntNode(): TypeNode(){
	}
	void unparse(std::ostream& out, int indent);
};

class BoolNode : public TypeNode{
public:
	BoolNode(): TypeNode(){
	}
	void unparse(std::ostream& out, int indent);
};



} //End namespace LIL' C

#endif
