#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "HEADER.h"
#include "WAREHOUSE.h"

//GLOBAL VARIABLE.
AVL_TREE tree;


// HELPER FUNCTION TO CHECK IF ID IS UNIQUE.
bool UNIQUE_ID(int id){
    if(tree.SEARCH (tree.root, id) != NULL){
        cerr<<ANSI_COLOR_BOLD_RED<<"\n ERROR:: ITEM WITH ID [ "<<id<<"] ALREADY EXISTS.\n"<<ANSI_COLOR_RESET;
        return 0;
    }
    return 1;
}


// HELPER FUNCTION TO CHECK IF NAME IS UNIQUE.
bool UNIQUE_NAM(string N){

    WARE_HOUSE* item=tree.SEARCH_NAME(tree.root, N);
    
    if(item!=NULL){
        cerr<<ANSI_COLOR_BOLD_RED<<"\n ERROR:: ITEM WITH NAME [ "<<N<<"] ALREADY EXISTS.\n"<<ANSI_COLOR_RESET;
        return 0;
    }
    return 1;
}


// LOCAL MAIN OF STOCK OPERATIONS.
void STOCK_OPERATIONS(){

    ADMIN_PLAYS();

    // CREATE AVL TREE AND LOAD DATA FROM CSV FILE.
    tree.LOAD_DATA_FROM_CSV("DATA.csv");

    // MAIN MENU FOR STOCK OPERATIONS.
    while(true){
        int choice;
        cout<<endl<<endl<<ANSI_COLOR_BOLD_GREEN<<"\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(30)<<left<<" [ WHAT DO YOU WANT TO DO ? ] "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(30)<<left<<" 1. ADD NEW ITEM. "<<"|\n";
        cout<<"\t | "<<setw(30)<<left<<" 2. DELETE ITEM. "<<"|\n";
        cout<<"\t | "<<setw(30)<<left<<" 3. UPDATE ITEM. "<<"|\n";
        cout<<"\t | "<<setw(30)<<left<<" 4. SEARCH ITEM. "<<"|\n";
        cout<<"\t | "<<setw(30)<<left<<" 5. DISPLAY ALL ITEMS. "<<"|\n";
        cout<<"\t | "<<setw(30)<<left<<" 6. EXIT {RETURN BACK} "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(32)<<"-"<<setfill(' ')<<ANSI_COLOR_RESET<<endl;

        cin>>choice;
        c=0;
        switch(choice){
            case 1:
            {
                WARE_HOUSE item;
                cout<<"\n ENTER ITEM ID :: ";
                cin>>item.id;
                while(!UNIQUE_ID(item.id)){
                    cout<<"\n ENTER AGAIN :: ";
                    cin>>item.id;
                }
                cout<<"\n ENTER ITEM NAME :: ";
                cin.ignore();
                getline(cin, item.name);
                while(!UNIQUE_NAM(item.name)){
                    cout<<"\n ENTER AGAIN :: ";
                    getline(cin, item.name);
                }

                cout<<"\n ENTER ITEM DESCRIPTION :: ";
                getline(cin, item.descript);
                cout<<"\n ENTER ITEM PRICE :: ";
                cin>>item.price;
                cout<<"\n ENTER ITEM QUANTITY :: ";
                cin>>item.quantity;
                while(item.quantity<0){
                    cout<<"\n QUANTITY CANNOT BE NEGATIVE.\n";
                    cout<<"\n ENTER ITEM QUANTITY :: ";
                    cin>>item.quantity;
                }
                tree.root=tree.Insert(tree.root, item);

                //WRITE DATA IN FILE AS WELL.
                fstream write("DATA.csv" , ios::out | ios::app);
                if(!write){
                    cerr<<ANSI_COLOR_BOLD_RED<<"\n ERROR:: CANNOT OPEN FILE.\n"<<ANSI_COLOR_RESET;
                    break;
                }
                item.T_price = item.price * item.quantity;
                write<<item.id<<","<<item.name<<","<<item.descript<<","<<item.price<<","<<item.quantity<<","<<item.T_price<<"\n";
                write.close();

                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t\t ------------------------------ \n";
                cout<<"\t\t |   !!!!  ITEM ADDED   !!!!  | \n";
                cout<<"\t\t ------------------------------ \n"<<ANSI_COLOR_RESET;  
                break;
            }
            case 2:
            {
                int id;
                cout<<"\n ENTER ITEM ID TO DELETE :: ";
                cin>>id;
                if(tree.SEARCH(tree.root, id)==NULL){
                    cerr<<ANSI_COLOR_BOLD_RED<<"\n ERROR:: NO ITEM FOUND WITH ID [ "<<id<<"].\n"<<ANSI_COLOR_RESET;
                    break;
                }
                tree.DEL_ITEM(id);
                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t\t -------------------------------- \n";
                cout<<"\t\t |   !!!!  ITEM DELETED   !!!!  | \n";
                cout<<"\t\t -------------------------------- \n"<<ANSI_COLOR_RESET;
                break;
            }
            case 3:
            {
                int id , quantity;
                double price;
                cout<<"\n ENTER ITEM ID TO UPDATE :: ";
                cin>>id;
                cout<<"\n ENTER THE NEW PRICE :: ";
                cin>>price;
                cout<<"\n ENTER THE NEW QUANTITY :: ";
                cin>>quantity;
                tree.UPDATE_ITEM(id, price, quantity);
                break;
            }
            case 4:
            {
                const char* color = ANSI_COLOR_RESET;
                int id;
                cout<<"\n ENTER ITEM ID TO SEARCH :: ";
                cin>>id;
                WARE_HOUSE* item=tree.SEARCH(tree.root, id);
                if(item==NULL){
                    cerr<<ANSI_COLOR_BOLD_RED<<"\n ERROR:: NO ITEM FOUND WITH ID [ "<<id<<"].\n"<<ANSI_COLOR_RESET;
                    break;
                }
                if(item->quantity == 0){
                    color = ANSI_COLOR_BOLD_RED;
                }
                else if(item->quantity < 5){
                    color = ANSI_COLOR_BOLD_YELLOW;
                }
                else{
                    color = ANSI_COLOR_BOLD_GREEN;
                }
                cout<<color<<"\n\t ------------------------------ \n";
                cout<<"\t |   ID           :: "<<item->id<<"\n";
                cout<<"\t |   NAME         :: "<<item->name<<"\n";
                cout<<"\t |   DESCRIPTION  :: "<<item->descript<<"\n";
                cout<<"\t |   PRICE        :: "<<item->price<<"\n";
                cout<<"\t |   QUANTITY     :: "<<item->quantity<<"\n";
                cout<<"\t ------------------------------ "<<ANSI_COLOR_RESET<<endl<<endl;
                break;
            }
            case 5:
            {
                tree.P_PRE_ORDER(tree.root);
                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t|                                                                              |";
                cout<<"\n\t|______________________________________________________________________________|"<<ANSI_COLOR_RESET;
                break;
            }
            case 6:
            {
                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t -------------------------------------- \n";
                cout<<"\t |   THANK YOU FOR USING OUR SYSTEM.  |\n";
                cout<<"\t -------------------------------------- \n"<<ANSI_COLOR_RESET;
                return;
            }
            default:
            {
                cout<<ANSI_COLOR_BOLD_RED<<"\n\t--------------------------------------\n";
                cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t----------------------------------------\n"<<ANSI_COLOR_RESET;
                break;
            }
        
        }//switcj ki

    }// loop ki

return;
}



// PRICE BASED QUERIES.
void PRICE_BASED_QUERIES(){

    tree.LOAD_DATA_FROM_CSV("DATA.csv");

    while(true){
        int choice;
        cout<<endl<<ANSI_COLOR_BOLD_GREEN<<"\t -"<<setfill('-')<<setw(35)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(33)<<left<<" [ WHAT DO YOU WANT TO DO ? ] "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(35)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(33)<<left<<" 1. SEARCH ITEM IN PRICE RANGE. "<<"|\n";
        cout<<"\t | "<<setw(33)<<left<<" 2. SEARCH CHEAPEST ITEM. "<<"|\n";
        cout<<"\t | "<<setw(33)<<left<<" 3. SEARCH MOST EXPENSIVE ITEM. "<<"|\n";
        cout<<"\t | "<<setw(33)<<left<<" 0. EXIT {RETURN BACK} "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(35)<<"-"<<setfill(' ')<<ANSI_COLOR_RESET<<endl;

        BUTTONS();
        cin>>choice;
        
        c=0;
        switch(choice){
            case 1:
            {
                double min_price, max_price;
                cout<<"\n ENTER MINIMUM PRICE :: ";
                cin>>min_price;
                while(min_price<=0){
                    cout<<"\n MINIMUM PRICE CANNOT BE ZERO.\n";
                    cout<<"\n ENTER MINIMUM PRICE :: ";
                    cin>>min_price;
                }
                cout<<"\n ENTER MAXIMUM PRICE :: ";
                cin>>max_price;
                while(max_price<=min_price){
                    cout<<"\n MAXIMUM PRICE CANNOT BE LESS THAN OR EQUAL TO MINIMUM PRICE.\n";
                    cout<<"\n ENTER MAXIMUM PRICE :: ";
                    cin>>max_price;
                }

                tree.SEARCH_IN_RANGE(tree.root, min_price, max_price);
                break;
            }
            case 2:
            {
                const char* color = ANSI_COLOR_BOLD_RED;
                Node* temp = NULL;
                tree.SEARCH_MIN_PRICE(tree.root , temp);
                if(temp==NULL){
                    cerr<<ANSI_COLOR_BOLD_RED<<"\n ERROR:: NO ITEMS FOUND.\n"<<ANSI_COLOR_RESET;
                    break;
                }
                else{
                    cout<<color<<"\n\t ------------------------------ \n";
                    cout<<"\t |   ID           ::  "<<temp->data.id<<"\n";
                    cout<<"\t |   NAME         ::  "<<temp->data.name<<"\n";
                    cout<<"\t |   DESCRIPTION  ::  "<<temp->data.descript<<"\n";
                    cout<<"\t |   PRICE        ::  "<<temp->data.price<<"\n";
                    cout<<"\t |   QUANTITY     ::  "<<temp->data.quantity<<"\n";
                    cout<<"\t ------------------------------ "<<ANSI_COLOR_RESET<<endl;
                }
                break;
            }
            case 3:
            {
                Node* temp = NULL;
                tree.SEARCH_MAX_PRICE(tree.root, temp);
                if(temp==NULL){
                    cerr<<"\n ERROR:: NO ITEMS FOUND.\n";
                    break;
                }
                else{
                    const char* color = ANSI_COLOR_BOLD_GREEN;

                    cout<<color<<"\n\t ------------------------------ \n";
                    cout<<"\t |   ID            ::  "<<temp->data.id<<"\n";
                    cout<<"\t |   NAME          ::  "<<temp->data.name<<"\n";
                    cout<<"\t |   DESCRIPTION   ::  "<<temp->data.descript<<"\n";
                    cout<<"\t |   PRICE         ::  "<<temp->data.price<<"\n";
                    cout<<"\t |   QUANTITY      ::  "<<temp->data.quantity<<"\n";
                    cout<<"\t ------------------------------ "<<ANSI_COLOR_RESET<<endl;
                }
                break;
            }
            case 0:
            {
                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t -------------------------------------- \n";
                cout<<"\t |   THANK YOU FOR USING OUR SYSTEM.  |\n";
                cout<<"\t -------------------------------------- \n"<<ANSI_COLOR_RESET;
                return;
            }
            default:
            {
                cout<<ANSI_COLOR_BOLD_RED<<"\n\t--------------------------------------\n";
                cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t----------------------------------------\n"<<ANSI_COLOR_RESET;
                break;
            }
        }// switch
    }// loop
}



// SOME OTHER OPERATIONS.
void OTHER_OPERATIONS(){
    tree.LOAD_DATA_FROM_CSV("DATA.csv");

    while(true){
        int choice;
        cout<<ANSI_COLOR_BOLD_GREEN<<"\t -"<<setfill('-')<<setw(34)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(32)<<left<<" [ WHAT DO YOU WANT TO DO ? ] "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(34)<<"-"<<setfill(' ')<<endl;
        cout<<"\t | "<<setw(32)<<left<<" 1. SEARCH ITEM IN WAREHOUSE. "<<"|\n";
        cout<<"\t | "<<setw(32)<<left<<" 2. LIST LOWER QUANTITY ITEMS. "<<"|\n";
        cout<<"\t | "<<setw(32)<<left<<" 3. REFILL ITEMS. "<<"|\n";
        cout<<"\t | "<<setw(32)<<left<<" 0. EXIT {RETURN BACK} "<<"|\n";
        cout<<"\t -"<<setfill('-')<<setw(34)<<"-"<<setfill(' ')<<ANSI_COLOR_RESET<<endl;
        BUTTONS();
        cin>>choice;
        c=0;
        switch(choice){
            case 1:
            {
                int id;
                cout<<"\n ENTER ID :: ";
                cin>>id;
                WARE_HOUSE *h;
                h = tree.SEARCH(tree.root, id);
                if(h==NULL){
                    cerr<<"\n ERROR:: NO SUCH ITEM FOUND.\n";
                    break;
                }
                else{
                    const char* color = ANSI_COLOR_RESET;

                    if(h->quantity == 0){
                        color = ANSI_COLOR_BOLD_RED;
                    }
                    else if(h->quantity < 5){
                        color = ANSI_COLOR_BOLD_YELLOW;
                    }
                    else{
                        color = ANSI_COLOR_BOLD_GREEN;
                    }
                    cout<<color<<"\n\t ------------------------------ \n";
                    cout<<"\t |   ID          :: "<<h->id<<"\n";
                    cout<<"\t |   NAME        :: "<<h->name<<"\n";
                    cout<<"\t |   DESCRIPTION :: "<<h->descript<<"\n";
                    cout<<"\t |   PRICE       :: "<<h->price<<"\n";
                    cout<<"\t |   QUANTITY    :: "<<h->quantity<<"\n";
                    cout<<"\t ------------------------------ "<<ANSI_COLOR_RESET<<endl<<endl;
                }
                break;
            }
            case 2:
            {
                tree.LIST_LOWER_QUANTITY_ITEMS(tree.root);
                break;
            }
            case 3:
            {
                tree.REFILL_ITEMS(tree.root);

                // UPDATE DATA IN FILE AS WELL.
                fstream write("DATA.csv" , ios::out | ios::trunc);
                if(!write){
                    cerr<<"\n ERROR:: COULD NOT OPEN FILE.\n";
                    break;
                }
                else{
                    write<<tree.root->data.id<<","<<tree.root->data.name<<","<<tree.root->data.descript<<","<<tree.root->data.price<<","<<tree.root->data.quantity<<"\n";
                    tree.W_IN_ORDER(tree.root, write);
                    write.close();
                }
                break;
            }
            case 0:
            {
                cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t -------------------------------------- \n";
                cout<<"\t |   THANK YOU FOR USING OUR SYSTEM.  |\n";
                cout<<"\t -------------------------------------- \n"<<ANSI_COLOR_RESET<<endl;
                return;
            }
            default:
            {
                cout<<ANSI_COLOR_BOLD_RED<<"\n\t--------------------------------------\n";
                cout<<"\t|   !!!!  ENTER A  VALID  INPUT  !!!!  |\n";
                cout<<"\t----------------------------------------\n"<<ANSI_COLOR_RESET<<endl;
                break;
            }
        
        }//switch
    }//loop

return;
}


#endif