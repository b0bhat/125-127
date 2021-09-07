#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  char input;
  int oldw = 1;
  char curstr[100];
  int i = 0;
  int c = getchar();
  while ( c != EOF ) {
    if ((c>='A' && c<='Z') || (c>='a' && c<='z') || c == '\''){
        curstr[i] = (char)c;
        i++;
        curstr[i] = '\0';
    } else {
      if (i > 0){
        int check = 0;
        for (int j=1; j<argc; j++){
          if (strcmp(curstr,argv[j]) == 0){
            printf("CENSORED");
            check = 1;
            break;
          }
        } if (check != 1){
          printf("%s",curstr);
        }
      }
      curstr[0] = '\0';
      i = 0;
      printf("%c",(char)c);
    } c = getchar();
  }
}
