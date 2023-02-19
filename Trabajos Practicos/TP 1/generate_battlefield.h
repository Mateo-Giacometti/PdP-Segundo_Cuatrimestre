#pragma once

#include <stdio.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"

status_t battlefield(struct Pokemon ***bat, size_t rows, size_t cols);
status_t full_battlefield(struct Pokemon **bat, size_t rows, size_t cols, int seed);
