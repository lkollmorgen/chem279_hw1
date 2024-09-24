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
        mat _s; //matrix of 3d coordinates for atoms

        //constants for gold
        float _epsilon = 5.29; //in kcal mol-1
        float _sigma = 2.951;   // in angstrom
    
    public:
        LJ(std::string file);
        ~LJ();

        void read_data(std::string);

        float calc_distance(int, int);

        float calc_potential(int, int, float h=0);

        float calc_total_potential(float h=0);

        float direction_force(int, int, int);

        float calc_analytical_force(int, int, int);

        // rowvec unit_vector(int, int);

        mat analytical_force_on_system();

        float forward_diff(int, int, float);

        mat forward_diff_on_system(float);

        float central_diff(int, int, float);

        mat central_diff_on_system(float);

        void golden_section(float, float);

    //debugging/output functions
        void print_matrix();


};
