#include "HEADER.h"
#include "WAREHOUSE.h"
#include "simulator.h"

using namespace std;

int main(){

    LOADING_LINE();

    cover_tags();

    while(true){
        char choice;
        cout<<endl<<ANSI_COLOR_ORANGE<<"\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(55)<<left<<"<< ENTER THE CORRESPONDING CHARACTER TO PROCEED >> "<<"|\n";
        cout<<"\t | "<<setfill('-')<<setw(55)<<""<<setfill(' ')<<"|\n";
        cout<<"\t | "<<setw(55)<<left<<"A. WAREHOUSE STOCK MANAGEMENT "<<"|\n";
        cout<<"\t | "<<setw(55)<<left<<"B. SEARCH, ADD, REMOVE & UPDATE ANY ITEM IN STOCK"<<"|\n";
        cout<<"\t | "<<setw(55)<<left<<"C. DO PRICE BASED ANALYSIS. "<<"|\n";
        cout<<ANSI_COLOR_BOLD_RED<<"\t | "<<setw(55)<<left<<"E. EXIT [RETURN 0]. "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(57)<<"-"<<setfill(' ')<<ANSI_COLOR_RESET;
        cin>>choice;

        switch (choice)
        {
            case 'A':
            case 'a':
            {
                LOADING_LINE();
                OTHER_OPERATIONS();
                break;
            }
            break;
            case 'B':
            case 'b':
            {
                LOADING_LINE();
                STOCK_OPERATIONS();
                break;
            }
            break;
            case 'C':
            case 'c':
            {
                LOADING_LINE();
                PRICE_BASED_QUERIES();
                break;
            }
            break;
            case 'E':
            case 'e':
            {
                LOADING_LINE();
                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t -------------------------------------- \n";
                cout<<"\t |   THANK YOU FOR USING OUR SYSTEM.  |\n";
                cout<<"\t -------------------------------------- \n"<<ANSI_COLOR_RESET;
                return 0;
            }
            default:
            {
                cout<<ANSI_COLOR_BOLD_RED<<"\n\t\t--------------------------------------\n";
                cout<<"\t\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t\t----------------------------------------\n"<<ANSI_COLOR_RESET;
                break;
            }
        }
    }
    

return 0;
}