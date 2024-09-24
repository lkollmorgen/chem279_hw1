
#target to setup the environment
env:
	conda create -n hw1 "python=3.11" matplotlib conda-forge::armadillo

all:
	cd src; make all
	cd tests; make all
	cd utils; make all 

