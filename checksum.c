/********************************/
/* Program Name: checksum.c     */
/* Author: Nelson Blanco Ventura*/
/* Date: 02/16/2021             */
/********************************/
/* Description: checksum in c   */
/* Validation Checks: ints 0-255*/
/* Enhancements:                */
/********************************/

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>
#include <sys/types.h>

#define max_int (255)
#define byte unsigned char

int main (int argc, char * argv[], char ** envp) {

  int count = 10;
  int sum = 0;   
  int quotient;
  int remainder;
  byte checksum;
  byte complement;
  byte header[10];
  
  read(STDIN_FILENO, &header, 10);

  for(int i = 0; i < count; i++) {
    if((int)header[i] <= 255 && (int)header[i] >= 0){
	if (i == 5){
	  checksum = (int)header[i];
	  header[i]=0;
	}
          sum+=(int)header[i];
        }else{
           printf("The following number is not within range (0...125) : %d", (int)header[i]);
	}
	  
  }
  
  quotient = sum / (max_int +1);
  remainder = sum % (max_int +1);
  sum = quotient + remainder;
  complement = max_int - sum;  
  
    fprintf(stdout, "Stored Checksum: %d, Computed Checksum: %d\n", checksum, complement);
  if (checksum != complement ) {
    fprintf(stderr, "Error Detected!\n"); 
    return 1;
  }
  return 0;
}
