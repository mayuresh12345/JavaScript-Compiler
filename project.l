%{
// #include &quot;project.symbolTable.h&quot;
#include &quot;project.tokenTable.h&quot;
#include &quot;project.tab.h&quot;
#include &lt;string.h&gt;
#define TABLENGTH 4
int curlyBracketsCount = 0;
int colCount = 1;
int tokenCount;

%}
WHITESPACE [&quot; &quot;\t\n]
%%
&quot;var&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_VAR);
yylval.strval = strdup(yytext);
return VAR;
}
&quot;let&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LET);
yylval.strval = strdup(yytext);
return LET;
}
&quot;const&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_CONST);
yylval.strval = strdup(yytext);
return CONST;
}
&quot;import&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_IMPORT);
yylval.strval = strdup(yytext);
return IMPORT;
}
&quot;export&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_EXPORT);
yylval.strval = strdup(yytext);
return EXPORT;
}
&quot;require&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_REQUIRE);
yylval.strval = strdup(yytext);
return REQUIRE;
}
&quot;from&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_FROM);
yylval.strval = strdup(yytext);
return FROM;

}
&quot;as&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_AS);
yylval.strval = strdup(yytext);
return AS;
}

&quot;function&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_FUNCTION);
yylval.strval = strdup(yytext);
return FUNCTION;
}
&quot;this&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_THIS);
yylval.strval = strdup(yytext);
return THIS;
}
&quot;new&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_NEW);
yylval.strval = strdup(yytext);
return NEW;
}
&quot;instanceof&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_INSTANCEOF);
yylval.strval = strdup(yytext);
return INSTANCEOF;
}
&quot;true&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_TRUE_CONDITION);
yylval.strval = strdup(yytext);
return TRUE_CONDITION;
}
&quot;false&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_FALSE_CONDITION);
yylval.strval = strdup(yytext);
return FALSE_CONDITION;
}
&quot;if&quot; {

colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_IF);
yylval.strval = strdup(yytext);
return IF;
}
&quot;else&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_ELSE);
yylval.strval = strdup(yytext);
return ELSE;
}
&quot;do&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_DO);
yylval.strval = strdup(yytext);
return DO;
}
&quot;for&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_FOR);
yylval.strval = strdup(yytext);
return FOR;
}
&quot;while&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_WHILE);
yylval.strval = strdup(yytext);
return WHILE;
}
&quot;in&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_IN);
yylval.strval = strdup(yytext);
return IN;
}
&quot;continue&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_CONTINUE);
yylval.strval = strdup(yytext);
return CONTINUE;
}
&quot;break&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BREAK);
yylval.strval = strdup(yytext);
return BREAK;
}

&quot;with&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_WITH);
yylval.strval = strdup(yytext);
return WITH;
}
&quot;return&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_RETURN);
yylval.strval = strdup(yytext);
return RETURN;
}
&quot;try&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_TRY);
yylval.strval = strdup(yytext);
return TRY;
}
&quot;catch&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_CATCH);
yylval.strval = strdup(yytext);
return CATCH;
}
&quot;finally&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_FINALLY);
yylval.strval = strdup(yytext);
return FINALLY;
}
&quot;throw&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_THROW);
yylval.strval = strdup(yytext);
return THROW;
}
&quot;delete&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_DELETE);
yylval.strval = strdup(yytext);
return DELETE;
}
&quot;void&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_VOID);
yylval.strval = strdup(yytext);
return VOID;

}
&quot;typeof&quot;/{WHITESPACE} {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_TYPEOF);
yylval.strval = strdup(yytext);
return TYPEOF;
}

&quot;switch&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_SWITCH);
yylval.strval = strdup(yytext);
return SWITCH;
}
&quot;case&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_CASE);
yylval.strval = strdup(yytext);
return CASE;
}
&quot;default&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_DEFAULT);
yylval.strval = strdup(yytext);
return DEFAULT;
}
&quot;=&gt;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_ARROW_FUNC);
yylval.strval = strdup(yytext);
return ARROW_FUNC;
}
&quot;*=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_MUL_ASSIGN);
yylval.strval = strdup(yytext);
return MUL_ASSIGN;
}
&quot;/=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_DIV_ASSIGN);
yylval.strval = strdup(yytext);
return DIV_ASSIGN;
}
&quot;%=&quot; {
colCount += yyleng;

newToken(yytext, rowCount, colCount, ENUM_REMAINDER_ASSIGN);
yylval.strval = strdup(yytext);
return REMAINDER_ASSIGN;
}
&quot;+=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_ADD_ASSIGN);
yylval.strval = strdup(yytext);
return ADD_ASSIGN;
}
&quot;-=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_SUB_ASSIGN);
yylval.strval = strdup(yytext);
return SUB_ASSIGN;
}
&quot;&lt;&lt;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LEFT_SHIFT_ASSIGN);
yylval.strval = strdup(yytext);
return LEFT_SHIFT_ASSIGN;
}
&quot;&gt;&gt;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_RIGHT_SHIFT_ASSIGN);
yylval.strval = strdup(yytext);
return RIGHT_SHIFT_ASSIGN;
}
&quot;&gt;&gt;&gt;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_UNSIGNED_RIGHT_SHIFT_ASSIGN);
yylval.strval = strdup(yytext);
return UNSIGNED_RIGHT_SHIFT_ASSIGN;
}
&quot;&amp;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BITWISE_AND_ASSIGN);
yylval.strval = strdup(yytext);
return BITWISE_AND_ASSIGN;
}
&quot;^=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BITWISE_XOR_ASSIGN);
yylval.strval = strdup(yytext);
return BITWISE_XOR_ASSIGN;
}
&quot;|=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BITWISE_OR_ASSIGN);

yylval.strval = strdup(yytext);
return BITWISE_OR_ASSIGN;
}
&quot;++&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_PLUS_PLUS);
yylval.strval = strdup(yytext);
return PLUS_PLUS;
}
&quot;--&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_MINUS_MINUS);
yylval.strval = strdup(yytext);
return MINUS_MINUS;
}
&quot;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_EQUAL);
yylval.strval = strdup(yytext);
return EQUAL;
}
&quot;+&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_PLUS);
yylval.strval = strdup(yytext);
return PLUS;
}
&quot;-&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_MINUS);
yylval.strval = strdup(yytext);
return MINUS;
}
&quot;*&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_STAR);
yylval.strval = strdup(yytext);
return STAR;
}
&quot;/&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_FORWARD_SLASH);
yylval.strval = strdup(yytext);
return FORWARD_SLASH;
}
&quot;%&quot; {
colCount += yyleng;

newToken(yytext, rowCount, colCount, ENUM_PERCENT);
yylval.strval = strdup(yytext);
return PERCENT;
}
&quot;&amp;&amp;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BOOLEAN_AND);
yylval.strval = strdup(yytext);
return BOOLEAN_AND;
}
&quot;||&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BOOLEAN_OR);
yylval.strval = strdup(yytext);
return BOOLEAN_OR;
}
&quot;!&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_EXCLAMATION);
yylval.strval = strdup(yytext);
return EXCLAMATION;
}
&quot;&amp;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BIT_AND);
yylval.strval = strdup(yytext);
return BIT_AND;
}
&quot;|&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BIT_OR);
yylval.strval = strdup(yytext);
return BIT_OR;
}
&quot;~&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_TILDE);
yylval.strval = strdup(yytext);
return TILDE;
}
&quot;^&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_BIT_XOR);
yylval.strval = strdup(yytext);
return BIT_XOR;
}
&quot;&lt;&lt;&quot; {

colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_SHIFT_LEFT);
yylval.strval = strdup(yytext);
return SHIFT_LEFT;
}
&quot;&gt;&gt;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_SHIFT_RIGHT);
yylval.strval = strdup(yytext);
return SHIFT_RIGHT;
}
&quot;&gt;&gt;&gt;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_UNSIGNED_RIGHT_SHIFT);
yylval.strval = strdup(yytext);
return UNSIGNED_RIGHT_SHIFT;
}
&quot;==&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_EQUAL_EQUAL);
yylval.strval = strdup(yytext);
return EQUAL_EQUAL;
}
&quot;!=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_NOT_EQUAL);
yylval.strval = strdup(yytext);
return NOT_EQUAL;
}
&quot;===&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_IDENTITY);
yylval.strval = strdup(yytext);
return IDENTITY;
}
&quot;!==&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_NOT_IDENTITY);
yylval.strval = strdup(yytext);
return NOT_IDENTITY;
}
&quot;&lt;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LESS_THAN);
yylval.strval = strdup(yytext);
return LESS_THAN;
}

&quot;&gt;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_GREATER_THAN);
yylval.strval = strdup(yytext);
return GREATER_THAN;
}
&quot;&lt;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LESS_THAN_EQUAL);
yylval.strval = strdup(yytext);
return LESS_THAN_EQUAL;
}
&quot;&gt;=&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_GREATER_THAN_EQUAL);
yylval.strval = strdup(yytext);
return GREATER_THAN_EQUAL;
}

&quot;.&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_DOT);
yylval.strval = strdup(yytext);
return DOT;
}
&quot;:&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_COLON);
yylval.strval = strdup(yytext);
return COLON;
}
&quot;?&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_QUESTION);
yylval.strval = strdup(yytext);
return QUESTION;
}
&quot;[&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LBRACKET);
yylval.strval = strdup(yytext);
return LBRACKET;
}
&quot;]&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_RBRACKET);

yylval.strval = strdup(yytext);
return RBRACKET;
}
&quot;(&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LPAREN);
yylval.strval = strdup(yytext);
return LPAREN;
}
&quot;)&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_RPAREN);
yylval.strval = strdup(yytext);
return RPAREN;
}
&quot;{&quot; {
curlyBracketsCount++;
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_LCURLY);
yylval.strval = strdup(yytext);
return LCURLY;
}
&quot;}&quot; {
curlyBracketsCount--;
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_RCURLY);
yylval.strval = strdup(yytext);
return RCURLY;
}
&quot;;&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_SEMICOLON);
yylval.strval = strdup(yytext);
return SEMICOLON;
}
&quot;,&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_COMMA);
yylval.strval = strdup(yytext);
return COMMA;
}
\&quot;(\\.|[^&quot;\\])*\&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_STRING);
yylval.strval = strdup(yytext);

return STRING; //double-quoted-string-literal
}
\&#39;((?:&#39;&#39;|[^&#39;])*)\&#39; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_STRING);
yylval.strval = strdup(yytext);
return STRING; //single-quoted-string-literal
}

&quot;NULL&quot; {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_NULL_VALUE);
yylval.strval = strdup(yytext);
return NULL_VALUE;
}
[a-zA-Z_][a-zA-Z&quot;_&quot;0-9]* {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_ID);
yylval.strval = strdup(yytext);
return ID;
}
[+-]?([0-9]+[.])?[0-9]+ {
colCount += yyleng;
newToken(yytext, rowCount, colCount, ENUM_NUMBER);
yylval.strval = strdup(yytext);
return NUMBER;
}
&quot;//&quot;[^\n]*|&quot;\/\*&quot;.*&quot;\*\/&quot; ; // ignore single-line-comment
&quot;/*&quot;([^*]|\*+[^*/])*\*+&quot;/&quot; ; // ignore block-comment // ignore
\n {
rowCount++;
colCount = 1;
}
\t {
colCount += TABLENGTH;
}
&quot; &quot; {
colCount += yyleng;
}
%%

int yywrap (){
return 1;
}