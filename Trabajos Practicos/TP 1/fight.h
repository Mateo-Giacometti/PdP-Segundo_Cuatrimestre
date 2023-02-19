#pragma once

#include <stdio.h>
#include <stdbool.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"

status_t surrounded_pokemon(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c);
status_t pokemon_in_the_left_corners(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c);
status_t pokemon_in_the_right_corners(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c);
status_t pokemon_against_the_right_and_the_left_wall(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c);
status_t pokemon_against_the_top_and_the_bottom_wall(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c);
status_t special_cases(struct Pokemon **bat, struct Pokemon **new_bat, size_t rows, size_t cols);
status_t fights(struct Pokemon **bat, struct Pokemon **new_bat, size_t rows, size_t cols);
bool who_wins(struct Pokemon **bat, size_t rows, size_t cols, Pokemones *winner);