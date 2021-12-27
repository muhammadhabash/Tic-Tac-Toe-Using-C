/***************************************************/
/*          Author    : Muhammad Ali Habash        */            
/*          Version   : 1.0                        */
/*          Date      : 12/25/2021                 */
/*          Last Edit : N/A                        */
/***************************************************/


/***************************************************/
/*                Start Of Code                    */
/***************************************************/


/***************************************************************************************************************/
/***************************************************************************************************************/


/***************************************************/
/*                Files Inclusions                 */
/***************************************************/

#include "tic-tac-toe.h"

/***************************************************/
/*                End Of Section                   */
/***************************************************/


/***************************************************/
/*                Defined Macros                   */
/***************************************************/
        
#define  TRUE                     1
#define  FALSE                    0 
#define  NUMBER_OF_TILES          9
#define  ROW                      3
#define  COLUMN                   3
#define  WIN                      1
#define  NO_WIN_YET               0

/***************************************************/
/*                End Of Section                   */
/***************************************************/ 

/**************************************************/
/*                Functions Definitions           */
/**************************************************/

uint8_t extract_numbers (uint8_t* au8_Line)
{
	uint8_t u8_Index, u8_Number = 0, u8_Weight = 0;
	u8_Weight = strlen(au8_Line) - 2;
	for(u8_Index = 0 ; u8_Index < strlen(au8_Line) - 1 ; u8_Index++)
	{
	    u8_Number += ( (au8_Line[u8_Index] - '0' ) * pow(10,u8_Weight) );
		u8_Weight --;
    }
	return u8_Number;
}

uint8_t check_status (uint8_t* au8_Tiles)         
{
	uint8_t u8_RowIndex;
	
	for (u8_RowIndex = 0 ; u8_RowIndex < COLUMN ; u8_RowIndex++)
	{
		if(au8_Tiles[(u8_RowIndex*COLUMN) + 0] == 'X' && au8_Tiles[(u8_RowIndex*COLUMN) + 1] == 'X' && au8_Tiles[(u8_RowIndex*COLUMN) + 2] == 'X')
		{
			return WIN;
		}
	}
	
	for (u8_RowIndex = 0 ; u8_RowIndex < COLUMN ; u8_RowIndex++)
	{
		if(au8_Tiles[(u8_RowIndex*COLUMN) + 0] == 'O' && au8_Tiles[(u8_RowIndex*COLUMN) + 1] == 'O' && au8_Tiles[(u8_RowIndex*COLUMN) + 2] == 'O')
		{
			return WIN;
		}
	}
	
	for (u8_RowIndex = 0 ; u8_RowIndex < COLUMN ; u8_RowIndex++)
	{
		if(au8_Tiles[(0*COLUMN) + u8_RowIndex] == 'X' && au8_Tiles[(1*COLUMN) + u8_RowIndex] == 'X' && au8_Tiles[(2*COLUMN) + u8_RowIndex] == 'X')
		{
			return WIN;
		}
	}
	
	for (u8_RowIndex = 0 ; u8_RowIndex < COLUMN ; u8_RowIndex++)
	{
		if(au8_Tiles[(0*COLUMN) + u8_RowIndex] == 'O' && au8_Tiles[(1*COLUMN) + u8_RowIndex] == 'O' && au8_Tiles[(2*COLUMN) + u8_RowIndex] == 'O')
		{
			return WIN;
		}
	}
	
	if(au8_Tiles[0] == 'X' && au8_Tiles[4] == 'X' && au8_Tiles[8] == 'X')
		{
			return WIN;
		}
	
	if(au8_Tiles[0] == 'O' && au8_Tiles[4] == 'O' && au8_Tiles[8] == 'O')
		{
			return WIN;
		}
	
	if(au8_Tiles[2] == 'X' && au8_Tiles[4] == 'X' && au8_Tiles[6] == 'X')
		{
			return WIN;
		}
	
	if(au8_Tiles[2] == 'O' && au8_Tiles[4] == 'O' && au8_Tiles[6] == 'O')
		{
			return WIN;
		}
	
	return NO_WIN_YET;
}

uint8_t check_input_is_digit (uint8_t* au8_Line)  
{
	uint32_t u8_LiteralIndex;
	
	for(u8_LiteralIndex = 0 ; u8_LiteralIndex < strlen(au8_Line) ; u8_LiteralIndex++)
	{
		if (*(au8_Line+u8_LiteralIndex) >='A'	&& *(au8_Line+u8_LiteralIndex) <= 'z')
		{
			return 0;
		}
	}
	
    return 1;
}

void update_board (uint8_t* au8_Tiles)       
{
	uint8_t u8_RowIndex, u8_ColumnIndex, k = 0;
	
	for (u8_RowIndex = 0 ; u8_RowIndex < COLUMN ; u8_RowIndex++)
	{
		for (u8_ColumnIndex = 0 ; u8_ColumnIndex < COLUMN ; u8_ColumnIndex++)
		{
			printf("\t%c",au8_Tiles[ (u8_RowIndex*COLUMN) + u8_ColumnIndex]);
			printf("\t|");
		}
		if ( k < 2 )
		{
		    printf("\n-------------------------------------------------\n");
			k++;
		}
	}
	printf("\n\n");
}

void start_game (uint8_t u8_Choice)           
{
	uint8_t  u8_PlayerNumber     = 1;
	uint8_t  u8_Counter           = 0;
	uint8_t  u8_NoWin            = TRUE;
	uint8_t  u8_Input;
	uint8_t  u8_NoChoice;
	uint8_t  u8_IsDigit;
	uint8_t  au8_AvailableTiles[] = {1,1,1,1,1,1,1,1,1};  
	uint8_t  au8_Line[256];
	uint8_t  au8_Tokens[]          = {'X','O'};
	uint8_t  au8_Tiles[9]          = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};             

	
	while (u8_NoWin && (u8_Counter < NUMBER_OF_TILES))
	{
		u8_NoChoice = TRUE;
		printf("\nPlayer's %d turn: \n\n", u8_PlayerNumber);
		update_board(au8_Tiles);
		while (u8_NoChoice)
		{
		    printf("\nChoose where to place your token %c: ", au8_Tokens[u8_Choice - 1]);
		    fflush(stdin);                           // Clear the STDIN buffer of any previous input
		    fgets(au8_Line, sizeof(au8_Line), stdin);
		    u8_IsDigit = check_input_is_digit(au8_Line);
			
			if (u8_IsDigit)
			{
				u8_Input = extract_numbers(au8_Line);
		        if (u8_Input > 0 && u8_Input < 10)
		        {   
		            if (au8_AvailableTiles[u8_Input - 1])
				    {
				        if (u8_Input > 6)
		                {
					        u8_NoChoice = FALSE;
			                au8_Tiles[(u8_Input - 1) - 6] = au8_Tokens[u8_Choice - 1];
					        au8_AvailableTiles[(u8_Input - 1)] = 0;
		                }
			            else if(u8_Input < 4)
		                {
					        u8_NoChoice = FALSE;
			                au8_Tiles[(u8_Input - 1) + 6] = au8_Tokens[u8_Choice - 1];
					        au8_AvailableTiles[(u8_Input - 1)] = 0;
		                }
			            else
		                {
					        u8_NoChoice = FALSE;
			                au8_Tiles[(u8_Input - 1)]     = au8_Tokens[u8_Choice - 1];
					        au8_AvailableTiles[u8_Input - 1] = 0;
		                }
					    if (check_status(au8_Tiles) == WIN)
					    {
						    u8_NoWin = FALSE;
						    printf("\n");
						    update_board(au8_Tiles);
						    printf("\nToken %c Wins!!!\n", au8_Tokens[u8_Choice - 1]);
					    }
		                u8_Counter++;
		                u8_Choice        ^= 0b0011; // Toggle between X and O each game round
		                u8_PlayerNumber  ^= 0b0011; // Toggle between Player 1 and Player 2 each game round 
				    }
			        else 
				        printf("\nSelected tile is already taken. Choose another one\n");
		        }
		        else 
		        {
			        printf("\nWrong Choice !!\n");
		        }
		    }
			else 
				printf("\nWrong Choice !!\n");
		}
	}
	if (u8_NoWin)
	{
		printf("\n");
		update_board(au8_Tiles);
		printf("\nDRAW!!!\n");
	}
}
	
void game_init()                      
{
	uint8_t au8_Line[256];
	uint8_t u8_IsDigit;
	uint8_t u8_Choice;
	uint8_t u8_NoChoice = TRUE;
	
	printf("\nYour PC's numeric keypad is mapped to the tic-tac-toe game board. Use the num keypad to play. Enjoy!\n");
	printf("\n--------------------\n");
	printf("Choose player 1 token: 1- X   2- O\n");
	
	while (u8_NoChoice)
	{
		printf("\nChoice: ");
		fflush(stdin);
		fgets(au8_Line, sizeof(au8_Line), stdin);
		u8_IsDigit = check_input_is_digit(au8_Line);
		if (u8_IsDigit)
		{
			sscanf(au8_Line,"%d",&u8_Choice);
			if (u8_Choice == 1 || u8_Choice == 2)
			{
				u8_NoChoice = FALSE;
				start_game(u8_Choice);
			}
			else
			{
				printf("\nWrong choice. Choose either (1) to play with X or (2) to play with O\n");
			}
		}
		else
		{
			printf("\nWrong choice. Choose either (1) to play with X or (2) to play with O\n");
		}
	}
}
void quit_game()                      
{
	printf("\nHave a nice day!");
}

/***************************************************/
/*                End Of Section                   */
/***************************************************/


void (*interface[2])() = {game_init, quit_game};  // Array of Two Functions used to select whether to start game or quit game

uint8_t main()
{
	uint8_t au8_Line[256];
	uint8_t u8_IsDigit;
	uint8_t u8_Choice;
	uint8_t u8_NoChoice = TRUE; 
	
	printf("Welcome to tic-tac-toe game! This game is developed by Muhammad Habash\n");
	printf("\nTo start playing press (1)\nTo quit game press     (2)\n");
	
	while (u8_NoChoice)
	{
	    printf("\nChoice: ");
	    fflush(stdin);
		fgets(au8_Line, sizeof (au8_Line), stdin);
	    u8_IsDigit = check_input_is_digit(au8_Line);
	    
		if (u8_IsDigit)
	    {
			sscanf(au8_Line, "%d", &u8_Choice);
		    if (u8_Choice == 1 || u8_Choice == 2)
		    {
				u8_NoChoice = FALSE;
				interface[u8_Choice - 1]();
		    }
		    else
		    {
			    printf("\nWrong choice. Choose either (1) to play or (2) to quit\n");
		    }
	    }
		else 
		{
			printf("\nWrong choice. Choose either (1) to play or (2) to quit\n");
		}
	}
}


/***************************************************/
/*                End Of Code                      */
/***************************************************/


/***************************************************************************************************************/
/***************************************************************************************************************/

