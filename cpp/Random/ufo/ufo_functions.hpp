
#ifndef UFO_FUNCTIONS_HPP
#define UFO_FUNCTIONS_HPP

#include <string_view>


void display_misses(int misses);

void greet();

void end_game(std::string_view answer, std::string_view codeword);

void display_status(const std::vector<char>& incorrect, const std::string& answer);

#endif //UFO_FUNCTIONS_HPP
