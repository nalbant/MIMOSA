#***************     mimosa makefile      ************************/
#*  University of Nebraska-Lincoln                               */
#*  Department of Electrical Engineering                         */
#*  Occult Information Lab                                       */
#*  Author: Ufuk Nalbantoglu                                     */
#*  25/4/16                                                      */
#*****************************************************************/


EXE     = ../mimosa 
CC      = g++
CCFLAGS = -O3 -w
OBJS     = main.o Kmer.o Hybridize.o PolytopeFacesPursuit.o SAMParser.o GetOptions.o LoadScaleFactors.o ReportResult.o
SOURCE   = main.cpp Kmer.cpp Hybridize.cpp PolytopeFacesPursuit.cpp SAMParser.cpp GetOptions.cpp LoadScaleFactors.cpp ReportResult.cpp


${EXE}: ${OBJS} ${SOURCE}
	${CC} ${CCFLAGS} ${OBJS} -o ${EXE} 

main.o: main.cpp Globals.h Kmer.h Hybridize.h PolytopeFacesPursuit.h SAMParser.h GetOptions.h LoadScaleFactors.h ReportResult.h
	${CC} -c ${CCFLAGS} main.cpp

Kmer.o: Kmer.cpp Kmer.h
	${CC} -c ${CCFLAGS} Kmer.cpp

Hybridize.o: Hybridize.cpp Hybridize.h
	${CC} -c ${CCFLAGS} Hybridize.cpp

PolytopeFacesPursuit.o: PolytopeFacesPursuit.cpp PolytopeFacesPursuit.h
	${CC} -c ${CCFLAGS} PolytopeFacesPursuit.cpp

SAMParser.o: SAMParser.cpp SAMParser.h
	${CC} -c ${CCFLAGS} SAMParser.cpp
	
GetOptions.o: GetOptions.cpp GetOptions.h
	${CC} -c ${CCFLAGS} GetOptions.cpp
	
LoadScaleFactors.o: LoadScaleFactors.cpp LoadScaleFactors.h
	${CC} -c ${CCFLAGS} LoadScaleFactors.cpp
	
ReportResult.o: ReportResult.cpp ReportResult.h
	${CC} -c ${CCFLAGS} ReportResult.cpp
	
	
clean:
	rm -rf *.o ${EXE}
