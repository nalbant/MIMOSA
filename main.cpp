/*****************************************************************/
/*  University of Nebraska-Lincoln                               */
/*  Department of Electrical Engineering                         */
/*  Occult Information Lab                                       */
/*  Ufuk Nalbantoglu                                             */
/*  3/5/13                                                      */
/*****************************************************************/




/***********************  Headers    *****************************/
#include "Globals.h"
#include "Kmer.h"
#include "Hybridize.h"
#include "PolytopeFacesPursuit.h"
#include "SAMParser.h"
#include "GetOptions.h"
#include "LoadScaleFactors.h"
#include "ReportResult.h"



/***********************  Mainfucntion with void modules   *******/
INT main(INT argc, BYTE *argv[])
{

BYTE* fname=NULL;
BOOLEAN IsHybrid=TRUE;
clock_t t;

GetOptions(&fname, IsHybrid, argc, argv);

if (fname==NULL)
   {return 1;}

VectorXf Z = VectorXf::Zero(SEQ_NUMBER);
VectorXd Z_observe = VectorXd::Zero(SEQ_NUMBER);
VectorXd ScaleFactor = VectorXd::Zero(SEQ_NUMBER);
LoadScaleFactors(IsHybrid,ScaleFactor);


if (IsHybrid)
  {cout << "MIMOSA-H running..." << endl;
   t=clock(); 
   Hybridize(fname, Z);		//hybridize the metagenome
   Z_observe = Z.cast<double>();
  }
else
  {cout << "MIMOSA-B running..." << endl;
   SAMParser(fname,Z);		//or get results from short-read mapping
   Z_observe = Z.cast<double>().cwiseQuotient(ScaleFactor);
  }


VectorXd  N = VectorXd::Zero(SEQ_NUMBER);

cout << "Approximating the metagenome profile.." << endl;
PolytopeFacesPursuit(Z_observe,N,ScaleFactor,IsHybrid); //recover the profile


ReportResult(fname,N);		//print predicted profile in file

t = clock()-t;
cout << "Task completed in  "<< ((float)t)/CLOCKS_PER_SEC <<"  seconds." << endl;

return 0;
}
