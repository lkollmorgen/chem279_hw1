# This creates executables for tests of LJ class 

# GNU C++ Compiler
CPP         = g++      

# compiler flags -O3 optimized version -c create a library object
CPPFLAGS    = -O0 -o

# The directory where our LJ main library include files are stored.
INC_DIR = ../include

# The directory where lib object files are stored
LIB_DIR     = ../lib

# Executable programs
BIN_DIR     = ../bin

# armadillo library & include
ARMA_INC	= $(CONDA_PREFIX)/include
ARMA_LIB	= $(CONDA_PREFIX)/lib -larmadillo


# The next line contains a list of executable object files 
# created by this Makefile.
LJ_EXECUTABLES = pt1 pt2 pt3

pt1: $(INC_DIR)/lj.h
	$(CPP) $(CPPFLAGS) pt1 pt1.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lljclass \
	-I$(ARMA_INC) -L$(ARMA_LIB)
	mv pt1 $(BIN_DIR)

run_pt1:
	cd $(BIN_DIR); ./pt1

pt2: $(INC_DIR)/lj.h
	$(CPP) $(CPPFLAGS) pt2 pt2.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lljclass \
	-I$(ARMA_INC) -L$(ARMA_LIB)
	mv pt2 $(BIN_DIR)

run_pt2:
	cd $(BIN_DIR); ./pt2

pt3: $(INC_DIR)/lj.h
	$(CPP) $(CPPFLAGS) pt3 pt3.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lljclass \
	-I$(ARMA_INC) -L$(ARMA_LIB)
	mv pt3 $(BIN_DIR)

run_pt3:
	cd $(BIN_DIR); ./pt3

all:
	cd ../src; make all
	make $(LJ_EXECUTABLES)
	cd $(BIN_DIR); ./pt1
	cd $(BIN_DIR); ./pt2
	cd $(BIN_DIR); ./pt3
	
cleanall:
	cd $(BIN_DIR); rm $(LJ_EXECUTABLES) 

