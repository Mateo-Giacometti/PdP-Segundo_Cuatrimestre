#include <stdio.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"

status_t argparse(int argc, char *argv[], size_t *cols, size_t *rows, int *ppm_num, int *seed, int *cycles, bool *term_repr, bool *ppm_tr);