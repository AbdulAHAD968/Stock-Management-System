#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;


//* ANSI COLOR SEQUENCES. *//
#define ANSI_COLOR_RESET        "\x1b[0m "
#define ANSI_COLOR_RED          "\x1b[31m"
#define ANSI_COLOR_YELLOW       "\x1b[33m"
#define ANSI_COLOR_GREEN        "\x1b[32m"
#define ANSI_COLOR_BLUE         "\033[34m"
#define ANSI_COLOR_ORANGE       "\033[38;5;208m"
#define ANSI_COLOR_PINK         "\033[38;5;205m"
#define ANSI_COLOR_PURPLE       "\033[38;5;165m"
#define ANSI_COLOR_DARK_GREEN   "\033[38;5;22m"
#define CLEAR_SCREEN            "\x1B[2J\x1B[H"
#define ANSI_COLOR_BOLD_RED   "\033[1;31m"
#define ANSI_COLOR_BOLD_GREEN   "\033[1;32m"
#define ANSI_COLOR_BOLD_YELLOW "\033[1;33m"


// *[ CLEAR-SCREEN FUNCTION ]* //
void clearScreen(){

    cout<<CLEAR_SCREEN;  		// USING THE DEFINED FUNCTIONALITY.
}


//*ADMIN_DISPLAY_UTILITY*//
void ADMIN_PLAYS(){

    clearScreen();
    
    cout<<endl<<endl;
    cout<<ANSI_COLOR_BOLD_GREEN<<"\t  #########################################################################"<<endl;
    cout<<ANSI_COLOR_BOLD_RED<<"\t  //        __      ________  ___      ___  __   _____  ___              //"<<endl; 
    cout<<"\t  //       /  \\    |        \\|   \\    /   ||  \\ (\\    \\|   \\             //"<<endl; 
    cout<<"\t  //      /    \\   (.  ___  :)\\   \\  //   |||  ||.\\\\   \\    |            //"<<endl; 
    cout<<"\t  //     /' /\\  \\  |: \\   ) ||/\\\\  \\/.    ||:  ||: \\.   \\\\  |            //"<<endl; 
    cout<<"\t  //    //  __'  \\ (| (___\\ ||: \\.        ||.  ||.  \\    \\. |            //"<<endl; 
    cout<<"\t  //   /   /  \\\\  \\|:       :|.  \\    /:  |/\\  ||    \\    \\ |            //"<<endl; 
    cout<<"\t  //  (___/    \\___(________/|___|\\__/|___(__\\_|_\\___|\\____\\)            //"<<ANSI_COLOR_RESET<<endl; 
    cout<<ANSI_COLOR_BOLD_GREEN<<"\t  #########################################################################"<<endl<<ANSI_COLOR_RESET<<endl;

return;
}


//** COVER_TAGS */
void cover_tags(){

    clearScreen();
    cout<<endl<<endl;
    cout<<ANSI_COLOR_BOLD_RED<<"\t  _______________________________________________________________________________"<<endl;
    cout<<"\t ||_____________________________________________________________________________||"<<ANSI_COLOR_RESET<<endl;
    cout<<ANSI_COLOR_BOLD_GREEN<<"\t ||  _________ ___________.____    .____      ____________________ ________     ||"<<endl;
    cout<<"\t ||  \\_   ___ \\\\_   _____/|    |   |    |     \\______   \\______   \\\\_____  \\    ||"<<endl;
    cout<<"\t ||  /    \\  \\/ |    __)_ |    |   |    |      |     ___/|       _/ /   |   \\   ||"<<endl;
    cout<<"\t ||  \\     \\____|        \\|    |___|    |___   |    |    |    |   \\/    |    \\  ||"<<endl;
    cout<<"\t ||   \\______  /_______  /|_______ \\_______ \\  |____|    |____|_  /\\_______  /  ||"<<endl;
    cout<<"\t ||          \\/        \\/         \\/       \\/                   \\/         \\/   ||"<<endl;
    cout<<ANSI_COLOR_BOLD_RED<<"\t ||_____________________________________________________________________________||"<<endl;
    cout<<"\t |_______________________________________________________________________________|"<<ANSI_COLOR_RESET<<endl<<endl;

return ;
}


// *[ LOADING LINE FUNCTION ]* //
void LOADING_LINE(){

    clearScreen();
	
	int star = 20;
	int space = 65;
	int per = 25;
	
	clearScreen();			// CALLING THE CLEAR SCREEN FUNCTION.
	
    const char* color = ANSI_COLOR_RESET;
	cout<<"\n\n\t\t\t\t\t _____________________________________" ;
	cout<<"\n\t\t\t\t\t|                                     |";
	cout<<color<<ANSI_COLOR_RED<<"\n\t\t\t\t\t|  >>>    LOADING PLEASE WAIT     <<< |"<<ANSI_COLOR_RESET;
	cout<<"\n\t\t\t\t\t|_____________________________________|"<<endl;
	
	cout<<"\t\t "<<setfill('-')<<setw(89)<<"-"<<setfill(' ')<<endl;
	
	for(int i=0 ; i<=3 ; i++ )
	{
		Sleep(400);
		if(i==0){
			color = ANSI_COLOR_RED;
		}
		else if(i==1){
			color = ANSI_COLOR_PURPLE;
		}
		else if(i==2){
			color = ANSI_COLOR_ORANGE;
		}
		else if(i==3){
			color = ANSI_COLOR_GREEN;
		}
		
		cout<<"\t\t | "<<color<<setfill('*')<<setw(star)<<" "<<setfill(' ')<<setw(space)<<" "<<" | "<<per<<" %"<<ANSI_COLOR_RESET<<endl;
		
		star += 20 ;
		space -= 20;
		per += 25 ;
	}
	
	cout<<"\t\t "<<setfill('-')<<setw(89)<<"-"<<setfill(' ');
	
	cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t\t\t\t\t\t ___________________________" ;
	cout<<"\n\t\t\t\t\t\t|                           |";
	cout<<"\n\t\t\t\t\t\t|  >>>    COMPLETED    <<<  |";
	cout<<"\n\t\t\t\t\t\t|___________________________|\n"<<ANSI_COLOR_RESET<<endl;
		
return;
}


// *[ BUTTONS-MENU ]* //
void BUTTONS()
{
    cout<<"\n\t\t ______________________________________";
    cout<<"\n\t\t|                                      |";
    cout<<ANSI_COLOR_GREEN<<"\n\t\t| > PRESS THE BUTTON {ONE AT A TIME} < |"<<ANSI_COLOR_RESET;
    cout<<ANSI_COLOR_RED<<"\n\t\t|      __________________________      |";
    cout<<"\n\t\t|     |                          |     |";
    cout<<"\n\t\t|     |    ' 1 '   ' 2 '   ' 3 ' |     |";
    cout<<"\n\t\t|     |                          |     |";
    cout<<"\n\t\t|     |    ' 4 '   ' 5 '   ' 6 ' |     |";
    cout<<"\n\t\t|     |                          |     |";
    cout<<"\n\t\t|     |    ' 7 '   ' 8 '   ' 9 ' |     |";
    cout<<"\n\t\t|     |__________________________|     |";
    cout<<"\n\t\t|                                      |";
    cout<<"\n\t\t|______________________________________|\n\n"<<ANSI_COLOR_RESET;
		
return;
}

#endif