#include "LoadScaleFactors.h"

void LoadScaleFactors(BOOLEAN IsHybrid, VectorXd& ScaleFactor)
{
ifstream ifs;
if (IsHybrid)
   ifs.open(SCALEFACTORS_H,ios::in | ios::binary );
else
   ifs.open(SCALEFACTORS_B,ios::in | ios::binary );
   
   
   
   
if (ifs.is_open())
  {
    static double ScaleFactorTemp[SEQ_NUMBER];
    ifs.read( (char *) &ScaleFactorTemp, sizeof ScaleFactorTemp);	
    ifs.close();
    for (INT i=0;i<SEQ_NUMBER;i++) ScaleFactor(i) = ScaleFactorTemp[i];
  }
else
    cout << "Database file missing!"<< endl;

}   
