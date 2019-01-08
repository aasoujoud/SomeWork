#include <iostream>
#include <conio.h>
#include <ctime>
#include <windows.h>
#include <vector>
#include<algorithm>

using namespace std;

class Player{
	private: 
		string name;
		int score = 0;
		int amountTurns;
		int ranking;
		int age;
		int level;			
		float winnings;
		float betAmount;
		vector<int> scores;
		int highScore;
		
	public:						
		Player(string);
		Player(string,int);
		Player(string,int,int);
	 
		void setName(string);
		string getName();
		
		void setScore(int);
		int getScore();
		
		void setAmountTurns(int);
		int getAmountTurns();
		
		void setRanking(int);
		int getRanking();
		
		void setAge(int);
		int getAge();
		
		void setLevel(int);
		int getLevel();
		
		void setWinnings(float);
		float getWinnings();
		
		void setBetAmount(float);
		float getBetAmount();
		
		void setHighScore();
		int getHighScore();
		
		Player& operator++();
		void loadVector();
};

	void Player::setName(string n ){name= n;}
	string Player::getName(){return name;}
	
	void Player::setScore(int s){score = s;}
	int Player::getScore(){return score;}
	
	void Player::setAmountTurns(int at){amountTurns = at;}
	int Player::getAmountTurns(){return amountTurns;}
	
	void Player::setRanking(int r ){ranking=r;}
	int Player::getRanking(){return ranking;}
	
	void Player::setAge(int ag ){age=ag;}
	int Player::getAge(){return age ;}
	
	void Player::setLevel(int lvl ){level=lvl;}
	int Player::getLevel(){return level ;}
	
	void Player::setWinnings(float win ){winnings=win;}
	float Player::getWinnings(){return winnings ;}
	
	void Player::setBetAmount(float ba ){betAmount=ba;}
	float Player::getBetAmount(){return betAmount ;}
	
	int Player::getHighScore(){return highScore ;}
	
void Player::setHighScore(){
	int max=*max_element(scores.begin(), scores.end());
	highScore=max;
}
	

Player::Player(string s, int a)
{
	name = s;
	age = a;
	
}

void Player :: loadVector(){
	scores.push_back(score);
}

class Dice{
	private: 
		int value;
	
	public: 
		Dice();
		void roll();
		int getValue();
	
};

Dice ::Dice(){
	srand(time(0));
	value=  rand() % 6 + 1;
}

void Dice:: roll(){
	srand(time(0));
	value= rand() % 6 + 1;
}

Player& Player::operator++(){
	++score;
	return *this;
}



int Dice::getValue(){return value;}

void drawGrid(char grid[8][8]){
	for(int i=0; i<8; i++)    //This loops on the rows.
		{
			for(int j=0; j<8; j++) //This loops on the columns
			{
				cout<<grid[i][j]<<"                ";
			}
			cout<<"\n\n\n";
		}
}

int main()
{
	bool GAME = true;
	string name;
	int age;
	int game;
	cout<<"Enter in your name: "<<endl;
	getline(cin,name);
	cout<<"Enter in your age: "<<endl;
	cin>>age;
	Player first(name,age);
	
	while (GAME){
		Dice dice;
	    char grid[8][8] = {{'|',' ',' ',' ',' ',' ',' ','|'},
	                   {'|',' ',' ',' ',' ',' ',' ','|'},
	                   {'|',' ',' ',' ',' ',' ',' ','|'},
	                   {'|',' ',' ',' ',' ',' ',' ','|'},
	                   {'|',' ',' ',' ',' ',' ',' ','|'},
					   {'|',' ',' ',' ',' ',' ',' ','|'},
					   {'|',' ',' ',' ',' ',' ',' ','|'},
					   {'-','-','-','-','-','-','-','-'}};
	    char key = ' ';
	    char player= '>';
	    char computer = '*';
	    int horizentalPosition = 4;
	    int verticalPosition = 1;
	    int rand1,rand2;
	    rand1 = dice.getValue();
	    dice.roll();
	    rand2 = dice.getValue();
	    grid[rand1][rand2] = computer;
	    
	    grid[horizentalPosition][verticalPosition] = player;
	    
	    cout<<"\nYou will get 50 turns, use the best ways to get the points !";
	    cout<<"\nOh also remember, you can go from one side to the other using a shortcut *HINT*.";
	    Sleep(3000);
	    
	    int counter = 0;
	    	drawGrid(grid);
			while(counter != 50){
				key = _getch();
				if(key == 'w'){
					system("CLS");
					grid[horizentalPosition][verticalPosition] = ' '; // clear recent position
					player='^';									// make player look "up"
					horizentalPosition -=1;							// plus to mouse position				
					if(horizentalPosition  == 0){		        // border control									
						horizentalPosition  = 6;				//trump's  border controll wall 
					}
				}
				else if(key == 's'){
					system("CLS");
					grid[horizentalPosition ][verticalPosition] = ' ';
					player='V';
					horizentalPosition +=1;
					if(horizentalPosition  == 7){
						horizentalPosition  = 1;
					}
				}
				else if(key == 'd'){
					system("CLS");
					grid[horizentalPosition ][verticalPosition] = ' ';
					player = '>';
					verticalPosition+=1;
					if(verticalPosition == 7){
						verticalPosition = 1;
					}
				}
				else if(key == 'a'){
					system("CLS");
					grid[horizentalPosition ][verticalPosition] = ' '; 
					player = '<';
					verticalPosition-=1;
					if(verticalPosition == 0){
						verticalPosition = 6;
					}
				}
				if(grid[horizentalPosition][verticalPosition] == '*'){
						int rand1Copy,rand2Copy;
						rand1Copy = rand1;
						rand2Copy = rand2;
						grid[rand1][rand2]=' ';
						++first;
						dice.roll();
						rand1 = dice.getValue();
					    dice.roll();
					    rand2 = dice.getValue();
					    grid[rand1][rand2] = computer;
					    while((rand1 ==  rand1Copy) && (rand2 == rand2Copy )){ // while first two random numbers are the same, it will generate new numbers!										
					    	dice.roll();	
							rand1 = dice.getValue();
						    dice.roll();
						    rand2 = dice.getValue();
						    grid[rand1][rand2] = computer;	
						}
				}	
				grid[horizentalPosition ][verticalPosition] = player;  // new position after info was taken from keyboard
				drawGrid(grid);	
													// draw grid
				counter++;
			}
		system("CLS");
		first.loadVector();
	    cout<<"You scored: "<<first.getScore()<<endl;
	    first.setScore(0); 
	    Sleep(1000);
	    cout<<"Would you like to continue playing? (0/Yes ---- Any other number/NO)";
	    cin>>game;
	    if(game != 0) 
	    	break;
	    else 
	    	continue;
	}
	first.setHighScore();
	cout<<"Highest score: "<<first.getHighScore()<<", Thank you for playing "<<first.getName();;
	cout<<" Have a good day!";
}
