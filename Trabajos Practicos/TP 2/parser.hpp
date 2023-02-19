#pragma once

#include <string>
#include <string.h>
#include "status.hpp"

class Parser{
    protected:
        Parser() = default;
    public:
        static Parser& getInstance();
        ~Parser(){}
        Parser(const Parser&) = delete;
        Parser(Parser&&) = delete;
        Parser& operator=(const Parser&) = delete;
        Parser& operator=(Parser&&) = delete;
        static status_t verifyArgsNumber(int argc);
        status_t static assign(int& argc, char*argv[], std:: string& csvFile,
        double& variationThreshold, int& generations, std:: string& outputFormat, 
        int& population, int& elite, double& mutation);
        static void printHelp();
};

typedef enum {
    ARG_FILE_SHORT,
    ARG_FILE_LONG,
    ARG_VARIATION_SHORT,
    ARG_VARIATION_LONG,
    ARG_GENERATIONS_SHORT,
    ARG_GENERATIONS_LONG,
    ARG_OUTPUT_SHORT,
    ARG_OUTPUT_LONG,
    ARG_MUTATION_LONG,
    ARG_MUTATION_SHORT,
    ARG_ELITE_LONG,
    ARG_ELITE_SHORT,
    ARG_POPULATION_LONG,
    ARG_POPULATION_SHORT,
} arg_t;

static const char *valid_args[] = {
    [ARG_FILE_SHORT] = "-f",
    [ARG_FILE_LONG] = "--file",
    [ARG_VARIATION_SHORT] = "-v",
    [ARG_VARIATION_LONG] = "--variation",
    [ARG_GENERATIONS_SHORT] = "-g",
    [ARG_GENERATIONS_LONG] = "--generations",
    [ARG_OUTPUT_SHORT] = "-o",
    [ARG_OUTPUT_LONG] = "--output",
    [ARG_MUTATION_LONG] = "--mutation",
    [ARG_MUTATION_SHORT] = "-m",
    [ARG_ELITE_LONG] = "--elite",
    [ARG_ELITE_SHORT] = "-e",
    [ARG_POPULATION_LONG] = "--population",
    [ARG_POPULATION_SHORT] = "-p",
};