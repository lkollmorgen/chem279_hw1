
env:
	conda create -n hw1 "python=3.11" conda-forge::armadillo

source.o:  $(INC_DIR)/lj.h
	$(CPP) $(CPPFLAGS) source.cpp -I$(INC_DIR)

# The following target creates a static library 
liblj.a: $(LJ_OBJS)
	ar ru $(LJ_LIB) $(LJ_OBJS) 
	mv $(LJ_LIB) $(LIB_DIR)
	rm $(LJ_OBJS)

all:

cleanall:
	cd $(LIB_DIR); rm $(LJ_LIB)

