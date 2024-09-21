#include "lj.h"

int main(void) {
    
std::cout << "running tests for part 1: " << std::endl;

// Test that matrix is properly saved in class
    std::cout << "ensure that matrices are properly saved in class";
    std::cout << std::endl;
    std::string path_a = "../sample_input/Energy/1.txt";
    LJ a(path_a);
    a.print_matrix();

// Test that the distance-calculation function is working correctly
    std::string path_b = "../sample_input/Energy/1.txt";
    LJ b(path_b);
    std::cout << std::endl << "distance between rows 2 and 3: ";
    std::cout << b.calc_distance(1,2) << std::endl << std::endl;

// Test that the PE is calculated correctly with 2 atoms
    std::string three_atom_path = "../sample_input/Energy/1.txt";
    LJ o3(three_atom_path);
    o3.print_matrix();
    std::cout << "E_LJ = " << o3.calc_total_potential() << std::endl;
    std::cout << std::endl;

// Test that the PE is calculated correctly with 5 atoms
    std::string five_atom_path = "../sample_input/SD_with_line_search/2.txt";
    LJ o5(five_atom_path);
    o5.print_matrix();
    std::cout << "E_LJ = " << o5.calc_total_potential() << std::endl;

// Test only proper atom types accepted
    std::cout << "ensure that class detects errors for clusters";
    std::cout << " that do not only contain Au" << std::endl;
    std::string path_error = "../sample_input/Energy/c.txt";
    LJ c(path_error);

    return 0;
}