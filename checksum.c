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
  int checksum;        
  int quotient;             
  int remainder;            
  int complement;   
  byte buf[10];
  int fd;
  size_t nbyte;
  nbyte = sizeof(buf);
  int retval;
  int tmp = 0;
  int checkPass = 5;

  /* the following is the prototype for the read system call */
  retval = read(fd,  (void *) &buf,nbyte);  
  for(int i = 0; i < 10; i++)
    {
        int value = buf[i];
	  	  if (sum > max_int)
	  {
		  tmp = 0;
		  sum = sum-256;
		  tmp++;
	  }
    if(i == checkPass)
		{
			checksum = value;
			value = 0;
		}
		sum = sum+value + tmp;

    }
	complement = 256 - sum;

  fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
