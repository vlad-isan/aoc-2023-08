//
// Created by Vlad Isan on 05/12/2023.
//

#include "puzzle.h"

int puzzle_sample_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_sample_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-sample-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int puzzle_1(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-1.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_1(file);
}

int puzzle_2(const std::string &base_file_path) {
    std::string file_path = fmt::format("{}/{}", base_file_path, "puzzle-input-2.txt");

    std::ifstream file(file_path);

    if (!file.is_open()) {
        fmt::println("{}", file_path);
        fmt::println("Something happened while opening the file. EAT DEEZNUTS!!!");
        fmt::println("Error {}", strerror(errno));

        return 0;
    }

    return do_puzzle_2(file);
}

int do_puzzle_1(std::ifstream &file) {
    std::string line;

    std::regex regex(R"((\b\w+\b) = \((\b\w+\b), (\b\w+\b)\))");

    std::vector<Instruction> instructions;
    NodeMap nodes;

    std::getline(file, line);

    std::for_each(line.begin(), line.end(), [&](char &c) {
        instructions.emplace_back(c == 'R' ? Instruction::RIGHT : Instruction::LEFT);
    });

    while (std::getline(file, line)) {
        for (auto it = std::sregex_iterator(line.begin(), line.end(), regex); it != std::sregex_iterator(); ++it) {
            const std::smatch &match = *it;

            nodes[match.str(1)] = std::make_pair(match.str(2), match.str(3));
        }
    }

    const std::string start = "AAA";
    const std::string end = "ZZZ";

    return get_steps_to_target(nodes, instructions, start, end);
}

int do_puzzle_2(std::ifstream &file) {
    std::string line;

    while (std::getline(file, line)) {
        fmt::println("{}", line);
    }

    return 0;
}

int get_steps_to_target(const NodeMap &node_map, std::vector<Instruction> &instructions, const std::string &start,
                        const std::string &target) {
    int steps = 0;

    if (instructions.empty() || node_map.empty()) {
        return steps;
    }

    std::string current = start;

    evil_label_suck_it:

    for (auto &instruction: instructions) {
        const auto &node = node_map.at(current);

        if (instruction == Instruction::LEFT) {
            current = node.first;
        } else {
            current = node.second;
        }

        steps++;

        if (current == target) {
            break;
        }
    }

    if (current != target) {
        goto evil_label_suck_it;
    }

    return steps;
}
