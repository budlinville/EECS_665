#include "symbol_table.hpp"
namespace LILC{

/*******************************************
		Scope Table
*******************************************/
ScopeTable::ScopeTable(int l){
	map = new std::unordered_map<std::string, SymbolTableEntry *>();
	level = l;
}

bool ScopeTable::isInScope(std::string id){
	if (map->find(id) != map->end()) {
		return true;
	}
	return false;
}

/*****************************************
		Symbol Table
*****************************************/
SymbolTable::SymbolTable(){
	//TODO: implement the list of hashtables
	// approach to building a symbol table
	scopeTables = new std::list<ScopeTable *>();
};

void SymbolTable::enterNewScope() {
	ScopeTable * newScope = new ScopeTable(this->getHighestLevel() + 1);
	scopeTables->push_front(newScope);
}

void SymbolTable::leaveCurrentScope() {
	scopeTables->pop_front();
}

bool SymbolTable::isInScope(std::string id){
	for (std::list<ScopeTable *>::iterator it=scopeTables->begin(); it != scopeTables->end(); ++it){
		if ((*it)->isInScope(id)) {
			return true;
		}
	}
	return false;
}

int SymbolTable::getHighestLevel() {
	if (scopeTables->front() == nullptr) {
		return 0;
	}
	return scopeTables->front()->level;
}

}	//namespace LILC
