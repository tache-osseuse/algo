#include "combinatorics.h"
#include "utils.h"

void placements_with_repetitions(unsigned int length, unsigned int range){
    std::vector<unsigned int> current_sequence(length, 1);
    std::vector<unsigned int> last_sequence(length, range);
    std::vector<unsigned int>::iterator it;
    print_vector(current_sequence);
    while(!std::equal(current_sequence.begin(), current_sequence.end(), last_sequence.begin())){
        it = current_sequence.end() - 1;
        while(!(*it < range)){
            it--;
        }
        (*it)++;
        if (it != current_sequence.end() - 1){
            it++;
            for(; it != current_sequence.end(); it++){
                *it = 1;
            }
        }
        print_vector(current_sequence);
    }
}

void permutations_without_repetitions(unsigned int range){
    std::vector<unsigned int> current_sequence(range);
    std::vector<unsigned int> last_sequence(range);
    unsigned int i = 0;
    std::generate(current_sequence.begin(), current_sequence.end(), [&i]{ return i+=1; });
    i = range;
    std::generate(last_sequence.begin(), last_sequence.end(), [&i]{ return i--;});
    std::vector<unsigned int>::iterator first_it, second_it;
    while(!std::equal(current_sequence.begin(), current_sequence.end(), last_sequence.begin())){
        print_vector(current_sequence);
        first_it = current_sequence.end() - 2; // ?
        while (*first_it > *(first_it+1)){
            first_it--;
        }
        second_it = first_it + 1;
        while (second_it < current_sequence.end() - 1 && *(second_it + 1) > *first_it){
            second_it++;
        }
        std::iter_swap(first_it, second_it);
        std::reverse(first_it + 1, current_sequence.end());
    }
    print_vector(current_sequence);
}
