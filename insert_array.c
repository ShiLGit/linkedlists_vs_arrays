#include<stdio.h>

#include <stdlib.h>

#include"ds_array.h"



int main(int argc, char**argv )

{

 int value;

  long index;



  if(argc!=3)

  {

    fprintf( stderr,"Usage:  %svalue index\n", argv[0] );

    return -1;

  }



  value = atoi( argv[1] );

  index = atol( argv[2] );



  ds_init_array();

  ds_insert( value, index );

  ds_finish_array();



  return 0;

}
