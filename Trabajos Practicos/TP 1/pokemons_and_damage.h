#pragma once

#define white "\033[0;37m"
#define red "\033[0;31m"
#define light_red "\033[1;31m"
#define blue "\033[0;34m"
#define light_blue "\033[1;34m" 
#define pink "\033[1;35m"
#define purple "\033[35m"
#define green "\033[0;32m"
#define light_green "\033[1;32m"
#define yellow "\033[0;33m"
#define cyan "\033[1;33m"
#define cylian_claro "\033[1;36m"
#define black "\033[0;30m"
#define grey "\033[1;30m"
#define brown "\033[0;33m"

//Definition of types - Pokemons
typedef enum{Fire, Grass, Water, Electric, Ice, Fighting, Poison, Ground, Flying, Psychic, Bug, Rock, Ghost, Dragon, No_type, Pokemons} Pokemones;


static char *types[Pokemons] = {[Fire] = "Fire",          [Grass] = "Grass",    [Water] = "Water",    [Electric] = "Electric",  [Ice] = "Ice", 
                                [Fighting] = "Fighting",  [Poison] = "Poison",  [Ground] = "Ground",  [Flying] = "Flying",      [Psychic] = "Psychic", 
                                [Bug] = "Bug",            [Rock] = "Rock",      [Ghost] = "Ghost",    [Dragon] = "Dragon",      [No_type] = "No_type"};

static char *ppm_rep[Pokemons] = {[Fire] = "255 0 0 ",          [Grass] = "0 150 0 ",     [Water] = "0 0 255 ",      [Electric] = "255 255 0 ",  [Ice] = "255 255 255 ", 
                                  [Fighting] = "255 192 203 ",  [Poison] = "0 255 0 ",    [Ground] = "102 51 0 ",    [Flying] = "0 255 200 ",    [Psychic] = "255 0 255 ", 
                                  [Bug] = "51 153 51 ",         [Rock] = "128 128 128 ",  [Ghost] = "102 204 255 ",  [Dragon] = "120 0 0 ",      [No_type] = "0 0 0 "};

static char *tr_rep[Pokemons] = {[Fire] = light_red "██" white,  [Grass] = light_green "██" white,  [Water] = blue "██" white,          [Electric] = yellow "██" white,  [Ice] = white "██" white, 
                                 [Fighting] = pink "██" white,   [Poison] = green "██" white,       [Ground] = brown "██" white,        [Flying] = cyan "██" white,      [Psychic] = purple "██" white, 
                                 [Bug] = light_blue "██" white,  [Rock] = grey "██" white,          [Ghost] = cylian_claro "██" white,  [Dragon] = red "██" white,       [No_type] = black "██" white};

//Definition of types - Damage
typedef enum{max_dmg, normal_dmg, low_dmg, no_dmg, Damages} Damage;

static float dmg [Damages] = {[max_dmg] = 2, [normal_dmg] = 1, [low_dmg] = 0.5, [no_dmg] = 0 };

//Definition of structs - Pokemons
struct Pokemon{
    Pokemones type;
    float life;

};