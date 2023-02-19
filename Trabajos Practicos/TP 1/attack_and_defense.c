#include <stdio.h>

#include "pokemons_and_damage.h"
#include "generate_battlefield.h"
#include "attack_and_defense.h"
#include "fight.h"
#include "game_maker.h"

//Type of damage that gives and receives each Pokemon
Damage fight[Pokemons][Pokemons] = {

    [Fire] = {[Fire] = low_dmg,         [Grass] = max_dmg,       [Water] = low_dmg,     [Electric] = normal_dmg,  [Ice] = max_dmg, 
              [Fighting] = normal_dmg,  [Poison] = normal_dmg,   [Ground] = max_dmg,    [Flying] = normal_dmg,    [Psychic] = normal_dmg, 
              [Bug] = max_dmg,          [Rock] = low_dmg,        [Ghost] = normal_dmg,  [Dragon] = low_dmg,       [No_type] = no_dmg},

    [Grass] = {[Fire] = low_dmg,         [Grass] = low_dmg,   [Water] = max_dmg,     [Electric] = normal_dmg,  [Ice] = normal_dmg, 
               [Fighting] = normal_dmg,  [Poison] = low_dmg,  [Ground] = max_dmg,    [Flying] = low_dmg,       [Psychic] = normal_dmg, 
               [Bug] = low_dmg,          [Rock] = max_dmg,    [Ghost] = normal_dmg,  [Dragon] = low_dmg,       [No_type] = no_dmg },

    [Water] = {[Fire] = max_dmg,         [Grass] = low_dmg,   [Water] = low_dmg,     [Electric] = normal_dmg,  [Ice] = normal_dmg, 
               [Fighting] = normal_dmg,  [Poison] = low_dmg,  [Ground] = max_dmg,    [Flying] = normal_dmg,    [Psychic] = normal_dmg, 
               [Bug] = normal_dmg,       [Rock] = max_dmg,    [Ghost] = normal_dmg,  [Dragon] = low_dmg,       [No_type] = no_dmg },

    [Electric] = {[Fire] = normal_dmg,      [Grass] = low_dmg,      [Water] = max_dmg,     [Electric] = low_dmg,  [Ice] = normal_dmg, 
                  [Fighting] = normal_dmg,  [Poison] = normal_dmg,  [Ground] = low_dmg,    [Flying] = max_dmg,    [Psychic] = normal_dmg, 
                  [Bug] = normal_dmg,       [Rock] = normal_dmg,    [Ghost] = normal_dmg,  [Dragon] = low_dmg,    [No_type] = no_dmg },

    [Ice] = {[Fire] = normal_dmg,      [Grass] = max_dmg,      [Water] = low_dmg,     [Electric] = normal_dmg,  [Ice] = low_dmg, 
             [Fighting] = normal_dmg,  [Poison] = normal_dmg,  [Ground] = max_dmg,    [Flying] = max_dmg,       [Psychic] = normal_dmg, 
             [Bug] = normal_dmg,       [Rock] = normal_dmg,    [Ghost] = normal_dmg,  [Dragon] = max_dmg,       [No_type] = no_dmg },

    [Fighting] = {[Fire] = normal_dmg,      [Grass] = normal_dmg,  [Water] = normal_dmg,   [Electric] = normal_dmg,  [Ice] = max_dmg, 
                  [Fighting] = normal_dmg,  [Poison] = low_dmg,    [Ground] = normal_dmg,  [Flying] = low_dmg,       [Psychic] = low_dmg, 
                  [Bug] = low_dmg,          [Rock] = max_dmg,      [Ghost] = normal_dmg,   [Dragon] = normal_dmg,    [No_type] = no_dmg },

    [Poison] = {[Fire] = normal_dmg,      [Grass] = max_dmg,   [Water] = normal_dmg,  [Electric] = normal_dmg,  [Ice] = normal_dmg, 
                [Fighting] = normal_dmg,  [Poison] = low_dmg,  [Ground] = low_dmg,    [Flying] = normal_dmg,    [Psychic] = normal_dmg, 
                [Bug] = max_dmg,          [Rock] = low_dmg,    [Ghost] = low_dmg,     [Dragon] = normal_dmg,    [No_type] = no_dmg },

    [Ground] = {[Fire] = max_dmg,         [Grass] = low_dmg,   [Water] = normal_dmg,   [Electric] = max_dmg,   [Ice] = normal_dmg, 
                [Fighting] = normal_dmg,  [Poison] = max_dmg,  [Ground] = normal_dmg,  [Flying] = normal_dmg,  [Psychic] = normal_dmg, 
                [Bug] = low_dmg,          [Rock] = max_dmg,    [Ghost] = normal_dmg,   [Dragon] = normal_dmg,  [No_type] = no_dmg },

    [Flying] = {[Fire] = normal_dmg,   [Grass] = max_dmg,      [Water] = normal_dmg,   [Electric] = low_dmg,   [Ice] = normal_dmg, 
                [Fighting] = max_dmg,  [Poison] = normal_dmg,  [Ground] = normal_dmg,  [Flying] = normal_dmg,  [Psychic] = normal_dmg, 
                [Bug] = max_dmg,       [Rock] = low_dmg,       [Ghost] = normal_dmg,   [Dragon] = normal_dmg,  [No_type] = no_dmg },

    [Psychic] = {[Fire] = normal_dmg,   [Grass] = normal_dmg,  [Water] = normal_dmg,   [Electric] = normal_dmg,  [Ice] = normal_dmg, 
                 [Fighting] = max_dmg,  [Poison] = max_dmg,    [Ground] = normal_dmg,  [Flying] = normal_dmg,    [Psychic] = low_dmg, 
                 [Bug] = normal_dmg,    [Rock] = normal_dmg,   [Ghost] = normal_dmg,   [Dragon] = normal_dmg,    [No_type] = no_dmg },

    [Bug] = {[Fire] = low_dmg,     [Grass] = max_dmg,    [Water] = normal_dmg,   [Electric] = normal_dmg,  [Ice] = normal_dmg, 
            [Fighting] = low_dmg,  [Poison] = max_dmg,   [Ground] = normal_dmg,  [Flying] = low_dmg,       [Psychic] = max_dmg, 
            [Bug] = max_dmg,       [Rock] = normal_dmg,  [Ghost] = low_dmg,      [Dragon] = normal_dmg,    [No_type] = no_dmg },

    [Rock] = {[Fire] = max_dmg,      [Grass] = normal_dmg,   [Water] = normal_dmg,  [Electric] = normal_dmg,  [Ice] = max_dmg, 
              [Fighting] = low_dmg,  [Poison] = normal_dmg,  [Ground] = low_dmg,    [Flying] = max_dmg,       [Psychic] = normal_dmg, 
              [Bug] = max_dmg,       [Rock] = normal_dmg,    [Ghost] = normal_dmg,  [Dragon] = normal_dmg,    [No_type] = no_dmg },


    [Ghost] = {[Fire] = normal_dmg,      [Grass] = normal_dmg,   [Water] = normal_dmg,   [Electric] = normal_dmg,  [Ice] = normal_dmg, 
               [Fighting] = normal_dmg,  [Poison] = normal_dmg,  [Ground] = normal_dmg,  [Flying] = normal_dmg,    [Psychic] = low_dmg, 
               [Bug] = normal_dmg,       [Rock] = normal_dmg,    [Ghost] = low_dmg,      [Dragon] = normal_dmg,    [No_type] = no_dmg },

    [Dragon] = {[Fire] = normal_dmg,      [Grass] = normal_dmg,   [Water] = normal_dmg,   [Electric] = normal_dmg,  [Ice] = normal_dmg, 
                [Fighting] = normal_dmg,  [Poison] = normal_dmg,  [Ground] = normal_dmg,  [Flying] = normal_dmg,    [Psychic] = normal_dmg, 
                [Bug] = normal_dmg,       [Rock] = normal_dmg,    [Ghost] = max_dmg,      [Dragon] = normal_dmg,    [No_type] = no_dmg},

    [No_type] = {[Fire] = no_dmg,      [Grass] = no_dmg,   [Water] = no_dmg,   [Electric] = no_dmg,  [Ice] = no_dmg, 
                 [Fighting] = no_dmg,  [Poison] = no_dmg,  [Ground] = no_dmg,  [Flying] = no_dmg,    [Psychic] = no_dmg, 
                 [Bug] = no_dmg,       [Rock] = no_dmg,    [Ghost] = no_dmg,   [Dragon] = no_dmg,    [No_type] = no_dmg}
};


float attack(Pokemones type_defender,Pokemones type_attacker, float life_difender){
    /*
    Calculate the damage that a Pokemon of a certain type will do to another Pokemon of a certain type.

    Parameters
    ----------
    type_defender : Pokemones
        Type of the Pokemon that will receive the attack.
    
    type_attacker : Pokemones
        Type of the Pokemon that will attack.
    
    life_difender : float
        Life of the Pokemon that will receive the attack.
    
    Returns
    -------
    new_life : float
        Pokemon Defender life after being attacked.
    */
    float new_life = life_difender - dmg[fight[type_attacker][type_defender]];

    if (new_life <= 0){
        new_life = 10;
    }

    return new_life;
}


Pokemones status(Pokemones type_defender,Pokemones type_attacker, float life_difender){
    /*
    Calculate the status of the Pokemon that will receive the attack.

    Parameters
    ----------
    type_defender : Pokemones
        Type of the Pokemon that will receive the attack.
    
    type_attacker : Pokemones
        Type of the Pokemon that will attack.
    
    life_difender : float
        Life of the Pokemon that will receive the attack.
    
    Returns
    -------
    status : Pokemones
        If the Pokemon Difender is alive, it returns its type. If it is dead, it returns Pokemon Attackers type.
    */
    
    if(life_difender == 10 && type_attacker != No_type){
        return type_attacker;
    }
    else{
        return type_defender;
    }
}