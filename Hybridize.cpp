#include "Hybridize.h"

void Hybridize(const BYTE* fname, VectorXf& Z)
{
static FLOAT RefOrgTemp[VEC_LEN];
VectorXf WordFreq=VectorXf::Zero(VEC_LEN);
VectorXf RefOrg=VectorXf::Zero(VEC_LEN);
Kmer(fname, WordFreq);

fstream ifs(SEQ_DB,ios::in | ios::binary);
if (ifs.is_open())
  {for(UINT i=0;i<SEQ_NUMBER;i++)
      {ifs.read( (BYTE *) &RefOrgTemp, sizeof RefOrgTemp);
      
      Map<VectorXf> RefOrg(RefOrgTemp,VEC_LEN);
      Z(i) = RefOrg.dot(WordFreq);
      }
    ifs.close();
   }
else
   cout << "Database file missing!"<< endl;
}
