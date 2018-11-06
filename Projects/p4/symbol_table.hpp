#ifndef LILC_SYMBOL_TABLE_HPP
#define LILC_SYMBOL_TABLE_HPP
#include <unordered_map>
#include <list>

namespace LILC{

//A single entry for one name in the symbol table
class SymbolTableEntry{
public:
	virtual std::string getType() = 0;
	virtual std::string getKind() = 0;
};



//A single
class ScopeTable{
	public:
		ScopeTable(int l);
		//TODO: add functions for looking up symbols
		// and/or returning information to indicate
		// that the symbol does not exist within
		// the current scope
		bool isInScope(std::string id);
		SymbolTableEntry * getEntry(std::string id);
		void addEntry(SymbolTableEntry * e);
		int level;


	private:
		std::unordered_map<std::string, SymbolTableEntry *>* map;

};

class SymbolTable{
	public:
		SymbolTable();
		void enterNewScope();
		void leaveCurrentScope();
		bool isInScope(std::string id);
		void addEntry(SymbolTableEntry * e);
		SymbolTableEntry * getEntry(std::string id);

	private:
		std::list<ScopeTable *> * scopeTables;
		int getHighestLevel();
};

class VarSymbolEntry : public SymbolTableEntry {
public:
	VarSymbolEntry(std::string type, std::string kind, int size) {
		myType = type;
		myKind = kind;
		mySize = size;
	}
	int getSize() {
		return mySize;
	}
	std::string getKind() {
		return myKind;
	}
	std::string getType() {
		return myType;
	}

private:
	std::string myKind;
	std::string myType;
	int mySize;
};


class FnSymbolEntry : public SymbolTableEntry {
public:
	FnSymbolEntry(std::string type, std::string kind, std::list<VarSymbolEntry *> * vars) {
		myType = type;
		myKind = kind;
		myArgs = vars;
	}

	std::string getKind() {
		return myKind;
	}

	std::string getType();

private:
	std::string myKind;
	std::list<VarSymbolEntry *> * myArgs;
	std::string myType;
};


class StructSymbolEntry : public SymbolTableEntry {
public:
	StructSymbolEntry(std::string kind, std::list<VarSymbolEntry *> * props) {
		myKind = kind;
		myProps = props;
	}
	std::string getKind() {
		return myKind;
	}

	std::string getType() {
			return myKind;
	}


	VarSymbolEntry * find(std::string id);

private:
	std::string myKind;
	std::list<VarSymbolEntry *> * myProps;
};

}
#endif
