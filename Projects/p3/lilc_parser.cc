// A Bison parser, made by GNU Bison 3.0.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2013 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "lilc_parser.cc" // lalr1.cc:399

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "grammar.hh"

// User implementation prologue.

#line 51 "lilc_parser.cc" // lalr1.cc:407
// Unqualified %code blocks.
#line 33 "lilc.yy" // lalr1.cc:408

    #include <iostream>
    #include <cstdlib>
    #include <fstream>

    /* include for interoperation between scanner/parser */
    #include "lilc_compiler.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "lilc_parser.cc" // lalr1.cc:408


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif



// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyempty = true)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "lilc.yy" // lalr1.cc:474
namespace LILC {
#line 132 "lilc_parser.cc" // lalr1.cc:474

  /// Build a parser object.
  LilC_Parser::LilC_Parser (LilC_Scanner  &scanner_yyarg, LilC_Compiler &compiler_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      compiler (compiler_yyarg)
  {}

  LilC_Parser::~LilC_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  LilC_Parser::syntax_error::syntax_error (const std::string& m)
    : std::runtime_error (m)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
  {
    value = other.value;
  }


  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v)
    : Base (t)
    , value (v)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t)
    : Base (t)
    , value ()
  {}

  template <typename Base>
  inline
  LilC_Parser::basic_symbol<Base>::~basic_symbol ()
  {
  }

  template <typename Base>
  inline
  void
  LilC_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
  }

  // by_type.
  inline
  LilC_Parser::by_type::by_type ()
     : type (empty)
  {}

  inline
  LilC_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  LilC_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  LilC_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.type = empty;
  }

  inline
  int
  LilC_Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  LilC_Parser::by_state::by_state ()
    : state (empty)
  {}

  inline
  LilC_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  LilC_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.state = empty;
  }

  inline
  LilC_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  LilC_Parser::symbol_number_type
  LilC_Parser::by_state::type_get () const
  {
    return state == empty ? 0 : yystos_[state];
  }

  inline
  LilC_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  LilC_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s)
  {
    value = that.value;
    // that is emptied.
    that.type = empty;
  }

  inline
  LilC_Parser::stack_symbol_type&
  LilC_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    return *this;
  }


  template <typename Base>
  inline
  void
  LilC_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  LilC_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " (";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  LilC_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  LilC_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  LilC_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  LilC_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  LilC_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  LilC_Parser::debug_level_type
  LilC_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  LilC_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline LilC_Parser::state_type
  LilC_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  LilC_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  LilC_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  LilC_Parser::parse ()
  {
    /// Whether yyla contains a lookahead.
    bool yyempty = true;

    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyempty)
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
        yyempty = false;
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Discard the token being shifted.
    yyempty = true;

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;


      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 169 "lilc.yy" // lalr1.cc:847
    {
    //$$ = new ProgramNode(new DeclListNode($1));
    (yylhs.value.programNode) = new ProgramNode(new DeclListNode((yystack_[0].value.declList)));
    compiler.setASTRoot((yylhs.value.programNode));
}
#line 533 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 176 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
	(yylhs.value.declList) = (yystack_[1].value.declList);
}
#line 542 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 179 "lilc.yy" // lalr1.cc:847
    {
	(yylhs.value.declList) = new std::list<DeclNode *>();
}
#line 550 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 184 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.varDeclNode); }
#line 556 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 185 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.structDeclNode); }
#line 562 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 186 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.fnDeclNode); }
#line 568 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 189 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.varDeclList)->push_back((yystack_[0].value.varDeclNode));
	(yylhs.value.varDeclList) = (yystack_[1].value.varDeclList);
}
#line 577 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 192 "lilc.yy" // lalr1.cc:847
    {
	(yylhs.value.varDeclList) = new std::list<VarDeclNode *>();
}
#line 585 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 197 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.varDeclNode) = new VarDeclNode((yystack_[2].value.typeNode), (yystack_[1].value.idNode), VarDeclNode::NOT_STRUCT);
}
#line 593 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 202 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.fnDeclNode) = new FnDeclNode((yystack_[3].value.typeNode), (yystack_[2].value.idNode), (yystack_[1].value.formalsNode), (yystack_[0].value.fnBodyNode));
}
#line 601 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 207 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.structDeclNode) = new StructDeclNode((yystack_[4].value.idNode), (yystack_[2].value.structBodyNode));
}
#line 609 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 212 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.structBodyNode)->myVarDecls.push_back((yystack_[0].value.varDeclNode));
    (yylhs.value.structBodyNode) = (yystack_[1].value.structBodyNode);
}
#line 618 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 215 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.structBodyNode) = new StructBodyNode(new std::list<VarDeclNode *>());
}
#line 626 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 220 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalsNode) = new FormalsNode(new FormalsListNode(new std::list<FormalDeclNode *>()));
}
#line 634 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 222 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalsNode) = new FormalsNode((yystack_[1].value.formalsListNode));
}
#line 642 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 227 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalsListNode) = new FormalsListNode(new std::list<FormalDeclNode *>());
}
#line 650 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 229 "lilc.yy" // lalr1.cc:847
    {
  (yystack_[0].value.formalsListNode)->myFormalDecls->push_back((yystack_[2].value.formalDeclNode));
  (yylhs.value.formalsListNode) = (yystack_[0].value.formalsListNode);
}
#line 659 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 235 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalDeclNode) = new FormalDeclNode((yystack_[1].value.typeNode), (yystack_[0].value.idNode));
}
#line 667 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 240 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.fnBodyNode) = new FnBodyNode(new VarDeclListNode((yystack_[2].value.varDeclList)), (yystack_[1].value.stmtListNode));
}
#line 675 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 245 "lilc.yy" // lalr1.cc:847
    {
  (yystack_[1].value.stmtListNode)->myStmtNodes->push_back((yystack_[0].value.stmtNode));
  (yylhs.value.stmtListNode) = (yystack_[1].value.stmtListNode);
}
#line 684 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 248 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtListNode) = new StmtListNode(new std::list<StmtNode *>());
}
#line 692 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 253 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new AssignStmtNode((yystack_[1].value.assignNode));

}
#line 701 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 256 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new PostIncStmtNode((yystack_[2].value.dotAccessNode));

}
#line 710 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 259 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new PostDecStmtNode((yystack_[2].value.dotAccessNode));

}
#line 719 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 262 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new ReadStmtNode((yystack_[1].value.dotAccessNode));

}
#line 728 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 265 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new WriteStmtNode((yystack_[1].value.expNode));

}
#line 737 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 28:
#line 268 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new IfStmtNode((yystack_[5].value.expNode), new VarDeclListNode((yystack_[2].value.varDeclList)), (yystack_[1].value.stmtListNode));

}
#line 746 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 29:
#line 271 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new IfElseStmtNode((yystack_[10].value.expNode), new VarDeclListNode((yystack_[7].value.varDeclList)), (yystack_[6].value.stmtListNode), new VarDeclListNode((yystack_[2].value.varDeclList)), (yystack_[1].value.stmtListNode));

}
#line 755 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 30:
#line 274 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new WhileStmtNode((yystack_[5].value.expNode), new VarDeclListNode((yystack_[2].value.varDeclList)), (yystack_[1].value.stmtListNode));

}
#line 764 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 31:
#line 277 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[1].value.expNode));

}
#line 773 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 32:
#line 280 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode(new ExpNode());

}
#line 782 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 33:
#line 283 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new CallStmtNode((yystack_[1].value.callExpNode));
}
#line 790 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 34:
#line 288 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new PlusNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 799 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 35:
#line 291 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new MinusNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 808 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 36:
#line 294 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new TimesNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 817 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 37:
#line 297 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new DivideNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 826 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 38:
#line 300 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new NotNode((yystack_[0].value.expNode));

}
#line 835 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 39:
#line 303 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new AndNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 844 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 40:
#line 306 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new OrNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 853 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 41:
#line 309 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new EqualsNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 862 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 42:
#line 312 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new NotEqualsNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 871 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 43:
#line 315 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new LessNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 880 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 44:
#line 318 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new GreaterNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 889 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 45:
#line 321 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new LessEqNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 898 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 46:
#line 324 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new GreaterEqNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 907 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 47:
#line 327 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new UnaryMinusNode((yystack_[0].value.unaryExpNode));

}
#line 916 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 48:
#line 330 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new UnaryExpNode((yystack_[0].value.unaryExpNode));
}
#line 924 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 49:
#line 335 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.assignNode) = new AssignNode((yystack_[2].value.dotAccessNode), (yystack_[0].value.expNode));
}
#line 932 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 50:
#line 340 "lilc.yy" // lalr1.cc:847
    {
    //TODO: implement this?
}
#line 940 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 51:
#line 342 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new IntLitNode((yystack_[0].value.intTokenValue)));

}
#line 949 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 52:
#line 345 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new StrLitNode((yystack_[0].value.strTokenValue)));

}
#line 958 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 53:
#line 348 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new TrueNode());

}
#line 967 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 54:
#line 351 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new FalseNode());

}
#line 976 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 55:
#line 354 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode((yystack_[1].value.expNode));

}
#line 985 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 56:
#line 357 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode((yystack_[0].value.callExpNode));
}
#line 993 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 57:
#line 362 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.callExpNode) = new CallExpNode((yystack_[2].value.idNode), new ExpListNode(new std::list<ExpNode *>()));

}
#line 1002 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 58:
#line 365 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.callExpNode) = new CallExpNode((yystack_[3].value.idNode), (yystack_[1].value.expListNode));

}
#line 1011 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 59:
#line 371 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expListNode) = new ExpListNode(new std::list<ExpNode *>());

}
#line 1020 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 60:
#line 374 "lilc.yy" // lalr1.cc:847
    {
  (yystack_[2].value.expListNode)->myExpNodes->push_back((yystack_[0].value.expNode));
  (yylhs.value.expListNode) = (yystack_[2].value.expListNode);

}
#line 1030 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 61:
#line 382 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new IntNode(); }
#line 1036 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 62:
#line 383 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new BoolNode(); }
#line 1042 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 63:
#line 384 "lilc.yy" // lalr1.cc:847
    {}
#line 1048 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 64:
#line 387 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.dotAccessNode) = new DotAccessNode(new ExpNode() , (yystack_[0].value.idNode));
}
#line 1056 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 65:
#line 389 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.dotAccessNode) = new DotAccessNode((yystack_[2].value.dotAccessNode), (yystack_[0].value.idNode));
}
#line 1064 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 66:
#line 394 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.idNode) = new IdNode((yystack_[0].value.idTokenValue)); }
#line 1070 "lilc_parser.cc" // lalr1.cc:847
    break;


#line 1074 "lilc_parser.cc" // lalr1.cc:847
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yysyntax_error_ (yystack_[0].state,
                                           yyempty ? yyempty_ : yyla.type_get ()));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyempty)
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyempty = true;
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }


      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyempty)
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyempty)
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  LilC_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what());
  }

  // Generate an error message.
  std::string
  LilC_Parser::yysyntax_error_ (state_type, symbol_number_type) const
  {
    return YY_("syntax error");
  }


  const signed char LilC_Parser::yypact_ninf_ = -103;

  const signed char LilC_Parser::yytable_ninf_ = -1;

  const short int
  LilC_Parser::yypact_[] =
  {
    -103,     1,   136,  -103,  -103,  -103,  -103,    30,  -103,  -103,
    -103,  -103,    30,  -103,    -4,   -15,    78,    46,  -103,    41,
    -103,    49,    30,  -103,    37,    38,    30,  -103,  -103,    43,
    -103,    50,  -103,    78,  -103,    78,  -103,  -103,  -103,    65,
      51,    66,    73,    75,    40,  -103,  -103,    79,    80,   -12,
      88,    30,    90,    90,    90,  -103,  -103,  -103,  -103,    90,
    -103,   214,    90,   158,  -103,  -103,    85,  -103,  -103,    30,
      89,    92,    90,    83,     2,  -103,   178,    96,   117,   138,
    -103,   206,  -103,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,  -103,  -103,  -103,   206,  -103,
     206,     8,  -103,  -103,    94,    97,  -103,   206,   206,   206,
     206,   206,   206,   206,   206,   206,   206,   206,   206,  -103,
      90,  -103,  -103,   206,    78,    78,   213,   239,   106,  -103,
     101,  -103,    78,   246,  -103
  };

  const unsigned char
  LilC_Parser::yydefact_[] =
  {
       4,     0,     2,     1,    62,    61,    63,     0,     3,     5,
       7,     6,     0,    66,     0,     0,     0,     0,    10,     0,
      14,     0,     0,    15,     0,    17,     0,     9,    11,     0,
      13,     0,    16,     0,    19,    22,    12,    18,     8,     0,
       0,     0,     0,     0,     0,    20,    21,     0,     0,     0,
      64,     0,     0,     0,     0,    53,    54,    51,    52,     0,
      32,     0,     0,     0,    48,    56,    50,    23,    33,     0,
       0,     0,     0,     0,     0,    64,     0,     0,     0,     0,
      47,    38,    31,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    24,    25,    49,    57,
      59,     0,    26,    27,     0,     0,    55,    34,    35,    36,
      37,    39,    40,    41,    42,    43,    44,    45,    46,    58,
       0,     9,     9,    60,    22,    22,     0,     0,    28,    30,
       0,     9,    22,     0,    29
  };

  const signed char
  LilC_Parser::yypgoto_[] =
  {
    -103,  -103,  -103,  -103,  -102,     6,  -103,  -103,  -103,  -103,
      91,  -103,  -103,   -59,  -103,   -49,  -103,    62,   -37,  -103,
      13,   -39,    -1
  };

  const signed char
  LilC_Parser::yydefgoto_[] =
  {
      -1,     1,     2,     8,    35,    38,    10,    11,    21,    19,
      24,    25,    28,    39,    46,    63,    47,    64,    65,   101,
      22,    66,    50
  };

  const unsigned char
  LilC_Parser::yytable_[] =
  {
      49,     3,    48,    76,    77,    78,    14,    17,     9,    18,
      79,    15,    74,    81,    69,    12,    16,    70,    71,   124,
     125,    31,    20,    98,   100,    34,   102,    30,    69,   132,
      26,   119,    72,   120,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,    26,    13,    55,    56,
      75,     4,     5,     6,     4,     5,     6,    13,    57,    58,
      32,    27,    59,    33,    60,   126,   127,    36,    95,    23,
      29,   123,    61,   133,    18,    62,    40,    41,    42,    51,
      43,    44,    13,     4,     5,     6,    45,    49,    49,    48,
      48,    55,    56,    52,    49,    53,    48,    54,    55,    56,
      13,    57,    58,    67,    68,    59,    99,    13,    57,    58,
      73,    69,    59,    96,   121,    61,    97,   122,    62,   104,
     130,   131,    61,    80,    37,    62,     0,    83,    84,    85,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
     105,     4,     5,     6,     0,     0,     7,     0,    83,    84,
      85,    86,     0,    87,    88,    89,    90,    91,    92,    93,
      94,   106,     0,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,    82,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,   103,     0,     0,     0,     0,     0,     0,    83,
      84,    85,    86,     0,    87,    88,    89,    90,    91,    92,
      93,    94,    55,    56,    40,    41,    42,     0,    43,    44,
      13,    13,    57,    58,   128,     0,    59,    83,    84,    85,
      86,     0,    87,    88,    89,    90,    91,    92,    93,    94,
      40,    41,    42,     0,    43,    44,    13,    40,    41,    42,
     129,    43,    44,    13,     0,     0,     0,   134
  };

  const short int
  LilC_Parser::yycheck_[] =
  {
      39,     0,    39,    52,    53,    54,     7,    22,     2,    24,
      59,    12,    51,    62,    26,     2,    20,    29,    30,   121,
     122,    22,    16,    72,    73,    26,    24,    21,    26,   131,
      17,    23,    44,    25,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    33,    17,     8,     9,
      51,     5,     6,     7,     5,     6,     7,    17,    18,    19,
      23,    20,    22,    25,    24,   124,   125,    24,    69,    23,
      21,   120,    32,   132,    24,    35,    11,    12,    13,    28,
      15,    16,    17,     5,     6,     7,    21,   126,   127,   126,
     127,     8,     9,    27,   133,    22,   133,    22,     8,     9,
      17,    18,    19,    24,    24,    22,    23,    17,    18,    19,
      22,    26,    22,    24,    20,    32,    24,    20,    35,    23,
      14,    20,    32,    61,    33,    35,    -1,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      23,     5,     6,     7,    -1,    -1,    10,    -1,    31,    32,
      33,    34,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    -1,    36,    37,    38,    39,    40,    41,
      42,    43,     8,     9,    11,    12,    13,    -1,    15,    16,
      17,    17,    18,    19,    21,    -1,    22,    31,    32,    33,
      34,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      11,    12,    13,    -1,    15,    16,    17,    11,    12,    13,
      21,    15,    16,    17,    -1,    -1,    -1,    21
  };

  const unsigned char
  LilC_Parser::yystos_[] =
  {
       0,    46,    47,     0,     5,     6,     7,    10,    48,    50,
      51,    52,    65,    17,    67,    67,    20,    22,    24,    54,
      50,    53,    65,    23,    55,    56,    65,    20,    57,    21,
      50,    67,    23,    25,    67,    49,    24,    55,    50,    58,
      11,    12,    13,    15,    16,    21,    59,    61,    63,    66,
      67,    28,    27,    22,    22,     8,     9,    18,    19,    22,
      24,    32,    35,    60,    62,    63,    66,    24,    24,    26,
      29,    30,    44,    22,    66,    67,    60,    60,    60,    60,
      62,    60,    24,    31,    32,    33,    34,    36,    37,    38,
      39,    40,    41,    42,    43,    67,    24,    24,    60,    23,
      60,    64,    24,    24,    23,    23,    23,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    23,
      25,    20,    20,    60,    49,    49,    58,    58,    21,    21,
      14,    20,    49,    58,    21
  };

  const unsigned char
  LilC_Parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    49,    49,
      50,    51,    52,    53,    53,    54,    54,    55,    55,    56,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    60,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60,    61,
      62,    62,    62,    62,    62,    62,    62,    63,    63,    64,
      64,    65,    65,    65,    66,    66,    67
  };

  const unsigned char
  LilC_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     2,     0,
       3,     4,     6,     2,     1,     2,     3,     1,     3,     2,
       4,     2,     0,     2,     3,     3,     4,     4,     8,    13,
       8,     3,     2,     2,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     1,     3,
       1,     1,     1,     1,     1,     3,     1,     3,     4,     1,
       3,     1,     1,     1,     1,     3,     1
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const LilC_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"newline\"", "CHAR", "BOOL",
  "INT", "VOID", "TRUE", "FALSE", "STRUCT", "INPUT", "OUTPUT", "IF",
  "ELSE", "WHILE", "RETURN", "ID", "INTLITERAL", "STRINGLITERAL", "LCURLY",
  "RCURLY", "LPAREN", "RPAREN", "SEMICOLON", "COMMA", "DOT", "WRITE",
  "READ", "PLUSPLUS", "MINUSMINUS", "PLUS", "MINUS", "TIMES", "DIVIDE",
  "NOT", "AND", "OR", "EQUALS", "NOTEQUALS", "LESS", "GREATER", "LESSEQ",
  "GREATEREQ", "ASSIGN", "$accept", "program", "declList", "decl",
  "varDeclList", "varDecl", "fnDecl", "structDecl", "structBody",
  "formals", "formalsList", "formalDecl", "fnBody", "stmtList", "stmt",
  "exp", "assignExp", "term", "fncall", "actualList", "type", "loc", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  LilC_Parser::yyrline_[] =
  {
       0,   169,   169,   176,   179,   184,   185,   186,   189,   192,
     197,   202,   207,   212,   215,   220,   222,   227,   229,   235,
     240,   245,   248,   253,   256,   259,   262,   265,   268,   271,
     274,   277,   280,   283,   288,   291,   294,   297,   300,   303,
     306,   309,   312,   315,   318,   321,   324,   327,   330,   335,
     340,   342,   345,   348,   351,   354,   357,   362,   365,   371,
     374,   382,   383,   384,   387,   389,   394
  };

  // Print the state stack on the debug stream.
  void
  LilC_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  LilC_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  LilC_Parser::token_number_type
  LilC_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
    };
    const unsigned int user_token_number_max_ = 299;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "lilc.yy" // lalr1.cc:1155
} // LILC
#line 1515 "lilc_parser.cc" // lalr1.cc:1155
#line 395 "lilc.yy" // lalr1.cc:1156

void
LILC::LilC_Parser::error(const std::string &err_message )
{
    std::cerr << "Error: " << err_message << "\n";
}
