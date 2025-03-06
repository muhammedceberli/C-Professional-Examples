	#include <stdio.h>
	#include <stdbool.h>
	
	#define TAB_SIZE	8
	#define ARRAY_SIZE	1001	// Maximum input length is ARRAY_SIZE - 1
	
	int readInputLine( char[], bool* );
	void entab( char[], int* len );
	
	int main( int argc, char** argv )
	{
		char input[ ARRAY_SIZE ];		// Buffer to store the input string
		bool isEOF = false;			// Flag to check if input reaches EOF
		int len = 0;				// Stores length of the input
		
		while( !isEOF )
		{
			// Read input from the user and process only if it's within bounds
			if((( len = readInputLine( input, &isEOF )) > 0 ) && ( len < ARRAY_SIZE ))
			{
				printf("\nOriginal:\n%s\n", input);
				printf("Length before entab: %d\n\n", len);
				
				// Convert spaces to tabs
				entab( input, &len );
				
				printf("Entabbed:\n%s\n", input);
				printf("Length after entab: %d\n\n", len);
				
			}else if( len >= ARRAY_SIZE )
				printf("Limit exceeded\n");
			
			else if( !isEOF )
				printf("Input is empty\n");
			
			else
				printf("Program terminating\n");
			
		}
		
		return 0;
	}
	
	
	/*
	 *	Converts spaces into tabs where possible,
	 *	aligning text with tab stops.
	*/
	void entab( char text[], int* len )
	{
		int index = 0;			// Current position in the string
		int shiftIndex = 0;		// Used for shifting characters left after inserting a tab
		int postTabIndex = 0;		// Stores the position right after inserting a tab
		int column = 1;			// Keeps track of the current column ( for tab stops )
		int spaceCount = 0;		// Number of consecutive spaces encountered
			
		while( text[ index ] != '\0' )
		{
			if( text[ index ] == ' ' )
			{
				++spaceCount;
				
				// if spaces reach a tab stop, replace with a tab.
				if( spaceCount && !( column % TAB_SIZE ))
				{
					
					shiftIndex = index + 1;			// Start shifting from next character
					index -= ( spaceCount - 1 );		// Move back to where tab will be placed
					text[ index++ ] = '\t';			// Insert tab
					postTabIndex = index;			// Store position after tab
					
					// Shift remaining characters to the left
					while(( text[ index++ ] = text[ shiftIndex++ ]) != '\0' );
					
					// Reset counters after inserting tab
					index = postTabIndex;
					spaceCount = 0;
					column = 1;
					
				}else
				{
					++index;
					++column;
				}
				
			}else
			{
				spaceCount = 0;
				++index;
				++column;
			}		
		}
		
		// update the new length after entabbing
		( *len ) = index;
		
	}
	
	
	/*
	 *	Reads a line of input from the user, storing it in 'input'.
	 *	Returns the length of the input string.
	 *	If EOF is reached, sets isEOF is true.
	*/
	int readInputLine( char input[], bool *isEOF )
	{
		int ch, len = 0;
		
		// Read first character
		if(( ch = getchar()) == EOF )
		{
			( *isEOF ) = true;
			return 0;
			
		}else if( ch == '\n' )
			return 0;
			
		input[ len++ ] = ch;
		
		// Read remaining characters up to ARRAY_SIZE - 1		
		while((( ch = getchar()) != EOF ) && ( len < ( ARRAY_SIZE - 1 )) && ( ch != '\n' ))
			input[ len++ ] = ch;
			
		// Null-terminate string
		input[ len ] = '\0';
		
		// If input is longer than allowed, discard remaining characters
		if(( ch != EOF ) && ( ch != '\n' ))
		{
			++len;
			
			while((( ch = getchar()) != EOF ) && ( ch != '\n' ))
				++len;	
		}
		
		return len;
	}
