// Sample code for ECE 198

// Written by Bernie Roehl, August 2021

// This file contains code for a number of different examples.
// Each one is surrounded by an #ifdef ... #endif block inside of main().

// To run a particular example, you should remove the comment (//) in
// front of exactly ONE of the following lines:
//

#define maincode


#include <stdbool.h> // booleans, i.e. true and false
#include <stdio.h>   // sprintf() function
#include <stdlib.h>  // srand() and random() functions
#include "ece198.h"
#include "LiquidCrystal.h"



int main(void)
{
    HAL_Init(); // initialize the Hardware Abstraction Layer

    // Peripherals (including GPIOs) are disabled by default to save power, so we
    // use the Reset and Clock Control registers to enable the GPIO peripherals that we're using.

    __HAL_RCC_GPIOA_CLK_ENABLE(); // enable port A (for the on-board LED, for example)
    __HAL_RCC_GPIOB_CLK_ENABLE(); // enable port B (for the rotary encoder inputs, for example)
    __HAL_RCC_GPIOC_CLK_ENABLE(); // enable port C (for the on-board blue pushbutton, for example)

    // initialize the pins to be input, output, alternate function, etc...

    // InitializePin(GPIOA, GPIO_PIN_5, GPIO_MODE_OUTPUT_PP, GPIO_NOPULL, 0);  // on-board LED

    // note: the on-board pushbutton is fine with the default values (no internal pull-up resistor
    // is required, since there's one on the board)

    // set up for serial communication to the host computer
    // (anything we write to the serial port will appear in the terminal (i.e. serial monitor) in VSCode)

    SerialSetup(9600);

    // as mentioned above, only one of the following code sections will be used
    // (depending on which of the #define statements at the top of this file has been uncommented)





#ifdef maincode




int num_of_rounds=1;
bool game_one=true;
bool game_two=true;
bool game_three=true;
bool game_four=true;

bool won_round_1=false;
bool won_round_2=false;
bool won_round_3=false;
bool won_round_4=false;



int i = 0;

//In order to determin whether or not player has won round there will be a series of gates






LiquidCrystal(GPIOB, GPIO_PIN_8, GPIO_PIN_9, GPIO_PIN_10, GPIO_PIN_3,
GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6);

InitializePin(GPIOC, GPIO_PIN_3, GPIO_MODE_INPUT, GPIO_PULLUP, 0); // Note C
InitializePin(GPIOC, GPIO_PIN_10, GPIO_MODE_INPUT, GPIO_PULLUP, 0);// Note D
InitializePin(GPIOC, GPIO_PIN_11, GPIO_MODE_INPUT, GPIO_PULLUP, 0);// Note E
InitializePin(GPIOC, GPIO_PIN_12, GPIO_MODE_INPUT, GPIO_PULLUP, 0);// Note F
InitializePin(GPIOC, GPIO_PIN_13, GPIO_MODE_INPUT, GPIO_PULLUP, 0);// Note G 


while (num_of_rounds <= 4) {
    if(num_of_rounds == 1){
        setCursor(0,0); //finds location on LCD to display
        print("Hello Welcome to"); // prints on LCD
        setCursor(0,1);
        print("Music Box");
        HAL_Delay(3000); // delay so writing is visible
        clear();  // removes all writing on LCD

        setCursor(0,0); 
        print("Welcome to");
        setCursor(0,1);
        print("round 1");
        HAL_Delay(4000);
        clear(); // second block of writing done



        setCursor(0,0);
        print("12 seconds to");
        setCursor(0,1);
        print("complete round 1");
        HAL_Delay(3000);
        clear();


        setCursor(0,0);
        print("Play Notes:");
        setCursor(0,1);
        print("C E D G F");

        
        char gamearray_one[5]={'C', 'E' ,'D', 'G', 'F'}; // Array to check button pressed order
        char p_array[5]={'0', '0' ,'0', '0', '0'};
        
        

        uint32_t timeNow= HAL_GetTick(); // timer variables
        uint32_t timer= HAL_GetTick();

        
        while (game_one){  // This while loop will check which buttons are pressed and will set the timer.

           
        if(i<5){// makes sure player does not play more that 5 notes
            
            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)){ // this will check if the button if pressed and will then assign it
                p_array[i]='C';
                i=i+1;
                HAL_Delay(180); // slight delay
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10)){ // Button number 2
                p_array[i]='D';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11)){ // Button number 3
                p_array[i]='E';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12)){ // Button number 4
                p_array[i]='F';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){ // Button number 5
                p_array[i]='G';
                i=i+1;
                HAL_Delay(180);
            }
            }

            timeNow=HAL_GetTick();  
             if ( (timeNow - timer) > 12000 && (timeNow - timer) < 100000){//Timer will check if time is up
                won_round_1=true;
                game_one=false; // will exit loop
            }

            
        }


        for(int k=0; k<5; k++) { // this will compare the two arrays and will return boolean stating if player won
                if (gamearray_one[k]==p_array[k]) {
                    won_round_1 = true;
                } else{
                    won_round_1 = false;
                    break;
                }
            }



        //Now that the statistics of the player have been calculated we can check if the round has been won

        if(won_round_1) {
            clear();
            setCursor(0,0);
            print("You Won!");
            setCursor(0,1);
            print("Level 2...");
            HAL_Delay(4000);
            i=0; //resets buttons
            game_one=true;
            num_of_rounds++;// This will initiate the next level
        }
        else{
            clear();
            setCursor(0,0);
            print("You lost...");
            setCursor(0,1);
            print("back to round 1");
            HAL_Delay(4000);
            game_one = true; // this will reset the while loop that checks button input and time 
            i=0; // resets buttons
            num_of_rounds=1;// This will send player back to level 1
            

        }
        clear();





    }//main if for round 1 ends here




    //Round 2 begins:

    if(num_of_rounds == 2){

        setCursor(0,0); 
        print("Welcome to");
        setCursor(0,1);
        print("round 2");
        HAL_Delay(4000);
        clear(); // second block of writing done



        setCursor(0,0);
        print("10 seconds to");
        setCursor(0,1);
        print("complete round 2");
        HAL_Delay(3000);
        clear();


        setCursor(0,0);
        print("Play Notes:");
        setCursor(0,1);
        print("F C G D D");

        
        char gamearray_two[5]={'F', 'C' ,'G', 'D', 'D'};
        char p_array_two[5]={'0', '0' ,'0', '0', '0'}; 
        
        

        uint32_t timeNow= HAL_GetTick();
        uint32_t timer= HAL_GetTick();

        
        while (game_two){  // This while loop will check which buttons are pressed and will set the timer.

           
        if(i<5){// makes sure player does not play more that 5 notes
            
            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)){ // this will check if the button if pressed and will then assign it
                p_array_two[i]='C';
                i=i+1;
                HAL_Delay(180); // slight delay
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10)){ // Button number 2
                p_array_two[i]='D';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11)){ // Button number 3
                p_array_two[i]='E';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12)){ // Button number 4
                p_array_two[i]='F';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){ // Button number 5
                p_array_two[i]='G';
                i=i+1;
                HAL_Delay(180);
            }
            }

            timeNow=HAL_GetTick();  
             if ( (timeNow - timer) > 10000 && (timeNow - timer) < 100000){//Timer will check if time is up
             
                won_round_2=true;
                game_two=false; // will exit loop
            }

            
        }


        for(int k=0; k<5; k++) { // this will compare the two arrays and will check if player has won
                if (gamearray_two[k]==p_array_two[k]) {
                    won_round_2 = true;
                } else{
                    won_round_2 = false;
                    break;
                }
            }



        //Now that the statistics of the player have been calculated we can check if the round has been won

        if(won_round_2) {
            clear();
            setCursor(0,0);
            print("You Won!");
            setCursor(0,1);
            print("Level 3...");
            HAL_Delay(4000);
            game_two=true;
            i=0; //resets buttons
            num_of_rounds++;// This will initiate the next level
        }
        else{
            clear();
            setCursor(0,0);
            print("You lost...");
            setCursor(0,1);
            print("back to round 1");
            HAL_Delay(4000);
            game_two = true; // this will reset the while loop that checks button input and time 
            i=0; // resets buttons
            num_of_rounds=1;// This will send player back to level 1
            

        }
        clear();





    }//main if for round 2 ends here

    if(num_of_rounds == 3){

        setCursor(0,0); 
        print("Welcome to");
        setCursor(0,1);
        print("round 3");
        HAL_Delay(4000);
        clear(); 



        setCursor(0,0);
        print("8 seconds to");
        setCursor(0,1);
        print("complete round 3");
        HAL_Delay(3000);
        clear();


        setCursor(0,0);
        print("Play Notes:");
        setCursor(0,1);
        print("F D D E E D C E");

        
        char gamearray_three[8]={'F', 'D', 'D', 'E', 'E', 'D', 'C', 'E'};
        char p_array_three[8]={'0', '0' ,'0', '0', '0', '0','0','0'}; 
        
        

        uint32_t timeNow= HAL_GetTick();
        uint32_t timer= HAL_GetTick();

        
        while (game_three){  // This while loop will check which buttons are pressed and will set the timer.

           
        if(i<8){// makes sure player does not play more that 5 notes
            
            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)){ // this will check if the button if pressed and will then assign it
                p_array_three[i]='C';
                i=i+1;
                HAL_Delay(180); // slight delay
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10)){ // Button number 2
                p_array_three[i]='D';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11)){ // Button number 3
                p_array_three[i]='E';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12)){ // Button number 4
                p_array_three[i]='F';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){ // Button number 5
                p_array_three[i]='G';
                i=i+1;
                HAL_Delay(180);
            }
            }

            timeNow=HAL_GetTick();  
            //change timer
             if ( (timeNow - timer) > 8000 && (timeNow - timer) < 100000){//Timer will check if time is up
                game_three=false; // will exit loop
            }

            
        }


        for(int k=0; k<8; k++) { // this will compare the two arrays and will check if player has won
                if (gamearray_three[k]==p_array_three[k]) {
                    won_round_3 = true;
                } else{
                    won_round_3 = false;
                    break;
                }
            }



        //Now that the statistics of the player have been calculated we can check if the round has been won

        if(won_round_3) {
            clear();
            setCursor(0,0);
            print("You Won!");
            setCursor(0,1);
            print("Level 4...");
            HAL_Delay(4000);
            i=0; //resets buttons
            game_three=true;
            num_of_rounds++;// This will initiate the next level
        }
        else{
            clear();
            setCursor(0,0);
            print("You lost...");
            setCursor(0,1);
            print("back to round 1");
            HAL_Delay(4000);
            game_three = true; // this will reset the while loop that checks button input and time 
            i=0; // resets buttons
            num_of_rounds=1;// This will send player back to level 1
            

        }
        clear();
            
    }//round 3 if statement end here


    if(num_of_rounds == 4){

        setCursor(0,0); 
        print("Welcome to");
        setCursor(0,1);
        print("round 4");
        HAL_Delay(4000);
        clear(); 



        setCursor(0,0);
        print("6 seconds to");
        setCursor(0,1);
        print("complete round 4");
        HAL_Delay(3000);
        clear();


        setCursor(0,0);
        print("Play Notes:");
        setCursor(0,1);
        print("C D E F D F C D");

        
        char gamearray_four[8]={'C', 'D' ,'E', 'F', 'D' ,'F', 'C', 'D'};
        char p_array_four[8]={'0', '0' ,'0', '0', '0', '0','0', '0'}; 
        
        

        uint32_t timeNow= HAL_GetTick();
        uint32_t timer= HAL_GetTick();

        
        while (game_four){  // This while loop will check which buttons are pressed and will set the timer.

           
        if(i<8){// makes sure player does not play more that 5 notes
            
            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_3)){ // this will check if the button if pressed and will then assign it
                p_array_four[i]='C';
                i=i+1;
                HAL_Delay(180); // slight delay
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_10)){ // Button number 2
                p_array_four[i]='D';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_11)){ // Button number 3
                p_array_four[i]='E';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_12)){ // Button number 4
                p_array_four[i]='F';
                i=i+1;
                HAL_Delay(180);
            }

            if(!HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)){ // Button number 5
                p_array_four[i]='G';
                i=i+1;
                HAL_Delay(180);
            }
            }

            timeNow=HAL_GetTick();  
            //change timer
             if ( (timeNow - timer) > 6000 && (timeNow - timer) < 100000){//Timer will check if time is up
            
                game_four=false; // will exit loop
            }

            
        }


        for(int k=0; k<8; k++) { // this will compare the two arrays and will check if player has won
                if (gamearray_four[k]==p_array_four[k]) {
                    won_round_4 = true;
                } else{
                    won_round_4 = false;
                    break;
                }
            }



        //Now that the statistics of the player have been calculated we can check if the round has been won

        if(won_round_4) {
            clear();
            setCursor(0,0);
            print("You Won!");
            setCursor(0,1);
            print("Congrats!");
            HAL_Delay(4000);
            i=0; //resets buttons
            game_four=true;
            num_of_rounds++;// This will initiate the next level
        }
        else{
            clear();
            setCursor(0,0);
            print("You lost...");
            setCursor(0,1);
            print("back to round 1");
            HAL_Delay(4000);
            game_four = true; // this will reset the while loop that checks button input and time 
            i=0; // resets buttons
            num_of_rounds=1;// This will send player back to level 1
            

        }
        clear();
            
    } //round 4 if statement end here

    


} //main while ends here

if(num_of_rounds == 5){
        clear();
        setCursor(0,0);
        print("Game Over!");
        setCursor(0,1);
        print("You are a winner!");
}



#endif


    return 0;
}

// This function is called by the HAL once every millisecond
void SysTick_Handler(void)
{
    HAL_IncTick(); // tell HAL that a new tick has happened
    // we can do other things in here too if we need to, but be careful
}

