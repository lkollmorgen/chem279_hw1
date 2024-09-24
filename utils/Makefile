# This creates executables for utils of LJ class 

# GNU C++ Compiler
CPP         = g++      

# compiler flags -O3 optimized version -c create a library object
CPPFLAGS    = -O0 -o

# The directory where Week 9's main library include files are stored.
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
LJ_EXECUTABLES = output_error

output_error: $(INC_DIR)/lj.h
	$(CPP) $(CPPFLAGS) output_error output_error.cpp \
	-I$(INC_DIR) -L$(LIB_DIR) -lljclass \
	-I$(ARMA_INC) -L$(ARMA_LIB)
	mv output_error $(BIN_DIR)

run_error:
	cd $(BIN_DIR); ./output_error
	cd $(BIN_DIR); mv gradient_error.txt ../output

plot_error:
	python plot_error.py
	mv error_comparison.png ../output

all:
	make output_error
	make run_error
	make plot_error

cleanall:
	cd $(BIN_DIR); rm $(LJ_EXECUTABLES) 

