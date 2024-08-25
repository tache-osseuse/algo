#include "combinatorics.h"
#include "utils.h"

void placements_with_repetitions(unsigned int length, unsigned int range){
    std::vector<unsigned int> current_sequence(length, 1);
    std::vector<unsigned int> last_sequence(length, range);
    std::vector<unsigned int>::iterator it;
    print_vector(current_sequence);
    while (!std::equal(current_sequence.begin(), current_sequence.end(), last_sequence.begin())){
        it = current_sequence.end() - 1;
        while (!(*it < range)){
            it--;
        }
        (*it)++;
        if (it != current_sequence.end() - 1){
            it++;
            for (; it != current_sequence.end(); it++){
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
    while (!std::equal(current_sequence.begin(), current_sequence.end(), last_sequence.begin())){
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

// NOT READY
void subsets_of_set(unsigned int subset_range, unsigned int set_range){
    // check, if subset_range is 0!
    if(subset_range > set_range){
        // print smth
        return;
    }
    std::vector<bool> current_subset(set_range, true);
    std::vector<bool> last_subset(set_range, false);
    unsigned int cut = set_range - subset_range;
    std::vector<bool>::iterator it = current_subset.begin();
    for(; it < current_subset.begin() + cut; it++){
        *it = false;
    }
    it = last_subset.begin();
    for(; it < last_subset.begin() + cut; it++){
        *it = true;
    }
    print_vector(current_subset);
    while(!std::equal(current_subset.begin(), current_subset.end(), last_subset.begin())){
        it = current_subset.end() - 2; // ?
        while(!(*it == 0 && *(it+1) == 1)){
            it--;
        }
        unsigned int units_count = 0;
        for(auto temp_it = it; temp_it != current_subset.end(); temp_it++){
            units_count += *temp_it;
        }
        *it = 1;
        it++;
        for(auto temp_it = it; temp_it != it + units_count - 1; temp_it++){
            *it = 0;
        }
        for(auto temp_it = it + units_count - 1; temp_it != current_subset.end(); temp_it++){
            *temp_it = 1;
        }
        print_vector(current_subset);
    }
}

void increasing_sequences(unsigned int length, unsigned int range){
    // check, if range < length
    std::vector<unsigned int> current_sequence(length);
    std::vector<unsigned int> last_sequence(length);
    unsigned int i = 0;
    std::generate(current_sequence.begin(), current_sequence.end(), [&i]{ return i+=1; });
    i = range - length;
    std::generate(last_sequence.begin(), last_sequence.end(), [&i]{ return i+=1; });
    std::vector<unsigned int>::iterator it;
    print_vector(current_sequence, "");
    while (!std::equal(current_sequence.begin(), current_sequence.end(), last_sequence.begin())){
        it = current_sequence.end() - 1;
        while (!(*it < range - length + std::distance(current_sequence.begin(), it) + 1)){
            it--;
        }
        (*it)++;
        it++;
        for (; it < current_sequence.end(); it++){
            *it = *(it-1) + 1;
        }
        print_vector(current_sequence, "");
    }
}

// NEEDS IMPROVEMENTS
void positive_number_partitions(unsigned int number){
    // Check for zero and one
    std::vector<unsigned int> current_sequence(number);
    std::generate(current_sequence.begin(), current_sequence.end(), [] { return 1; });
    std::vector<unsigned int>::iterator boundary_it = current_sequence.end() - 1, it, inter_it, end_it;
    std::vector<std::string> partitions;
    std::string current_partition;
    unsigned int current_sum;
    for (it = current_sequence.begin(); it != current_sequence.end(); it++){
        if (it != current_sequence.begin() & it == current_sequence.end() - 1){
            current_partition += std::to_string(*it);
        }
        else{
            current_partition += std::to_string(*it) + "+";
        }
    }
    partitions.push_back(current_partition);
    while(current_sequence[0] != number){
        it = boundary_it - 1;
        while(!(it == current_sequence.begin() || *(it-1) > *it)){
            it--;
        }
        (*it)++;
        current_sum = 0;
        for (inter_it = it + 1; inter_it != current_sequence.end(); inter_it++){
            current_sum += *inter_it;
        }
        inter_it = it + 1;
        end_it = it + current_sum - 1;
        for (; inter_it != end_it; inter_it++){
            *inter_it = 1;
        }
        boundary_it = it + current_sum - 1;
        current_sum = 0;
        for (inter_it = current_sequence.begin(); inter_it != current_sequence.end(); inter_it++){
            current_sum += *inter_it;
            if (current_sum == number){
                break;
            }
            else if (current_sum > number){
                inter_it = current_sequence.end();
                break;
            }
        }
        if (inter_it != current_sequence.end()){
            current_partition = "";
            if (inter_it == current_sequence.begin()){
                current_partition = std::to_string(*inter_it);
            }
            else{
                for (it = current_sequence.begin(); it != inter_it + 1; it++){
                    if (it != current_sequence.begin() & it == inter_it){
                        current_partition += std::to_string(*it);
                    }
                    else{
                        current_partition += std::to_string(*it) + "+";
                    }
                }
            }
            if (std::find(partitions.begin(), partitions.end(), current_partition) == partitions.end()){
                partitions.push_back(current_partition);
            }
        }
    }
    for (const auto& part: partitions){
        std::cout << part << "\n";
    }
}
