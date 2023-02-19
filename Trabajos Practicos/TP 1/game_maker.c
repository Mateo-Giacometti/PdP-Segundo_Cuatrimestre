#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#include "pokemons_and_damage.h"
#include "args_and_errors.h"
#include "attack_and_defense.h"
#include "generate_battlefield.h"
#include "battle_rep.h"
#include "fight.h"
#include "game_maker.h"

status_t free_battlefield(struct Pokemon ***bat, size_t rows, size_t cols){
    /*
    This function frees the memory allocated for the battlefield.

    Parameters
    ----------
    bat : struct Pokemon ***
        A matrix of struct Pokemon with the specified number of rows and columns.

    r : size_t
        Row of the Pokemon that will receive the attack.
    
    c : size_t
        Column of the Pokemon that will receive the attack.
    
    Returns
    -------
    status_t
    */

    if(bat == NULL){
        return ST_ERR_NULL_PTR;
    }

    if((rows == 0) || (cols == 0)){
        return ST_ERR_INVALID_NUMBER;
    }

    struct Pokemon **_bat_f;

    if (bat) {
        _bat_f = *bat;
        while (rows--) {
            free(_bat_f[rows]);
        }
        free(_bat_f);
        *bat = NULL;
    }

    return ST_OK;
}

status_t play(size_t rows, size_t cols, int ppm_num, int seed, int cycles, bool term_repr, bool ppm_tr){
    /*
    Plays the Pokemon's battle.

    Parameters
    ----------
    rows : size_t
        Number of rows of the matrix to be created.
    
    cols : size_t
        Number of columns of the matrix to be created.
    
    ppm_num : int
        Number of turns in when PPM files will be generated.

    seed : int
        Seed to generate random numbers.
    
    cycles : int
        Number of turns in the battle.
    
    term_repr : bool
        True if the representation of the battlefield in the terminal is desired, False otherwise.
    
    ppm_tr : bool
        True if the representation of the battlefield in PPM representation is desired, False otherwise.
    
    Returns
    -------
    status_t
    */
    
    char direc_name[20] = "PPM_files";
    Pokemones winner;
    struct Pokemon **old_battlefield;
    struct Pokemon **new_battlefield;
    status_t c1 = battlefield(&old_battlefield, rows, cols);
    if(c1 != ST_OK){
        return c1;
    }

    status_t c2 = battlefield(&new_battlefield, rows, cols);
    if(c2 != ST_OK){
        return c2;
    }

    status_t c3 = full_battlefield(old_battlefield,rows,cols,seed);
    if(c3 != ST_OK){
        return c3;
    }

    if((ppm_num != 0)){
        status_t file = create_folder(direc_name);
        if(file != ST_OK){
            return file;
        }
    }
        
    if((ppm_num != 0) && (ppm_num != -1)){
        status_t ppm = ppm_battlefield(old_battlefield,rows,cols,0,direc_name);
            if(ppm != ST_OK){
                return ppm;
            }
    }

    if(term_repr == true){
       status_t show = show_battlefield_in_terminal(old_battlefield,rows,cols);
        if(show != ST_OK){
            return show;
        }

       sleep(1);
    }

    if(ppm_tr == true){
        status_t pm = show_ppm_battlefield_in_termina(old_battlefield,rows,cols);
        if(pm != ST_OK){
            return pm;
        }
    }

    status_t c4 = fights(old_battlefield,new_battlefield,rows,cols);
    if(c4 != ST_OK){
        return c4;
    }

    if((ppm_num != 0) && (ppm_num != -1) && (1 % ppm_num == 0)){
        status_t ppm2 = ppm_battlefield(new_battlefield,rows,cols,1,direc_name);
        if(ppm2 != ST_OK){
            return ppm2;
        }
    }

    if(term_repr == true){
        status_t show2 = show_battlefield_in_terminal(new_battlefield,rows,cols);
        if(show2 != ST_OK){
            return show2;
        }
        sleep(1);
    }

    if(ppm_tr == true){
        status_t pm2 = show_ppm_battlefield_in_termina(old_battlefield,rows,cols);
        if(pm2 != ST_OK){
            return pm2;
        }
    }

    for(int i = 2; i <= cycles; i++){
        old_battlefield = new_battlefield;
        status_t f = fights(old_battlefield,new_battlefield,rows,cols);
        if(f != ST_OK){
            return f;
        }
        if((ppm_num != 0) && (ppm_num != -1) && (i % ppm_num == 0)){
            status_t ppmf = ppm_battlefield(new_battlefield,rows,cols,i,direc_name);
            if(ppmf != ST_OK){
                return ppmf;
            }
        }
        if(term_repr == true){
           status_t show_f = show_battlefield_in_terminal(new_battlefield,rows,cols);
            if(show_f != ST_OK){
                return show_f;
            }
           sleep(1);
        }
        if(ppm_tr == true){
            status_t pmf = show_ppm_battlefield_in_termina(old_battlefield,rows,cols);
            if(pmf != ST_OK){
                return pmf;
            }
        }
        if(who_wins(new_battlefield,rows,cols,&winner) == true){
            printf("The winners are the Pokemons type %s\n",types[winner]);
            if((ppm_num != 0) && (ppm_num != -1)){
                status_t ppmf = ppm_battlefield(new_battlefield,rows,cols,i,direc_name);
                if(ppmf != ST_OK){
                    return ppmf;
                }
            }
            break;
        }
        if((ppm_num == -1) && (i == cycles)){
            status_t ppmff = ppm_battlefield(new_battlefield,rows,cols,cycles,direc_name);
            if(ppmff != ST_OK){
                return ppmff;
            }
        } 
    }

   
    if(ppm_num == -1){
        status_t ppmff = ppm_battlefield(new_battlefield,rows,cols,cycles,direc_name);
        if(ppmff != ST_OK){
            return ppmff;
        }
    } 

    status_t free = free_battlefield(&new_battlefield, rows,cols); 
    if(free != ST_OK){
        return free;
    }

    puts("The game has ended"); 
    
    return ST_OK;
}