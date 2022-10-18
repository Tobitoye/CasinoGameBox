#include <iostream>
using namespace std;


#include "Functions.h"//This is to call my function file

void welcome();
void rules1();

int main(){//this is where all the functions are set to run and how they are meant to run



    welcome();

    player player1;

    char reply;

   cout<<"WHAT GAME WILL YOU LIKE TO TRY YOUR LUCK ON TODAY \n";
   cout<<"1. Number guesser  \n";
   cout<<"2. Creps  \n";
   cout<<"3. Roulette \n";
   cout<<"4. See players history\n";
   cout<<"5. View rules of all the games\n";
   cin>> reply;
   if (reply=='1'){
    player1.player_det();
       guessing_game(player1);
    }
   else if(reply =='2'){
       player1.player_det();
       creps(player1);
   }
   else if(reply=='3'){
       player1.player_det();
       roulette( player1);

   }
   else if(reply=='4'){//this is to read the file saved for the players history
       fstream myfile;
       myfile.open("highscore.txt", ios::in);//Read File
       if (myfile.is_open()) {
           string line;
           while (getline(myfile, line)) {
               cout << line << endl;
           }
       }

   }
   else if(reply=='5'){
        rules1();
        rules2();
        rules3();
   }
   else{
       cout<<"invalid response";
   }


   }










//welcome message
void welcome(){
cout<< "\t\t.............Welcome to pink diamond casino...............\n";
cout<< "\t\t.............the more the money the more the merry...............\n";



}
//rules for guessing game
void rules1(){
    cout << "\t\t......GUESS GAME RULES.........\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";

}
//rules for craps
void rules2(){

    cout << "\t\t......CRAPS GAME RULES.........\n";
    cout << "\t1. You are required to roll a dice. \n";
    cout << "\t2. If the dice sums up to 7 or 11 you win.\n";
    cout << "\t3. If you get either a 2, 3 or 12, you lose.\n";
    cout << "\t4. If you roll any other number you are required to roll again and you must roll the exact same number to win.\n\n";


}

//Roulette rules
void rules3(){
    cout<<"\t......Roulette Game Rules.........\n";
    cout << "\t1. You choose your guess on the type of number the computer will generate. \n";
    cout << "\t2. You can bet that the number is either; a specific number, an even number or an odd number;";
    cout << "\t3. If you guess a specific value your bet value is multiplied by 3. \n";
    cout << "\t4. If you guess if the nu,ber is even or odd your bet value is doubled.\n\n";

}



