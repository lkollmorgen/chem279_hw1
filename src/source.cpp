#include <iostream>
#include <fstream>
#include <sstream>
#include <armadillo>
#include <math.h>

#include "lj.h"

using namespace arma;


LJ::LJ(std::string path)
    : _file_path(path)
    {
        read_data(_file_path);
    }
LJ::~LJ(){}


void LJ::read_data(std::string f_path) {
    std::fstream data_file;
    std::string line;
    std::string s;

    data_file.open(f_path);
    getline(data_file,line,'\n');

    //save the number of atoms in the cluster
    _num_atoms = std::stoi(line);
    //resize the matrix, _s
    _s.set_size(_num_atoms,3);

    getline(data_file, line, '\n');

    std::string Au = "79";
    for(int i = 0; i < _num_atoms; i++) {
        std::stringstream ss(line);
        //std::cout << line << std::endl;
        getline(ss,s,' ');

        //exit if atoms other than gold are present in .txt file
        if(s!= Au) {
            std::cout << "Atomic number " << s << " not allowed" << std::endl;
            exit(1);
        }

        for(int j = 0; j < 3; j++)
        {
            //gather & save x,y,z coordinates
            getline(ss,s,' ');
            _s(i,j) = std::stof(s);
        }
        getline(data_file, line, '\n');
    }
}

float LJ::calc_distance(int i, int j) {
    rowvec result = _s.row(i) - _s.row(j);
    return sqrt(pow(result(0),2) + pow(result(1),2) + pow(result(2),2));
}

float LJ::calc_potential(int i, int j, float h) {
    float r = calc_distance(i,j) + h;
    float repel = pow((_sigma/r),12);
    float attract = pow((_sigma/r),6);
    return _epsilon *(repel - 2 * attract);
}

float LJ::calc_total_potential(float h) {
    float total_energy = 0;
    for(int i = 0; i < _num_atoms; i++) {
        for(int j = 0; j < _num_atoms; j++) {
            if(i != j) {
                total_energy += calc_potential(i, j, h);
            }
        }
    }
    return .5 * total_energy;
}

float LJ::direction_force(int i, int j, int dim) {
    float direction_displacement = _s(j, dim) - _s(i, dim);
    float dist = calc_distance(i, j);
    return direction_displacement / dist;
}

float LJ::calc_analytical_force(int i, int j, int dim) {
    float r = calc_distance(i, j);
    float repel = (pow(_sigma, 12)) / (pow(r, 13));
    float attract = (pow(_sigma, 6)) / (pow(r, 7));
    return _epsilon * (12*repel - 12*attract) * direction_force(i, j, dim);
}

mat LJ::analytical_force_on_system() {
    mat force_matrix(3,_num_atoms);
    for(int i = 0; i < _num_atoms; i++) {
        vec q(3);
        int dim = 0; //dimension of force:
        // 0 = x
        // 1 = y
        // 2 = z
        for(int j = 0; j < _num_atoms; j++) {
            if(i != j) {
                q(dim) = calc_analytical_force(i, j, dim);
                dim++;
            }
        }
        force_matrix.col(i) = q;
    }
    force_matrix.print();
    return force_matrix;
}


float LJ::forward_diff(int i, int j, float h) {
    float energy = calc_potential(i,j);
    float energy_increment = calc_potential(i,j,h);
    return -(energy_increment - energy) / h;
}

mat LJ::forward_diff_on_system(float h) {
    mat force_matrix(3,_num_atoms);
    for(int i = 0; i < _num_atoms; i++) {
        vec q(3);
        int pos = 0;
        for(int j = 0; j < _num_atoms; j++) {
            if(i != j) {
                q(pos) = forward_diff(i, j, h);
                pos ++;
            }
        }
        force_matrix.col(i) = q;
    }
    force_matrix.print();
    std::cout << std::endl;
    return force_matrix;
}

float LJ::central_diff(int i, int j, float h) {
    float energy_decrement = calc_potential(i,j, -h);
    float energy_increment = calc_potential(i,j,h);
    return - (energy_increment - energy_decrement) / (2 * h);
}

mat LJ::central_diff_on_system(float h) {
    mat force_matrix(3,_num_atoms);
    for(int i = 0; i < _num_atoms; i++) {
        vec q(3);
        int pos = 2;
        for(int j = 0; j < _num_atoms; j++) {
            if(i != j) {
                q(pos) = central_diff(i, j, h);
                pos --;
            }
        }
        force_matrix.col(i) = q;
    }
    // force_matrix.print();
    // std::cout << std::endl;
    return force_matrix;
}

void LJ::golden_section(float h, float tol) {
    //function to minimize will be 'calc_total_potential'
    mat central_diff_matrix = central_diff_on_system(h);
    float tau = (sqrt(5) - 1) / 2;

    arma::uword dim = 0;
    for(arma::uword col = 0; col < central_diff_matrix.n_cols; col++)
    {
        dim = arma::index_min(central_diff_matrix.col(col));  
    }

    float upper_bound = _s(1,dim);
    float lower_bound = _s(0,dim);

    std::cout << lower_bound << " " << upper_bound << std::endl;

    float c = upper_bound - tau * (upper_bound - lower_bound);
    float d = lower_bound + tau * (upper_bound - lower_bound);
    std::cout << c << " " << d << std::endl;

    //reset coords in matrix
    _s(1,dim) = c;
    _s(0,dim) = d;

}

void LJ::print_matrix() {
    //this is so convenient omg
    _s.print();
}


