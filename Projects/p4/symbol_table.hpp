#ifndef LILC_SYMBOL_TABLE_HPP
#define LILC_SYMBOL_TABLE_HPP
#include <unordered_map>
#include <list>

namespace LILC{

//A single entry for one name in the symbol table
class SymbolTableEntry{
public:
	std::string type;
	std::string kind;	//NOTE: maybe AstNode
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

	private:
		std::list<ScopeTable *> * scopeTables;
		int getHighestLevel();
};

}
#endif
