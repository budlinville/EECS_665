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
#line 168 "lilc.yy" // lalr1.cc:847
    {
    //$$ = new ProgramNode(new DeclListNode($1));
    (yylhs.value.programNode) = new ProgramNode(new DeclListNode((yystack_[0].value.declList)));
    compiler.setASTRoot((yylhs.value.programNode));
}
#line 533 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 3:
#line 174 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.declList)->push_back((yystack_[0].value.declNode));
	(yylhs.value.declList) = (yystack_[1].value.declList);
}
#line 542 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 4:
#line 177 "lilc.yy" // lalr1.cc:847
    {
	(yylhs.value.declList) = new std::list<DeclNode *>();
}
#line 550 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 5:
#line 181 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.varDeclNode); }
#line 556 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 6:
#line 182 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.structDeclNode); }
#line 562 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 7:
#line 183 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.declNode) = (yystack_[0].value.fnDeclNode); }
#line 568 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 8:
#line 187 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.varDeclNode) = new VarDeclNode((yystack_[2].value.typeNode), (yystack_[1].value.idNode), VarDeclNode::NOT_STRUCT);
}
#line 576 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 9:
#line 191 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.fnDeclNode) = new FnDeclNode((yystack_[3].value.typeNode), (yystack_[2].value.idNode), (yystack_[1].value.formalsNode), (yystack_[0].value.fnBodyNode));
}
#line 584 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 10:
#line 195 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.structDeclNode) = new StructDeclNode((yystack_[4].value.idNode), (yystack_[2].value.structBodyNode));
}
#line 592 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 11:
#line 199 "lilc.yy" // lalr1.cc:847
    {
    (yystack_[1].value.structBodyNode)->myVarDecls.push_back((yystack_[0].value.varDeclNode));
    (yylhs.value.structBodyNode) = (yystack_[1].value.structBodyNode);
}
#line 601 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 12:
#line 202 "lilc.yy" // lalr1.cc:847
    {
    (yylhs.value.structBodyNode) = new StructBodyNode(new std::list<VarDeclNode *>());
}
#line 609 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 13:
#line 206 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalsNode) = new FormalsNode(new FormalsListNode(new std::list<FormalDeclNode *>()));
}
#line 617 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 14:
#line 208 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalsNode) = new FormalsNode((yystack_[1].value.formalsListNode));
}
#line 625 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 15:
#line 212 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalsListNode) = new FormalsListNode(new std::list<FormalDeclNode *>());
}
#line 633 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 16:
#line 214 "lilc.yy" // lalr1.cc:847
    {
  (yystack_[0].value.formalsListNode)->myFormalDecls->push_back((yystack_[2].value.formalDeclNode));
  (yylhs.value.formalsListNode) = (yystack_[0].value.formalsListNode);
}
#line 642 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 17:
#line 219 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.formalDeclNode) = new FormalDeclNode((yystack_[1].value.typeNode), (yystack_[0].value.idNode));
}
#line 650 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 18:
#line 223 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.fnBodyNode) = new FnBodyNode(new DeclListNode((yystack_[2].value.declList)), (yystack_[1].value.stmtListNode));
}
#line 658 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 19:
#line 227 "lilc.yy" // lalr1.cc:847
    {
  (yystack_[1].value.stmtListNode)->myStmtNodes->push_back((yystack_[0].value.stmtNode));
  (yylhs.value.stmtListNode) = (yystack_[1].value.stmtListNode);
}
#line 667 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 20:
#line 230 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtListNode) = new StmtListNode(new std::list<StmtNode *>());
}
#line 675 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 21:
#line 235 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new AssignStmtNode((yystack_[1].value.assignNode));

}
#line 684 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 22:
#line 238 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new PostIncStmtNode((yystack_[2].value.dotAccessNode));

}
#line 693 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 23:
#line 241 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new PostDecStmtNode((yystack_[2].value.dotAccessNode));

}
#line 702 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 24:
#line 244 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new ReadStmtNode((yystack_[1].value.dotAccessNode));

}
#line 711 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 25:
#line 247 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new WriteStmtNode((yystack_[1].value.expNode));

}
#line 720 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 26:
#line 250 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new IfStmtNode((yystack_[5].value.expNode), new DeclListNode((yystack_[2].value.declList)), (yystack_[1].value.stmtListNode));

}
#line 729 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 27:
#line 253 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new IfElseStmtNode((yystack_[10].value.expNode), new DeclListNode((yystack_[7].value.declList)), (yystack_[6].value.stmtListNode), new DeclListNode((yystack_[2].value.declList)), (yystack_[1].value.stmtListNode));

}
#line 738 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 28:
#line 256 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new WhileStmtNode((yystack_[5].value.expNode), new DeclListNode((yystack_[2].value.declList)), (yystack_[1].value.stmtListNode));

}
#line 747 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 29:
#line 259 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode((yystack_[1].value.expNode));

}
#line 756 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 30:
#line 262 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new ReturnStmtNode(new ExpNode());

}
#line 765 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 31:
#line 265 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.stmtNode) = new CallStmtNode((yystack_[1].value.callExpNode));
}
#line 773 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 32:
#line 272 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new PlusNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 782 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 33:
#line 275 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new MinusNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 791 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 34:
#line 278 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new TimesNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 800 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 35:
#line 281 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new DivideNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 809 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 36:
#line 284 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new NotNode((yystack_[0].value.expNode));

}
#line 818 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 37:
#line 287 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new AndNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 827 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 38:
#line 290 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new OrNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 836 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 39:
#line 293 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new EqualsNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 845 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 40:
#line 296 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new NotEqualsNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 854 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 41:
#line 299 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new LessNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 863 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 42:
#line 302 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new GreaterNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 872 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 43:
#line 305 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new LessEqNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 881 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 44:
#line 308 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new GreaterEqNode((yystack_[2].value.expNode), (yystack_[0].value.expNode));

}
#line 890 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 45:
#line 311 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new UnaryMinusNode((yystack_[0].value.unaryExpNode));

}
#line 899 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 46:
#line 314 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expNode) = new UnaryExpNode((yystack_[0].value.unaryExpNode));
}
#line 907 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 47:
#line 318 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.assignNode) = new AssignNode((yystack_[2].value.dotAccessNode), (yystack_[0].value.expNode));
}
#line 915 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 48:
#line 323 "lilc.yy" // lalr1.cc:847
    {
    //TODO: implement this?
}
#line 923 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 49:
#line 325 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new IntLitNode((yystack_[0].value.intLitValue)));

}
#line 932 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 50:
#line 328 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new StrLitNode((yystack_[0].value.strLitValue)));

}
#line 941 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 51:
#line 331 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new TrueNode());

}
#line 950 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 52:
#line 334 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode(new FalseNode());

}
#line 959 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 53:
#line 337 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode((yystack_[1].value.expNode));

}
#line 968 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 54:
#line 340 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.unaryExpNode) = new UnaryExpNode((yystack_[0].value.callExpNode));
}
#line 976 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 55:
#line 345 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.callExpNode) = new CallExpNode((yystack_[2].value.idNode), new ExpListNode(new std::list<ExpNode *>()));

}
#line 985 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 56:
#line 348 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.callExpNode) = new CallExpNode((yystack_[3].value.idNode), (yystack_[1].value.expListNode));

}
#line 994 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 57:
#line 354 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.expListNode) = new ExpListNode(new std::list<ExpNode *>());

}
#line 1003 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 58:
#line 357 "lilc.yy" // lalr1.cc:847
    {
  (yystack_[2].value.expListNode)->myExpNodes->push_back((yystack_[0].value.expNode));
  (yylhs.value.expListNode) = (yystack_[2].value.expListNode);

}
#line 1013 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 59:
#line 365 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new IntNode(); }
#line 1019 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 60:
#line 366 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.typeNode) = new BoolNode(); }
#line 1025 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 61:
#line 367 "lilc.yy" // lalr1.cc:847
    {}
#line 1031 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 62:
#line 369 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.dotAccessNode) = new DotAccessNode(new ExpNode() , (yystack_[0].value.idNode));
}
#line 1039 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 63:
#line 371 "lilc.yy" // lalr1.cc:847
    {
  (yylhs.value.dotAccessNode) = new DotAccessNode((yystack_[2].value.dotAccessNode), (yystack_[0].value.idNode));
}
#line 1047 "lilc_parser.cc" // lalr1.cc:847
    break;

  case 64:
#line 375 "lilc.yy" // lalr1.cc:847
    { (yylhs.value.idNode) = new IdNode((yystack_[0].value.idTokenValue)); }
#line 1053 "lilc_parser.cc" // lalr1.cc:847
    break;


#line 1057 "lilc_parser.cc" // lalr1.cc:847
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


  const signed char LilC_Parser::yypact_ninf_ = -72;

  const signed char LilC_Parser::yytable_ninf_ = -1;

  const short int
  LilC_Parser::yypact_[] =
  {
     -72,     2,    22,   -72,   -72,   -72,   -72,    14,   -72,   -72,
     -72,   -72,    14,   -72,    29,    -1,     3,    10,   -72,    42,
     -72,    13,    14,   -72,     7,    40,    14,   -72,   -72,    46,
     -72,    49,   -72,     3,   -72,    22,   -72,   -72,   228,    38,
      52,    70,    74,    39,   -72,   -72,    77,    80,    25,    88,
      14,    97,    97,    97,   -72,   -72,   -72,   -72,    97,   -72,
     202,    97,   144,   -72,   -72,    85,   -72,   -72,    14,    93,
      99,    97,    90,    76,   -72,   164,    44,   103,   124,   -72,
     195,   -72,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,   -72,   -72,   -72,   195,   -72,   195,
      95,   -72,   -72,   101,   104,   -72,   195,   195,   195,   195,
     195,   195,   195,   195,   195,   195,   195,   195,   -72,    97,
     -72,   -72,   195,    22,    22,   235,   242,   113,   -72,   108,
     -72,    22,   249,   -72
  };

  const unsigned char
  LilC_Parser::yydefact_[] =
  {
       4,     0,     2,     1,    60,    59,    61,     0,     3,     5,
       7,     6,     0,    64,     0,     0,     0,     0,     8,     0,
      12,     0,     0,    13,     0,    15,     0,     4,     9,     0,
      11,     0,    14,     0,    17,    20,    10,    16,     0,     0,
       0,     0,     0,     0,    18,    19,     0,     0,     0,    62,
       0,     0,     0,     0,    51,    52,    49,    50,     0,    30,
       0,     0,     0,    46,    54,    48,    21,    31,     0,     0,
       0,     0,     0,     0,    62,     0,     0,     0,     0,    45,
      36,    29,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    63,    22,    23,    47,    55,    57,
       0,    24,    25,     0,     0,    53,    32,    33,    34,    35,
      37,    38,    39,    40,    41,    42,    43,    44,    56,     0,
       4,     4,    58,    20,    20,     0,     0,    26,    28,     0,
       4,    20,     0,    27
  };

  const short int
  LilC_Parser::yypgoto_[] =
  {
     -72,   -72,   -27,   -72,    43,   -72,   -72,   -72,   -72,    98,
     -72,   -72,   -71,   -72,   -47,   -72,    73,   -35,   -72,   192,
     -37,     0
  };

  const signed char
  LilC_Parser::yydefgoto_[] =
  {
      -1,     1,     2,     8,     9,    10,    11,    21,    19,    24,
      25,    28,    38,    45,    62,    46,    63,    64,   100,    12,
      65,    49
  };

  const unsigned char
  LilC_Parser::yytable_[] =
  {
      35,    48,     3,    47,    75,    76,    77,    14,     4,     5,
       6,    78,    15,    73,    80,     4,     5,     6,     4,     5,
       6,    17,    31,    18,    97,    99,    34,     4,     5,     6,
      32,    13,     7,    23,    29,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,    54,    55,    16,
      74,    68,   125,   126,    69,    70,    13,    56,    57,    20,
     132,    58,    27,    59,    30,    33,    50,   103,    94,    71,
      36,    60,   122,    18,    61,    82,    83,    84,    85,    51,
      86,    87,    88,    89,    90,    91,    92,    93,    48,    48,
      47,    47,    52,   123,   124,    48,    53,    47,    54,    55,
     101,    66,    68,   131,    67,    54,    55,    13,    56,    57,
      72,    68,    58,    98,    13,    56,    57,    95,   118,    58,
     119,   120,    60,    96,   121,    61,   104,   129,   130,    60,
       0,    37,    61,    79,    82,    83,    84,    85,     0,    86,
      87,    88,    89,    90,    91,    92,    93,   105,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    81,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,     0,
      86,    87,    88,    89,    90,    91,    92,    93,   102,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,     0,
      86,    87,    88,    89,    90,    91,    92,    93,    22,    26,
      54,    55,     0,    22,     0,     0,     0,     0,     0,    13,
      56,    57,     0,     0,    58,    26,    82,    83,    84,    85,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    39,
      40,    41,     0,    42,    43,    13,    39,    40,    41,    44,
      42,    43,    13,    39,    40,    41,   127,    42,    43,    13,
      39,    40,    41,   128,    42,    43,    13,     0,     0,     0,
     133
  };

  const short int
  LilC_Parser::yycheck_[] =
  {
      27,    38,     0,    38,    51,    52,    53,     7,     5,     6,
       7,    58,    12,    50,    61,     5,     6,     7,     5,     6,
       7,    22,    22,    24,    71,    72,    26,     5,     6,     7,
      23,    17,    10,    23,    21,    82,    83,    84,    85,    86,
      87,    88,    89,    90,    91,    92,    93,     8,     9,    20,
      50,    26,   123,   124,    29,    30,    17,    18,    19,    16,
     131,    22,    20,    24,    21,    25,    28,    23,    68,    44,
      24,    32,   119,    24,    35,    31,    32,    33,    34,    27,
      36,    37,    38,    39,    40,    41,    42,    43,   125,   126,
     125,   126,    22,   120,   121,   132,    22,   132,     8,     9,
      24,    24,    26,   130,    24,     8,     9,    17,    18,    19,
      22,    26,    22,    23,    17,    18,    19,    24,    23,    22,
      25,    20,    32,    24,    20,    35,    23,    14,    20,    32,
      -1,    33,    35,    60,    31,    32,    33,    34,    -1,    36,
      37,    38,    39,    40,    41,    42,    43,    23,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    -1,
      36,    37,    38,    39,    40,    41,    42,    43,    16,    17,
       8,     9,    -1,    21,    -1,    -1,    -1,    -1,    -1,    17,
      18,    19,    -1,    -1,    22,    33,    31,    32,    33,    34,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    11,
      12,    13,    -1,    15,    16,    17,    11,    12,    13,    21,
      15,    16,    17,    11,    12,    13,    21,    15,    16,    17,
      11,    12,    13,    21,    15,    16,    17,    -1,    -1,    -1,
      21
  };

  const unsigned char
  LilC_Parser::yystos_[] =
  {
       0,    46,    47,     0,     5,     6,     7,    10,    48,    49,
      50,    51,    64,    17,    66,    66,    20,    22,    24,    53,
      49,    52,    64,    23,    54,    55,    64,    20,    56,    21,
      49,    66,    23,    25,    66,    47,    24,    54,    57,    11,
      12,    13,    15,    16,    21,    58,    60,    62,    65,    66,
      28,    27,    22,    22,     8,     9,    18,    19,    22,    24,
      32,    35,    59,    61,    62,    65,    24,    24,    26,    29,
      30,    44,    22,    65,    66,    59,    59,    59,    59,    61,
      59,    24,    31,    32,    33,    34,    36,    37,    38,    39,
      40,    41,    42,    43,    66,    24,    24,    59,    23,    59,
      63,    24,    24,    23,    23,    23,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    23,    25,
      20,    20,    59,    47,    47,    57,    57,    21,    21,    14,
      20,    47,    57,    21
  };

  const unsigned char
  LilC_Parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    48,    48,    48,    49,    50,
      51,    52,    52,    53,    53,    54,    54,    55,    56,    57,
      57,    58,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    60,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    65,    65,    66
  };

  const unsigned char
  LilC_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     0,     1,     1,     1,     3,     4,
       6,     2,     1,     2,     3,     1,     3,     2,     4,     2,
       0,     2,     3,     3,     4,     4,     8,    13,     8,     3,
       2,     2,     3,     3,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     2,     1,     3,     1,     1,
       1,     1,     1,     3,     1,     3,     4,     1,     3,     1,
       1,     1,     1,     3,     1
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
  "varDecl", "fnDecl", "structDecl", "structBody", "formals",
  "formalsList", "formalDecl", "fnBody", "stmtList", "stmt", "exp",
  "assignExp", "term", "fncall", "actualList", "type", "loc", "id", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  LilC_Parser::yyrline_[] =
  {
       0,   168,   168,   174,   177,   181,   182,   183,   187,   191,
     195,   199,   202,   206,   208,   212,   214,   219,   223,   227,
     230,   235,   238,   241,   244,   247,   250,   253,   256,   259,
     262,   265,   272,   275,   278,   281,   284,   287,   290,   293,
     296,   299,   302,   305,   308,   311,   314,   318,   323,   325,
     328,   331,   334,   337,   340,   345,   348,   354,   357,   365,
     366,   367,   369,   371,   375
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
#line 1500 "lilc_parser.cc" // lalr1.cc:1155
#line 376 "lilc.yy" // lalr1.cc:1156

void
LILC::LilC_Parser::error(const std::string &err_message )
{
    std::cerr << "Error: " << err_message << "\n";
}
