#include <iostream>
#include <fstream>
#include <sstream>
#include <armadillo>
#include <math.h>

#include "lj.h"

using namespace arma;

int main(void) {

    std::string four_atom_path = "../sample_input/Force/1.txt";

    LJ system(four_atom_path);

    //step sizes for forward & central difference approximations
    float steps[4] = {0.1, 0.01, 0.001, 0.0001};

    //output filestream
    std::ofstream error_file ("gradient_error.txt");

    if (error_file.is_open()) {
        //for each h, calculate analytical, central, forward
        for(int i = 0; i < 4; i++) {
            //output h
            error_file << steps[i] << std::endl;
            //calculate analytical force & forward/central difference approximations
            mat ana_force =  system.analytical_force_on_system();
            mat forward_force = system.forward_diff_on_system(steps[i]);
            mat central_force = system.central_diff_on_system(steps[i]);

                    
            // calc/output mean difference between analytical & central
            // calc/output mean difference between analytical & forward
            double forward_avg = arma::mean(arma::mean(arma::abs(ana_force - forward_force)));
            double central_avg = arma::mean(arma::mean(arma::abs(ana_force - central_force)));
            error_file << forward_avg << std::endl;
            error_file << central_avg << std::endl;
        }

        error_file.close();
    }

    return 0;
}