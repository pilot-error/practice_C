#include <stdio.h>
#include <stdlib.h>
//Learn to spot the pitfalls of C programming. Strings. Memory... the good stuff.
//
//Start reading down in Main()
//

//First attempt at "Ian's" strcpy.
char* iancpy1(char* dest,char* orig){
  int i = 0;
  while(orig[i]!='\0'){
    dest[i]=orig[i];
    i++;
  }
  //It is looking for the end of string \0 but never adds it back to the dest.
  return dest;
}

//Fixed attempt at "Ian's" strcpy.
char* iancpy2(char* dest,char* orig){
  int i = 0;
  while(orig[i]!='\0'){
    dest[i]=orig[i];
    i++;
  }
  dest[i]='\0';
  return dest;
}
char* goodcpy(char* orig){
  int i = 0;
  while(orig[i]!='\0'){
    i++;
  }
  char* dest =  calloc(i+1,sizeof(char));
  i = 0;
  while(orig[i]!='\0'){
    dest[i]=orig[i];
    i++;
  }
  dest[i]='\0';
  return dest;
}

//Start here
int main(void) {
  //Nothing exciting, let's take the original string and paste it into the destination.
  // Because c requires strict typing of memory, we first declare the two locations as char type
  char* orig = "The Original String"; //A pointer to a constant in read only memory space
  char dest_50[50]; //A blank 50 bytes of memory
  printf("Pre-Copy: \n\tOrig-mem:%s-%p\n\tdest_50-mem:                  %s-%p\n",orig,orig,dest_50,dest_50);
  iancpy1(dest_50,orig);
  printf("Post-Copy: \n\tOrig-mem:%s-%p\n\tdest_50-mem:%s-%p\n",orig,orig,dest_50,dest_50);
  printf("See the large deference in memory location.  The original is in\nspecial read only memory space, the copied string is on the heap. And notice the correct copy...it works!\n\n\n");
  //I thought I was done...but let's see if it really works.
  //Now let's check the same iancpy1 with slighlty different method of declaring destination.
  char dest[] = "$&%$&%$&%&$&%$&!!&!&!%&%&!&!&&!%&!%&!%"; //garbage text
  printf("Pre-Copy: \n\ttext-mem:%s-%p\n\ttext-mem:%s-%p\n",orig,orig,dest,dest);
  iancpy1(dest,orig);
  printf("Post-Copy: \n\ttext-mem:%s-%p\n\ttext-mem:%s-%p\n",orig,orig,dest,dest);
  printf("Well crap, it left the garbage text. Let's go up to iancpy1 and see what is happening.\n\n");

  iancpy2(dest,orig);
  printf("Post-Copy: \n\ttext-mem:%s-%p\n\ttext-mem:%s-%p\n",orig,orig,dest,dest);
  printf("\nMuch better.  Just another example of how exhaustive testing is\n necessary to uncover  problems in every use case.  \n Who knew how you declare a variable could matter.\n\n");

  //And this is simply the way I wish strcpy worked.  Called goodcpy.
  char* new_orig = "New  Original String";
  printf("Pre-Copy: \n\ttext-mem:%s-%p\n",new_orig,new_orig);
  char* new_dest = goodcpy(new_orig);
  printf("Post-Copy: \n\ttext-mem:%s-%p\n\ttext-mem:%s-%p\n",new_orig,new_orig,new_dest,new_dest);
  return 0;

}




