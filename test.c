#include <stdio.h>
#include <string.h>
#include <errno.h>

// int main () {
//    FILE *fp;

//    fp = fopen("file.txt","r");
//    if( fp == NULL ) {
//       printf("Error: %s\n", strerror(errno)); //Sterror returns a pointer to the error string describing error errnum 
//    }
   
//    return(0);
// }

int main () {
   FILE *fp;

   /* first rename if there is any file */
   rename("file.txt", "newfile.txt");

   /* now let's try to open same file */
   fp = fopen("file.txt", "r");
   if( fp == NULL ) {
      perror("Error: ");
      return(-1);
   }
   fclose(fp);
      
   return(0);
}

//The main difference between perror and strerror
// perror : outputs to STDERR (fd = 2)
// strerror : outputs to stdout results. 