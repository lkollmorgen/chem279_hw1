#include <iostream>
#include <fstream>
#include <sstream>
#include <armadillo>

#include "lj.h"

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
    std::cout << "line: " << line << std::endl;

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

        //skip atomic number
        // getline(ss,s,' ');

        for(int j = 0; j < 3; j++)
        {
            //gather & save x,y,z coordinates
            getline(ss,s,' ');
            _s(i,j) = std::stof(s);
        }
        getline(data_file, line, '\n');
    }
}

float LJ::calc_distance(int a, int b) {
    return _s(a) - _s(b);
}

void LJ::print_matrix() {
    //this is so convenient omg
    _s.print();
}


