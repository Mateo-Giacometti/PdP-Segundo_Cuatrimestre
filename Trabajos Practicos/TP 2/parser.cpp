#include "parser.hpp"
#include <iostream>
#include <fstream>

Parser& Parser::getInstance(){
    static Parser instance;
    return instance;
}

status_t Parser::verifyArgsNumber(int argc){
    if (argc < 7) {return ST_ERR_INSUFFICIENT_ARGUMENTS;}
    if (argc > 15) {return ST_ERR_TOO_MANY_ARGUMENTS;}
    return ST_OK;
}

status_t Parser::assign(int& argc, char*argv[], std:: string& csvFile,
double& variationThreshold, int& generations, std:: string& outputFormat,
int& population, int& elite, double& mutation){

    char *pend = NULL;
    int arg;
    bool csvFileProcessed = false;

    if((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--help") == 0)){
        printHelp();
        return ST_HELP;
    }

    if (verifyArgsNumber(argc) != ST_OK) {
        std::cout << err_to_str(ST_ERR_INSUFFICIENT_ARGUMENTS) << std::endl;
        return ST_ERR_INSUFFICIENT_ARGUMENTS;
    }

    for (int i = 1; i < argc - 1; ++i) {
        for (arg = 0; arg < int(sizeof(valid_args)) / int(sizeof(valid_args[0])); ++arg) {
            if (0 == strcmp(argv[i], valid_args[arg])) {break;}
        }
        switch (arg) {
            case ARG_FILE_SHORT:
            case ARG_FILE_LONG:{
                i++;
                csvFile = argv[i];
                int position = csvFile.find (".csv");
                if (position == std::string::npos) {
                    std::cout << err_to_str(ST_ERR_INVALID_ARG) << std::endl;
                    return ST_ERR_INVALID_ARG;
                }
                std::ifstream infile(csvFile);
                if (!infile.good()) {
                std::cout << err_to_str(ST_ERR_FILE_NOT_FOUND) << std::endl;
                return ST_ERR_FILE_NOT_FOUND;
                }
                csvFileProcessed = true;}
                break;
            case ARG_VARIATION_SHORT:
            case ARG_VARIATION_LONG:
                i++;
                variationThreshold = strtod(argv[i], &pend);
                if (pend == argv[i] || variationThreshold < 0) {
                    std::cout << err_to_str(ST_ERR_INVALID_VARIATION_THRESHOLD) << std::endl;
                    return ST_ERR_INVALID_VARIATION_THRESHOLD;
                }
                break;
            case ARG_GENERATIONS_SHORT:
            case ARG_GENERATIONS_LONG:
                i++;
                generations = strtol(argv[i], &pend, 10);
                if (pend == argv[i] || generations < 1) {
                    std::cout << err_to_str(ST_ERR_INVALID_GENERATIONS) << std::endl;
                    return ST_ERR_INVALID_GENERATIONS;
                }
                break;
            case ARG_OUTPUT_SHORT:
            case ARG_OUTPUT_LONG:
                i++;
                outputFormat = argv[i];
                if (outputFormat != "graphic" && outputFormat != "none") {
                    std::cout << err_to_str(ST_ERR_INVALID_OUTPUT_FORMAT) << std::endl;
                    return ST_ERR_INVALID_OUTPUT_FORMAT;
                }
                break;
            case ARG_MUTATION_LONG:
            case ARG_MUTATION_SHORT:
                i++;
                mutation = strtod(argv[i], &pend);
                if (pend == argv[i] || mutation < 0 || mutation > 1) {
                    std::cout << err_to_str(ST_ERR_INVALID_MUTATION) << std::endl;
                    return ST_ERR_INVALID_MUTATION;
                }
                break;
            case ARG_POPULATION_LONG:
            case ARG_POPULATION_SHORT:
                i++;
                population = strtol(argv[i], &pend, 10);
                if (pend == argv[i] || population < 1) {
                    std::cout << err_to_str(ST_ERR_INVALID_POPULATION) << std::endl;
                    return ST_ERR_INVALID_POPULATION;
                }
                break;
            case ARG_ELITE_LONG:
            case ARG_ELITE_SHORT:
                i++;
                elite = strtol(argv[i], &pend, 10);
                if (pend == argv[i] || elite < 0) {
                    std::cout << err_to_str(ST_ERR_INVALID_ELITE) << std::endl;
                    return ST_ERR_INVALID_ELITE;
                }
                break;
            default:
                return ST_ERR_UNKNOWN_ARGUMENT;           
        }
    }
    if (population < elite){
        std::cout << err_to_str(ST_ERR_INVALID_ELITE) << std::endl;
        return ST_ERR_INVALID_ELITE;
    }

    if (!csvFileProcessed) {
        return ST_ERR_FILE_NOT_FOUND;
    }

    return ST_OK;
}

void Parser::printHelp(){
    std::cout <<"--help, -h:   Prints a help and ends the execution of the program." << std::endl;
    std::cout <<"-f, --file:   Path to the csv file with the cities." << std::endl;
    std::cout <<"-v, --variation:   Rate of change between the solutions of a generation of routes and the previous ones." << std::endl;
    std::cout <<"-g, --generations:   Number of generations for the genetic algorithm." << std::endl;
    std::cout <<"-o, --output:   Output format for the genetic algorithm solutions." << std::endl;
    std::cout <<"-p, --population:   Population size for the genetic algorithm." << std::endl;
    std::cout <<"-e, --elite:   Elite size for the genetic algorithm." << std::endl;
    std::cout <<"-m, --mutation:   Mutation rate for the genetic algorithm." << std::endl;
}