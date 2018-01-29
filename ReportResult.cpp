#include "ReportResult.h"

void ReportResult(BYTE* fname, VectorXd& N)
{
  string linein;
  ostringstream lineout;
  ifstream ifs(TAXONOMY_INFO,ios::in);
  ofstream ofs(strcat(fname,".mimosa"),ios::out);
  for(INT i=0;i<N.size();i++)
     {
      getline(ifs,linein);
      if(N(i)>0.001)
       {
		ofs << linein << "\t" << N(i) << "\n";

       }
     }
   ofs.close();
   ifs.close();
     
}
