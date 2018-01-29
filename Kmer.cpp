
#include "Kmer.h"


void Kmer(const BYTE* fname, VectorXf& WordFreq)//VectorXd& WordFreq
{
unsigned int i, read8, is_DNA, c_read, CountIndex;
static char Seq[BLOCK_SIZE];
unsigned char NumHash[128];

	for(i=0;i<128;i++)
	{
		NumHash[i]=255;
		if(i==65 || i==97) NumHash[i]=0;
		if(i==67 || i==99) NumHash[i]=1;
		if(i==71 || i==103) NumHash[i]=2;
		if(i==84 || i==116) NumHash[i]=3;
	}/*end for(i=0;i<128;i++)*/

	fstream file(fname, ios::in);
	if (file.is_open()) 	
	{
	is_DNA = 0;
	CountIndex=0;
	
	while(!file.eof())
	{
		file.read(Seq,BLOCK_SIZE);
		c_read=file.gcount();
		i=0;
		do
		{
			if(is_DNA)
			{
				//if(Seq[i]=='>') {is_DNA = 0; CountIndex=0; read8=0;}
				if((Seq[i]=='>')||(Seq[i]=='@')|(Seq[i]=='+')) {is_DNA = 0; CountIndex=0; read8=0;i++;}
				else
				{
					if (Seq[i]>64)/*(isalpha(Seq[i])) */
					{	
						if(NumHash[Seq[i]]<4)
						{ CountIndex*=4; CountIndex+=NumHash[Seq[i]]; read8++;//CountIndex<<=2
							if(read8>=10)
							//WordFreq[MOD_w10]++;
							WordFreq(CountIndex%VEC_LEN)++;
						}
						else
						{CountIndex=0; read8=0;}
					}/*end isalpha(Seq[i])*/

				}/*end else (Seq[i]==">") */
				
			}/*end if(is_DNA)*/
			else
			{
				if(Seq[i]==10||Seq[i]==13) is_DNA = 1; 

			}/*end else (is_DNA)*/	
		}while(++i<c_read);
	}/*end while(1)*/
	file.close();
	
	}
	else
	cout << "Unable to open input file"<< endl;
}


