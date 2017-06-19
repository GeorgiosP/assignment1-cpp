#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <iostream>

void _welcomeMenu(); 
void _homeMenu(); 
bool _checkMenuInputLength(char *input); 
void _notValid(char const *function);
void _pascalsTriangle();
void _binomialTherom();
int binomial(int n, int k); 

int main(){
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
                    _notValid("Default Case: Main");
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

void _pascalsTriangle(){
    printf("\nPascals Triangle Selected!\n"); 
    printf("Enter a number between 0 and 10\n");
    
    char buffer[256];
    printf(">> ");

    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; 

    int rows = atoi(buffer);
    if(rows <= 10){
    
    for(int i = 0; i < rows; i++){
        int val = 1; 
        for(int j = 1; j < (rows - i); j++){
            printf("  "); 
        }
        for(int k = 0; k <= i; k++){
            printf("   %d", val);
            val = val * (i - k) / (k + 1); 
        }
        printf("\n\n");
    }
    printf("\n"); 
    return;
    }
    else{
        printf("your input must be between 0 and 10");
        return;
    }
    return;  
}

void _binomialTherom(){
    printf("\nBinomial Therom Selected!\n");
    printf("Enter a natural number:\n");

    char buffer[256];
    // char bufferTwo[256];

    printf(">> ");

    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0; 
    int firstValue = atoi(buffer);

    printf(">> ");
    fgets(buffer, sizeof(buffer),stdin);
    buffer[strcspn(buffer, "\n")] = 0; 
    int secondValue = atoi(buffer);

    binomial(firstValue, secondValue);

    
    return; 
}

int binomial(int n, int k){

    int num, den;
    if(n < k){
        
        return(0); 
    }
    else{
        int den = 1; 
        int num = 1;
        for(int i = 1; i <= k; i = i+1)
            den = den * i; 
        for(int j = n-k+1; j<=n; j=j+1)
            num = num * j; 
            return(num/den);
    }
    return(0);
}