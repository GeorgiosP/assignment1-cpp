#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


void _welcomeMenu();
void _homeMenu(); 
bool _checkMenuInputLength(char *input); 
void _notValid();  


int main()
{

    char buffer[256]; 
    bool keepGoing = true; 

     _welcomeMenu();
    do{
        _homeMenu();

        printf("\n>> ");
        fgets(buffer, sizeof(buffer), stdin);  

        buffer[strcspn(buffer, "\n")] = 0;
        if(_checkMenuInputLength(buffer)){
            int menuSelection = atoi(buffer); 
            switch(menuSelection){
                case 1: 
                    printf("celcius"); 
                    break; 
                case 2: 
                    printf("Fahrenheit"); 
                    break; 
                case 3: 
                    printf("Kelvin"); 
                    break; 
                case 4: 
                    printf("Exiting program..."); 
                    keepGoing = false; 
                    break; 
                default: 
                    _notValid(); 
                
            }
        }
        else{
            _notValid(); 
        }
        



    }while(keepGoing == true);

    
    return 0; 
}

void _welcomeMenu(){
    printf("******************************************************\n"); 
    printf("**            Assignment 1 Temp/Boiling             **\n"); 
    printf("**  Please enter the degree type you want to use:   **\n"); 
    printf("******************************************************\n"); 
    
    
}

void _notValid(){
    printf("******************************************************\n"); 
    printf("**             That's Not A Valid Input             **\n"); 
    printf("******************************************************\n"); 
} 

void _homeMenu(){
    printf("\n1. Celcius\n"); 
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n"); 
    printf("4. Exit program\n");

}

bool _checkMenuInputLength(char *input){
    int length = strlen(input);
    if(length == 1)
        return true; 
    else
        return false; 
}


void _boilingMenu(char const *temperatureType){
    if(temperatureType == NULL){
        printf("_boilingMenu() ERROR: CANNOT PARSE NULL"); 
        return; 
    }
    printf("******************************************************\n"); 
    printf(" %s selected!\n",temperatureType); 
    printf(" Select the boiling point, in %s\n", temperatureType); 
    printf("******************************************************\n"); 
}

void _getTemp(char const *temperatureType){
    if(temperatureType == NULL){
        printf("_getTemp() ERROR: CANNOT PARSE NULL"); 
        return; 
    }
    _boilingMenu(temperatureType);   
    //get use input
    char buffer[256];
    printf(">> "); 
    fgets(buffer, sizeof(buffer), stdin); 
    buffer[strcspn(buffer, "\n")] = 0;

    const float temp = atof(buffer);

    //convert input to a number 
}