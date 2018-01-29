#include "SAMParser.h"

void SAMParser(const BYTE* fname, VectorXf& Z)//VectorXd& WordFreq
{
UINT i, c_read, CountIndex, NumHash[128],skip_digit;
static BYTE Seq[BLOCK_SIZE];

	for(i=0;i<128;i++)
	{
		NumHash[i]=0;
		if(i==49) NumHash[i]=1;
		if(i==50) NumHash[i]=2;
		if(i==51) NumHash[i]=3;
		if(i==52) NumHash[i]=4;
		if(i==53) NumHash[i]=5;
		if(i==54) NumHash[i]=6;
		if(i==55) NumHash[i]=7;
		if(i==56) NumHash[i]=8;
		if(i==57) NumHash[i]=9;
	}

	fstream file(fname, ios::in);
	if (file.is_open()) 	
	{
	CountIndex=0;
	
	while(!file.eof())
	{
		file.read(Seq,BLOCK_SIZE);
		c_read=file.gcount();
		i=3;
		do
		{
		  if((Seq[i-3]=='s')&&(Seq[i-2]=='e')&&(Seq[i-1]=='q')&&(Seq[i]=='_'))
		     { CountIndex=0;skip_digit=0;
		       i++;
		       while(((Seq[i]!='\t')&&(Seq[i]!=',')&&(Seq[i]!=' '))&& skip_digit<7)
		       {
		         CountIndex = CountIndex*10+NumHash[Seq[i++]]; skip_digit++;
		       }
		       if(skip_digit<7)
		       	Z(CountIndex)++;
		     }
		     
			
		}while(++i<c_read);
	}
	file.close();
	for(i=1;i<Z.size();i++)
	    Z(i)-=1;
	}
	else
	cout << "Unable to open file";
}


