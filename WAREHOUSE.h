#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "HEADER.h"
// BOTH THE CLASSES [WAREHOUSE, AVL_TREE ARE DECLEARED AND DEFINED HERE.]
// I HAVE USED THE APPROACH OF OUT_LINE CLASS DEFINITIONS. {YOU CAN DEFINE THEM INLINE AS WELL}

static int c=0;

//MAIN WAREHOUSE CLASS [ALL OTHER ARE ITS UTILITIES]
class WARE_HOUSE{

    public:

        string name;
        string descript;
        double price;
        int id;
        double T_price;
        int quantity;

    public:

        // DEFAULT CONSTRUCTOR. NOT TAKING ANY VALUE HERE, WILL LOAD FROM FILE LEATER ON.
        WARE_HOUSE(){
            this->id=0;
            this->price=0;
            this->T_price=0;
            this->quantity=0;
            this->name="";
            this->descript="";
        }

        // DESTRUCTOR.
        ~WARE_HOUSE(){
            //cout<<"WAREHOUSE Help_DeleteD"<<endl;
        }

};


//** NODE CLASS FOR AVL TREE. */
class Node{

    public:
        WARE_HOUSE data;
        Node* left;
        Node* right;
        int HEIGHT;

    public:

        // CONSTRUCTORS
        Node(WARE_HOUSE &data){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
            this->HEIGHT=1;
        }

        ~Node(){
            //cout<<"NODE Help_DeleteD"<<endl;
        }

};


//** CLASS OF AVL-TREE */
class AVL_TREE{

    public:

        Node* root;
    
    public:
    
        // CONSTRUCTORS
        AVL_TREE(){
            this->root=NULL;
        }

        // HEIGHT FUNCTION TO GET HEIGHT OF AVL TREE
        int GET_HEIGHT(Node* node){
            if(node==NULL){
                return 0;
            }
            return node->HEIGHT;
        }


        // LEFT ROTATE FUNCTION
        Node* R_LEFT(Node* y);


        // RIGHT ROTATE FUNCTION
        Node* R_RIGHT(Node* x);


        // INSERT FUNCTION TO ADD ITEM OF AVL TREES
        Node* Insert(Node* node, WARE_HOUSE &data);


        // READ DATA FROM CSV FILE IN TREE.
        void LOAD_DATA_FROM_CSV(const string &filePath);


        // SEARCH FUNCTION TO FIND AN ITEM IN TREE [BASED ON ID PARAMETERS].
        WARE_HOUSE* SEARCH(Node* node, int id);


        // SEARCH FUNCTION TO FIND AN ITEM IN TREE [BASED ON ID PARAMETERS].
        WARE_HOUSE* SEARCH_NAME(Node* node, string N);


        // GET MINIMUM NODE FUNCTION FOR DELETING. [aik right-> or phir extreme left]
        Node* All_LEFT(Node* node);


        // HELPER FUNCTION FOR DELETING ITEMS.
        Node* Help_Delete(Node* root, int id);


        // WRITING IN IN-ORDER FORMAT.
        void W_IN_ORDER(Node* temp , fstream &write);


        // FUNCTION TO REMOVE AN ITEM FROM TREE.
        void DEL_ITEM(int id);


        //UPDATE FUNCTION TO UPDATE AN ITEM [PRICE, QUANTITY] BASED ON ID.
        void UPDATE_ITEM(int Id, double Price, int Quantity);


        //PRINT COLUMNS TITLES.
        void P_COLUMNS();


        // PRINT FUNCTION FOR TREE [PRE-ORDERED]
        void P_PRE_ORDER(Node* temp);


        //LIST ITEMS WHICH ARE LOWER IN QUANTITY.
        void LIST_LOWER_QUANTITY_ITEMS(Node* temp);

        // REFILL ITEMS.
        void REFILL_ITEMS(Node* temp);

        //SEARCH ITEM WITHIN A PRICE RANGE.
        void SEARCH_IN_RANGE(Node* temp, double min, double max);

        // SEE ITEM WITH MAXIMUM PRICE
        void SEARCH_MAX_PRICE(Node* temp , Node* &alpha);

        // SEARCH ITEM WITH MINIMUM PRICE
        void SEARCH_MIN_PRICE(Node* temp , Node* &alpha);


        // HELP DELETION FUNCTION
        void HELP_ME(Node* temp);

        // DESTRUCTORS
        ~AVL_TREE();

};


// -------------------- {FUNCTIONS ARE DEFINED BELOW} -----------------\\\\



//LIST ITEMS WHICH ARE LOWER IN QUANTITY.
void AVL_TREE :: LIST_LOWER_QUANTITY_ITEMS(Node* temp){
    if(temp == NULL){
        return;
    }
    if(temp->data.quantity < 10){
        cout<<ANSI_COLOR_BOLD_YELLOW<<setw(5)<<temp->data.id<<setw(10)<<temp->data.name<<setw(10)<<temp->data.descript<<setw(5)<<temp->data.price<<setw(5)<<temp->data.quantity<<ANSI_COLOR_RESET<<endl;
    }
    LIST_LOWER_QUANTITY_ITEMS(temp->left);
    LIST_LOWER_QUANTITY_ITEMS(temp->right);
}

// REFILL ITEMS.
void AVL_TREE :: REFILL_ITEMS(Node* temp){
    if(temp == NULL){
        return;
    }
    if(temp->data.quantity < 10){
        temp->data.quantity = 50;
        temp->data.T_price = temp->data.quantity * temp->data.price;
    }
    REFILL_ITEMS(temp->left);
    REFILL_ITEMS(temp->right);
}


// SEE ITEM WITH MAXIMUM PRICE
void AVL_TREE::SEARCH_MAX_PRICE(Node* temp, Node*& alpha){
    if(temp == NULL){
        return;
    }

    if(alpha == NULL || temp->data.price > alpha->data.price){
        alpha = temp;
    }

    SEARCH_MAX_PRICE(temp->left, alpha);
    SEARCH_MAX_PRICE(temp->right, alpha);
}


// SEARCH ITEM WITH MINIMUM PRICE
void AVL_TREE::SEARCH_MIN_PRICE(Node* temp, Node*& min){
    
    if(temp == NULL){
        return;
    }

    if(min == NULL || temp->data.price < min->data.price){
        min = temp;
    }

    SEARCH_MIN_PRICE(temp->left, min);
    SEARCH_MIN_PRICE(temp->right, min);
}




//SEARCH ITEM WITHIN A PRICE RANGE.
void AVL_TREE :: SEARCH_IN_RANGE(Node* temp, double min, double max){
    if(temp==NULL){
        return;
    }
    if(temp->data.price >= min && temp->data.price <= max){
        cout<<ANSI_COLOR_PURPLE<<"\n ID = "<<temp->data.id<<"  :: NAME = "<<temp->data.name<<"  :: PRICE = "<<temp->data.price<<"  :: QUANTITY = "<<temp->data.quantity<<ANSI_COLOR_RESET<<endl;
    }
    SEARCH_IN_RANGE(temp->left, min, max);
    SEARCH_IN_RANGE(temp->right, min, max);

return;
}


// LEFT ROTATE FUNCTION
Node* AVL_TREE :: R_LEFT(Node* y){

    Node* x = y->right;
    Node* T2 = x->left;

    x->left = y;
    y->right = T2;

    y->HEIGHT = 1 + max(GET_HEIGHT(y->left) , GET_HEIGHT(y->right));
    x->HEIGHT = 1 + max(GET_HEIGHT(x->left) , GET_HEIGHT(x->right));

return x;
}


// RIGHT ROTATE FUNCTION
Node* AVL_TREE :: R_RIGHT(Node* x){
    Node* y = x->left;
    Node* z = y->right;

    y->right = x;
    x->left = z;

    x->HEIGHT= 1 + max(GET_HEIGHT(x->left) , GET_HEIGHT(x->right));
    y->HEIGHT= 1 + max(GET_HEIGHT(y->left) , GET_HEIGHT(y->right));

    return y;
}


// SEARCH FUNCTION TO FIND AN ITEM IN TREE [BASED ON ID PARAMETERS].
WARE_HOUSE* AVL_TREE :: SEARCH(Node* node, int id){

    if(node==NULL){
        return NULL;
    }
    else if(node->data.id==id){
        return &node->data;
    }
    else if(id < node->data.id){            //left jao if id is small
        return SEARCH(node->left, id);
    }
    else if(id > node->data.id){            //right jao if id is large
        return SEARCH(node->right, id);
    }
}


// INSERT FUNCTION TO ADD ITEM OF AVL TREES
Node* AVL_TREE :: Insert(Node* node, WARE_HOUSE &data){

    if(node==NULL){
        return new Node(data);
    }
    if(data.id < node->data.id){
        node->left = Insert(node->left,data);
    }
    else if(data.id > node->data.id){
        node->right = Insert(node->right,data);
    }
    else if(data.id == node->data.id){      // overwrite existing.
        node->data=data;
    }
    node->HEIGHT = 1 + max(GET_HEIGHT(node->left) , GET_HEIGHT(node->right));
    int balanceFactor = GET_HEIGHT(node->left) - GET_HEIGHT(node->right);
    if(balanceFactor>1){
        if(data.id < node->left->data.id){
            return R_RIGHT(node);
        }
        node->left=R_LEFT(node->left);
        return R_RIGHT(node);
    }
    if(balanceFactor<-1){
        if(data.id > node->right->data.id){
            return R_LEFT(node);
        }
        node->right=R_RIGHT(node->right);
        return R_LEFT(node);
    }
    return node;
}


// READ DATA FROM CSV FILE IN TREE.
void AVL_TREE :: LOAD_DATA_FROM_CSV(const string &filePath){

    ifstream read(filePath);

    if(!read){
        cerr<<"\n ERROR OPENING FILE. \n";
        return;
    }
    else{
        root=NULL;
        string head;
        getline(read,head);         // IGNORE HEADER LINE
        
        string line;
        while(getline(read, line)){
            WARE_HOUSE item;
            
            stringstream ss(line);
            string value;
            getline(ss, value, ',');
            item.id = stoi(value);
            getline(ss, item.name, ',');
            getline(ss, item.descript, ',');
            getline(ss, value, ',');
            item.price = stod(value);
            getline(ss, value, ',');
            item.quantity = stoi(value);
            item.T_price = item.price * item.quantity;

            root=Insert(root, item);
        }
    }

}


// SEARCH FUNCTION TO FIND AN ITEM IN TREE [BASED ON ID PARAMETERS].
WARE_HOUSE* AVL_TREE :: SEARCH_NAME(Node* node, string N){

    if(node==NULL){
        return NULL;
    }
    
    if(node->data.name==N){
        return &node->data;
    }

    WARE_HOUSE* temp = SEARCH_NAME(node->left, N);      //search in left side
    if(temp != NULL){
        return temp;
    }

    return SEARCH_NAME(node->right, N);      //search in right side
}


// GET MINIMUM NODE FUNCTION FOR DELETING. [aik right-> or phir extreme left]
Node* AVL_TREE :: All_LEFT(Node* node){

    Node* temp = node;
    while(temp && temp->left!= NULL){
        temp = temp->left;
    }

return temp;
}


// WRITING IN IN-ORDER FORMAT.
void AVL_TREE :: W_IN_ORDER(Node* temp , fstream &write){
    if(temp!= NULL){
        W_IN_ORDER(temp->left, write);
        write<<temp->data.id<<","<<temp->data.name<<","<<temp->data.descript<<","<<temp->data.price<<","<<temp->data.quantity<<","<<temp->data.T_price<<endl;
        W_IN_ORDER(temp->right, write);
    }
}


// HELPER FUNCTION FOR DELETING ITEMS.
Node* AVL_TREE :: Help_Delete(Node* root, int id){

    // case with only one node
    if(root==NULL){
        return root;
    }
    else if(id < root->data.id){
        root->left = Help_Delete(root->left, id);
    }
    else if(id > root->data.id){
        root->right = Help_Delete(root->right, id);
    }
    else{

        if((root->left == NULL) || (root->right == NULL)){

            Node* temp = root->left ? root->left : root->right;

            // No child case
            if(temp == NULL){
                temp = root;
                root = NULL;
            }
            else{
                *root = *temp;
            }
            delete temp;
        }
        else{           // case with 2 nodes...
            Node* temp = All_LEFT(root->right);
            root->data = temp->data;
            root->right = Help_Delete(root->right, temp->data.id);
        }

    }

    // case with only one node
    if(root == NULL){
        return root;
    }
    
    root->HEIGHT = 1 + max(GET_HEIGHT(root->left), GET_HEIGHT(root->right));
    
    int BF = GET_HEIGHT(root->left) - GET_HEIGHT(root->right);
    
    // LEFT LEFT CASE.
    if(BF>1 && GET_HEIGHT(root->left->left) >= GET_HEIGHT(root->left->right)){
        return R_RIGHT(root);
    }

    // RIGHT RIGHT CASE.
    if(BF<-1 && GET_HEIGHT(root->right->right) >= GET_HEIGHT(root->right->left)){
        return R_LEFT(root);
    }

    // LEFT RIGHT CASE.
    if(BF>1 && GET_HEIGHT(root->left->right) > GET_HEIGHT(root->left->left)){
        root->left = R_LEFT(root->left);
        return R_RIGHT(root);
    }

    // RIGHT LEFT CASE.
    if(BF<-1 && GET_HEIGHT(root->right->left) > GET_HEIGHT(root->right->right)){
        root->right = R_RIGHT(root->right);
        return R_LEFT(root);
    }
    return root;
}


//PRINT COLUMNS TITLES.
void AVL_TREE :: P_COLUMNS(){
    cout<<ANSI_COLOR_PURPLE<<"\n\t|''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''|";
    cout<<"\n\t|   ID   |   ITEM_NAME   |  DESCRIPTION  |  PRICE  |  NO_ITEMS  |  TOTAL_PRICE |";
    cout<<"\n\t|______________________________________________________________________________|";
    cout<<"\n\t|                                                                              |"<<ANSI_COLOR_RESET;
}


//UPDATE FUNCTION TO UPDATE AN ITEM [PRICE, QUANTITY] BASED ON ID.
void AVL_TREE :: UPDATE_ITEM(int Id, double Price, int Quantity){

    WARE_HOUSE* item = SEARCH(root, Id);
    
    if(item!=NULL){
        item->price=Price;
        item->quantity = Quantity;
        item->T_price=item->price * item->quantity;

        // UPDATE DATA IN FILE.
        string f_name = "DATA.csv";
        fstream write(f_name , ios::out | ios::trunc );
        if(!write){
            cerr<<"\n ERROR OPENING FILE FOR UPDATE.\n";
            return;
        }
        else{
            write<<"ID"<<","<<"ITEM_NAME"<<","<<"DESCRIPTION"<<","<<"PRICE"<<","<<"NO_ITEMS"<<","<<"TOTAL_PRICE"<<endl;
            W_IN_ORDER(root, write);
            write.close();
        }
        cout<<ANSI_COLOR_BOLD_GREEN<<"\n\t-------------------------------\n";
        cout<<"\t|   ITEM UPDATED SUCCESSFULLY  |\n";
        cout<<"\t-------------------------------\n"<<ANSI_COLOR_RESET;
    }
    else{
        cout<<ANSI_COLOR_BOLD_RED<<"\n\t-------------------------------\n";
        cout<<"\t|   !!!!  ID NOT FOUND  !!!!  |\n";
        cout<<"\t-------------------------------\n"<<ANSI_COLOR_RESET;
    }
}


// FUNCTION TO REMOVE AN ITEM FROM TREE.
void AVL_TREE :: DEL_ITEM(int id){
    root=Help_Delete(root, id);

    if(root==NULL){
        cerr<<"\n NO ITEM FOUND WITH THIS ID.\n";
        return;
    }

    // UPDATE DATA IN FILE.
    string f_name = "DATA.csv";
    fstream write(f_name , ios::out | ios::trunc );
    if(!write){
        cerr<<"\n ERROR OPENING FILE FOR UPDATE.\n";
        return;
    }
    else{
        write<<"ID"<<","<<"ITEM_NAME"<<","<<"DESCRIPTION"<<","<<"PRICE"<<","<<"NO_ITEMS"<<","<<"TOTAL_PRICE"<<endl;
        W_IN_ORDER(root, write);
        write.close();
    }
}


// HELP DELETION FUNCTION
void AVL_TREE :: HELP_ME(Node* temp){
    if(temp!=NULL){
        HELP_ME(temp->left);
        HELP_ME(temp->right);
        delete temp;
    }
    else{
        return;
    }
}


// DESTRUCTORS
AVL_TREE :: ~AVL_TREE(){
    HELP_ME(root);
}


// PRINT FUNCTION FOR TREE [PRE-ORDERED]
void AVL_TREE :: P_PRE_ORDER(Node* temp){

    const char* color = ANSI_COLOR_RESET;			// NON-CONSTANT POINTER TO CONSTANT DATA.
    if(temp!= NULL){
        if(c==0){
            P_COLUMNS();
        }
        c++;
        if(temp->data.quantity == 0){
            color = ANSI_COLOR_BOLD_RED;
        }
        else if(temp->data.quantity < 30){
            color = ANSI_COLOR_BOLD_YELLOW;
        }
        else{
            color = ANSI_COLOR_BOLD_GREEN;
        }
        cout<<color<<"\n\t|   "<<setw(4)<<temp->data.id<<" |  "<<setw(13)<<temp->data.name<<"|  "<<setw(12)<<temp->data.descript<<" |  "<<setw(7)<<temp->data.price<<"|    "<<setw(8)<<temp->data.quantity<<"|   "<<setw(11)<<temp->data.T_price<<"|"<<ANSI_COLOR_RESET;
        P_PRE_ORDER(temp->left);
        P_PRE_ORDER(temp->right);
    }
}


#endif