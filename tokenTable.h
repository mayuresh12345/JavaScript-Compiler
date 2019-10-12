#include &lt;string.h&gt;
#include &lt;stdio.h&gt;
#include &lt;stdlib.h&gt;
#define maxLexemeLength 100
#define maxTokenTableSize 1000
enum enumTokenProp;

enum enumTokenType;
void addToken(char * lex, int row, int col, enum enumTokenProp enum_name, enum enumTokenType
type);
int isArithmaticOp (enum enumTokenProp enum_name);
int isAssignmentOp (enum enumTokenProp enum_name);
int isBitwiseOp(enum enumTokenProp enum_name);
int isIdentifier(enum enumTokenProp enum_name);
int isKeyword(enum enumTokenProp enum_name);
int isKeywordOperator(enum enumTokenProp enum_name);
int isLogicalOp(enum enumTokenProp enum_name);
int isNumber(enum enumTokenProp enum_name);
int isPropertyAccessor(enum enumTokenProp enum_name);
int isRelationalOp (enum enumTokenProp enum_name);
int isSpecial(enum enumTokenProp enum_name);
int isString(enum enumTokenProp enum_name);
int isTernaryOp(enum enumTokenProp enum_name);
char * getEnum_Name_to_String(enum enumTokenProp enum_name);
enum enumTokenType getTokenType(enum enumTokenProp enum_name);
void newToken(char * lex, int row, int col, enum enumTokenProp enum_name);
void printToken();
void printTokenTable();
int tokenCount = 0;
enum enumTokenProp {
// 1
ENUM_VAR,
ENUM_LET,
ENUM_CONST,
ENUM_REQUIRE,
ENUM_IMPORT,
ENUM_EXPORT,
ENUM_FROM,
ENUM_AS,
ENUM_FUNCTION,
ENUM_THIS,
ENUM_NEW,
ENUM_TRUE_CONDITION,
ENUM_FALSE_CONDITION,
ENUM_IF,
ENUM_ELSE,
ENUM_DO,
ENUM_FOR,
ENUM_WHILE,
ENUM_CONTINUE,
ENUM_BREAK,
ENUM_WITH,
ENUM_RETURN,

ENUM_TRY,
ENUM_CATCH,
ENUM_FINALLY,
ENUM_THROW,
ENUM_SWITCH,
ENUM_CASE,
ENUM_DEFAULT,
// 2
ENUM_EQUAL,
ENUM_MUL_ASSIGN,
ENUM_DIV_ASSIGN,
ENUM_REMAINDER_ASSIGN,
ENUM_ADD_ASSIGN,
ENUM_SUB_ASSIGN,
ENUM_LEFT_SHIFT_ASSIGN,
ENUM_RIGHT_SHIFT_ASSIGN,
ENUM_UNSIGNED_RIGHT_SHIFT_ASSIGN,
ENUM_BITWISE_AND_ASSIGN,
ENUM_BITWISE_XOR_ASSIGN,
ENUM_BITWISE_OR_ASSIGN,
// 3
ENUM_PLUS,
ENUM_PLUS_PLUS,
ENUM_MINUS,
ENUM_MINUS_MINUS,
ENUM_STAR,
ENUM_FORWARD_SLASH,
ENUM_PERCENT,
// 4
ENUM_BOOLEAN_AND,
ENUM_BOOLEAN_OR,
ENUM_EXCLAMATION,
// 5
ENUM_NOT_EQUAL,
ENUM_EQUAL_EQUAL,
ENUM_IDENTITY,
ENUM_NOT_IDENTITY,
ENUM_LESS_THAN,
ENUM_GREATER_THAN,
ENUM_LESS_THAN_EQUAL,
ENUM_GREATER_THAN_EQUAL,
// 6
ENUM_BIT_AND,
ENUM_BIT_OR,
ENUM_BIT_XOR,
ENUM_TILDE,
ENUM_SHIFT_LEFT,
ENUM_SHIFT_RIGHT,
ENUM_UNSIGNED_RIGHT_SHIFT,

// 7
ENUM_DOT,
// 8
ENUM_COLON,
ENUM_QUESTION,
ENUM_LBRACKET,
ENUM_RBRACKET,
ENUM_LPAREN,
ENUM_RPAREN,
ENUM_LCURLY,
ENUM_RCURLY,
ENUM_SEMICOLON,
ENUM_COMMA,
ENUM_ARROW_FUNC,
// 9
ENUM_STRING,
ENUM_ID,
ENUM_NULL_VALUE,
ENUM_NUMBER,
// 10
ENUM_VOID,
ENUM_DELETE,
ENUM_IN,
ENUM_INSTANCEOF,
ENUM_TYPEOF,
};

enum enumTokenType {
type_keyword,
type_identifier,
type_string,
type_number,
type_propertyAccessor,
type_keyword_op,
type_ar_op,
type_assignment_op,
type_rel_op,
type_tern_op,
type_log_op,
type_bitwise_op,
type_special_op,
};
typedef struct tokenTableStructure{
char lex[maxLexemeLength];
int row;
int col;

enum enumTokenProp enum_name;
enum enumTokenType type;
} token_struct;
token_struct tokenTable[maxTokenTableSize];
int isArithmaticOp (enum enumTokenProp enum_name){
switch(enum_name){
case ENUM_PLUS:
case ENUM_MINUS:
case ENUM_STAR:
case ENUM_FORWARD_SLASH:
case ENUM_PERCENT:
case ENUM_PLUS_PLUS:
case ENUM_MINUS_MINUS: return 1;
default: return 0;
}
}
int isAssignmentOp (enum enumTokenProp enum_name){
switch(enum_name){
case ENUM_EQUAL:
case ENUM_MUL_ASSIGN:
case ENUM_DIV_ASSIGN:
case ENUM_REMAINDER_ASSIGN:
case ENUM_ADD_ASSIGN:
case ENUM_SUB_ASSIGN:
case ENUM_LEFT_SHIFT_ASSIGN:
case ENUM_RIGHT_SHIFT_ASSIGN:
case ENUM_UNSIGNED_RIGHT_SHIFT_ASSIGN:
case ENUM_BITWISE_AND_ASSIGN:
case ENUM_BITWISE_XOR_ASSIGN:
case ENUM_BITWISE_OR_ASSIGN: return 1;
default: return 0;
}
}
int isRelationalOp (enum enumTokenProp enum_name){
switch(enum_name){
case ENUM_EQUAL_EQUAL:
case ENUM_NOT_EQUAL:
case ENUM_IDENTITY:
case ENUM_NOT_IDENTITY:
case ENUM_LESS_THAN:
case ENUM_GREATER_THAN:
case ENUM_LESS_THAN_EQUAL:
case ENUM_GREATER_THAN_EQUAL: return 1;
default: return 0;
}
}

int isTernaryOp(enum enumTokenProp enum_name){
if(enum_name == ENUM_COLON){
int i = tokenCount-1;
while(i &gt;= 0 &amp;&amp; tokenTable[i].enum_name != ENUM_EQUAL &amp;&amp; tokenTable[i].enum_name !=
ENUM_SEMICOLON){
if(tokenTable[i].enum_name == ENUM_QUESTION){
return 1;
}
i--;
}
}
return 0;
}
int isLogicalOp(enum enumTokenProp enum_name){
switch (enum_name){
case ENUM_BOOLEAN_AND:
case ENUM_BOOLEAN_OR:
case ENUM_EXCLAMATION: return 1;
default: return 0;
}
}
int isBitwiseOp(enum enumTokenProp enum_name){
switch (enum_name){
case ENUM_BIT_AND:
case ENUM_BIT_OR:
case ENUM_TILDE:
case ENUM_BIT_XOR:
case ENUM_SHIFT_LEFT:
case ENUM_SHIFT_RIGHT:
case ENUM_UNSIGNED_RIGHT_SHIFT: return 1;
default: return 0;
}
}
int isKeywordOperator(enum enumTokenProp enum_name){
switch(enum_name){
case ENUM_DELETE:
case ENUM_VOID:
case ENUM_INSTANCEOF:
case ENUM_IN:
case ENUM_TYPEOF: return 1;
default: return 0;
}
}
int isSpecial(enum enumTokenProp enum_name){

switch(enum_name){
case ENUM_ARROW_FUNC:
case ENUM_COLON:
case ENUM_QUESTION:
case ENUM_LBRACKET:
case ENUM_RBRACKET:
case ENUM_LPAREN:
case ENUM_RPAREN:
case ENUM_LCURLY:
case ENUM_RCURLY:
case ENUM_SEMICOLON:
case ENUM_COMMA: return 1;
default: return 0;
}
}
int isPropertyAccessor(enum enumTokenProp enum_name){
if(enum_name == ENUM_DOT) return 1;
return 0;
}
int isKeyword(enum enumTokenProp enum_name){
switch(enum_name){
case ENUM_VAR:
case ENUM_LET:
case ENUM_CONST:
case ENUM_REQUIRE:
case ENUM_IMPORT:
case ENUM_EXPORT:
case ENUM_FROM:
case ENUM_AS:
case ENUM_FUNCTION:
case ENUM_THIS:
case ENUM_NEW:
case ENUM_TRUE_CONDITION:
case ENUM_FALSE_CONDITION:
case ENUM_IF:
case ENUM_ELSE:
case ENUM_DO:
case ENUM_FOR:
case ENUM_WHILE:
case ENUM_CONTINUE:
case ENUM_BREAK:
case ENUM_WITH:
case ENUM_RETURN:
case ENUM_TRY:
case ENUM_CATCH:
case ENUM_FINALLY:
case ENUM_THROW:

case ENUM_SWITCH:
case ENUM_CASE:
case ENUM_DEFAULT: return 1;
default: return 0;
}
}
int isNumber(enum enumTokenProp enum_name){
if(enum_name == ENUM_NUMBER) return 1;
return 0;
}
int isIdentifier(enum enumTokenProp enum_name){
if(enum_name == ENUM_ID) return 1;
return 0;
}
int isString(enum enumTokenProp enum_name){
if(enum_name == ENUM_STRING) return 1;
return 0;
}
enum enumTokenType getTokenType(enum enumTokenProp enum_name){
if(isTernaryOp(enum_name)){
return type_tern_op;
}
if(isKeyword(enum_name)){
return type_keyword;
}
if(isIdentifier(enum_name)){
return type_identifier;
}
if(isNumber(enum_name)){
return type_number;
}
if(isString(enum_name)){
return type_string;
}
if(isArithmaticOp(enum_name)){
return type_ar_op;
}
if(isAssignmentOp(enum_name)){
return type_assignment_op;
}
if(isRelationalOp(enum_name)){
return type_rel_op;
}
if(isLogicalOp(enum_name)){
return type_log_op;
}
if(isBitwiseOp(enum_name)){

return type_bitwise_op;
}
if(isKeywordOperator(enum_name)){
return type_keyword_op;
}
if(isPropertyAccessor(enum_name)){
return type_propertyAccessor;
}
return type_special_op;
}
void addToken(char * lex, int row, int col, enum enumTokenProp enum_name, enum enumTokenType
type){
if(type == type_tern_op){
int i = tokenCount-1;
while(i &gt;= 0 &amp;&amp; tokenTable[i].enum_name != ENUM_EQUAL &amp;&amp; tokenTable[i].enum_name !=
ENUM_SEMICOLON){
if(tokenTable[i].enum_name == ENUM_QUESTION){
strcat(tokenTable[i].lex, lex);
tokenTable[i].enum_name = enum_name;
tokenTable[i].type = type;
break;
}
i--;
}
} else {
strcpy(tokenTable[tokenCount].lex, lex);
tokenTable[tokenCount].col = col;
tokenTable[tokenCount].row = row;
tokenTable[tokenCount].enum_name = enum_name;
tokenTable[tokenCount].type = type;
tokenCount++;
}
}
char * getEnum_Name_to_String(enum enumTokenProp enum_name){
switch(enum_name){
case ENUM_VAR: return &quot;VAR&quot;;
case ENUM_LET: return &quot;LET&quot;;
case ENUM_CONST: return &quot;CONST&quot;;
case ENUM_REQUIRE: return &quot;REQUIRE&quot;;
case ENUM_IMPORT: return &quot;IMPORT&quot;;
case ENUM_EXPORT: return &quot;EXPORT&quot;;
case ENUM_FROM: return &quot;FROM&quot;;
case ENUM_AS: return &quot;AS&quot;;
case ENUM_FUNCTION: return &quot;FUNCTION&quot;;
case ENUM_THIS: return &quot;THIS&quot;;
case ENUM_NEW: return &quot;NEW&quot;;
case ENUM_TRUE_CONDITION: return &quot;TRUE_CONDITION&quot;;

case ENUM_FALSE_CONDITION: return &quot;FALSE_CONDITION&quot;;
case ENUM_IF: return &quot;IF&quot;;
case ENUM_ELSE: return &quot;ELSE&quot;;
case ENUM_DO: return &quot;DO&quot;;
case ENUM_FOR: return &quot;FOR&quot;;
case ENUM_WHILE: return &quot;WHILE&quot;;
case ENUM_CONTINUE: return &quot;CONTINUE&quot;;
case ENUM_BREAK: return &quot;BREAK&quot;;
case ENUM_WITH: return &quot;WITH&quot;;
case ENUM_RETURN: return &quot;RETURN&quot;;
case ENUM_TRY: return &quot;TRY&quot;;
case ENUM_CATCH: return &quot;CATCH&quot;;
case ENUM_FINALLY: return &quot;FINALLY&quot;;
case ENUM_THROW: return &quot;THROW&quot;;
case ENUM_SWITCH: return &quot;SWITCH&quot;;
case ENUM_CASE: return &quot;CASE&quot;;
case ENUM_DEFAULT: return &quot;DEFAULT&quot;;
case ENUM_EQUAL: return &quot;EQUAL&quot;;
case ENUM_MUL_ASSIGN: return &quot;MUL_ASSIGN&quot;;
case ENUM_DIV_ASSIGN: return &quot;DIV_ASSIGN&quot;;
case ENUM_REMAINDER_ASSIGN: return &quot;REMAINDER_ASSIGN&quot;;
case ENUM_ADD_ASSIGN: return &quot;ADD_ASSIGN&quot;;
case ENUM_SUB_ASSIGN: return &quot;SUB_ASSIGN&quot;;
case ENUM_LEFT_SHIFT_ASSIGN: return &quot;LEFT_SHIFT_ASSIGN&quot;;
case ENUM_RIGHT_SHIFT_ASSIGN: return &quot;RIGHT_SHIFT_ASSIGN&quot;;
case ENUM_UNSIGNED_RIGHT_SHIFT_ASSIGN: return &quot;UNSIGNED_RIGHT_SHIFT_ASSIGN&quot;;
case ENUM_BITWISE_AND_ASSIGN: return &quot;BITWISE_AND_ASSIGN&quot;;
case ENUM_BITWISE_XOR_ASSIGN: return &quot;BITWISE_XOR_ASSIGN&quot;;
case ENUM_BITWISE_OR_ASSIGN: return &quot;BITWISE_OR_ASSIGN&quot;;
case ENUM_PLUS: return &quot;PLUS&quot;;
case ENUM_PLUS_PLUS: return &quot;PLUS_PLUS&quot;;
case ENUM_MINUS: return &quot;MINUS&quot;;
case ENUM_MINUS_MINUS: return &quot;MINUS_MINUS&quot;;
case ENUM_STAR: return &quot;STAR&quot;;
case ENUM_FORWARD_SLASH: return &quot;FORWARD_SLASH&quot;;
case ENUM_PERCENT: return &quot;PERCENT&quot;;
case ENUM_BOOLEAN_AND: return &quot;BOOLEAN_AND&quot;;
case ENUM_BOOLEAN_OR: return &quot;BOOLEAN_OR&quot;;
case ENUM_EXCLAMATION: return &quot;EXCLAMATION&quot;;
case ENUM_NOT_EQUAL: return &quot;NOT_EQUAL&quot;;
case ENUM_EQUAL_EQUAL: return &quot;EQUAL_EQUAL&quot;;
case ENUM_IDENTITY: return &quot;IDENTITY&quot;;
case ENUM_NOT_IDENTITY: return &quot;NOT_IDENTITY&quot;;
case ENUM_LESS_THAN: return &quot;LESS_THAN&quot;;
case ENUM_GREATER_THAN: return &quot;GREATER_THAN&quot;;
case ENUM_LESS_THAN_EQUAL: return &quot;LESS_THAN_EQUAL&quot;;
case ENUM_GREATER_THAN_EQUAL: return &quot;GREATER_THAN_EQUAL&quot;;
case ENUM_BIT_AND: return &quot;BIT_AND&quot;;
case ENUM_BIT_OR: return &quot;BIT_OR&quot;;

case ENUM_BIT_XOR: return &quot;BIT_XOR&quot;;
case ENUM_TILDE: return &quot;TILDE&quot;;
case ENUM_SHIFT_LEFT: return &quot;SHIFT_LEFT&quot;;
case ENUM_SHIFT_RIGHT: return &quot;SHIFT_RIGHT&quot;;
case ENUM_UNSIGNED_RIGHT_SHIFT: return &quot;UNSIGNED_RIGHT_SHIFT&quot;;
case ENUM_DOT: return &quot;DOT&quot;;
case ENUM_COLON: return &quot;COLON&quot;;
case ENUM_QUESTION: return &quot;QUESTION&quot;;
case ENUM_LBRACKET: return &quot;LBRACKET&quot;;
case ENUM_RBRACKET: return &quot;RBRACKET&quot;;
case ENUM_LPAREN: return &quot;LPAREN&quot;;
case ENUM_RPAREN: return &quot;RPAREN&quot;;
case ENUM_LCURLY: return &quot;LCURLY&quot;;
case ENUM_RCURLY: return &quot;RCURLY&quot;;
case ENUM_SEMICOLON: return &quot;SEMICOLON&quot;;
case ENUM_COMMA: return &quot;COMMA&quot;;
case ENUM_ARROW_FUNC: return &quot;ARROW_FUNC&quot;;
case ENUM_STRING: return &quot;STRING&quot;;
case ENUM_ID: return &quot;ID&quot;;
case ENUM_NULL_VALUE: return &quot;NULL_VALUE&quot;;
case ENUM_NUMBER: return &quot;NUMBER&quot;;
case ENUM_VOID: return &quot;VOID&quot;;
case ENUM_DELETE: return &quot;DELETE&quot;;
case ENUM_IN: return &quot;IN&quot;;
case ENUM_INSTANCEOF: return &quot;INSTANCEOF&quot;;
case ENUM_TYPEOF: return &quot;TYPEOF&quot;;
}
}
void printToken(token_struct token){
char typeString[100];
char tokenString[100];
switch (token.type){
case type_keyword: strcpy(typeString, &quot;KEYWORD&quot;); break;
case type_identifier: strcpy(typeString, &quot;IDENTIFIER&quot;); break;
case type_string: strcpy(typeString, &quot;STRING&quot;); break;
case type_number: strcpy(typeString, &quot;NUMBER&quot;); break;
case type_propertyAccessor: strcpy(typeString, &quot;PROPERTY_ACCESSOR&quot;); break;
case type_keyword_op: strcpy(typeString, &quot;KEYWORD_OPERATOR&quot;); break;
case type_ar_op: strcpy(typeString, &quot;ARITHMATIC_OPERATOR&quot;); break;
case type_assignment_op: strcpy(typeString, &quot;ASSIGNMENT_OPERATOR&quot;); break;
case type_rel_op: strcpy(typeString, &quot;RELATIONAL_OPERATOR&quot;); break;
case type_tern_op: strcpy(typeString, &quot;TERNARY_OPERATOR&quot;); break;
case type_log_op: strcpy(typeString, &quot;LOGICAL_OPERATOR&quot;); break;
case type_bitwise_op: strcpy(typeString, &quot;BITWISE_OPERATOR&quot;); break;
case type_special_op: strcpy(typeString, &quot;SPECIAL_OPERATOR&quot;); break;
}
if(token.type == type_tern_op){
strcpy(tokenString, typeString);

} else {
strcpy(tokenString, getEnum_Name_to_String(token.enum_name));
}
printf(&quot;\n&lt;\t&quot;);
{
printf(&quot;\t%-40s\t\t%d\t\t%d\t\t%-20s\t%-20s&quot;, token.lex, token.row, token.col, typeString,
tokenString);
}
printf(&quot;\t&gt;&quot;);
}
void printTokenTable(){
printf(&quot;\n&quot;);
printf(&quot;---------------------------------------------------------------------- TOKEN TABLE -----------------------------------
-----------------------------------\n&quot;);
printf(&quot;\t\t%-40s\t\t%-5s\t\t%-5s\t\t%-20s\t%-20s\n&quot;, &quot;LEXEME&quot;, &quot;ROW&quot;, &quot;COL&quot;, &quot;TOKEN_TYPE&quot;,
&quot;TOKEN_KEYWORD&quot;);
if (tokenCount == 0)
{
printf(&quot;\nEMTPY\n&quot;);
return;
}
for (int i = 0; i &lt; tokenCount; ++i)
{
printToken(tokenTable[i]);
}
printf(&quot;\n&quot;);
printf(&quot;--------------------------------------------------------------------------------------------------------------------------------
--------------------------\n&quot;);
}
void newToken(char * lex, int row, int col, enum enumTokenProp enum_name){
addToken(lex, row, col-strlen(lex), enum_name, getTokenType(enum_name));
}