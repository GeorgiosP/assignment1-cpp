#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void _welcomeMenu();
void _promptMenu();
bool _checkMenuInputLength(char *input); 
void _displayValue(int year); 
void _notValid(char const *function);
inline int yearsSince2005(int value); 
inline float calculateDollarsSpent(int value); 

int main(){
    char buffer[256];
    bool keepGoing = true; 
 

    _welcomeMenu();

    do{
        _promptMenu();
        printf("\n>> ");
        fgets(buffer, sizeof(buffer), stdin);

        buffer[strcspn(buffer,"\n")] = 0;
       
        if(_checkMenuInputLength(buffer)){
            if(strcmp(buffer, "e") == 0){
                printf("Exiting program...");
                keepGoing = false;
            }
            else{
                int year = atoi(buffer);
                if(year < 2005){
                    printf("Sorry! you cannot enter a year less then 2005 exiting program...\n\n");
                    keepGoing = false; 
                }
                else if(year > 2100){
                    printf("Sorry! you cannot enter a year greater then 2100 exiting program...\n\n"); 
                    keepGoing = false; 
                }
                else{
                    _displayValue(year);
                }
            }
        }
        else{
            _notValid("Error: main");
        }
      
    }while(keepGoing == true); 

    return 0; 
}

void _welcomeMenu(){
    printf("******************************************************\n"); 
    printf("**              Assignment 1 TakeAway               **\n"); 
    printf("******************************************************\n\n"); 
    
}
void _promptMenu(){
    printf("*********************************************************************************************\n");
    printf("                TakeAway, enter a year after 2005 you want the data for                      \n");
    printf("                           Type \"e\" to end the program                                     \n");
    printf("*********************************************************************************************\n");
}

void _notValid(char const *function){
    printf("******************************************************\n"); 
    printf("           %s That's Not A Valid Input            \n", function); 
    printf("******************************************************\n"); 
} 
bool _checkMenuInputLength(char *input){
    int length = strlen(input);
    if(length == 4 || length == 1)
        return true;
    else 
        return false;
}

void _displayValue(int year){
    const int yearsSince = yearsSince2005(year);
 

    if(yearsSince > 95 || yearsSince < 0){
        _notValid("Error: _displayValue cannot be greater 95 or less then 0\n\n");
        return;
    }
    else{
    float dollarsSpent = calculateDollarsSpent(yearsSince);
    printf("\nIn the year %d the amount spent on fast food on credit and debit cards in the US was %.2f billion\n\n", year, dollarsSpent);
    }
}

inline int yearsSince2005(int value){

    return value - 2005; 
}

inline float calculateDollarsSpent(int value){
    return 33.2 + (16.8 * value); 
}
