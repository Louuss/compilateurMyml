
%code requires {


#include "Table_des_symboles.h"  // header included in y.tab.h

}

%{
#include <stdio.h>


extern int yylex();
extern int yyparse();

void yyerror (char* s) {
   printf("\n%s\n",s);
 }

%}

%union{
  symb_value_type val;
  //char * sid;
}



%type <val> atom_exp
%type <val> arith_exp
%type <val> let_exp
%type <val> bool
%type <val> comp
%type <val> control_exp
%type <val> aff_id


%type <val> ELSE_label
%type <val> IF_label
%type <val> THEN_label



%token NUM
%type <val> NUM
%token <val> FLOAT
%token <val> ID
%token STRING

%token PV LPAR RPAR LBR RBR LET IN VIR

%token IF THEN ELSE

%token ISLT ISGT ISLEQ ISGEQ ISEQ
%left ISEQ
%left ISLT ISGT ISLEQ ISGEQ


%token AND OR NOT BOOL
%left OR
%left AND

%type <val> exp

%token PLUS MOINS MULT DIV EQ
%left PLUS
%left MULT
%left CONCAT
%nonassoc UNA    /* pseudo token pour assurer une priorite locale */


%start prog



%%

prog : inst PV
| prog inst PV
;

inst : aff
| exp
;


aff : aff_id {}
| aff_fun
;

aff_id : ID EQ exp
        {
          //fprintf(test_c,"r%d = r%d;a\n", $1.reg,$3.reg);
          fprintf(test_c, "%s = r%d ; \n",$1.sid, $3.reg );
          $$=$3;
          $$.sid = $1.sid ;
          $$.type = $3.type;
          set_symbol_value($1.sid,$$);


          fprintf(test_h, "%s %s ;", getType($$.type) , $$.sid);

          if ($3.type == Float )
            fprintf(test_c, "printf(\"%s de type <%s> vaut %%f;\", r%d );\n", $1.sid, getType($3.type),$3.reg);
          else
            fprintf(test_c, "printf(\"%s de type <%s> vaut %%d ;\", r%d );\n", $1.sid, getType($3.type),$3.reg);
        }
;




aff_fun : fun_head EQ exp
;

fun_head : ID id_list
;

id_list : ID
        | id_list ID
;


exp : arith_exp {

  if($1.type == Float)
  {
    $$.type = Float ;
    fprintf(test_c, "printf(\"<exp> de type <%s> vaut %%f;\", r%d );\n"
                ,getType($1.type)
                ,$1.reg);

  }
  else
  {
    $$.type = Int ;
  fprintf(test_c, "printf(\"<exp> de type <%s> vaut %%d;\", r%d );\n"
              ,getType($1.type)
              ,$1.reg);

  }


  $$ = $1; $$.more =1;}
    | atom_exp { $$ = $1;}/*{printf("%d\n", $1.value);} Il faudra faire un switch pour l'affichage*/
    | control_exp
    | let_exp
    | LPAR funcall_exp RPAR
;

arith_exp : MOINS exp %prec UNA


          | exp PLUS exp
            {
            fprintf(test_c, "r%d = r%d + r%d;\n", $$.reg = newReg(), $1.reg, $3.reg);

              printf("\n\n\n je suis dedans cono");

             if(($1.type == Float) || $3.type == Float)
              {

                fprintf(test_h, "float r%d;\n", $$.reg);
                $$.type = Float;
                //$$.valf = $1.value + $3.value;
              }
            else {
              fprintf(test_h, "int r%d;\n", $$.reg);
              $$.type = Int ;
            }


            }
          | exp MULT exp
          {
            fprintf(test_c, "r%d = r%d * r%d;\n", $$.reg = newReg(), $1.reg, $3.reg);

            if(($1.type == Float) || $3.type == Float)
              {
                fprintf(test_h, "float r%d;\n", $$.reg);
                $$.type = Float;
                //$$.valf = $1.value + $3.value;
              }
            else {
              fprintf(test_h, "int r%d;\n", $$.reg);
              $$.type = Int ;
            }
          }
          | exp CONCAT exp
;

atom_exp :  NUM
            {
              $$.reg=newReg();
              $$.value = $1.value;
              $$.type = Int;
              fprintf(test_h, "int r%d;\n", $$.reg);
              fprintf(test_c,"r%d = %d;\n",$$.reg,$$.value);
            }

          | FLOAT
          {
            $$.reg=$$.reg=newReg();
            $$.valf = $1.valf;
            $$.type = Float ;
            fprintf(test_h, "float r%d;\n", $$.reg);
            fprintf(test_c,"r%d = %f;\n",$$.reg,$$.valf);
          }
          | STRING
          | ID
            {
              $$ = get_symbol_value($1.sid);
            }
          | list_exp
          | LPAR exp RPAR {$$ = $2;}
;

control_exp : IF_label bool THEN_label atom_exp ELSE_label atom_exp
              {


                fprintf(test_c,   "r%d=r%d;\n\t"
                                  "goto end%d;\n\t"
                                  "ifstatement%d:\n\t"
                                  "if (!r%d) goto iffalse%d;\n\t"
                                  "goto iftrue%d;\n\t"
                                  "end%d:\n"

                              , currentIfResultReg
                              , getCurrentReg()
                              , ifCounter
                              , ifCounter
                              , $2.reg
                              , ifCounter
                              , ifCounter
                              , ifCounter);

              }
;

IF_label: IF
  {
    $$.reg=newReg();
    fprintf(test_h, "int r%d;\n", $$.reg);
    currentIfResultReg = $$.reg;
  }
  ;


THEN_label: THEN
  {
    ifCounter++;
    fprintf(test_c, "goto ifstatement%d;\n\t"
                    "iftrue%d:\n"

                  , ifCounter
                  , ifCounter);
  }
  ;

ELSE_label: ELSE
  {
    fprintf(test_c, "r%d=r%d;\n\t"
                    "goto end%d;\n\t"
                    "iffalse%d:\n"

                  , currentIfResultReg
                  , getCurrentReg()
                  , ifCounter
                  , ifCounter);
  }
  ;


let_exp : let2 aff IN atom_exp {$$ = $4; lessStorage();}
;

let2 : LET {moreStorage();}

funcall_exp : ID atom_list
;

atom_list : atom_exp
          | atom_list atom_exp
;


list_exp : LBR exp_list RBR
;

exp_list :  exp
          | exp_list VIR exp
;

bool :  BOOL
      | bool OR bool
        {

        printf("\nhere\n");
        $$.reg=newReg();
        fprintf(test_h, "int r%d;\n", $$.reg);
        fprintf(test_c, "r%d = (r%d || r%d);\n", $$.reg, $1.reg,$3.reg);
        }
      | bool AND bool
        {
        printf("\nhere\n");
        $$.reg=newReg();
        fprintf(test_h, "int r%d;\n", $$.reg);
        fprintf(test_c, "r%d = (r%d && r%d);\n", $$.reg, $1.reg,$3.reg);
        }

      | NOT bool %prec UNA
      {
        fprintf(test_c, "r%d = !r%d;\n", $2.reg,$2.reg);
      }
      | exp comp exp
      {
        $$.reg=newReg();
        fprintf(test_h, "int r%d;\n", $$.reg);
        fprintf(stderr, "%d\nend", $$.reg);

        fprintf(test_c, "r%d = (r%d %s r%d);\n", $$.reg, $1.reg, $2.op,$3.reg);
      }
      | LPAR bool RPAR {$$=$2;}
;


comp :  ISLT  {$$.value=0; $$.op="<";}
      | ISGT {$$.value=1;  $$.op=">";}
      | ISLEQ {$$.value=2; $$.op="<=";}
      | ISGEQ {$$.value=3; $$.op=">=";}
      | ISEQ {$$.value=4;  $$.op="==";}
      ;

%%
int main () {
  test_c = fopen("test.c","w");
  test_h = fopen("test.h","w");

  fprintf(test_c, "#include \"test.h\"\n\t"
                  "#include <stdbool.h>\n\t"
                  "#include <stdio.h>\n\t"
                  "int main(void){\n");


  // lancement de la compilation
  yyparse ();
  // fermeture des fichiers

  fprintf(test_c, "return 0;\n}");
  fclose(test_c);
  fclose(test_h);

}
