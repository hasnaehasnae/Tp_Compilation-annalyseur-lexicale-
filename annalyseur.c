#include "annalyseur.h"
#include "stdio.h"
typedef enum { false, true } boolean;
boolean isligne();
boolean isCONST();
boolean isDeclr();
boolean isType();
boolean isMULT();
boolean isAux();
boolean isADD();
extern  int yylex();
extern  char* yytext();
extern  char*  yyerror();
int token=1 ;
int lig=1 ;
int ok=0 ;

int main(void){
while(token){
token=(tokensTypes)yylex();
if (token == LIGN ){
lig=lig+1 ;
}

if(token == DEBUT){
ok=1;
}
if(ok==0){
if(isDeclr()){
printf("c'est bien \n");
}else{if(token != LIGN  ){
printf("erreur à la ligne %d " , lig);
}}
}

if(ok==1){
if(isligne()){
printf("c'est bienn ");
}else { printf("erreur   ");}

}

                                                   }
return 0 ;
}

// fonction de verifecation de déclaration
boolean isDeclr(){
if (token == IDF ){
token=(tokensTypes)yylex();
if(isType()== true){
token=(tokensTypes)yylex();
if(isCONST()== true){
token=(tokensTypes)yylex();
if(token== DEL){
return true ;
}else {return false ;}
}else {return false ;}
}else {return false ;}
}else {return false ;}
}

// fonction de verfecation des constantes
boolean isCONST(){
if (token ==FALSE  ||  token ==TRUE ||  token==INT  ){
return true ;
}else return false ;
}

// fonction de verefication des type
boolean isType(){
if (token ==TINT  || token ==BOOL ){
return true ;
}else return false ;
}


////////
boolean isAux(){
if (token== IDF || token == INT ){
return true ;
}else { return false ;}

}
//
boolean isMULT(){
if (isAux() ) {
token=(tokensTypes)yylex();
if(token == MULT ){
token=(tokensTypes)yylex();
return ( isMULT() );
}else {
         if ( isADD() ) {return true ;
                                    }else {   if ( token == DEL ){return 
true ;}else{return false ;}
 } 

      }}





                          


}





//

boolean isADD(){
if ( token == ADD ||  token == SUB )      {
token=(tokensTypes)yylex();
return(isMULT());
}else {
         if ( token == DEL ) {return true ;
                                    }else {return false; } 

      }

                          }







//


boolean isligne(){
token=(tokensTypes)yylex();
if(token == LIGN){
token=(tokensTypes)yylex();
}
if(token == IDF){
token=(tokensTypes)yylex();
if ( token == EGAL ){
token=(tokensTypes)yylex();
if( isMULT() ){return true ;}
else{return false ;}
}else{return false ;}
}else{return false ;}






                   }
