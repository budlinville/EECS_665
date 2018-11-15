#ifndef LILC_ERROR_REPORTING_HH
#define LILC_ERROR_REPORTING_HH

#include <iostream>

namespace LILC{

class Err{
	public:
	static void report(std::string pos, std::string msg){
		std::cerr << pos
			<< " ***ERROR*** " << msg << std::endl;
	}

	static bool multiDecl(std::string pos){
		report(pos, "Multiply declared identifiers");
		return false;
	}

	static bool undeclaredID(std::string pos){
		report(pos, "Undeclared identifier");
		return false;
	}

	static bool undefType(std::string pos){
		report(pos, "Undefined type");
		return false;
	}

	static bool badVoid(std::string pos){
		report(pos, "Non-function declared void");
		return false;
	}

	static bool badDotLHS(std::string pos){
		report(pos, "Dot-access of non-struct type");
		return false;
	}

	static bool badDotRHS(std::string pos){
		report(pos, "Invalid struct field name");
		return false;
	}
	static bool fnWrite(std::string pos) {
		report(pos, "Attempt to write a function");
		return false;
	}
	static bool structWrite(std::string pos) {
		report(pos, "Attempt to write a struct name");
		return false;
	}
	static bool structVarWrite(std::string pos) {
		report(pos, "Attempt to write a struct variable");
		return false;
	}
	static bool voidWrite(std::string pos) {
		report(pos, "Attempt to write void");
		return false;
	}
	static bool fnRead(std::string pos) {
		report(pos, "Attempt to read a function");
		return false;
	}
	static bool structRead(std::string pos) {
		report(pos, "Attempt to read a struct name");
		return false;
	}
	static bool structVarRead(std::string pos) {
		report(pos, "Attempt to read a struct variable");
		return false;
	}
	static bool fnWrite(std::string pos) {
		report(pos, "Attempt to write a function");
		return false;
	}
	static bool nonFnCall(std::string pos) {
		report(pos, "Attempt to call a non-function");
		return false;
	}
	static bool wrongNumArgs(std::string pos) {
		report(pos, "Function call with wrong number of args");
		return false;
	}
	static bool wrongArgType(std::string pos) {
		report(pos, "Type of actual does not match type of formal");
		return false;
	}
	static bool noRetValue(std::string pos) {
		report(pos, "Missing return value");
		return false;
	}
	static bool voidFnReturn(std::string pos) {
		report(pos, "Return with a value in a void function");
		return false;
	}
	static bool badReturnValue(std::string pos) {
		report(pos, "Bad return value");
		return false;
	}
	static bool nonIntArithmeticOp(std::string pos) {
		report(pos, "Arithmetic operator applied to non-numeric operand");
		return false;
	}
	static bool nonIntRelationalOp(std::string pos) {
		report(pos, "Relational operator applied to non-numeric operand");
		return false;
	}
	static bool nonBoolLogicalOp(std::string pos) {
		report(pos, "Logical operator applied to non-bool operand");
		return false;
	}
	static bool nonBoolIf(std::string pos) {
		report(pos, "Non-bool expression used as an if condition");
		return false;
	}
	static bool nonBoolWhile(std::string pos) {
		report(pos, "Non-bool expression used as a while condition");
		return false;
	}
	static bool typeMismatch(std::string pos) {
		report(pos, "Type mismatch");
		return false;
	}
	static bool voidEqualityOp(std::string pos) {
		report(pos, "Equality operator applied to void functions");
		return false;
	}
	static bool fnEquality(std::string pos) {
		report(pos, "Equality operator applied to functions");
		return false;
	}
	static bool structNameEquality(std::string pos) {
		report(pos, "Equality operator applied to struct names");
		return false;
	}
	static bool structVarEquality(std::string pos) {
		report(pos, "Equality operator applied to struct variables");
		return false;
	}
	static bool fnAssignment(std::string pos) {
		report(pos, "Function assignment");
		return false;
	}
	static bool structNameAssignment(std::string pos) {
		report(pos, "Struct name assignment");
		return false;
	}
	static bool structVarAssignment(std::string pos) {
		report(pos, "Struct variable assignment");
		return false;
	}
};

} //End namespace LILC

#endif
