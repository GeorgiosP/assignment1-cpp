#include <stdio.h> 
#include <string.h>
#include <stdlib.h>



void _welcomeMenu();
void _homeMenu(); 
bool _checkMenuInputLength(char *input); 
void _getTemp(char const *temperatureType);
void _displaySubstance(char const *temperatureType, float temperature);
void _displayAsCelcius(float temperature); 
void _displayAsFahrenheit(float temperature); 
void _displayAsKelvin(float temperature); 
inline float celciusToFahrenheit(float value);
inline float celciusToKelvin(float value);
void _notValid(char const *function);


#define WaterCelcius 100
#define MercuryCelcius 357
#define CopperCelcius 1187
#define SilverCelcius 2193
#define GoldCelcius 2660


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
                    _getTemp("Celcius"); 
                    break; 
                case 2: 
                    _getTemp("Fahrenheit"); 
                    break; 
                case 3: 
                    _getTemp("Kelvin"); 
                    break; 
                case 4: 
                    printf("Exiting program..."); 
                    keepGoing = false; 
                    break; 
                default: 
                    _notValid("Default Case: main"); 
                
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
    printf("**            Assignment 1 Temp/Boiling             **\n"); 
    printf("**  Please enter the degree type you want to use:   **\n"); 
    printf("******************************************************\n"); 
    
    
}

void _notValid(char const *function){
    printf("******************************************************\n"); 
    printf("           %s That's Not A Valid Input            \n", function); 
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
        _notValid("Error: _boilingMenu");
        return; 
    }
    printf("******************************************************\n"); 
    printf(" %s selected!\n",temperatureType); 
    printf(" Select the boiling point, in %s\n", temperatureType); 
    printf("******************************************************\n"); 
}

void _getTemp(char const *temperatureType){
    if(temperatureType == NULL){
        _notValid("Error: _getTemp"); 
        return; 
    }
    _boilingMenu(temperatureType);   
    //get use input
    char buffer[256];
    printf(">> "); 
    fgets(buffer, sizeof(buffer), stdin); 
    buffer[strcspn(buffer, "\n")] = 0;

    const float temperature = atof(buffer);
    if(temperature <= 0){
        printf("Substance unknown.\n\n");
    }
    else{
        _displaySubstance(temperatureType, temperature); 
        return; 
    }


}
void _displaySubstance(char const *temperatureType, float temperature){
    if(temperatureType == NULL || temperature <= 0){
        _notValid("Error: _displaySubstance");
        return;
    }
    if(strcmp(temperatureType, "Celcius") == 0){
        _displayAsCelcius(temperature); 
    }
    else if(strcmp(temperatureType, "Fahrenheit") == 0){
        _displayAsFahrenheit(temperature);
    }
    else if(strcmp(temperatureType, "Kelvin") == 0){
        _displayAsKelvin(temperature);
    }
    else{
        printf("_displaySubstance ERROR: Invalid temperatureType [%s].", temperatureType); 
    }
    return; 
}

void _displayAsCelcius(float temperature){
    if(temperature >= (WaterCelcius  - (0.05 * WaterCelcius)) && temperature <= (WaterCelcius + (0.05 * WaterCelcius))){
        printf("Identified as Water!\n\n"); 
    }
    else if(temperature >= (MercuryCelcius  - (0.05 * MercuryCelcius)) && temperature <= (MercuryCelcius + (0.05 * MercuryCelcius))){
        printf("Identified as Mercury!\n\n"); 
    }
    else if(temperature >= (CopperCelcius  - (0.05 * CopperCelcius)) && temperature <= (CopperCelcius + (0.05 * CopperCelcius))){
        printf("Identified as Copper!\n\n"); 
    }
    else if(temperature >= (SilverCelcius  - (0.05 * SilverCelcius)) && temperature <= (SilverCelcius + (0.05 * SilverCelcius))){
        printf("Identified as Silver!\n\n"); 
    }
    else if(temperature >= (GoldCelcius  - (0.05 * GoldCelcius)) && temperature <= (GoldCelcius + (0.05 * GoldCelcius))){
        printf("Identified as Gold!\n\n"); 
    } 
    else{
        printf("Substance is unknown!\n\n"); 
    }
    return; 
}

void _displayAsFahrenheit(float temperature){
    const float WaterFahrenheit = celciusToFahrenheit(WaterCelcius), 
                MercuryFahrenheit = celciusToFahrenheit(MercuryCelcius),
                CopperFahrenheit = celciusToFahrenheit(CopperCelcius),
                SilverFahrenheit = celciusToFahrenheit(SilverCelcius),
                GoldFahrenheit = celciusToFahrenheit(GoldCelcius); 
    if(temperature >= (WaterFahrenheit  - (0.05 * WaterFahrenheit)) && temperature <= (WaterFahrenheit + (0.05 * WaterFahrenheit))){
        printf("Identified as Water!\n\n"); 
    }
    else if(temperature >= (MercuryFahrenheit  - (0.05 * MercuryFahrenheit)) && temperature <= (MercuryFahrenheit + (0.05 * MercuryFahrenheit))){
        printf("Identified as Mercury!\n\n"); 
    }
    else if(temperature >= (CopperFahrenheit  - (0.05 * CopperFahrenheit)) && temperature <= (CopperFahrenheit + (0.05 * CopperFahrenheit))){
        printf("Identified as Copper!\n\n"); 
    }
    else if(temperature >= (SilverFahrenheit  - (0.05 * SilverFahrenheit)) && temperature <= (SilverFahrenheit + (0.05 * SilverFahrenheit))){
        printf("Identified as Silver!\n\n"); 
    }
    else if(temperature >= (GoldFahrenheit  - (0.05 * GoldFahrenheit)) && temperature <= (GoldFahrenheit + (0.05 * GoldFahrenheit))){
        printf("Identified as Gold!\n\n"); 
    } 
    else{
        printf("Substance is unknown!\n\n"); 
    }
    return;   
}

void _displayAsKelvin(float temperature){
    const float WaterKelvin = celciusToKelvin(WaterCelcius),
                MercuryKelvin =  celciusToKelvin(MercuryCelcius),
                CopperKelvin = celciusToKelvin(CopperCelcius), 
                SilverKelvin = celciusToKelvin(SilverCelcius),
                GoldKelvin = celciusToKelvin(GoldCelcius); 

    if(temperature >= (WaterKelvin  - (0.05 * WaterKelvin)) && temperature <= (WaterKelvin + (0.05 * WaterKelvin))){
        printf("Identified as Water!\n\n"); 
    }
    else if(temperature >= (MercuryKelvin  - (0.05 * MercuryKelvin)) && temperature <= (MercuryKelvin + (0.05 * MercuryKelvin))){
        printf("Identified as Mercury!\n\n"); 
    }
    else if(temperature >= (CopperKelvin  - (0.05 * CopperKelvin)) && temperature <= (CopperKelvin + (0.05 * CopperKelvin))){
        printf("Identified as Copper!\n\n"); 
    }
    else if(temperature >= (SilverKelvin  - (0.05 * SilverKelvin)) && temperature <= (SilverKelvin + (0.05 * SilverKelvin))){
        printf("Identified as Silver!\n\n"); 
    }
    else if(temperature >= (GoldKelvin  - (0.05 * GoldKelvin)) && temperature <= (GoldKelvin + (0.05 * GoldKelvin))){
        printf("Identified as Gold!\n\n"); 
    } 
    else{
        printf("Substance is unknown!\n\n"); 
    }
    return;
}

inline float celciusToFahrenheit(float value){
    return (value * 1.8) + 32;
}
inline float celciusToKelvin(float value){
    return value + 273.15;
}