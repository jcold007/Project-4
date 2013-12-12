 
 # Used and referenced by Ivan Coronel 
 # (project 4 Gary Lewandowski - Data Structures)
 # Makefile utilized for creation and compilation of program

CC	= g++
INCLUDE	= -I/usr/local/include
#Windows users comment-out the above line and uncomment the line below
#INCLUDE	= -I/MinGW/msys/1.0/local/include

LIBS = -L/usr/local/lib
#Windows users comment out the above line and uncomment the line below
#LIBS = -L/MinGW/msys/1.0/local/lib

CFLAGS  = -g

runGame: board.o heap.o main.o
	$(CC) -o getURL $(INCLUDE) $(LIBS) $(CFLAGS)  board.o heap.o main.o -lcurl
 
.cpp.o:	
	$(CC) $(INCLUDE) $(CFLAGS) $(LIBS) -c $< -o $@