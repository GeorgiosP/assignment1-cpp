#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void _welcomeMenu(); 
void _homeMenu(); 
bool _checkMenuInputLength(); 
void _notValid();

int main(){
    char buffer[256];
    bool keepGoing = true; 

    _welcomeMenu();
    do{
        _homeMenu();
        printf("\n>> ");
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer), "\n")] = 0;
        if(_checkMenuInputLength(buffer)){
            int menuSelection = atoi(buffer); 
            switch(menuSelection){
                case 1:
                    _pascalsTriangle(); 
                    break;
                case 2: 
                    _binomialTherom();
                    break;
                case 3: 
                    printf("Exiting Program...");
                    keepGoing = false; 
                    break;
                default:
                    _notValid("Default Case: main");
            }
        }
        else{
            _notValid("Error: main"); 
        }

    }while(keepGoing == true)

    return 0; 
}

void _welcomeMenu(){
    printf("******************************************************\n"); 
    printf("**         Assignment 1 BiNomial Expansion          **\n"); 
    printf("**     Please enter the what you want to use:       **\n"); 
    printf("******************************************************\n"); 
    
    
}

void _notValid(char const *function){
    printf("******************************************************\n"); 
    printf("           %s That's Not A Valid Input            \n", function); 
    printf("******************************************************\n"); 
} 

void _homeMenu(){
    printf("\n1. Pascals Triangle\n"); 
    printf("2. Binomial Therom\n");
    printf("3. Exit program\n"); 
    

}

bool _checkMenuInputLength(char *input){
    int length = strlen(input);
    if(length == 1)
        return true; 
    else
        return false; 
}