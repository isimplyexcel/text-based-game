/**********************************************************************************************
** Program Name: train
** Author: Paul Min
** Date: 08/09/18
** Description: map.cpp is the map function implementation file.
************************************************************************************************/

#include <iostream>
#include <string>

/***********************************************************************************************
                                    displayMap(Space* location)
    This function displays a map of all the train cars. It has one parameter which is a space
    pointer. The map will place an asterisk on a certain car based off the argument that is 
    passed into it.
************************************************************************************************/

void displayMap(std::string carName){
	char map[7][66]; // row col

    std::cout << "\t\t\t Map" << std::endl;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 66; j++){
            //  top row
            if(i == 0){
                map[i][j] = '-';
                std::cout << map[i][j];
            }
            //  bottom row
            if(i == 6){
                map[i][j] = '-';
                std::cout << map[i][j];
            }
            // column |
            if(j < 100 && (j % 10 == 0) && (i > 0 && i < 6)){
                map[i][j] = '|';
                std::cout << map[i][j];
            }

            if(j > 0 && j < 60 && i > 0 && i < 6){
                map[i][j] = ' ';

                //  engine car
                map[3][52] = 'e';
                map[3][53] = 'n';
                map[3][54] = 'g';
                map[3][55] = 'i';
                map[3][56] = 'n';
                map[3][57] = 'e';

                //  dining car
                map[3][42] = 'd';
                map[3][43] = 'i';
                map[3][44] = 'n';
                map[3][45] = 'i';
                map[3][46] = 'n';
                map[3][47] = 'g';

                //  baggage car
                map[3][32] = 'b';
                map[3][33] = 'a';
                map[3][34] = 'g';
                map[3][35] = 'g';
                map[3][36] = 'a';
                map[3][37] = 'g';
                map[3][38] = 'e';

                //  shopping car
                map[3][21] = 's';
                map[3][22] = 'h';
                map[3][23] = 'o';
                map[3][24] = 'p';
                map[3][25] = 'p';
                map[3][26] = 'i';
                map[3][27] = 'n';
                map[3][28] = 'g';

                //  bar car
                map[3][14] = 'b';
                map[3][15] = 'a';
                map[3][16] = 'r';

                //  caboose
                map[3][2] = 'c';
                map[3][3] = 'a';
                map[3][4] = 'b';
                map[3][5] = 'o';
                map[3][6] = 'o';
                map[3][7] = 's';
                map[3][8] = 'e';

                if(carName == "Caboose car"){
                	map[5][5] = '*';
                }
                else if(carName == "Bar car"){
                	map[5][14] = '*';
                }
                else if(carName == "Shopping car"){
                	map[5][25] = '*';
                }
                else if(carName == "Baggage car"){
                	map[5][34] = '*';
                }
                else if(carName == "Dining car"){
                	map[5][44] = '*';
                }
                else if(carName == "Engine car"){
                	map[5][55] = '*';
                }

                std::cout << map[i][j];
            }
        }
        std::cout << std::endl;
    }

    std::cout << "Key: * Current Location" << std::endl;
    //  empty line
    std::cout << std::endl;
}
   