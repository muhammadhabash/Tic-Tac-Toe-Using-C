#ifndef __TIC_TAC_TOE_H__
#define __TIC_TAC_TOE_H__

/***************************************************/
/*                Files Inclusions                 */
/***************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "STD_types.h"

/***************************************************/
/*                End Of Section                   */
/***************************************************/


/***************************************************/
/*                Functions Prototypes             */
/***************************************************/

uint8_t check_input_is_digit(uint8_t*);             // This function returns 0 if input argument have any literals, if input argument consists only of digits it will return 1
void    game_init           (void);                 // In this function player 1 will choose his token whether X or O
void    quit_game           (void);                 // This function quits the game
void    start_game          (uint8_t);              // This function starts the game
uint8_t check_status        (uint8_t*);             // This function takes the tiles array as input and checks whether there is a win case or not 
void    update_board        (uint8_t*);             // This function takes the tiles array as input and updates it each game turn    
uint8_t extract_numbers     (uint8_t* u8_Line);     // This function transforms entered numbers in form of string to normal integer number

/***************************************************/
/*                End Of Section                   */
/***************************************************/

#endif  