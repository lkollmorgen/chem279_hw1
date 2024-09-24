#include "lj.h"

int main(void) {
    
std::cout << "running tests for part 2: " << std::endl;

// Test that golden section is running well
    std::string two_atom_path = "../sample_input/SD_with_line_search/1.txt";
    LJ oa(two_atom_path);
    //oa.print_matrix();
    std::cout << "start steepest descent with golden section line search";
    std:: cout << std::endl;
    std::cout << "Initial energy: " << oa.calc_total_potential() << std::endl;

    //defining golden section variables
    float threshold = 0.01; 
    float stepsize = 0.0001;

    std::cout << "Stepsize for central difference is: " << stepsize <<";Initial stepsize for line search is:0.3;";
    std::cout << std::endl;
    std::cout << "Threshold for convergence in force is: " << threshold <<std::endl;
    oa.central_diff_on_system(stepsize);
    oa.golden_section(stepsize,threshold);
    std::cout << "Total iterations: 1" << std::endl;
    std::cout << "Final energy: " << oa.calc_total_potential() << std::endl;




}