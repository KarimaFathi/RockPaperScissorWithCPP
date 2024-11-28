#include <iostream>
#include <cstdlib>
using namespace std;

enum gameChoices  { rock = 1, paper = 2, scissor = 3 };
enum enWinner { player = 1, computer = 2, draw = 3 };


string setWinnerScreenColor(enWinner winner) {
	switch (winner) {
	case(::player):
		system("color 2F");
		return "Player 1";
	case(::computer):
		system("color 4F");
		cout << "\a";
		return "Computer";
	case(::draw):
		system("color 6F");
		return "No winner";

	}
}


short readNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number > 10 || number <= 0);
	return number;
}


int random(int from, int to) {
	return rand() % (to - from + 1) + from;
}

gameChoices getComputerChoice() {
	int choice = random(1, 3);
	return (gameChoices)choice;
}

gameChoices getUserChoice() {
	int userChoice = readNumber("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ");
	return (gameChoices)userChoice;
}

string playRound(gameChoices userChoice, gameChoices computerChoice) {
		if ((userChoice == ::rock && computerChoice == ::scissor) || 
			(userChoice == ::scissor && computerChoice == ::paper) || 
			(userChoice == ::paper && computerChoice == ::rock)) {
			return setWinnerScreenColor(::player);
		}
		else if (userChoice == computerChoice) {
			return setWinnerScreenColor(::draw);
		}
		else {
			return setWinnerScreenColor(::computer);
		}
}


string getChoiceName(gameChoices choices) {
	switch (choices) {
	case(::rock):
		return "Rock";
	case(::paper):
		return "Paper";
	case(::scissor):
		return "Scissor";
	}
}

void showRoundResult(gameChoices userChoice, gameChoices computerChoice) {
	cout << "Player1 Choice  : " << getChoiceName(userChoice) << endl;
	cout << "Computer Choice : " << getChoiceName(computerChoice) << endl;
	cout << "Round Winner    : " << "[" << playRound(userChoice, computerChoice) << "]\n";
}

void playAllRounds(int number, int &userCounter, int &computerCounter, int &drawCounter) {
	string result;
	gameChoices userChoice;
	gameChoices computerChoice;
	
	for (int i = 1; i <= number; i++) {
		cout << "_______________ Round [" << i << "] ________________\n";

		userChoice = getUserChoice();
		computerChoice = getComputerChoice();
		result = playRound(userChoice, computerChoice);
		if (result == "Player 1") {
			userCounter++;
		}
		else if (result == "Computer") {
			computerCounter++;
		}
		else drawCounter++;
	    showRoundResult(userChoice, computerChoice);
		cout << "__________________________________________\n";
	}
}

void announceFinalResult(int number, int userCounter, int computerCounter, int drawCounter) {
	string finalWinner;
	if (userCounter > computerCounter) {
		finalWinner = setWinnerScreenColor(::player);
	}
	else if (userCounter == computerCounter) {
	
		finalWinner = setWinnerScreenColor(::draw);
	}
	else {
		cout << "\a";
		system("color 4F");
		finalWinner = setWinnerScreenColor(::computer);
	}
	cout << "\t\t_________________________________________________________\n";
	cout << "\t\t\t            +++ G a m e  O v e r +++\n";
	cout << "\t\t_________________________________________________________\n";
	cout << "\t\t_________________ [ Game Final Scores ] _________________\n";
	cout << "\t\tGame Rounds           : " << number << endl;
	cout << "\t\tPlayer 1 won times    : " << userCounter << endl;
	cout << "\t\tComputer won times    : " << computerCounter << endl;
	cout << "\t\tDraw times            : " << drawCounter << endl;
	cout << "\t\tFinal Winner          : " << finalWinner << endl;
	cout << "\t\t_________________________________________________________\n";
}

bool askToReplay() {
	char replay;
	cout << "Do you want to play again ? Y/N ? ";
	cin >> replay;
	if (toupper(replay) == 'Y') {
		return true;
	}
	else if (toupper(replay) == 'N') {
		return false;
	}
	else {
		cout << "Invalid Input. \n";
		return askToReplay();
	}
}

int main()
{
	bool replay = true;
	while (replay) {
		system("cls");
		system("color 0F");

		int numberOfRounds = readNumber("How Many Rounds You Want To Play ( 1 to 10 ) ? \n");

		srand((unsigned)time(NULL));

		int userCounter = 0, computerCounter = 0, drawCounter = 0;
		playAllRounds(numberOfRounds, userCounter, computerCounter, drawCounter);
		announceFinalResult(numberOfRounds, userCounter, computerCounter, drawCounter);

		replay = askToReplay();
	}
	cout << "Thanks for playing! Goodbye!" << endl;
	return 0;
}

