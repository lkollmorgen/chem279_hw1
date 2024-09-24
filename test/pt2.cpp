#include "lj.h"

int main(void) {
    
std::cout << "running tests for part 2: " << std::endl;

// Test that the analytical force is calculated correctly with 4 atoms
    std::string four_atom_path = "../sample_input/Force/1.txt";
    LJ oa(four_atom_path);
    oa.print_matrix();
    std:: cout << std::endl;

    std::cout << "direction of force" << std::endl;
    std::cout << "E_LJ = " << oa.calc_total_potential() << std::endl;
    std::cout << "F_LJ_analytical" << std::endl;
    oa.analytical_force_on_system().print();


// Test forward difference approximation with 4 atoms
    float h = 0.01;
    LJ ob(four_atom_path);
    std::cout << "Stepsize for finite difference: " << h << std::endl;
    std::cout << "F_LJ_forward_difference" << std::endl;
    ob.forward_diff_on_system(h).print();

// Test central difference approximation with 4 atoms
    //float h = 0.01;
    LJ oc(four_atom_path);
    std::cout << "F_LJ_central_difference" << std::endl;
    oc.central_diff_on_system(h).print();
    return 0;
}