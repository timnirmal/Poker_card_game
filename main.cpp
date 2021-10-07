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
        case 0: return 5.71751; break;
        case 2: return 35.0143; break;
        case 3: return 60.7052; break;
        case 4: return 64.3152; break;
        case 5: return 59.1922; break;
        case 6: return 69.4281; break;
        case 7: return 77.2093; break;
        case 8: return 57.8947; break;
        case 9: return 45.2877; break;
    }
}

int main() {
    //// File Stream
    string dir = "C:\\Users\\timni\\Poker-card-game\\";

    ifstream myReadFile;
    myReadFile.open(dir + "probability.txt");
    string output;
    string s;

    for (int i = 0; i < 12; ++i) {
        probability2.push_back(0);
    }


    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> output;
            s = output;
            probability.push_back( stoi(s) );
        }
    }

    wcout << endl << s.c_str() <<endl;

    wcout <<endl<< " File stream done\n\n";

    for (int i = 0; i < 10; ++i) {
        wcout<< probability[i];
    }
    wcout <<endl<< "\n\n File stream done";


    /*
    size_t pos = 0;
    string delimiter = " ";
    string token;

    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        if (item_count % 2 == 0){
            date = token;
        }if (item_count % 2 == 1){
            account_number = token;
        }
        item_count++;
        s.erase(0, pos + delimiter.length());
    }
    transaction_amount = s;
*/

    card cards;

    //cards.setValue(2,heart);
    //cards.display_card();

    int numPlayers = 3;
    int numRounds = 10;

    ////////////////////////////////////////////////  Create Player
    wcout << endl << "Create Players\n";

    vector<player> Player;  //Player[0] is the dealer
    Player.resize(numPlayers + 1);

    wcout << endl << "Create Players Done\n";


    ////////////////////////////////////////////////  UI Here

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

    wcout << "\nPoker Game";


    int inpNum;
    wchar_t inpStr[50];

    while (true) {
        if (finish) {    //Check termination conditions
            return 0;
        }


        ////Main menu
        wcout << "1. Start" << endl;
        wcout << "2. How to Play" << endl;
        wcout << "3. Settings" << endl;
        wcout << "4. Exit" << endl;

        wcout << "\nEnter number : ";
        wcin >> inpNum;
        wcout << endl;

        //Start
        if (inpNum == 1) {
            //puzzleGen();
            wcout << "\nEnter your name : ";
            wcin >> inpStr;
            wcout << endl;
            wcout<<"Name : "<<inpStr;
            wstring ws(inpStr);
            string str(ws.begin(), ws.end());
            Player[1].setPlayerName(str);
            wcout<<endl;
            wcout<<"Name : "<< Player[1].getPlayerName().c_str();
            wcout<<endl;

            string playerNameSet[10] = {"Shamika","Bari","Melodi","Rolland","Peter","Roger","Jessia","Claudia","Robbie"};

            for (int i = 2; i < numPlayers; ++i) {
                Player[i].setPlayerName(playerNameSet[i]);
            }

            for (int i = 0; i < 2; i++) {
                ////////////////////////////////////////////////  Deck Create and Shuffle
                deck deckOfCards;

                deckOfCards.show();

                for (int j=0; j<=i; j++){
                    deckOfCards.shuffle();
                }
                wcout << endl;

                wcout << endl;
                deckOfCards.show();
                wcout << endl;
                wcout << endl;

                ////////////////////////////////////////////////  Card Distribution
                //erase first two values
                deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());
                deckOfCards.deckOfCards.erase(deckOfCards.deckOfCards.begin());

                wcout << endl;
                deckOfCards.show();
                wcout << endl;

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
                Player[0].hand.back().display_card();
                Player[0].getHandCard(0).display_card();
                wcout << endl;

                wcout << "displaycard\n\n";

                for (int i = 0; i < 4; i++) {
                    for (int j = 0; j < 5; j++) {
                        Player[i].hand[j].display_card();
                    }
                    wcout << endl;
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

                    wchar_t withdraw_string[10];
                    //// In here we need to let user and players to left this hand
                    // For user
                    if (j == 1) {
                        wcout << "\nDo you need to Withdraw ? ";
                        wcin >> withdraw_string;
                        wstring withdraw_s(withdraw_string);
                        string withdraw_str(withdraw_s.begin(), withdraw_s.end());
                        wcout << "W => " << withdraw_str.c_str();

                        if (withdraw_str == "Y" ||withdraw_str == "y"  ) {
                            wcout << endl;
                            Player[1].setStatus(false);
                            wcout << "Wait Until Round Finish.\n";
                        }
                        else {
                            wcout << endl;
                            Player[1].setStatus(true);
                            wcout << "Play \n";
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

                            wcout << "num = " << randNum << endl;
                            wcout << "Possibility = " << playerRandNum << endl;
                            wcout << "tempScore = " << tempScore << endl;

                        }
                        else {
                            Player[j].setStatus(false);
                        }
                    }


                    wcout << "Me Score = " << Player[1].getStatus() << endl;

                    if (Player[j].getStatus() == true){
                        arrScore.push_back(tempScore);    //Add score to the hand score array
                        arrScoreLength++;
                    }else{
                        arrScore.push_back(-1);
                    }

                    if (tempScore == 0) {   //Take if it is a high card combination
                        highCardCount++;
                    }

                    wcout << "\nScore = " << tempScore;
                    wcout << "\tHigh Card = ";
                    Player[j].highCard().display_card();
                    wcout << endl;

                }

                wcout << endl << "arrScore = " << arrScore.size() <<endl;

                for (int i = 0; i < arrScore.size(); i++) {
                    wcout << arrScore[i] << " ";
                }

                int tempHighScore = arrScore[0];
                int winnerPosition = 0;
                int tempCount = 0;

                wcout << endl;
                for (int i = 0; i < arrScore.size(); i++) {
                    wcout << arrScore[i] << " ";
                }

                wcout << endl << "Size = " << arrScore.size() << endl;

                for (int i = 0; i < arrScore.size() ; i++) {
                    wcout<< "arrScore["<<i<<"] is " << arrScore[i] <<endl;
                    wcout<< "tempHighScore"<< tempHighScore <<endl;
                    if (tempHighScore < arrScore[i]) {
                        wcout << tempHighScore << " "<< arrScore[i]  << i<<endl;
                        tempHighScore = arrScore[i];
                        winnerPosition = i;
                    }
                }
                wcout << endl << tempHighScore << " " << winnerPosition;

            /*    //Check if two people have The Highest Val
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
                }*/

                // Now we have checked who wins
                // If there are two winners and that also calculated.
                // But if that also get tie then that part is to be added. (Scores will be given to both.)

                /*
                    winnerPosition is the position of winner in Player array
                    Player[winnerPosition] is winner
                    tempHighScore is his score

                    Others score can be taken by playerHandScore

                 */


                wcout << endl;
                wcout << "Winner is " << winnerPosition << "   Score : " << tempHighScore;
                probability2[tempHighScore]++;
                wcout << "\n\nOthers Score \n";

                /////////// Add Scores to Main Score

                for (int i = 0; i < Player.size() ; i++) {
                    tempScore = Player[i].getPlayerHandScore();
                    //Player[i].addPlayerScore(tempScore);

                    if (i == winnerPosition){
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

                    wcout << "Player " << i << "   Score : " << arrScore[i] << "   Total Score : " << Player[i].getPlayerScore()
                          << endl;
                    probability[tempScore]++;
                }



                wcout<<endl;
                wcout<<endl;
                for (int i = 0; i < Player.size() ; i++) {
                    wcout << "Player " << i << "   Score : " << arrScore[i] << "   Total Score : " << Player[i].getPlayerScore()
                          << endl;
                }


                ////////////////////////////////////////////////  Each Hand Score Calculation Done & Winner is Chosen & Score Boards are Updated.

                //Players cards are hidden
                //Dealers cards are visible

                // Probability
                // Log File

                wcout <<endl<< "\n\n";
                {   //Remove Later
                    for (int i = 0; i < 10; ++i) {
                        wcout << probability[i] << " ";
                    }
                    wcout << endl << "\n\n File stream done\n";
                    for (int i = 0; i < 10; ++i) {
                        wcout << probability2[i] << " ";
                    }

                    wcout << endl << "\n\n";

                    ofstream outfile(dir + "probability.txt");
                    for (int i = 0; i < 10; ++i) {
                        outfile << probability[i] << endl;
                    }
                    for (int i = 0; i < 10; ++i) {
                        outfile << probability2[i] << endl;
                    }

                    outfile.close();
                }

                tiePositions.clear();   // If tie Positions cleared
                tie = false;            // Make tie to untie

                arrScore.clear();
            }

        }
            //How to Play
        else if (inpNum == 2) {

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



    //5.79121
    //34.9811
    //61.0685
    //64.2276
    //57.6271
    //69.3639
    //71.6981
    //62.5
    //45.7143

    //Winning Probability if each Score comes.

    // If probability is 20% > the players will play && Dealers Card

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