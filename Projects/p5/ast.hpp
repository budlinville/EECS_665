#ifndef LILC_AST_HPP
#define LILC_AST_HPP

#include <ostream>
#include <list>
#include "tokens.hpp"
#include "symbol_table.hpp"

namespace LILC{
	class SymbolTable;
	class ScopeTable;
	class SymbolTableEntry;
	class VarSymbol;
}

namespace LILC {

class DeclListNode;
class StmtListNode;
class FormalsListNode;
class DeclNode;
class StmtNode;
class AssignNode;
class FormalDeclNode;
class TypeNode;
class ExpNode;
class IdNode;

enum TypeString { Void, Int, Bool, String, Struct, Function, Accept, Error, Ignore};

class ASTNode{
public:
	ASTNode(size_t line, size_t col){
		this->line = line;
		this->col = col;
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	virtual bool nameAnalysis(SymbolTable * symTab) = 0;
	virtual bool typeAnalysis();
	void doIndent(std::ostream& out, int indent){
		for (int k = 0 ; k < indent; k++){ out << " "; }
	}
	virtual size_t getLine(){ return line; }
	virtual size_t getCol(){ return col; }
	virtual std::string getPosition() {
		std::string res = "";
		res += std::to_string(getLine());
		res += ":";
		res += std::to_string(getCol());
		//res += std::string(1, getCol());
		return res;
	}
protected:
	size_t line;
	size_t col;
};

class ProgramNode : public ASTNode{
public:
	ProgramNode(DeclListNode * declList) : ASTNode(0,0){
		myDeclList = declList;
	}
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;

	void unparse(std::ostream& out, int indent) override;
private:
	DeclListNode * myDeclList;
};

class TypeNode : public ASTNode{
public:
	TypeNode(size_t line, size_t col) : ASTNode(line, col){ }
	virtual void unparse(std::ostream& out, int indent)
		override = 0;
	virtual bool nameAnalysis(SymbolTable * symTab)
		override = 0;
	virtual std::string getTypeString() = 0;
	virtual bool isVoid(){ return false; }
	virtual bool isPrimitive(){ return true; }
	virtual bool typeAnalysis() override = 0;
protected:
	size_t line;
	size_t col;

};


class DeclListNode : public ASTNode{
public:
	DeclListNode(std::list<DeclNode *> * decls) : ASTNode(0,0){
        	myDecls = decls;
	}
	FieldMap * fieldNameAnalysis(SymbolTable * symTab);
	bool nameAnalysis(SymbolTable * symTab);
	void unparse(std::ostream& out, int indent);
	bool typeAnalysis();
private:
	std::list<DeclNode *> * myDecls;
	bool fieldNameAnalysis(SymbolTable * symTab, FieldMap * m);
};



class ExpNode : public ASTNode{
public:
	ExpNode(size_t line, size_t col) : ASTNode(line, col){ }
	virtual void unparse(std::ostream& out, int indent)
		override = 0;
	virtual bool nameAnalysis(SymbolTable * symTab)
		override = 0;
		virtual bool typeAnalysis() override = 0;
	virtual StructSymbol * dotNameAnalysis(SymbolTable * symTab) {
		throw runtime_error("INTERNAL: Attempted "
			"dotNameAnalysis on a non-struct "
			"expression type");
	}
};

class IdNode : public ExpNode{
public:
	IdNode(IDToken * token)
	: ExpNode(token->line, token->column){
		myStrVal = token->value();
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;
	StructSymbol * dotNameAnalysis(
		SymbolTable * symTab) override;
	virtual std::string getString() { return myStrVal; }
	virtual SymbolTableEntry * getSymbol() { return mySymbol; }
	void setSymbol(SymbolTableEntry * symbolIn){
		this->mySymbol = symbolIn;
	}

private:
	SymbolTableEntry * mySymbol;
	std::string myStrVal;
};

class DeclNode : public ASTNode{
public:
	DeclNode(size_t line, size_t col, IdNode * id)
	: ASTNode(line, col) {
		this->myDeclaredID = id;
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	virtual bool nameAnalysis(SymbolTable * symTab) = 0;
	virtual bool typeAnalysis();
	virtual std::string getTypeString() = 0;
	virtual std::string getName() {
		return myDeclaredID->getString();
	}
	virtual IdNode * getDeclaredID() { return myDeclaredID; }
	virtual DeclKind getKind() = 0;
protected:
	IdNode * myDeclaredID;
};


class StmtNode : public ASTNode{
public:
	StmtNode(size_t line, size_t col) : ASTNode(line, col){ }
	virtual void unparse(std::ostream& out, int indent) = 0;
	virtual bool nameAnalysis(SymbolTable * symTab) = 0;
	virtual bool typeAnalysis();
};

class FormalsListNode : public ASTNode{
public:
	FormalsListNode(std::list<FormalDeclNode *> * formalsIn)
	: ASTNode(0, 0){
		myFormals = formalsIn;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();
	std::list<VarSymbol *> * getSymbols();
	virtual std::string getTypeString();

private:
	std::list<FormalDeclNode *> * myFormals;
};

class ExpListNode : public ASTNode{
public:
	ExpListNode(std::list<ExpNode *> * exps) : ASTNode(0,0){
		myExps = *exps;
	}
	void unparse(std::ostream& out, int indent) override;
	virtual bool nameAnalysis(SymbolTable * symTab) override;
	virtual bool typeAnalysis() override;

//private:
	std::list<ExpNode *> myExps;
};

class StmtListNode : public ASTNode{
public:
	StmtListNode(std::list<StmtNode *> * stmtsIn) : ASTNode(0,0){
		myStmts = stmtsIn;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;

private:
	std::list<StmtNode *> * myStmts;
};

class FnBodyNode : public ASTNode{
public:
	FnBodyNode(size_t line, size_t col, DeclListNode * decls, StmtListNode * stmts) : ASTNode(line, col){
		myDeclList = decls;
		myStmtList = stmts;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;

private:
	DeclListNode * myDeclList;
	StmtListNode * myStmtList;
};


class FnDeclNode : public DeclNode{
public:
	FnDeclNode(
		TypeNode * type,
		IdNode * id,
		FormalsListNode * formals,
		FnBodyNode * fnBody)
		: DeclNode(type->getLine(), type->getCol(), id)
	{
		myRetType = type;
		myId = id;
		myFormals = formals;
		myBody = fnBody;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;
	virtual std::string getTypeString() override;
	VarSymbol * makeRetSymbol(SymbolTable * symTab);
	virtual DeclKind getKind() override { return DeclKind::FUNC; }

private:
	TypeNode * myRetType;
	IdNode * myId;
	FormalsListNode * myFormals;
	FnBodyNode * myBody;
	std::list<TypeString> * argTypeStrings();
};

class FormalDeclNode : public DeclNode{
public:
	FormalDeclNode(TypeNode * type, IdNode * id)
	: DeclNode(type->getLine(), type->getCol(), id){
		myType = type;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;
	VarSymbol * getSymbol();
	virtual std::string getTypeString() override;
	virtual DeclKind getKind() override {
		return DeclKind::FORMAL;
	}

private:
	TypeNode * myType;
	VarSymbol * mySymbol;
};

class StructDeclNode : public DeclNode{
public:
	StructDeclNode(size_t line, size_t col,
		IdNode * id, DeclListNode * decls )
	: DeclNode(id->getLine(), id->getCol(), id){
		myDeclList = decls;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;
	virtual std::string getTypeString() override;
	virtual DeclKind getKind() override {
		return DeclKind::STRUCT;
	}
	static const int NOT_STRUCT = -1; //Use this value for mySize
					  // if this is not a struct type
private:
	DeclListNode * myDeclList;
};


class IntNode : public TypeNode{
public:
	IntNode(size_t line, size_t col) : TypeNode(line, col) { }
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab) { return true; }
	bool typeAnalysis();
	std::string getTypeString() { return "Int"; }
};

class BoolNode : public TypeNode{
public:
	BoolNode(size_t line, size_t col) : TypeNode(line, col) { }
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab) { return true; }
	bool typeAnalysis();
	std::string getTypeString() { return "Bool"; }
};

class VoidNode : public TypeNode{
public:
	VoidNode(size_t line, size_t col) : TypeNode(line, col){ }
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab)
		override { return true; }
	std::string getTypeString() override { return "Void"; }
	bool typeAnalysis() override;
	virtual bool isVoid() override { return true; }
};

class StructNode : public TypeNode{
public:
	StructNode(IdNode * id, size_t line, size_t col)
	: TypeNode(line, col)
	{
		if (id == nullptr){
			throw std::runtime_error("null ID");
		}
		myId = id;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;
	std::string getTypeString() override;
	virtual bool isPrimitive() override { return false; }

private:
	IdNode * myId;
};

class IntLitNode : public ExpNode{
public:
	IntLitNode(IntLitToken * token)
	: ExpNode(token->line, token->column){
		myInt = token->value();
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab) { return true; }
	bool typeAnalysis();
	std::string getString() { return std::to_string(myInt); }
private:
	int myInt;
};

class StrLitNode : public ExpNode{
public:
	StrLitNode(StringLitToken * token)
	: ExpNode(token->line, token->column){
		myString = token->value();
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab) { return true; }
	bool typeAnalysis();
	std::string getString() const { return myString; }
private:
	 std::string myString;
};


class TrueNode : public ExpNode{
public:
	TrueNode(size_t line, size_t col): ExpNode(line, col){ }
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab) { return true; }
	bool typeAnalysis();
	std::string getString() const { return "true"; }
};

class FalseNode : public ExpNode{
public:
	FalseNode(size_t line, size_t col): ExpNode(line, col){ }
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab) { return true; }
	bool typeAnalysis();
	std::string getString() const { return "false"; }
};

class DotAccessNode : public ExpNode{
public:
	DotAccessNode(size_t line, size_t col, ExpNode * exp, IdNode * id)
	: ExpNode(line, col){
		myExp = exp;
		myId = id;
	}
	void unparse(std::ostream& out, int indent) override;
	bool nameAnalysis(SymbolTable * symTab) override;
	bool typeAnalysis() override;
	StructSymbol * dotNameAnalysis(SymbolTable * symTab)
		override;
	std::string getString();

private:
	//Note that DotAccessNode does NOT have its own
	// symbol. getSymbol() does a recursive call on
	// its myExp every time to get the base struct type
	// then unroll every field type.
	ExpNode * myExp;
	IdNode * myId;
};

class AssignNode : public ExpNode{
public:
	AssignNode(
		size_t line, size_t col,
		ExpNode * expLHS, ExpNode * expRHS)
	: ExpNode(line, col){
		myExpLHS = expLHS;
		myExpRHS = expRHS;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	ExpNode * myExpLHS;
	ExpNode * myExpRHS;
};

class CallExpNode : public ExpNode{
public:
	CallExpNode(IdNode * id, ExpListNode * expList)
	: ExpNode(id->getLine(), id->getCol()){
		myId = id;
		myExpList = expList;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	IdNode * myId;
	ExpListNode * myExpList;
	SymbolTableEntry * mySymbol;
};

class UnaryExpNode : public ExpNode {
public:
	UnaryExpNode(size_t line, size_t col, ExpNode * myExp)
	: ExpNode(line, col){
		this->myExp = myExp;
	}
	virtual void unparse(std::ostream& out, int indent) = 0;
	virtual bool nameAnalysis(SymbolTable * symTab){
		return myExp->nameAnalysis(symTab);
	}
	virtual bool typeAnalysis();
protected:
	ExpNode * myExp;
};

class UnaryMinusNode : public UnaryExpNode{
public:
	UnaryMinusNode(ExpNode * exp)
	: UnaryExpNode(line, col, exp){ }
	void unparse(std::ostream& out, int indent);
	bool typeAnalysis();
};

class NotNode : public UnaryExpNode{
public:
	NotNode(size_t line, size_t col, ExpNode * exp)
	: UnaryExpNode(line, col, exp){ }
	void unparse(std::ostream& out, int indent);
	bool typeAnalysis();
};

class BinaryExpNode : public ExpNode{
public:
	BinaryExpNode(
		size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: ExpNode(line, col) {
		this->myExp1 = exp1;
		this->myExp2 = exp2;
	}
	virtual void unparse(std::ostream& out, int indent)
		override;
	virtual bool nameAnalysis(SymbolTable * symTab)
		override
	{
		bool result1 = myExp1->nameAnalysis(symTab);
		return myExp2->nameAnalysis(symTab) && result1;
	}
	virtual bool typeAnalysis() override;
	virtual std::string myOp() = 0;
protected:
	ExpNode * myExp1;
	ExpNode * myExp2;
};

class PlusNode : public BinaryExpNode{
public:
	PlusNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2) { }
	virtual std::string myOp(){ return "+"; }
	bool typeAnalysis();
};

class MinusNode : public BinaryExpNode{
public:
	MinusNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp(){ return "-"; }
	bool typeAnalysis();
};

class TimesNode : public BinaryExpNode{
public:
	TimesNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp(){ return "*"; }
	bool typeAnalysis();
};

class DivideNode : public BinaryExpNode{
public:
	DivideNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp(){ return "/"; }
	bool typeAnalysis();
};

class AndNode : public BinaryExpNode{
public:
	AndNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp(){ return "&&"; }
	bool typeAnalysis();
};

class OrNode : public BinaryExpNode{
public:
	OrNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return "||"; }
	bool typeAnalysis() override;
};

class EqualsNode : public BinaryExpNode{
public:
	EqualsNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return "=="; }
	bool typeAnalysis() override;
};

class NotEqualsNode : public BinaryExpNode{
public:
	NotEqualsNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return "!="; }
	bool typeAnalysis() override;
};

class LessNode : public BinaryExpNode{
public:
	LessNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return "<"; }
	bool typeAnalysis() override;
};

class GreaterNode : public BinaryExpNode{
public:
	GreaterNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return ">"; }
	bool typeAnalysis() override;
};

class LessEqNode : public BinaryExpNode{
public:
	LessEqNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return "<="; }
	bool typeAnalysis() override;
};

class GreaterEqNode : public BinaryExpNode{
public:
	GreaterEqNode(size_t line, size_t col,
		ExpNode * exp1, ExpNode * exp2)
	: BinaryExpNode(line, col, exp1, exp2){ }
	virtual std::string myOp() override { return ">="; }
	bool typeAnalysis() override;
};

class AssignStmtNode : public StmtNode{
public:
	AssignStmtNode(AssignNode * assignment)
	: StmtNode(assignment->getLine(), assignment->getCol()){
		myAssign = assignment;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	AssignNode * myAssign;
};

class PostIncStmtNode : public StmtNode{
public:
	PostIncStmtNode(ExpNode * exp)
	: StmtNode(exp->getLine(), exp->getCol()){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	ExpNode * myExp;
};

class PostDecStmtNode : public StmtNode{
public:
	PostDecStmtNode(ExpNode * exp)
	: StmtNode(exp->getLine(), exp->getCol()){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	ExpNode * myExp;
};

class ReadStmtNode : public StmtNode{
public:
	ReadStmtNode(size_t line, size_t col, ExpNode * exp)
	: StmtNode(line, col){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();
private:
	ExpNode * myExp;
};

class WriteStmtNode : public StmtNode{
public:
	WriteStmtNode(size_t line, size_t col, ExpNode * exp)
	: StmtNode(line, col){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();
private:
	ExpNode * myExp;
};

class IfStmtNode : public StmtNode{
public:
	IfStmtNode(size_t line, size_t col, ExpNode * exp,
	  DeclListNode * decls, StmtListNode * stmts)
	: StmtNode(line, col){
		myExp = exp;
		myDecls = decls;
		myStmts = stmts;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();
private:
	ExpNode * myExp;
	DeclListNode * myDecls;
	StmtListNode * myStmts;
};

class IfElseStmtNode : public StmtNode{
public:
	IfElseStmtNode(ExpNode * exp,
	  DeclListNode * declsT, StmtListNode * stmtsT,
	  DeclListNode * declsF, StmtListNode * stmtsF)
	: StmtNode(exp->getLine(), exp->getCol()){
		myExp = exp;
		myDeclsT = declsT;
		myStmtsT = stmtsT;
		myDeclsF = declsF;
		myStmtsF = stmtsF;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();
private:
	ExpNode * myExp;
	DeclListNode * myDeclsT;
	StmtListNode * myStmtsT;
	DeclListNode * myDeclsF;
	StmtListNode * myStmtsF;
};

class WhileStmtNode : public StmtNode{
public:
	WhileStmtNode(size_t line, size_t col,
	ExpNode * exp, DeclListNode * decls, StmtListNode * stmts)
	: StmtNode(line, col){
		myExp = exp;
		myDecls = decls;
		myStmts = stmts;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();
private:
	ExpNode * myExp;
	DeclListNode * myDecls;
	StmtListNode * myStmts;
};

class CallStmtNode : public StmtNode{
public:
	CallStmtNode(CallExpNode * callExp)
	: StmtNode(callExp->getLine(), callExp->getCol()){
		myCallExp = callExp;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	CallExpNode * myCallExp;
};

class ReturnStmtNode : public StmtNode{
public:
	ReturnStmtNode(size_t line, size_t col, ExpNode * exp)
	: StmtNode(line, col){
		myExp = exp;
	}
	void unparse(std::ostream& out, int indent);
	bool nameAnalysis(SymbolTable * symTab);
	bool typeAnalysis();

private:
	ExpNode * myExp;
};

class VarDeclNode : public DeclNode{
public:
	VarDeclNode(TypeNode * type, IdNode * id, int size)
	: DeclNode(id->getLine(), id->getCol(), id){
		myType = type;
		mySize = size;
	}
	bool nameAnalysis(SymbolTable * symTab) override;
	void unparse(std::ostream& out, int indent) override;
	bool typeAnalysis() override;
	virtual std::string getTypeString() override;
	virtual DeclKind getKind() override { return DeclKind::VAR; }
	static const int NOT_STRUCT = -1; //Use this value for mySize
					  // if this is not a struct type
private:
	TypeNode * myType;
	int mySize;
};

} //End namespace LIL' C

#endif
