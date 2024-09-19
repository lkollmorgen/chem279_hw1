# GNU C++ Compiler
CPP         = g++      # C++ Compuler

CPPFLAGS    = -O3 -c    

# The directory where the include files needed to create the library objects are
INC_DIR = ../include

# The directory where all object files are going to moved afer creation
LIB_DIR     = ../lib

# armadillo library
ARMA_INC	= $(CONDA_PREFIX)/include
ARMA_LIB	= $(CONDA_PREFIX)/lib -larmadillo

# linkable object files with class info
LJ_OBJS = source.o

# Lennard Jones library containing Lennard Jones Class
LJ_LIB = libljclass.a

source.o:  $(INC_DIR)/lj.h
	$(CPP) $(CPPFLAGS) source.cpp \
	-I$(INC_DIR) \
	-I$(ARMA_INC) -L$(ARMA_LIB)

# The following target creates a static library 
libljclass.a: $(LJ_OBJS)
	ar ru $(LJ_LIB) $(LJ_OBJS) 
	mv $(LJ_LIB) $(LIB_DIR)
	rm $(LJ_OBJS)

all: $(LJ_LIB)

cleanall:
	cd $(LIB_DIR); rm $(LJ_LIB)

