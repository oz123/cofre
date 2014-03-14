CC=gcc
CFLAGS=-std=c99 -O3 -Wall 

# run with $ DEBUG=1 make 
# this will add debug symbols to the binary
ifdef DEBUG
  CFLAGS+=-g
endif 
# if compiling dynamically you can run the program with 
# LD_LIBRARY_PATH=3rd_party/argparse ./src/cofre
LIBS=-l tomcrypt -l sqlite3 -I 3rd_party/iniparser/src  -L 3rd_party/iniparser/ -l iniparser \
	 -I 3rd_party/argparse/ -lm # -L 3rd_party/argparse/# -l argparse 

# use this when compiling with -static
STATIC_LIBS=-l tomcrypt -l sqlite3 -I 3rd_party/iniparser/src  -L 3rd_party/iniparser/ -l iniparser \
	 -I 3rd_party/argparse/ -L 3rd_party/argparse/ -l argparse -lm 

# altenatively you can directly link argparse.o with 
#cofre: src/config.o 3rd_party/argparse/argparse.o
#	$(CC) src/cofre.c $^ $(CFLAGS) $(LIBS) -o src/$@

#LIBS += -lm

DEPS= src/*.h
OBJ=src/config.o 3rd_party/argparse/argparse.o src/driver.o src/crypto.o \
	src/cli.o

# $@ - left side of :
# $^ - right side of :
# $< is the first item in the dependencies list

all: driver.o config.o cli.o cofre 

#cofre: src/config.o 3rd_party/argparse/argparse.o src/driver.o src/crypto.o
cofre: $(OBJ)
	$(CC) src/cofre.c $^ $(CFLAGS) $(LIBS) -o src/$@

clean:
	$(RM) src/cofre src/*.o 

config.o: src/config.c src/config.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

driver.o: src/driver.c src/driver.h 
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

crypto.o: src/crypto.c src/crypto.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

cli.o: src/cli.c src/cli.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

