#include <stdio.h>
#include <stdbool.h>

#define TAB_SIZE	8 		/* Defines the number of spaces per tab */
#define INPUT_SIZE	1001		/* The max length of user input ( including the null terminator ) */

int readUserInput( char[], bool* );
void expandTabs( char[], char[] );

int main( int argc, char **argv )
{
	char userInput[ INPUT_SIZE ];					// stores the user raw input ( before tab expansion )
	char expandedOutput[ TAB_SIZE * INPUT_SIZE ];	// stores the processed string( large enough to handle expanded tabs ), where tabs are replaced with spaces.
	bool isEOF = false;								// tracks EOF( End Of File ) to exit the loop.
	int inputLength = 0; 							// stores the length of the user input.
	
	while( !isEOF )
	{
		printf("Enter the input...\n");
		
		inputLength = readUserInput( userInput, &isEOF );
		
		if( inputLength == INPUT_SIZE )
			printf("\nInput truncated to %d characters...", INPUT_SIZE - 1);
			
		if( inputLength )
		{
			expandTabs( userInput, expandedOutput );
			printf("\nThe output :\n%s\n", expandedOutput);
						
		}else if( ( inputLength == 0 ) && !isEOF )
			printf("\nEmpty input...\n");
			
		printf("\n\n");
	}	
	
	printf("Terminating the application...\n");
	
	return 0;
} 


/* 
	- Converts tabs( \t ) into spaces.
	- Maintains correct alignment according to TAB_SIZE. 
*/
void expandTabs( char input[], char output[] )
{
	int inputIndex = 0;
	int cursorPosition = 0;
	int outputIndex = 0;
	int spacesToAdd = 0;
	
	while( input[ inputIndex ] != '\0' )
	{
		if( input[ inputIndex ] == '\t' )
		{
			spacesToAdd = TAB_SIZE - ( cursorPosition % TAB_SIZE );
			cursorPosition += spacesToAdd;
			
			for( int i = 0; i < spacesToAdd; i++ )
				output[ outputIndex++ ] = ' ';
				
			++inputIndex;
			
		}else
		{
			output[ outputIndex++ ] = input[ inputIndex++ ];
			++cursorPosition;
		}
			
	}
	
	output[ outputIndex ] = '\0';
}


/*	- Reads input from the user.
	- Stops reading at INPUT_SIZE - 1 to prevent overflow.
	- If EOF is detected, isEOF is set to true, and the function exits.
	- Trims extra characters beyond INPUT_SIZE - 1
*/
int readUserInput( char input[], bool *isEOF )
{
	int ch, charCount = 0;
	
	if((( ch = getchar()) == EOF ))
	{
		( *isEOF ) = true;
		return 0;
		
	}else if( ch == '\n' )
		return 0;

	input[ charCount++ ] = ch;	
	
	while((( ch = getchar()) != EOF ) && ( ch != '\n' ) && ( charCount < ( INPUT_SIZE - 1 ) ))
		input[ charCount++ ] = ch;
	
	input[ charCount ] = '\0';
	
	if(( ch != EOF ) && ( ch != '\n' ))
		++charCount;
	
	while(( ch != '\n' ) && (( ch = getchar()) != EOF ) && ( ch != '\n' ));
	
	return charCount;
}
