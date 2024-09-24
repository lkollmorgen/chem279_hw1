# Homework 1: Potential Energy Functions, Forces, and Local Optimization
## Laura Jones
## Chem 279 - Dr. Mayank Agrawal

Last updated: 9.23.2024

## Purpose
This repository explores the potential energy within systems of gold atoms. Then, it compares analytical force to finite difference approximations. Finally, there was an attempt made to optimize the positioning within a 2-atom system.  
## In This Directory
- test/
- src/
- include/
- sample_input/
- sample_output/
- utils/
- bin/
- lib/
- `Grading_rubric`
- `homework1.pdf`
- `ljones_hw1.pdf`
- `README.md`


## USAGE
### in Root Directory:
set up environment:

```
make env
```

Do everything:
```
make all
```
-------
### In /src:
generate library:
```
make all
```
-------
### In /test:
compile and run all tests:
```
make all
```

compile and run part 1 tests:
 
 ```
 make pt1
 make run_pt1
 ```
compile and run part 2 tests:
```
make pt2
make run_pt2
```
compile and run part 3 tests:
```
make pt3
make run_pt3
```
---------
### In /utils:
do everything:
```
make all
```
compile script to generate output_error.txt file:
```
make output_error
```
generate output_error.txt file:
```
make run_error
```
generate plot in /output:
```
make plot_error
```




## TODO list:
### The Lennard-Jones Energy of a Set of Atoms
- [x] create header file with function declarations
- [x] create source file
- [x] create makefile for easy compilation
- [x] create test file

----

- [x] fill in source file with code to read from .txt file
- [x] echo input to output, crash if there are atoms other than Au atoms
- [x] return energy of cluster

### Finite Difference Vs. Analytical Forces
- [x] work out algebra in function 2.1
- [x] implement the force as a function
- [x] implement forward difference equation
- [x] implement central difference equation
    - make sure that forces match finite differences
    - step size of 0.01 Angstroms
- [x] look into the truncation error of the forward/central diff expressions as a function of h
    - h = 0.1, 0.01, 0.001, 0.0001
- [x] make plot of log error vs. analytical gradient code vs the log of the step size.
- [x] report and discuss slope for each of the 2 approximations

### Optimizing the Geometry of a Small Gold Cluster
- [x] local optimizer working by steepest descent with line searches
    - look into 1-d function optimization to implement the simple algorithm yourself
    - convergence based on energy change
- [x] test w simplest gold cluster, Au2
- [ ] then pick gold cluster w/ more atoms