/********************************/
/* Program Name: checksum.c     */
/* Author:Kagen Christoph       */
/* Date:    2/13/2021           */
/********************************/
/* Description:                 */
/* Validation Checks:           */
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  byte checksum;                               
  byte complement;   
  byte buf[count];
  int fd;
  size_t nbyte; //n bytes to read
  nbyte = sizeof(buf);
  int retval;
  int checkPass = 5;

  /* the following is the prototype for the read system call */
  retval = read(fd,  (void *) &buf,nbyte);  
  for(int i = 0; i < 10; i++)
    {
    if(i == checkPass)
		{
			checksum = buf[i];
			buf[i] = 0;
		}
		sum += buf[i];
	 if (sum > max_int)
	  {
		  sum = sum-(max_int+1)+1;
	  }

    }
	complement = max_int - sum;

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
