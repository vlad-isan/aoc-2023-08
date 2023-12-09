//
// Created by Vlad Isan on 05/12/2023.
//

#ifndef PUZZLE_H
#define PUZZLE_H

#include <algorithm>
#include <array>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <ranges>
#include <regex>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>

#include "fmt/core.h"

using NodeMap = std::unordered_map<std::string, std::pair<std::string, std::string>>;

enum class Instruction {
    LEFT,
    RIGHT
};


int puzzle_sample_1(const std::string &base_file_path);

int puzzle_sample_2(const std::string &base_file_path);

int puzzle_1(const std::string &base_file_path);

int puzzle_2(const std::string &base_file_path);

int do_puzzle_1(std::ifstream &file);

int do_puzzle_2(std::ifstream &file);

int get_steps_to_target(const NodeMap &node_map, std::vector<Instruction> &instructions, const std::string &start, const std::string &target);

#endif //PUZZLE_H
