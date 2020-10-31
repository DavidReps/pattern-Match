#include <stdio.h>
char* findmatch(char *pattern, char *text,int patternlength,int textlength);
int readline(char *text, int n);
int printmessage(char *position, char *text, int patternlength, int textlength);



int main() {
  char text[40], pattern[40], *position;
  int textlength, patternlength;

  printf("Enter text: ");
  textlength = readline(text, 40);
  printf("Enter pattern: ");
  patternlength = readline(pattern, 40);
  position = findmatch(pattern, text, patternlength, textlength);
  printmessage(position, text, patternlength, textlength);

}

int readline(char *text, int n){
  char c;
  int i = 0;

  while ((c = getchar()) != 10){
    *(text + i) = c;
    i++;
  }
  if (i > n){
    return n;
  }
  else{
    return i;
  }

}

char* findmatch(char *pattern, char *text, int patternlength,int textlength){
  int y = 0;
  int z = 0;
  int h = 0;
    while(y < textlength - 1){
      if (*(text + y + h) == *(pattern + z)||*(pattern + z) == '?'){
        if (z == patternlength-1){
          return (text + y);
         }
        h++;
        z++;
      }
      if(*(text + y + h) != *(pattern + z)&&(*(pattern + z) != '?')){
       z = 0;
       h = 0;
       y++;
       if (y == textlength-1){
         printf("string not contained \n");
         return NULL;
       }
      }
}
}

int printmessage(char *position, char *text, int patternlength, int textlength){
  int i = 0;
  while ((text + i) != position){
  i++;
}
printf("The pattern appears at index: %d, remaining text is:", i);
int start = i + patternlength;
for (start; start < textlength; start++){
  printf("%c", *(text + start));
}
return 0;
}
