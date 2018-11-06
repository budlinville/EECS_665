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

void ScopeTable::addEntry(SymbolTableEntry* e) {
	map->insert({e->getKind(), e});
}

SymbolTableEntry * ScopeTable::getEntry(std::string id) {
	return map->at(id);
}

/*****************************************
		Symbol Table
*****************************************/
SymbolTable::SymbolTable(){
	//TODO: implement the list of hashtables
	// approach to building a symbol table
	scopeTables = new std::list<ScopeTable *>();
	enterNewScope();
};

void SymbolTable::enterNewScope() {
	ScopeTable * newScope = new ScopeTable(this->getHighestLevel() + 1);
	scopeTables->push_front(newScope);
}

void SymbolTable::leaveCurrentScope() {
	if (scopeTables->size() <= 1) {

	}
	else {
			scopeTables->pop_front();
	}

}

bool SymbolTable::isInScope(std::string id){
	for (std::list<ScopeTable *>::iterator it=scopeTables->begin(); it != scopeTables->end(); ++it){
		if ((*it)->isInScope(id)) {
			return true;
		}
	}
	return false;
}

void SymbolTable::addEntry(SymbolTableEntry* e) {
	scopeTables->front()->addEntry(e);
}

SymbolTableEntry * SymbolTable::getEntry(std::string id) {
	for (std::list<ScopeTable *>::iterator it = scopeTables->begin(); it != scopeTables->end(); ++it) {
		ScopeTable * current = *it;
		if (current->isInScope(id)) {
			return current->getEntry(id);
		}
	}
	return nullptr;
}

int SymbolTable::getHighestLevel() {
	if (scopeTables->front() == nullptr) {
		return 0;
	}
	return scopeTables->front()->level;
}

std::string FnSymbolEntry::getType() {
	std::string type = "";
	for (std::list<VarSymbolEntry *>::iterator it = myArgs->begin(); it != myArgs->end(); ++it) {
		VarSymbolEntry * e = *it;
		type += e->getType();

		if (next(it) != myArgs->end()) {
			type += ",";
		}
	}

	type += "->" + myType;
	return type;
}


VarSymbolEntry * StructSymbolEntry::find(std::string id) {
	for (std::list<VarSymbolEntry *>::iterator it = myProps->begin(); it != myProps->end(); ++it) {
		VarSymbolEntry * e = *it;
		if (e->getKind() == id) {
			return e;
		}
	}
	return nullptr;
}

}	//namespace LILC
