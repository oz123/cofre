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

OBJ=src/config.o 3rd_party/argparse/argparse.o src/driver.o src/crypto.o \
	src/cli.o

# $@ - left side of :
# $^ - right side of :
# $< is the first item in the dependencies list

all: cofre 

# run tests as defined by CuTest 
test: check 

check:
	make -C test -f test.mk

# because config.o and argparse.o were to the list of objects linked
# gcc will automatically compile and hard link argparse.o 
#cofre: src/config.o 3rd_party/argparse/argparse.o src/driver.o src/crypto.o
#cofre: src/config.o 3rd_party/argparse/argparse.o src/driver.o src/crypto.o

DEPS = driver.o crypto.o config.o cli.o 3rd_party/argparse/argparse.o

cofre: $(DEPS)
	$(CC) src/cofre.c $(OBJ) $(CFLAGS) $(LIBS) -o src/$@

config.o: src/config.c src/config.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

driver.o: src/driver.c src/driver.h 
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

crypto.o: src/crypto.c src/crypto.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

cli.o: src/cli.c src/cli.h
	$(CC) $(CFLAGS) -c $< $(LIBS) -o src/$@

veryclean:	clean cleandeps

clean:
	$(RM) src/cofre src/*.o 
	make -C test/ -f test.mk clean

# clean 3rd party	
cleandeps: clean
	make -C 3rd_party/iniparser/ clean
	make -C 3rd_party/argparse/ clean

get_3rd_party:
	sudo apt-get install libsqlite3-dev libtomcrypt-dev
	git clone  https://github.com/ndevilla/iniparser.git 3rd_party/iniparser
	git clone https://github.com/Cofyc/argparse.git 3rd_party/argparse

3rd_party:
	make -C 3rd_party/iniparser/ 
	make -C 3rd_party/argparse/ 

.PHONY: 3rd_party
