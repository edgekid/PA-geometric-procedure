grammar LIA;
start : formula EOF ;

term : term termop term # TermOperation
| term2 #TermTmp
;

term2 : term2 MULT INT # MultByConst1
| INT MULT term2 # MultByConst0
| termop term2 # SignedTerm 
| LPAREN term RPAREN #Paren1
| VARIABLE # Var
| INT # Const
;

formula : QUANT VARIABLE COLON formula # Quant
| NOT formula # Complement
| LPAREN formula RPAREN # Paren2
| formula2 # FormulaTmp
;

formula2 : term relop term # TermRelation
| LPAREN formula2 RPAREN # Paren3
| formula2 boolop formula2 # FormulaOperation
| NOT formula2 # Complement2
;

relop : EQ | GT | LT ;
boolop: OR | AND ;
termop: PLUS | MINUS ;

QUANT : 'forall' | 'exists' ;

VARIABLE : VALID_ID_START VALID_ID_CHAR* ;
fragment VALID_ID_START : 'a' .. 'z' | 'A' .. 'Z' | '_' ;
fragment VALID_ID_CHAR : VALID_ID_START | '0' .. '9' ;

INT : ('0' .. '9')+ ;

LPAREN : '(' ;

RPAREN : ')' ;

PLUS : '+' ;

MINUS : '-' ;

MULT : '*' ;

GT : '>' ;

LT : '<' ;

EQ : '=' ;

OR : '||' ;

AND : '&&' ;

COLON : ':' ;

NOT : '!' ;

WS: [ \n\t\r]+ -> skip;