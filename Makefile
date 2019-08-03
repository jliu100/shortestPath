########################################
##
## Makefile
## LINUX compilation 
##
##############################################





#FLAGS
C++FLAG = -g -std=c++11 -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.


#Rule for .cpp files
# .SUFFIXES : .cc.o 

.cc.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@


#Including
INCLUDES=  -I. 

LIBS_ALL =  -L/usr/lib -L/usr/local/lib $(MATH_LIBS) 


#ZEROTH PROGRAM
ALL_OBJ0=CreateGraphAndTest.o
PROGRAM_0=CreateGraphAndTest
$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

#1ST TH PROGRAM
ALL_OBJ1=FindPaths.o
PROGRAM_1=FindPaths
$(PROGRAM_1): $(ALL_OBJ1)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

#2ND TH PROGRAM
ALL_OBJ2=TestRandomGraph.o
PROGRAM_2=TestRandomGraph
$(PROGRAM_2): $(ALL_OBJ2)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ2) $(INCLUDES) $(LIBS_ALL)

#Compiling all

all: 	
		make $(PROGRAM_0)
		make $(PROGRAM_1)
		make $(PROGRAM_2)

run1Q1G1: 	
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries1.txt

run1Q1G2: 	
		./$(PROGRAM_0) Graph2.txt AdjacencyQueries1.txt

run1Q1G3: 	
		./$(PROGRAM_0) Graph3.txt AdjacencyQueries1.txt

run1Q2G1: 	
		./$(PROGRAM_0) Graph1.txt AdjacencyQueries2.txt

run1Q2G2: 	
		./$(PROGRAM_0) Graph2.txt AdjacencyQueries2.txt

run1Q2G3: 	
		./$(PROGRAM_0) Graph3.txt AdjacencyQueries2.txt



run2G21: 	
		./$(PROGRAM_1) Graph2.txt 1

run3: 	
		./$(PROGRAM_2) 100
run3A: 	
		./$(PROGRAM_2) 55
run3AB: 	
		./$(PROGRAM_2) 20
run3c: 	
		./$(PROGRAM_2) 10
run3d: 	
		./$(PROGRAM_2) 7


#Clean obj files

clean:
	(rm -f *.o; rm -f $(PROGRAM_0); rm -f $(PROGRAM_1); rm -f $(PROGRAM_2))

(:
