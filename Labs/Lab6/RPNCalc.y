%{
#include <stdio.h>
#include <math.h>
int yylex (void);
void yyerror (char const *);
%}

%define api.value.type {double}
%token NUM
%left '+' '-'
%left '*' '/'
%precedence NEG
%right '^'

%%
input:
    %empty          /* empty string in bison */
    | input line
    ;

line:
    '\n'
    | exp '\n'  { printf("%.10g\n", $1); }
    | error '\n' { yyerrok; }
    ;

exp:
    NUM             { $$ = $1; }
    | '-' exp %prec NEG { $$ = -$2; }
    | exp '+' exp   { $$ = $1 + $3; }
    | exp '-' exp   { $$ = $1 - $3; }
    | exp '*' exp   { $$ = $1 * $3; }
    | exp '/' exp  {
        if ($3)
            $$ = $1 / $3;
        else {
            $$ = $1;
            fprintf(stderr, "%d.%d-%d.%d: division by zero",
                @2.first_line, @2.first_column, @2.last_line, @2.last_column);
        }
    }
    | exp '^' exp   { $$ = pow($1, $3); }
    | '(' exp ')'   { $$ = $2; }
    ;

%%

/* The lexical analyzer returns a double floating point
   number on the stack and the token NUM, or the numeric code
   of the character read if not a number.  It skips all blanks
   and tabs, and returns 0 for end-of-input.  */

#include <ctype.h>

int yylex (void) {
    int c;

    /* Skip white space.  */
    while ((c = getchar ()) == ' ' || c == '\t')
        continue;

    /* Process numbers.  */
    if (c == '.' || isdigit (c)) {
        ungetc (c, stdin);
        scanf ("%lf", &yylval);
        return NUM;
    }

    /* Return end-of-input.  */
    if (c == EOF)
        return 0;

    /* Return a single char.  */
    return c;
}

/* Called by yyparse on error.  */
void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
}

int main (void) {
    return yyparse ();
}
