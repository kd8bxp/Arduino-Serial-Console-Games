/*
Copyright (c) 2018 LeRoy Miller

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses>

If you find this or any of my projects useful or enjoyable please support me.  
Anything I do get goes to buy more parts and make more/better projects.  
https://www.patreon.com/kd8bxp  
https://ko-fi.com/lfmiller  

https://github.com/kd8bxp
https://www.youtube.com/channel/UCP6Vh4hfyJF288MTaRAF36w  
https://kd8bxp.blogspot.com/  
*/

/*
 * May 9, 2018, (C) LeRoy Miller
 * Based on the game Deal or No Deal.
 * Play in the Serial Console at 9600 baud, Newline for line feeds.
 * (work in progress, and not finished yet).
 * 
 * https://en.wikipedia.org/wiki/Deal_or_No_Deal_(U.S._game_show)
 * https://infogalactic.com/info/Deal_or_No_Deal_(U.S._game_show)
 * https://en.wikipedia.org/wiki/Deal_or_No_Deal
 * https://en.wikibooks.org/wiki/Introduction_to_Game_Theory/Deal_Or_No_Deal
 */
long money[27] = { 1,5,10,15,25,50,75,100,200,300,400,500,750,1000,5000,10000,25000,50000,75000,100000,200000,300000,400000,500000,750000,1000000};
//int cases[1][27] = {};
//amount,inplay
long cases[27][2] = {
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1},
  {0,1}
};

int yourCase = 0;
int gameRound = 0;
int dollarOffer = 0;
int number = 0;
 
void setup() {
  Serial.begin(9600);
  Serial.println("Find a Million\n");
  Serial.println("Maximize the Serial Console Window\nfor a better experiance.\nSet Line Ending to 'Newline'\n\n\n");
  Serial.println("Before we begin, I need a long number:");
   while(!Serial.available()); 
   while(Serial.available() > 0) {
    long number = Serial.parseInt();
    if (Serial.read() == '\n') {
    randomSeed(78745079832 + number + digitalRead(A0) + digitalRead(A5)+millis());
    }
  }
randomizeCases();
Serial.println("\n\n\n\nWelcome to Find a Million.\n");
Serial.println("With your host: Arduino!.\n");
Serial.println("We have 26 cases, all have a dollar value from $1 to 1 Million dollars.");
Serial.println("The cases have been randomized, we have no idea what is in any of them.");
Serial.println("It is your job to walk away with as much cash as you can.\n\n");
Serial.println("\nLet's get started, I need you to choose a case. \nThis will be your case to take home.");
Serial.println("Or if you choose, you can swap for the last case, at the end of the game.");
Serial.println("Whatever is in the case is yours to keep.\n\n");
Serial.println("Give me a case number:\n[1 to 26]: ");
chooseyourcase();
}

void loop() {
gameRound = 1;
displayInPlay();
Serial.println("\nRound 1\nChoose 5 cases: ");
chooseCase(5);
displayRounds();
banker();
deal();

gameRound = 2;
displayInPlay();
Serial.println("\nRound 2\nChoose 5 cases: ");
chooseCase(5);
displayRounds();
banker();
deal();

gameRound = 3;
displayInPlay();
Serial.println("\nRound 3\nChoose 3 cases: ");
chooseCase(3);
displayRounds();
banker();
deal();

gameRound = 4;
displayInPlay();
Serial.println("\nRound 4\nChoose 3 cases: ");
chooseCase(3);
displayRounds();
banker();
deal();

gameRound = 5;
displayInPlay();
Serial.println("\nRound 5\nChoose 2 cases: ");
chooseCase(2);
displayRounds();
banker();
deal();

gameRound = 6;
displayInPlay();
Serial.println("\nRound 6\nChoose 2 cases: ");
chooseCase(2);
displayRounds();
banker();
deal();

gameRound = 7;
displayInPlay();
Serial.println("\nRound 7\n Choose 2 cases: ");
chooseCase(2);
displayRounds();
banker();
deal();

gameRound = 8;
displayInPlay();
Serial.println("\nRound 8\n Choose 1 case: ");
chooseCase(1);
displayRounds();
banker();
deal();

gameRound = 9;
displayInPlay();
Serial.println("\nRound 9\n Choose 1 case: ");
chooseCase(1);
displayRounds();
banker();
deal();

gameRound = 10;
displayInPlay();
Serial.println("\nSwap cases:");
Serial.print("Your case had the ");
Serial.print(cases[yourCase-1][0]);
Serial.print(" dollars in it.");

 //displayCases();
 while(1);
}

void displayInPlay() {
  Serial.print("\nCases in play:\n");
  for (int n=0; n<26; n++) {
      //  Serial.print(" Case: ");
       // Serial.print(n+1);
        //Serial.print(" In Play: ");
        if (cases[n][1] == 0) {} else
          if (cases[n][1] == 1) {Serial.print(" "); Serial.print(n+1);Serial.print(" ");} else
            if (cases[n][1] == 2) {}
      }
    }

void banker() {}
void deal() {}  

void chooseCase(int openCases) {
  for (int i=0;i<openCases; i++) {
    
  chooseAgain:
  Serial.print("Choice Number: ");
  Serial.println(i+1);
  while(!Serial.available()); 
   while(Serial.available() > 0) {
    number = Serial.parseInt();
    if (Serial.read() == '\n') {
      if (number > 26 || number < 1) {
        Serial.println("Please choose a number between 1 and 26!\nChoose another case:");
        goto chooseAgain;
      }
      if (number == yourCase) {
        Serial.println("That is your case.\nChoose again:");
        goto chooseAgain;
      }
      if (cases[number-1][1] == 0) {
        Serial.println("Already choosen. \n Choose another case: ");
        goto chooseAgain;
        }
      }
    }
 Serial.print("Open that case! ");
 Serial.print(" Case: ");
 Serial.print(number);
 Serial.print(" Amount: ");
 Serial.println(cases[number-1][0]);
 cases[number-1][1]=0; // Set out of play
  }
}

void chooseyourcase() {
  choose:
  while(!Serial.available()); 
   while(Serial.available() > 0) {
    yourCase = Serial.parseInt();
    if (Serial.read() == '\n') {
      if (yourCase > 26 || yourCase < 1) {
        Serial.println("Please choose a number between 1 and 26!\nChoose your case:");
        goto choose;
      }
    }
  }
   cases[yourCase-1][1] = 2; //set as players case, takes out of play
}

void randomizeCases() {

  for (int i=0; i<26;i++) {

    rerandom:
      int c = random(0, 26);
      if (cases[c][0] != 0) {
          goto rerandom;}
      cases[c][0] = money[i];
    }
}

void displayRounds() {
  Serial.print("\nRound: ");
  Serial.print(gameRound);
  Serial.print(" Your Case: ");
  Serial.print(yourCase);
  Serial.print(" Current Offer: ");
  Serial.println(dollarOffer);
  Serial.println("\n");
  for (int i=0; i<26; i++) {
    Serial.print("Amount: ");
    Serial.print(money[i]);
    for (int n=0; n<26; n++) {
      if (money[i] == cases[n][0]) {
        //Serial.print(" Case: ");
        //Serial.print(i+1);
        Serial.print(" In Play: ");
        if (cases[n][1] == 0) {Serial.println("No");} else
          if (cases[n][1] == 1) {Serial.println("Yes");} else
            if (cases[n][1] == 2) {Serial.println("Yes");}
      }
    }
  }
}

void displayCases() {
 Serial.print("Your Case: ");
 Serial.print(yourCase);
 Serial.print(" Amount: ");
 Serial.print(cases[yourCase-1][0]); 
 Serial.print(" In Play: ");
 Serial.println(cases[yourCase-1][1]);
 Serial.println();
  
  /*for (int i=0; i<26; i++) {
    Serial.print("Case: ");
    Serial.print(i+1);
    Serial.print(" Amount: ");
    Serial.print(cases[i][0]);
    Serial.print(" IN Play: ");
    Serial.println(cases[i][1]);
  }*/

  for (int i=0; i<26; i++) {
    Serial.print("Amount: ");
    Serial.print(money[i]);
    for (int n=0; n<26; n++) {
      if (money[i] == cases[n][0]) {
        Serial.print(" Case: ");
        Serial.print(n+1);
        Serial.print(" In Play: ");
        if (cases[n][1] == 0) {Serial.println("No.");} else
          if (cases[n][1] == 1) {Serial.println("Yes.");} else
            if (cases[n][1] == 2) {Serial.println("Players.");}
      }
    }
  }
}

