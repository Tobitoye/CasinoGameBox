//
// Created by Tobiloba Olutoye on 23/03/2022.
//Now this is where all my functions are kept

#ifndef UNTITLED2_FUNCTIONS_H
#define UNTITLED2_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <ctime>
#endif //UNTITLED2_FUNCTIONS_H
void rules1();
void rules2();
void rules3();





class player{//A class used to save players details
public://These are made public because they are going to be edited by the users
    string name;
    float amount;
    float startingamount;
    float betting_amount;
    void player_det(){
        cout<< "Enter your name:";
        cin>> name;
        cout<< "Enter starting amount: $";
        cin>>startingamount;
        amount=startingamount;



    }
    void bet(){
        cout<< "Enter betting amount: $";
        cin>> betting_amount;
        if (betting_amount> amount){
            cout<<"Your betting amount can not be more than your starting amount\n";
            cout<<"Enter betting amount again:";
            cin >> betting_amount;
        }

    }

};

//using void so that the games can be called at any time anywhere that is needed
void guessing_game( player & player ) {

    int guess;
    int comp_guess;
    char choice;

    rules1();
    do {
        player.bet();

        cout << "Guess any betting number between 1 & 10 :";
        cin >> guess;
        if (guess <= 0 || guess > 10) {
            cout << "\nNumber should be between 1 to 10\n"
                 << "Re-enter number:\n ";
            cin >> guess;
        }

        comp_guess = rand() % 10 + 1;


        if (comp_guess == guess) {

            cout << "\n\nCongratulations!! You have won ." << player.betting_amount * 2;
            player.amount += 2 * player.betting_amount;
        } else {
            cout << "sorry,!! You lost $ " << player.betting_amount << "\n";
            player.amount = player.amount - player.betting_amount;
        }
        cout << "\nThe winning number was : " << comp_guess << "\n";
        cout << "\n" << player.name << ", You have balance of $ " << player.amount << "\n";
        if (player.amount == 0) {
            cout << "You have lost all your money to play ";

        }
        cout << "\n\n-->Do you want to play again (y/n)?  ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    if (choice == 'n') {
        cout<<"Your records have been saved";
        fstream myfile;
        myfile.open("highscore.txt", ios::app);
        if (myfile.is_open()) {
            myfile <<player.name<<"\t\t $"<<player.startingamount<<"\t\t $"<<player.amount<<endl;
            myfile.close();
        }
    }

    }




    void creps(player & player) {
        rules2();
        int dice1;
        int dice2;
        int dice3;
        int dice4;
        int rolldice;
        char choice;
        do {

            player.bet();
            srand(time(NULL));
            dice1 = rand() % 6 + 1;
            dice2 = rand() % 6 + 1;
            rolldice = dice1 + dice2;


            if (rolldice == 7 || rolldice == 11) {

                cout << "You rolled a " << rolldice << "\n";
                cout << "You won: $" << player.betting_amount * 2 << "\n";
                player.amount = player.amount + player.betting_amount;
                cout << "Your new balance is  $" << player.amount << "\n";
                cout << "\n\n-->Do you want to play again (y/n)?  ";
                cin >> choice;

            } else if (rolldice == 2 || rolldice == 3 || rolldice == 12) {
                cout << "You rolled a " << rolldice << "\n";
                cout << "Sorry mate, you lost: $" << player.betting_amount << "\n";
                player.amount = player.amount - player.betting_amount;
                cout << "Your new balance is  $" << player.amount << "\n";
                cout << "\n\n-->Do you want to play again (y/n)?  ";
                cin >> choice;

            } else if (rolldice == 4 || rolldice == 5 || rolldice == 6 || rolldice == 8 || rolldice == 9 ||
                       rolldice == 10) {
                srand(time(NULL));
                dice3 = rand() % 6 + 1;
                dice4 = rand() % 6 + 1;
                int sum2 = dice3 + dice4;
                if (sum2 == rolldice) {
                    cout << "Your first roll was " << rolldice << " and your second roll was " << sum2;
                    cout << "You won: $" << player.betting_amount * 2 << "\n";
                    player.amount = player.amount + player.betting_amount;
                    cout << "Your new balance is  $" << player.amount << "\n";

                } else if (sum2 == 7) {
                    cout << "Your first roll was " << rolldice << " and your second roll was " << sum2;
                    cout << "Sorry mate, you lost: $" << player.betting_amount << "\n";
                    player.amount = player.amount - player.betting_amount;
                    cout << "Your new balance is  $" << player.amount << "\n";
                }
                cout << "\n\n-->Do you want to play again (y/n)?  ";
                cin >> choice;
            }

        } while (choice == 'Y' || choice == 'y');
        if (choice == 'n') {
            fstream myfile;
            myfile.open("highscore.txt", ios::app);
            if (myfile.is_open()) {
                myfile <<player.name<<"\t\t $"<<player.startingamount<<"\t\t $"<<player.amount<<endl;
                myfile.close();
            }}

        cout << "\n";

    }

    void roulette(player & player) {
        int value;
        int random;
        int const Minimum = 1, Maximum = 36;
        char choice;
        char game;
        char even_odd;
        rules3();
        do {
            player.bet();

            cout << "Would you like to bet that the number is going to be a specific number (N) or on even/odd (O)? ";
            cin >> game;

            if (game == 'N' || game == 'n') {
                cout << "Input your number";
                cin >> value;
                if (value == 00)
                    value = 37;

                srand(time(NULL));
                random = rand() % (Maximum - Minimum + 1) + Minimum;

                cout << "The ball landed on " << random << "\n";
                if (value != random) {
                    cout << "You lose $" << player.betting_amount << "\n";
                    player.amount -= player.betting_amount;
                    cout << "You have a balance of $" << player.amount << "\n";
                } else {
                    cout << "You won $" << 3 * player.betting_amount << endl;
                    player.amount += 3 * player.betting_amount;
                    cout << "You have a balance of $" << player.amount << "\n";
                }
            }
            // Even or odd game
            if (game == 'o' || game == 'O') {
                cout << "Would you like to bet on even (E) or odd (O)? ";

                cin >> even_odd;
                srand(time(NULL));
                random = rand() % (Maximum - Minimum + 1) + Minimum;
                cout << "The ball landed on " << random << endl;
                if (even_odd == 'E' || even_odd == 'e') {
//if even win
                    if (2 * (random / 2) == random) {
                        cout << "You won $" << 2 * player.betting_amount << endl;
                        player.amount += 2 * player.betting_amount;
                        cout << "\n" << player.name << ", You have balance of $ " << player.amount << "\n";
                    }
//if even lose
                    else {
                        cout << "You lost $" << player.betting_amount << endl;
                        player.amount -= player.betting_amount;
                        cout << "\n" << player.name << ", You have balance of $ " << player.amount << "\n";
                    }
                }
                if (even_odd == 'O' || even_odd == 'o') {
//if odd lose
                    if (2 * (random / 2) == random) {
                        cout << "You lost $" << player.betting_amount << endl;
                        player.amount -= player.betting_amount;
                        cout << "\n" << player.name << ", You have balance of $ " << player.amount << "\n";
                    }
//if odd win
                    else {
                        cout << "You won $" << 2 * player.betting_amount << endl;
                        player.amount += 2 * player.betting_amount;
                        cout << "\n" << player.name << ", You have balance of $ " << player.amount << "\n";
                    }
                }

            }
            cout << "\n\n-->Do you want to play again (y/n)?  ";

            cin >> choice;
        } while (choice == 'Y' || choice == 'y');
        if (choice == 'n') {
            fstream myfile;
            myfile.open("highscore.txt", ios::app);
            if (myfile.is_open()) {
                myfile << player.name << "\t\t $" << player.startingamount << "\t\t $" << player.amount << endl;
                myfile.close();
            }}

        }


