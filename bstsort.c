

#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include<string.h>



int main(int argc, char **argv)
{
	
	FILE *entrada;  //declaration of the files input and output
   	FILE *saida;
	extern char *optarg;
	extern int optind;
	int c,n,err = 0;
	int mflag=0, pflag=0;
	char *fname="input_file_name or output_file_names";
	static char usage[] = "usage: %s  [-c] [-o outfile] [infile] \n";
	char info[44];
	char array[44];
	int i=0,j=0;
	char temp;


	  entrada = fopen ("infile.dat", "r");   //seting up permissions to the file w=write and r=read.
          saida = fopen ("outfile.dat", "wr");

  	 if (entrada == NULL)
	 {
    		  printf ("\n I couldnt find the file\n");
  	    	  exit (EXIT_FAILURE);
  	 }
	  if (saida == NULL)
	 {
      	  	printf ("\nI couldnt find the file\n");
     	 	exit (EXIT_FAILURE);
   	 }	



	while ((c = getopt(argc, argv, "co:")) != -1)
		switch (c) 
	        {
		case 'c':
		mflag = 1;
	
	
	for(i=0;i<41;i++) 		                     
	{
	fscanf(entrada,"%c",&info[i]); // taking the numbers from the file infile.data
	}

	for(i=0;i<44;i++) 		                      
	{
	 if(info[i]!='\0' && info[i]!=' ')
	 strcpy(array,info);
	
	}

	/*
	 for (i=0; i<40-1; i++)
        {
        for (j=i+1; j<40; j++)
        {
            int  s = tolower(array[i]) - tolower(array[j]);
            if ( s == 0 )
            {   // letters are the same... now watch out for case
                s = array[i] - array[j];
            }

            if (s > 0)
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        }*/

   

	for(i=0;i<44;i++) 		 // This part sorts the 32 interger numbers from the array.                         
	{
      	printf("%c",array[i]); // taking the numbers from the file infile.data
	
	}






	
		break;
		








		case 'o':
		pflag=1;
			
		fname = optarg;

		if (fname="Rodrigo")
			{
					
			}
	       
						
		break;
		case '?':
			err = 1;
			break;
		}

		if (mflag == 0 && pflag == 0) 
		{
		//fprintf(stderr, "%s: missing -c or -o option\n", argv[0]);		
		fprintf(stderr, usage, argv[0]);
		exit(1);
		}



	
		if (optind < argc)
	        {	/* these are the arguments after the command-line options */
		for (; optind < argc; optind++)
			printf("WRONG argument: \"%s\"\n", argv[optind]);
		        printf(" Please use [-c] [-o outfile] [infile] \n");
		}
		if (err) {
		fprintf(stderr, usage, argv[0]);
		exit(1);
		}
		
	//printf("pflag = %d\n", pflag);
	//printf("mflag = %d\n", mflag);
	//printf("fname = \"%s\"\n", fname);
	

        fclose (entrada);  // closing inputfile
        fclose (saida); // closing outputfile
	exit(0);
}
