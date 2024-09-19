#include "lj.h"

int main(void) {
    
    // std::string path = "../sample_input/Energy/1.txt";
    // LJ o(path);

// Test only proper atom types accepted
    // std::cout << "ensure that class detects errors for clusters";
    // std::cout << " that do not only contain Au" << std::endl;
    // std::string path = "../sample_input/Energy/c.txt";
    // LJ o(path);

// Test that matrix is properly saved in class
    // std::cout << "ensure that matrices are properly saved in class";
    // std::string path = "../sample_input/Energy/1.txt";
    // LJ o(path);
    // o.print_matrix();

// Test that the distance-calculation function is working correctly
    std::string path = "../sample_input/Energy/1.txt";
    LJ o(path);
    o.print_matrix();
    std::cout << o.calc_distance(1,2) << std::endl;

    return 0;
}