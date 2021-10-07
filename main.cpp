/********************************************************************************
 * Name             : Nirmal L.Y.T.
 * Index No         : 19/ENG/072
 * Registration No  : EN93921
*********************************************************************************/

/********************************************************************************
 * In this Game we have Dealer, You as a Player and Other Players.
 * By default there are 3 Players and Dealer & There are 10 rounds.
 *
 * The Dealer Plays with you but he don't gain any points.
 * Their actions controlled by the programme. This is done by using Probability.
 * For that the probability is calculated using 80,000 tests.
 * Then that values multiplied with a random value to give some randomness.
 *
 * Happy Gaming.....
*********************************************************************************/

/////// ****** Change Dir before Playing
// You can change numRound if you want.

#include <iostream>
#include <windows.h>
#include <io.h>
#include <fstream>
#include <string>
#include <ctime>

#include "deck.h"
#include "player.h"

//enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

bool tie = false;
vector<int> tiePositions;   //Clear at each round
vector <int> probability;
vector <int> probability2;

int player::nextId = 0;
bool finish = 0;
bool effectEnable = 1;

int checkHighCard(card c1, card c2, int p1, int p2) {
    wcout << "\nChecking High Card "<< endl;
    c1.display_card();
    wcout <<endl;
    c2.display_card();

    if (c1.getValueA() > c2.getValueA()){
        return p1;
    }
    else if (c1.getValueA() < c2.getValueA()){
        return p2;
    }
    else {
        tie = true;
        tiePositions.push_back(p1);
        tiePositions.push_back(p2);
    }
}

int checkOnePair (int c1, int c2, int p1, int p2) {
    if (c1 == 1) c1 = 14;
    if (c2 == 1) c2 = 14;

    wcout << "\nChecking One Pair "<< endl;
    wcout << c1;
    wcout <<endl;
    wcout << c2;

    if (c1 > c2){
        return p1;
    }
    else if (c1 < c2){
        return p2;
    }
    else {
        tie = true;
        tiePositions.push_back(p1);
        tiePositions.push_back(p2);
    }
}

//Text Animations
void textLoader(string txt){
    vector<char> LoaderTXT(txt.begin(), txt.end());
    for (const char &c: LoaderTXT) {
        //Switch Based on Effects Settings
        if (effectEnable == true) {
            wcout << "G";
            Sleep(30);
            wcout<< "\b ";
            Sleep(40);
        }
        std::wcout << c;
    }
}

float Possibility (int score){
    // 5.71751 35.0143 60.7052 64.3152 59.1922 69.4281 77.2093 57.8947 45.2877
    switch (score) {
        case 0: return 5.71751;
        case 2: return 35.0143;
        case 3: return 60.7052;
        case 4: return 64.3152;
        case 5: return 59.1922;
        case 6: return 69.4281;
        case 7: return 77.2093;
        case 8: return 57.8947;
        case 9: return 45.2877;
    }
}

int main() {
    //// File Stream
    string dir = "C:\\Users\\timni\\Poker-card-game\\";

    //// File Reading
    ifstream myReadFile;
    myReadFile.open(dir + "probability.txt");
    string output;
    string s;

    for (int i = 0; i < 12; ++i) {
        probability2.push_back(0);
        probability.push_back(0);
    }

    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            s = output;
        }
    }

    wcout<<endl;

    ofstream outfile(dir + "probability.txt");
    outfile.close();

    //// File Reading

    int numPlayers = 3;
    int numRounds = 10;

    ////////////////////////////////////////////////  Create Player

    vector<player> Player;  //Player[0] is the dealer
    Player.resize(numPlayers + 1);

    ////////////////////////////////////////////////  UI Here


    int inpNum;
    wchar_t inpStr[50];

    while (true) {
        if (finish) return 0; //Check termination conditions

        ////Main menu
        wcout << "\n";
        wcout << "$$$$$$$\\            $$\\                                  $$$$$$\\                                    \n";
        wcout << "$$  __$$\\           $$ |                                $$  __$$\\                                   \n";
        wcout << "$$ |  $$ | $$$$$$\\  $$ |  $$\\  $$$$$$\\   $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\$$$$\\   $$$$$$\\  \n";
        wcout << "$$$$$$$  |$$  __$$\\ $$ | $$  |$$  __$$\\ $$  __$$\\       $$ |$$$$\\  \\____$$\\ $$  _$$  _$$\\ $$  __$$\\ \n";
        wcout << "$$  ____/ $$ /  $$ |$$$$$$  / $$$$$$$$ |$$ |  \\__|      $$ |\\_$$ | $$$$$$$ |$$ / $$ / $$ |$$$$$$$$ |\n";
        wcout << "$$ |      $$ |  $$ |$$  _$$<  $$   ____|$$ |            $$ |  $$ |$$  __$$ |$$ | $$ | $$ |$$   ____|\n";
        wcout << "$$ |      \\$$$$$$  |$$ | \\$$\\ \\$$$$$$$\\ $$ |            \\$$$$$$  |\\$$$$$$$ |$$ | $$ | $$ |\\$$$$$$$\\ \n";
        wcout << "\\__|       \\______/ \\__|  \\__| \\_______|\\__|             \\______/  \\_______|\\__| \\__| \\__| \\_______|\n";
        wcout << "                                                                                                    \n";
        wcout << "                                                                                                    \n";
        wcout << "                                                                                                    ";
        wcout << endl ;
        wcout << "\t1. Start" << endl;
        wcout << "\t2. How to Play" << endl;
        wcout << "\t3. Settings" << endl;
        wcout << "\t4. Exit" << endl;

        wcout << "\nEnter number : ";
        wcin >> inpNum;

        //Start
        if (inpNum == 1) {
            //puzzleGen();
            wcout << "\nEnter your name : ";
            wcin >> inpStr;
            wcout << endl;

            wcout << "\t";
            textLoader("Hello ") ;
            wcout<<inpStr;

            wstring ws(inpStr);
            string str(ws.begin(), ws.end());
            Player[1].setPlayerName(str);
            wcout<<endl <<endl;
            wcout << "Let's Begin the Game.."<<endl<<endl;
            string playerNameSet[10] = {"Shamika","Bari","Melodi","Rolland","Peter","Roger","Jessia","Claudia","Robbie"};

            for (int i = 2; i < Player.size(); ++i) {
                Player[i].setPlayerName(playerNameSet[i]);
            }

            for (int i = 0; i < numRounds; i++) {
                ////////////////////////////////////////////////  Deck Create and Shuffle
                deck deckOfCards;

                deckOfCards.show();

                wcout << endl << endl << "Shuffling ....." <<endl <<endl;
                for (int j=0; j<=i; j++){
                    deckOfCards.shuffle();
                }
                system("cls");
                wcout << endl <<endl;
                textLoader("Card Pack Shuffled....\n\n");


                ////////////////////////////////////////////////  Card Distribution
                //erase first two values
                deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
                deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());

                for (int i = 0; i < 4; i++) {
                    card newCard;
                    //wcout << i.getName().c_str();
                    //copy 5 card to hand of each player
                    for (int j = 0; j < 5; j++) {
                        newCard.setValue(deckOfCards.deckOfCards.begin()->getValue(),
                                         deckOfCards.deckOfCards.begin()->getSuit());
                        Player[i].hand[j] = newCard;
                        deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
                    }
                }

                wcout << endl;

                textLoader("Distributing....\n\n");

                system("cls");
                wcout << endl;

                Player[0].setPlayerName("Dealer");
                system("cls");
                for (int i = 0; i < 2; i++) {
                    wcout << Player[i].getName().c_str() << "'s Hand \t";
                    for (int j = 0; j < 5; j++) {
                        Player[i].hand[j].display_card();
                        wcout << " ";
                    }
                    wcout << endl << endl;;
                }
                wcout << endl;

                ////////////////////////////////////////////////  Calculate Scores
                //Calculating Score of Each Player
                int highCardCount = 0;      //Count if all are high cards.
                int tempScore;              // to Keep player score of each round of each player
                vector<int> arrScore; //4 Players

                int arrScoreLength = 0;

                for (int j = 0; j < 4; j++) {
                    tempScore = Player[j].score();  //Calculate Player score

                    Player[j].setPlayerHandScore(tempScore);    //Set Player's this hand score

                    /////////////////  We need to let players withdraw before moving further
                        // Player [0] is Dealer
                        // Player [1] is Player
                        // Other Players are controlled by game logic.
                    if (j == 1){
                        wcout << "\nYour Score = " << tempScore;
                        wcout << "\t\tHigh Card = ";
                        Player[0].highCard().display_card();

                        wcout << "\nDealer's Score = " << tempScore;
                        wcout << "\tHigh Card = ";
                        Player[1].highCard().display_card();
                    }

                    wchar_t withdraw_string[10];
                    //// In here we need to let user and players to left this hand
                    // For user
                    if (j == 1) {
                        wcout << "\n\nDo you need to Withdraw ? ";
                        wcin >> withdraw_string;
                        wstring withdraw_s(withdraw_string);
                        string withdraw_str(withdraw_s.begin(), withdraw_s.end());

                        if (withdraw_str == "Y" ||withdraw_str == "y"  ) {
                            wcout << endl;
                            Player[1].setStatus(false);
                            wcout << "Wait Until Round Finishes...\n";
                        }
                        else {
                            Player[1].setStatus(true);
                        }
                    }

                    // For Other Players Except Dealer
                    if (j > 1){
                        if (tempScore >= Player[0].getPlayerHandScore()){
                            // Equal or Larger than Dealers Score
                            // 5.71751 35.0143 60.7052 64.3152 59.1922 69.4281 77.2093 57.8947 45.2877
                            // Let's get possibilities higher than 20% to play further
                            // In that case only High Card combination

                            srand(time(0));
                            float randNum;
                            for (int k=0; k < i+j+1; k++){
                                randNum = (rand() % 200 + 1) / 100.0;
                            }
                            float playerRandNum = randNum * Possibility(tempScore);

                            // If this value less than 0.2 then user will be withdrawn
                            if (playerRandNum < 0.2){
                                Player[j].setStatus(false);
                            }
                            else {
                                Player[j].setStatus(true);
                            }
                        }
                        else {
                            Player[j].setStatus(false);
                        }
                    }

                    if (Player[j].getStatus() == true){
                        arrScore.push_back(tempScore);    //Add score to the hand score array
                        arrScoreLength++;
                    }else{
                        arrScore.push_back(-1);
                    }

                    if (tempScore == 0) {   //Take if it is a high card combination
                        highCardCount++;
                    }
                }


                int tempHighScore = arrScore[0];
                int winnerPosition = 0;
                int tempCount = 0;

                for (int i = 0; i < arrScore.size() ; i++) {
                    if (tempHighScore < arrScore[i]) {
                        tempHighScore = arrScore[i];
                        winnerPosition = i;
                    }
                }

    //Check if two people have The Highest Val
                for (int i = 0; i < 4; i++) {
                    if (arrScore[i] == tempHighScore && winnerPosition != i) {
                        //wcout << "\nDuplicate";
                        switch (tempHighScore) {
                            case 0:
                            case 6:
                                // 5 Cards have same color and Highest card win among players
                                winnerPosition = checkHighCard(Player[winnerPosition].highCard(), Player[i].highCard(),
                                                               winnerPosition, i);
                                wcout << "\n\nWinner(0) = " << winnerPosition;
                                break;
                            case 2:
                                winnerPosition = checkOnePair(Player[winnerPosition].OnePair(), Player[i].OnePair(),
                                                              winnerPosition,
                                                              i);
                                wcout << "\n\nWinner(2) = " << winnerPosition;
                                break;
                            case 3:
                                winnerPosition = checkOnePair(Player[winnerPosition].TwoPair(), Player[i].TwoPair(),
                                                              winnerPosition,
                                                              i);
                                //The highest Pair comes to here
                                wcout << "\n\nWinner(3) = " << winnerPosition;
                                break;
                            case 4:
                                winnerPosition = checkOnePair(Player[winnerPosition].ThreePair(), Player[i].ThreePair(),
                                                              winnerPosition, i);
                                wcout << "\n\nWinner(4) = " << winnerPosition;
                                break;
                            case 5:
                            case 9:
                                winnerPosition = checkOnePair(Player[winnerPosition].straight(), Player[i].straight(),
                                                              winnerPosition, i);
                                wcout << "\n\nWinner(5/9) = " << winnerPosition;
                                break;
                            case 7:
                                // Game Logic For Full House tie
                                // First Higher Triples wins
                                // If that gets equal then highest Pair Wins
                                // If that also get equal both get points
                                winnerPosition = checkOnePair(Player[winnerPosition].ThreePair(), Player[i].ThreePair(),
                                                              winnerPosition, i);
                                if (tie == true) {
                                    tie = false;
                                    winnerPosition = checkOnePair(Player[winnerPosition].TwoPair(), Player[i].TwoPair(),
                                                                  winnerPosition, i);
                                }
                                wcout << "\n\nWinner(7) = " << winnerPosition;
                                break;
                            case 8:
                                winnerPosition = checkOnePair(Player[winnerPosition].FourPair(), Player[i].FourPair(),
                                                              winnerPosition, i);
                                wcout << "\n\nWinner(8) = " << winnerPosition;
                                break;
                        }
                    }
                }

                // Now we have checked who wins
                // If there are two winners and that also calculated.
                // But if that also get tie then that part is to be added. (Scores will be given to both.)

                wcout << endl;
                wcout << "Winner is " << winnerPosition << "   Score : " << tempHighScore;
                probability2[tempHighScore]++;

                wcout << "\n\nScore Card\n\n";

                /////////// Add Scores to Main Score

                for (int i = 0; i < Player.size() ; i++) {
                    tempScore = Player[i].getPlayerHandScore();

                    if (i == winnerPosition){
                        Player[winnerPosition].addPlayerScore(10);
                        if (tie = true) {
                            for (int j=0; j<tiePositions.size(); j++){
                                Player[j].addPlayerScore(10);
                            }
                        }
                        else{
                            Player[winnerPosition].addPlayerScore(10);
                        }

                    }
                    else if (arrScore[i] == -1){
                        Player[i].addPlayerScore(0);
                    }
                    else {
                        Player[i].addPlayerScore(-1);
                    }
                    probability[tempScore]++;
                }

                float totScore = 0;
                float Prob = 0;

                for (int i = 1; i < Player.size() ; i++) {
                    totScore += Player[i].getPlayerScore();
                }

                for (int i = 1; i < Player.size() ; i++) {
                    Prob = (Player[i].getPlayerScore()*100/totScore);
                    wcout << Player[i].getName().c_str() << "\t\t"
                    << "Score : " << arrScore[i]
                    << "   Total Score : " << Player[i].getPlayerScore()
                    << "  Probability  " << Prob << " %"<< endl;
                }

                wcout << endl;
                system("pause");
                ////////////////////////////////////////////////  Each Hand Score Calculation Done & Winner is Chosen & Score Boards are Updated.

                //Players cards are hidden
                //Dealers cards are visible

                // Probability
                // Log File

                wcout <<endl<< "\n\n";
                {   //Remove Later


                    ofstream outfile(dir + "probability.txt",ios_base::app);
                    for (int i = 0; i < Player.size() ; i++) {

                        Prob = (Player[i].getPlayerScore()*100/totScore);
                        outfile << Player[i].getName().c_str() << "\t\t"
                              << "Score : " << arrScore[i]
                              << "   Total Score : " << Player[i].getPlayerScore()
                              << "  Probability  " << Prob << " %"<< endl;
                    }
                    outfile <<endl;
                    outfile.close();
                }

                system("cls");

                tiePositions.clear();   // If tie Positions cleared
                tie = false;            // Make tie to untie

                arrScore.clear();
            }


            ofstream outfile(dir + "probability.txt");
            for (int i = 0; i < Player.size() ; i++) {
                outfile << endl;
                outfile << "Number of Players Played " << numPlayers <<endl;
                outfile << "Number of Rounds Played " << numRounds <<endl;
            }

            outfile.close();
        }
            //How to Play
        else if (inpNum == 2) {
            wcout << "In this Game we have Dealer, You as a Player and Other Players.\n";
            wcout << "By default there are 3 Players and Dealer & There are 10 rounds.\n";
            wcout << "\n";
            wcout << "The Dealer Plays with you but he don't gain any points.\n";
            wcout << "Their actions controlled by the programme. This is done by using Probability.\n";
            wcout << "For that the probability is calculated using 80,000 tests.\n";
            wcout << "Then that values multiplied with a random value to give some randomness.\n";
            wcout << "\n";
            wcout << "Happy Gaming.....\n";
            wcout << "\n";
        }
            //Settings
        else if (inpNum == 3) {
            system("cls");
            wcout<<endl;
            wcout << "\t * * * Settings * * *" << endl;
            wcout<< "\nCurrent Settings : \n\tEffects : "<<effectEnable;
            //cout <<  "\n\tLevel : "<<Level<<endl;

            char inp;

            wcout<< "\n\nChange Effect (y/n) : ";
            cin>>inp;
            if(inp=='y' || inp=='Y'){
                effectEnable = !effectEnable;
            }else{
                effectEnable = effectEnable;
            }

            cout<<"Changed Effects : "<<effectEnable<<endl<<endl;
        }
            //Exit
        else if (inpNum == 4) {
            system("cls");
            textLoader("\nExiting.....");
            wcout<<endl<<endl;
            wcout<< "\tThank you for Playing";
            wcout<<endl<<endl;
            finish = true;
        }

    }

    return 0;
}

//Value
//2-10 & Jack, Queen, King, and Aces
//Shape Spade, Diamond, Heart, and Club
//Color

//Dealer shuffles the cards
//removes the first two cards in the pack
//distributes five cards (hands) for each player including himself
//The players’ hands are not visible but the dealer cards are visible