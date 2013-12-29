CC=gcc
CFLAGS=-std=c99 -O3 -Wall 
LIBS=-l tomcrypt -l sqlite3 -I 3rd_party/iniparser/src  -L 3rd_party/iniparser/ -l iniparser


DEPS= src/*.h
OBJ=

# $@ - left side of :
# $^ - right side of :
# $< is the first item in the dependencies list

all: config.o cofre 

cofre: src/config.o
	$(CC) src/cofre.c $^ $(CFLAGS) $(LIBS) -o src/$@

clean:
	$(RM) src/cofre src/*.o 

config.o: src/config.c src/config.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

	
