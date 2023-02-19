#include <stdio.h>
#include <stdbool.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"
#include "attack_and_defense.h"
#include "game_maker.h"
#include "attack_and_defense.h"

status_t surrounded_pokemon(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type. The Pokemon 
    that will receive the attack is completely surrounded.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    r : size_t
        Row of the Pokemon that will receive the attack.
    
    c : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((r == 0) || (c == 0)){
      return ST_ERR_INVALID_NUMBER;
    }

    new_bat[r][c].life = bat[r][c].life;
    new_bat[r][c].type = bat[r][c].type;

    
    for(size_t r1 = r-1; r1 < r+2; r1++){
        for(size_t c1 = c-1; c1 < c+2; c1++){
            
            if(r1 != r || c1 != c){
                new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
            }
        }
    }

    return ST_OK;
}

status_t pokemon_in_the_left_corners(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type. The Pokemon 
    that will receive the attack is in the left corner of the matrix and is surrounded by three Pokemons.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    r : size_t
        Row of the Pokemon that will receive the attack.
    
    c : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }


    new_bat[r][c].life = bat[r][c].life;
    new_bat[r][c].type = bat[r][c].type;

    if(r == 0){
        for(size_t r1 = r; r1 < r+2; r1++){
            for(size_t c1 = c; c1 < c+2; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    else{
        for(size_t r1 = r-1; r1 < r+1; r1++){
            for(size_t c1 = c; c1 < c+2; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    return ST_OK;
}

status_t pokemon_in_the_right_corners(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type. The Pokemon 
    that will receive the attack is in the right corner of the matrix and is surrounded by three Pokemons.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    r : size_t
        Row of the Pokemon that will receive the attack.
    
    c : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((c == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    new_bat[r][c].life = bat[r][c].life;
    new_bat[r][c].type = bat[r][c].type;

    if(r == 0){
        for (size_t r1 = r; r1 < r+2; r1++){
            for (size_t c1 = c-1; c1 < c+1; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    else{
        for(size_t r1 = r-1; r1 < r+1; r1++){
            for(size_t c1 = c-1; c1 < c+1; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    return ST_OK;
}

status_t pokemon_against_the_right_and_the_left_wall(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type. The Pokemon 
    that will receive the attack is against the wall of the matrix (right or left) and is surrounded by five Pokemons.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    r : size_t
        Row of the Pokemon that will receive the attack.
    
    c : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((r == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    new_bat[r][c].life = bat[r][c].life;
    new_bat[r][c].type = bat[r][c].type;

    if(c == 0){
        for(size_t r1 = r-1; r1 < r+2; r1++){
            for(size_t c1 = c; c1 < c+2; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }
    
    else{
        for(size_t r1 = r-1; r1 < r+2; r1++){
            for(size_t c1 = c-1; c1 < c+1; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    return ST_OK;
}

status_t pokemon_against_the_top_and_the_bottom_wall(struct Pokemon **bat, struct Pokemon **new_bat, size_t r, size_t c){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type. The Pokemon 
    that will receive the attack is against the wall of the matrix (top or bottom) and is surrounded by five Pokemons.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    r : size_t
        Row of the Pokemon that will receive the attack.
    
    c : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((c == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    new_bat[r][c].life = bat[r][c].life;
    new_bat[r][c].type = bat[r][c].type;

    if(r == 0){
        for(size_t r1 = r; r1 < r+2; r1++){
            for(size_t c1 = c-1; c1 < c+2; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    else{
        for(size_t r1 = r-1; r1 < r+1; r1++){
            for(size_t c1 = c-1; c1 < c+2; c1++){
                if(r1 != r || c1 != c){
                    new_bat[r][c].life = attack(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                    new_bat[r][c].type = status(new_bat[r][c].type, bat[r1][c1].type, new_bat[r][c].life);
                }
            }
        }
    }

    return ST_OK;
}

status_t special_cases(struct Pokemon **bat, struct Pokemon **new_bat, size_t rows, size_t cols){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type. The Pokemon 
    that will receive the attack is in special and unusual positions. The Pokemon is surrounded generally by two Pokemons.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    rows : size_t
        Row of the Pokemon that will receive the attack.
    
    cols : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */
    
    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((rows == 0) || (cols == 0)){
      return ST_ERR_INVALID_NUMBER;
    }

    new_bat[0][0].life = bat[0][0].life;
    new_bat[0][0].type = bat[0][0].type;

    if(cols == 1 && rows != 1){
        for(size_t r = 0; r < rows; r++){
            if(r == 0){
                new_bat[r][0].life = attack(new_bat[r][0].type, bat[r+1][0].type, new_bat[r][0].life);
                new_bat[r][0].type = status(new_bat[r][0].type, bat[r+1][0].type, new_bat[r][0].life);
            }
            else if(r == rows -1){
                new_bat[r][0].life = attack(new_bat[r][0].type, bat[r-1][0].type, new_bat[r][0].life);
                new_bat[r][0].type = status(new_bat[r][0].type, bat[r-1][0].type, new_bat[r][0].life);
            }
            else{
                new_bat[r][0].life = attack(new_bat[r][0].type, bat[r-1][0].type, new_bat[r][0].life);
                new_bat[r][0].type = status(new_bat[r][0].type, bat[r-1][0].type, new_bat[r][0].life);
                new_bat[r][0].life = attack(new_bat[r][0].type, bat[r+1][0].type, new_bat[r][0].life);
                new_bat[r][0].type = status(new_bat[r][0].type, bat[r+1][0].type, new_bat[r][0].life);
            }
        }
    }
    else if(cols != 1 && rows == 1){
        for(size_t c = 0; c < cols; c++){
            if(c == 0){
                new_bat[0][c].life = attack(new_bat[0][c].type, bat[0][c+1].type, new_bat[0][c].life);
                new_bat[0][c].type = status(new_bat[0][c].type, bat[0][c+1].type, new_bat[0][c].life);
            }
            else if(c == cols -1){
                new_bat[0][c].life = attack(new_bat[0][c].type, bat[0][c-1].type, new_bat[0][c].life);
                new_bat[0][c].type = status(new_bat[0][c].type, bat[0][c-1].type, new_bat[0][c].life);
            }
            else{
                new_bat[0][c].life = attack(new_bat[0][c].type, bat[0][c-1].type, new_bat[0][c].life);
                new_bat[0][c].type = status(new_bat[0][c].type, bat[0][c-1].type, new_bat[0][c].life);
                new_bat[0][c].life = attack(new_bat[0][c].type, bat[0][c+1].type, new_bat[0][c].life);
                new_bat[0][c].type = status(new_bat[0][c].type, bat[0][c+1].type, new_bat[0][c].life);
            }
        }
    }

    return ST_OK;
}

status_t fights(struct Pokemon **bat, struct Pokemon **new_bat, size_t rows, size_t cols){
    /*
    Assign the attack pattern according to the position of the pokemon in the matrix.

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.
    
    new_bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns. This matrix will be the result of the battle.

    rows : size_t
        Row of the Pokemon that will receive the attack.
    
    cols : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if((bat == NULL) || (new_bat == NULL)){
        return ST_ERR_NULL_PTR;
    }

    if((rows == 0) || (cols == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    if(rows == 1 || cols == 1){
        status_t c1 = special_cases(bat, new_bat, rows, cols);
        if(c1 != ST_OK){
            return c1;
        }
        
    }
    else{
        for(size_t r = 0; r < rows; r++){
            for(size_t c = 0; c < cols; c++){
                
                if (r == 0 && c == 0 || r == rows-1 && c == 0){
                    status_t c2 = pokemon_in_the_left_corners(bat, new_bat, r, c); 
                    if(c2 != ST_OK){
                        return c2;
                    }
                }
                else if(r == 0 && c == cols-1 || r == rows-1 && c == cols-1){
                    status_t c3 = pokemon_in_the_right_corners(bat, new_bat, r, c);
                    if(c3 != ST_OK){
                        return c3;
                    }
                }
                else if(r == 0 || r == rows-1){
                    status_t c4 = pokemon_against_the_top_and_the_bottom_wall(bat, new_bat, r, c); 
                    if(c4 != ST_OK){
                        return c4;
                    }
                }
                else if (c == 0 || c == cols-1){
                    status_t c5 = pokemon_against_the_right_and_the_left_wall(bat, new_bat, r, c); 
                    if(c5 != ST_OK){
                        return c5;
                    }
                }
                else{
                    status_t c6 = surrounded_pokemon(bat, new_bat, r, c);
                    if(c6 != ST_OK){
                        return c6;
                    }
                }
            }
        }
    }

    return ST_OK;
}

bool who_wins(struct Pokemon **bat, size_t rows, size_t cols, Pokemones *winner){
    /*
    Determines if there is a winner in the battle (only one Pokemon type in all the matrix).

    Parameters
    ----------
    bat : struct Pokemon **
        A matrix of struct Pokemon with the specified number of rows and columns.

    rows : size_t
        Number of rows of the matrix to be created.

    cols : size_t
        Number of columns of the matrix to be created.

    winner : Pokemones*
        Pointer to the type winner of the battle.

    Returns
    -------
    bool
        True if there is a winner, False otherwise.
    */
    Pokemones possible_winner = bat[0][0].type;
    for(size_t r = 0; r < rows; r++){
        for(size_t c = 0; c < cols; c++){
            if(bat[r][c].type != possible_winner){
                return false;
            }
        }
    }
    *winner = possible_winner;
    return true;
}