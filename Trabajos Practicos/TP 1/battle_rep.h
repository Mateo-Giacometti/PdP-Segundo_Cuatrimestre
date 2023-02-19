#pragma once

#include <stdio.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"

status_t create_folder(char *name);
status_t ppm_battlefield(struct Pokemon **bat, size_t rows, size_t cols, int turn, char *dic_name);
status_t show_battlefield_in_terminal(struct Pokemon **bat, size_t rows, size_t cols);
status_t show_ppm_battlefield_in_termina(struct Pokemon **bat, size_t rows, size_t cols);
