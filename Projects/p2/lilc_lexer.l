%{
#include <string>
#include <limits.h>

/* Provide custom yyFlexScanner subclass and specify the interface */
#include "lilc_scanner.hpp"
#undef  YY_DECL
#define YY_DECL int LILC::LilC_Scanner::yylex( LILC::LilC_Parser::semantic_type * const lval)

/* typedef to make the returns for the tokens shorter */
using TokenTag = LILC::LilC_Parser::token;

/*
Implementations of the non-nullary tokens. These classes are declared
in symbols.hpp and are subclasses of the main Symbol class representing
terminals that contain some value (e.g., a token that contains an integer
value as opposed to a curly brace which always represents exactly 1
literal character string)
 */
namespace LILC{
	IDToken::IDToken(size_t line, size_t col, std::string value)
	: SynSymbol(line,col,TokenTag::ID)
	{
		this->_value = value;
	}
	IntLitToken::IntLitToken(size_t line, size_t col, int value)
	: SynSymbol(line,col,TokenTag::INTLITERAL)
	{
		this->_value = value;
	}
	StringLitToken::StringLitToken(size_t line, size_t col, std::string value)
	: SynSymbol(line,col,TokenTag::STRINGLITERAL)
	{
		this->_value = value;
	}
} // End namespace



/* define yyterminate as this instead of NULL */
#define yyterminate() return( TokenTag::END )

/* Exclude unistd.h for Visual Studio compatability. */
#define YY_NO_UNISTD_H

%}

%option debug
%option nodefault
%option yyclass="LILC::LilC_Scanner"
%option noyywrap
%option c++

DIGIT [0-9]
WHITESPACE   [ \t]
LETTER [a-z][A-Z]
NOTBADCHAR [^\n\"\\]
NOQUOTE [^\"]
BADESCAPE [^tn\\\'\"?]

%%
%{	/** Code executed at the beginning of yylex **/
	yylval = lval;
%}

{DIGIT}+	{
	//Note: the following computation of the integer value
	// does NOT check for overflow. This must be changed
	long long ll = std::__cxx11::stoll(yytext);
	if (ll < INT_MIN || ll > INT_MAX) {
		std::string msg = "integer literal too large: ";
		msg += yytext;
		charNum += yyleng;
		error(lineNum, charNum, msg);
	}

	int intVal = (int) ll;
	yylval->symbolValue = new IntLitToken(lineNum, charNum, intVal);
	charNum += yyleng;
    return TokenTag::INTLITERAL;
}

\n	{
	// Update line number
	lineNum++;
	charNum = 1;
}

{WHITESPACE}+	{
	charNum += yyleng;
}

"#".*	{
	//do nothing
}

"//".* {
	//do nothing
}

"+"	{
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::PLUS);
	charNum++;
	return TokenTag::PLUS;
}

"-" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::MINUS);
	charNum++;
	return TokenTag::MINUS;
}

"*" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::TIMES);
	charNum++;
	return TokenTag::TIMES;
}

"/" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::DIVIDE);
	charNum++;
	return TokenTag::DIVIDE;
}

"bool" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::BOOL);
	charNum+=yyleng;
	return TokenTag::BOOL;
}

"void" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::VOID);
	charNum+=yyleng;
	return TokenTag::VOID;
}

"true" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::TRUE);
	charNum+=yyleng;
	return TokenTag::TRUE;
}

"false" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::FALSE);
	charNum+=yyleng;
	return TokenTag::FALSE;
}

"struct" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::STRUCT);
	charNum+=yyleng;
	return TokenTag::STRUCT;
}

"cin" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::INPUT);
	charNum+=yyleng;
	return TokenTag::INPUT;
}

"cout" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::OUTPUT);
	charNum+=yyleng;
	return TokenTag::OUTPUT;
}

"if" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::IF);
	charNum+=yyleng;
	return TokenTag::IF;
}

"else" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::ELSE);
	charNum+=yyleng;
	return TokenTag::ELSE;
}

"while" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::WHILE);
	charNum+=yyleng;
	return TokenTag::WHILE;
}

"return" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::RETURN);
	charNum+=yyleng;
	return TokenTag::RETURN;
}

({LETTER}|{DIGIT})+({LETTER}|{DIGIT}|"_")* {
	yylval->symbolValue = new IDToken(lineNum, charNum, yytext);
	charNum+=yyleng;
	return TokenTag::ID;
}

"\""(("\n"|"\t"|"\'"|"\""|"\?"|"\\")|{NOTBADCHAR})*"\""	{
	yylval->symbolValue = new StringLitToken(lineNum, charNum, yytext);
	charNum+=yyleng;
	return TokenTag::STRINGLITERAL;
}

"{" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::LCURLY);
	charNum+=yyleng;
	return TokenTag::LCURLY;
}

"}" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::RCURLY);
	charNum+=yyleng;
	return TokenTag::RCURLY;
}

"(" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::LPAREN);
	charNum+=yyleng;
	return TokenTag::LPAREN;
}

")" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::RPAREN);
	charNum+=yyleng;
	return TokenTag::RPAREN;
}

";" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::SEMICOLON);
	charNum+=yyleng;
	return TokenTag::SEMICOLON;
}

"," {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::COMMA);
	charNum+=yyleng;
	return TokenTag::COMMA;
}

"." {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::DOT);
	charNum+=yyleng;
	return TokenTag::DOT;
}

"<<" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::WRITE);
	charNum+=yyleng;
	return TokenTag::WRITE;
}

">>" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::READ);
	charNum+=yyleng;
	return TokenTag::READ;
}

"++" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::PLUSPLUS);
	charNum+=yyleng;
	return TokenTag::PLUSPLUS;
}

"--" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::MINUSMINUS);
	charNum+=yyleng;
	return TokenTag::MINUSMINUS;
}

"+" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::PLUS);
	charNum+=yyleng;
	return TokenTag::PLUS;
}

"-" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::MINUS);
	charNum+=yyleng;
	return TokenTag::MINUS;
}

"*" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::TIMES);
	charNum+=yyleng;
	return TokenTag::TIMES;
}

"/" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::DIVIDE);
	charNum+=yyleng;
	return TokenTag::DIVIDE;
}

"!=" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::NOTEQUALS);
	charNum+=yyleng;
	return TokenTag::NOTEQUALS;
}

"!" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::NOT);
	charNum+=yyleng;
	return TokenTag::NOT;
}

"&&" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::AND);
	charNum+=yyleng;
	return TokenTag::AND;
}

"||" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::OR);
	charNum+=yyleng;
	return TokenTag::OR;
}

"==" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::EQUALS);
	charNum+=yyleng;
	return TokenTag::EQUALS;
}

"<=" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::LESSEQ);
	charNum+=yyleng;
	return TokenTag::LESSEQ;
}

">=" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::GREATEREQ);
	charNum+=yyleng;
	return TokenTag::GREATEREQ;
}

"<" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::LESS);
	charNum+=yyleng;
	return TokenTag::LESS;
}

">" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::GREATER);
	charNum+=yyleng;
	return TokenTag::GREATER;
}

"=" {
	yylval->symbolValue = new NullaryToken(lineNum, charNum, TokenTag::ASSIGN);
	charNum+=yyleng;
	return TokenTag::ASSIGN;
}

"\"".*"\\"{BADESCAPE}.*"\n"	{
	std::string msg = "unterminated string literal with bad escaped character ignored: ";
	msg += yytext;
	charNum += yyleng;
	error(lineNum, charNum, msg);
}

"\"".*"\n" {
	std::string msg = "unterminated string literal ignored: ";
	msg += yytext;
	charNum += yyleng;
	error(lineNum, charNum, msg);
}

"\\"{BADESCAPE} {
	std::string msg = "string literal with bad escaped character ignored: ";
	msg += yytext;
	charNum += yyleng;
	error(lineNum, charNum, msg);
}

.	{
	std::string msg = "illegal character ignored: ";
	msg += yytext;
	charNum += yyleng;
	error(lineNum, charNum, msg);
}
%%
