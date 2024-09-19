// Homework 1: Potential Energy Functions, Forces, and Local Optimization
// Laura Jones
// Chem 279 - Dr. Mayank Agrawal
// Last revisited: 9/18/2024

// lj.h contains all the necessary information about the Lennard Jones
//      functionality created in /src


# pragma once

#include <iostream>
#include <fstream>
#include <armadillo>

using namespace arma;

class LJ
{
    private:
        std::string _file_path; //path to sample .txt file
        int _num_atoms; //number of atoms in simulation
        mat _s; //matrix
    
    public:
        LJ(std::string file);
        ~LJ();

        void read_data(std::string);

        float calc_distance(int, int);

        void print_matrix();


};
