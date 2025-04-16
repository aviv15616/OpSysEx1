#include <stdio.h>
int main(){
int *p = (int *)0xDEADBEEF;  // כתובת זיכרון לא חוקית
*p = 42;          // ניסיון לכתוב אליה
return 0;           
}