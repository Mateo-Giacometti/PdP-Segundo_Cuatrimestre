#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"

status_t play(size_t rows, size_t cols, int ppm_num, int seed, int cycles, bool term_repr, bool ppm_tr);