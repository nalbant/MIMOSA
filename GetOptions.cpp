#include "GetOptions.h"

void GetOptions(BYTE* fname[], BOOLEAN& IsHybrid, INT argc, BYTE *argv[])
{INT i;
for(i=1; i<argc; i++)
    {if ((strcmp(argv[i], "-B")==0)||(strcmp(argv[i], "-b")==0))
       IsHybrid = FALSE;
       
    else {if ((strcmp(argv[i], "-H")==0)||(strcmp(argv[i], "-h")==0))
       	     IsHybrid = TRUE;
    	 else 
    	   { {if (strlen(argv[i])>3)
          	{if ((strstr(argv[i],".sam")!=NULL)||(strstr(argv[i],".SAM")!=NULL))
             	  IsHybrid = FALSE; }}
             *fname = argv[i];
           }  
          }   
    }
 
 
if(*fname==NULL)
 {cout << "No input files provided." << endl;
    cout << endl; 
    cout << "------------------------------------------------" << endl; 
    cout << "                MIMOSA (v." << VERSION_MAJOR << "." << VERSION_MINOR << ")" << endl; 
    cout << "------------------------------------------------" << endl;
    cout << "-H ,-h: MIMOSA-H is used (default). Please provide an input Fasta or FASTQ file as a parameter." << endl; 
    cout << "-B ,-b: MIMOSA-B is used. Please provide an input SAM file as a parameter." << endl;
 }

}
