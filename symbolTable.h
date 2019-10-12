#include &lt;stdlib.h&gt;
#include &lt;stdio.h&gt;
#include &lt;string.h&gt;
#define tabSize 1000000
#define maxNameLength 1000
#define maxArguments 1000
enum scope_type {
global,
local,
function_parameters,
};
enum id_type {
type_function,
type_const,
type_let,
type_var,
};
typedef struct symbolTableStructure{
char * name;
enum id_type type;
enum scope_type scope;
int * arguments;
char * stringArguments;
int argCount;
int key;
struct symbolTableStructure * next;
} symbolTable_struct;
symbolTable_struct * symbolTable[tabSize];
void printSymbol(symbolTable_struct * sym);
void printSymbolTable();
void copyArray(int * arr1, int * arr2, int count);

char * symbolTypeToString(enum id_type symbolType){
switch (symbolType){
case type_let: return &quot;let&quot;;
case type_var: return &quot;var&quot;;
case type_function: return &quot;function&quot;;
default: return &quot;const&quot;;
}
}
char * symbolScopeToString(enum scope_type symbolScope){
switch (symbolScope){
case global : return &quot;global&quot;;
case function_parameters: return &quot;function_parameter&quot;;
default: return &quot;local&quot;;
}
}

int hash(char * id, enum scope_type symbolScope){
char * hashString = (char *)malloc(sizeof(char)*(strlen(id) +
strlen(symbolScopeToString(symbolScope)) + 1 ));
strcpy(hashString, id); strcat(hashString, &quot;_&quot;); strcat(hashString,
symbolScopeToString(symbolScope));
int charSum = 0;
for (int i = 0; i &lt; strlen(hashString); ++i){
charSum += (int)hashString[i]*(i+1);
}
free (hashString);
return charSum%tabSize;
}
int search(char * id, int hashKey){
if(symbolTable[hashKey] != NULL){
symbolTable_struct * link = symbolTable[hashKey];
while(link-&gt;next != NULL &amp;&amp; strcmp(link-&gt;name, id) != 0){
link = link-&gt;next;
}
if(strcmp(link-&gt;name, id) == 0){
return tabSize;
}
}
return hashKey;
}
void argumentsToString(symbolTable_struct * inputSymbol){
if(!(inputSymbol-&gt;argCount)) {
inputSymbol-&gt;stringArguments = (char *)malloc(sizeof(char)*1);
strcpy(inputSymbol-&gt;stringArguments, &quot;&quot;);
} else {

inputSymbol-&gt;stringArguments = (char *)malloc(sizeof(char)*1000);
char num[10] = { &#39;\0&#39; };
int count = 0;
strcpy(inputSymbol-&gt;stringArguments, &quot;[&quot;);
sprintf(num, &quot;%d&quot;, (inputSymbol-&gt;arguments)[count]);
strcat(inputSymbol-&gt;stringArguments, num);
count++;
while(count &lt; inputSymbol-&gt;argCount){
strcat(inputSymbol-&gt;stringArguments, &quot;, &quot;);
strcpy(num, &quot;\0&quot;);
sprintf(num, &quot;%d&quot;, (inputSymbol-&gt;arguments)[count]);
strcat(inputSymbol-&gt;stringArguments, num);
count++;
}
strcat(inputSymbol-&gt;stringArguments, &quot;]&quot;);
}
}

void printSymbol(symbolTable_struct * sym) {
if(sym == NULL) return;
printf(&quot;&lt;&quot;);
if(sym-&gt;type == type_function){
printf(&quot;\t%-30s\t\t%-15s\t\t%-30s\t\t%-40s\t%15d\t\t%10d&quot;, sym-&gt;name, &quot;function&quot;,

symbolScopeToString(sym-&gt;scope), sym-&gt;stringArguments, sym-&gt;argCount, sym-&gt;key);
} else {
printf(&quot;\t%-30s\t\t%-15s\t\t%-30s\t\t%-40s\t%-15s\t\t%10d&quot;, sym-&gt;name,
symbolTypeToString(sym-&gt;type), symbolScopeToString(sym-&gt;scope), &quot;&quot;, &quot;&quot;, sym-&gt;key);
}
printf(&quot;&gt;\n&quot;);
printSymbol(sym-&gt;next);
}
void printSymbolTable() {
printf(&quot;\n&quot;);
printf(&quot;----------------------------------------------------------------------------------------- SYMBOL TABLE ------
-----------------------------------------------------------------------------------\n&quot;);
printf(&quot;\t%-30s\t\t%-15s\t\t%-30s\t\t%-40s\t\t%-15s\t\t%-10s\n\n&quot;, &quot;NAME&quot;, &quot;TYPE&quot;, &quot;SCOPE&quot;,
&quot;ARGUMENTS&quot;, &quot;NO.of ARG&quot;, &quot;KEY&quot;);
for (int i = 0; i &lt; tabSize; ++i) {
printSymbol(symbolTable[i]);
}
printf(&quot;-----------------------------------------------------------------------------------------------------------------------
-----------------------------------------------------------------------------\n&quot;);
}
int insert(symbolTable_struct symInput){
int hashKey = hash(symInput.name, symInput.scope);
if(search(symInput.name, hashKey) != tabSize){

symbolTable_struct * sym = (symbolTable_struct *)malloc(sizeof(symbolTable_struct));
sym-&gt;name = (char *)malloc(sizeof(char)*strlen(symInput.name));
if(symInput.type == type_function){
sym-&gt;stringArguments = (char
*)malloc(sizeof(char)*strlen(symInput.stringArguments));

sym-&gt;arguments = (int *)malloc(sizeof(int)*symInput.argCount);
sym-&gt;argCount = symInput.argCount;
strcpy(sym-&gt;stringArguments, symInput.stringArguments);
copyArray(sym-&gt;arguments, symInput.arguments, symInput.argCount);
}
strcpy(sym-&gt;name, symInput.name);
sym-&gt;type = symInput.type;
sym-&gt;scope = symInput.scope;
sym-&gt;key = hashKey;
sym-&gt;next = NULL;
if(symbolTable[hashKey]){
symbolTable_struct * link = symbolTable[hashKey];
while(link-&gt;next)
link = link-&gt;next;
link-&gt;next = sym;
} else {
symbolTable[hashKey] = sym;
}
}
return hashKey;
}
int getArgCount(char * arguments){
int argCount = 0;
if(!strlen(arguments)) return argCount;
char * temp = (char *)malloc(sizeof(char)*strlen(arguments));
strcpy(temp, arguments);
strtok(temp, &quot;,&quot;);
while(temp){
argCount++;
temp = strtok(NULL, &quot;,&quot;);
}
return argCount;
}
void getFunctionArgumentKeys(symbolTable_struct * inputSymbol, char * arguments){
inputSymbol-&gt;arguments = (int *)malloc(sizeof(int)*(inputSymbol-&gt;argCount)); int counter = 0;
symbolTable_struct symbol;
symbol.name = (char *)malloc(sizeof(char)*strlen(arguments));
symbol.scope = function_parameters;
symbol.type = type_const;
char * temp = (char *)malloc(sizeof(char) * strlen(arguments));
temp = strtok(arguments, &quot;,&quot;);
while(temp){

strcpy(symbol.name, temp);
(inputSymbol-&gt;arguments)[counter] = insert(symbol);
temp = strtok(NULL, &quot;,&quot;);
counter++;
}
}
void copyArray(int * arr1, int * arr2, int count){
for(int i = 0; i &lt; count; i++){
arr1[i] = arr2[i];
}
}
void addFunctionSymbol(char * name, char * type, char * arguments, int curlyCount){
symbolTable_struct tempSymbol;
tempSymbol.name = (char *)malloc(sizeof(char)*strlen(name));
strcpy(tempSymbol.name, name);
tempSymbol.type = type_function;
tempSymbol.scope = curlyCount &gt; 0 ? local : global;
tempSymbol.argCount = getArgCount(arguments);
if(tempSymbol.argCount) getFunctionArgumentKeys(&amp;tempSymbol, arguments);
argumentsToString(&amp;tempSymbol);
insert(tempSymbol);
}
void addSymbol(char * name, char * type, int curlyCount){
symbolTable_struct tempSymbol;
tempSymbol.name = (char *)malloc(sizeof(char)*strlen(name));
tempSymbol.type = !strcmp(type, &quot;const&quot;) ? type_const : !strcmp(type, &quot;let&quot;) ? type_let :
type_var;
tempSymbol.scope = curlyCount &gt; 0 ? local : global;
char * tempName = (char *)malloc(sizeof(char)*strlen(name));
tempName = strtok(name, &quot;,&quot;);
while(tempName){
strcpy(tempSymbol.name,tempName);
insert(tempSymbol);
tempName = strtok(NULL, &quot;,&quot;);
}
}