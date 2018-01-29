MIMOSA
======

Mimosa is a time-efficient phylotyping method using metagenome reads for the estimation of the microbial diversity and the abundance profile associated with an environmental sample. 

The phylotyping method implemented is as follows. A simple DNA-DNA hybridization model generates the hybridization profile of a metagenome sample with a precompiled panel of prokaryotes. Then the cross-hybridizations are removed and the abundance of each taxonomic class is estimated by recovering the sparse representation.


/*****************************************************************/
  MIMOSA
  Version 0.1

  This program is freely available for academic use, without any
  warranty.  Commercial distribution of this program, in whole or
  in part, requires prior agreement with the authors.
/*****************************************************************/

1. INSTALL

MIMOSA is written in C++, so it requires a C++ compiler. Required Eigen Linear algebra library 
(http://eigen.tuxfamily.org/) files used in the development are included in the source directory.

Use the following commands to build
the program.

cd <path_to_"src"_directory_under_"mimosa.0.1"_directory>
make clean
make

At this point, the executable "mimosa" (on linux/unix/macosx)
will be built at "mimosa.0.1" directory.
The executable must be run at this directory.

/*****************************************************************/

2. USAGE

-H ,-h: MIMOSA-H (hybridization mode) is used (default). An input FASTA or FASTQ file should be presented.
	example: ./mimosa -H <INPUT_FILE>

-B ,-b: MIMOSA-B (alignment mode) is used. An input SAM file should be provided.
	example: ./mimosa -B <INPUT_FILE>

As the program runs succesfully, an INPUT_FILE.mimosa output is created, including the estimated 
 taxonomic groups and their relative abundance ratios in the corresponding metagenome.

/*****************************************************************/

3. DATABASE
MIMOSA requires database files, structured for both hybridization (-H) and alignment (-B) modes. Those files
can be downloaded from the project website (http://bioinfo.unl.edu/mimosa.php).

THE DATABASE FILES SHOULD BE PLACED IN THE "db" folder under mimosa directory. The regarding information is included in the "Version.h"
header file in the source code, and the users are free to manipulate this header file at their convenience.

As Mimosa is intended to run in the -B mode, a previous alignment (in sam format) against the prokaryote database needs to be input to the program.
Currently, alignment index files for BWA (http://bio-bwa.sourceforge.net/) aligner were built and provided at http://bioinfo.unl.edu/downloads/bwa_mimosa_index.tar.bz2. 
A Python script (MIMOSA-B.py) to align FASTQ/FASTA files, and process the resulting sam files using Mimosa is provided in the same webpage.
Running MIMOSA-B requires installing BWA. Also the BWA index files should be placed in "db" directory under the mimosa directory.

The commandline usage of the Python script is:

> python MIMOSA-B.py <INPUT_FILE>


/*****************************************************************/

