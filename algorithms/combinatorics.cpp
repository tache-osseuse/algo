#include "combinatorics.h"

void placements_with_repetitions(unsigned int length, unsigned int range){
    std::vector<unsigned int> current_sequence(length, 1);
    std::vector<unsigned int> last_sequence(length, range);
    std::vector<unsigned int>::iterator it;
    for(const auto& el: current_sequence){
        std::cout << el << " ";
    }
    std::cout << "\n";
    while(!std::equal(current_sequence.begin(), current_sequence.end(), last_sequence.begin())){
        it = current_sequence.end() - 1;
        while(!(*it < range)){
            it--;
        }
        (*it)++;
        if (it != current_sequence.end() - 1){
            it++;
            for(it; it != current_sequence.end(); it++){
                *it = 1;
            }
        }
        for(const auto& el: current_sequence){
            std::cout << el << " ";
        }
        std::cout << "\n";
    }
}
