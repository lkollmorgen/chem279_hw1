# Homework 1: Potential Energy Functions, Forces, and Local Optimization
## Laura Jones
## Chem 279 - Dr. Mayank Agrawal

Last updated: 9.20.2024

## In This Directory
- test/
- src/
- include/
- sample_input/
- sample_output/


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
- [ ] look into the truncation error of the forward/central diff expressions as a function of h
    - h = 0.1, 0.01, 0.001, 0.0001
- [ ] make plot of log error vs. analytical gradient code vs the log of the step size.
- [ ] report and discuss slope for each of the 2 approximations

### Optimizing the Geometry of a Small Gold Cluster
- [ ] local optimizer working by steepest descent with line searches
    - look into 1-d function optimization to implement the simple algorithm yourself
    - convergence based on energy change
- [ ] test w simplest gold cluster, Au2
- [ ] then pick gold cluster w/ more atoms