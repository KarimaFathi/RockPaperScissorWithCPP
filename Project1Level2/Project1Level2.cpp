#include <iostream>
using namespace std;

enum gameChoices  { rock = 1, paper = 2, scissor = 3 };
//enum gameRules { winner = 1, };

short readNumber(string message) {
	int number;
	do {
		cout << message;
		cin >> number;
	} while (number > 10 || number <= 0);
	return number;
}


int random(int from, int to) {
	return rand() % (from - to + 1) + from;
}

gameChoices getComputerChoice() {
	int choice = random(1, 3);
	return (gameChoices)choice;
}

gameChoices getUserChoice() {
	int userChoice = readNumber("Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors ?");
	return (gameChoices)userChoice;
}

string playRound(gameChoices userChoice, gameChoices computerChoice) {
	/*for (int i = 1; i <= number; i++) {
		cout << "Round [" << i << "] begins:\n";*/
		if ((userChoice == ::rock && computerChoice == ::scissor) || userChoice == ::scissor && computerChoice == ::paper) {
			system("color 2F");
			return "user";
		}
		else if (userChoice == computerChoice) {
			system("color 6F");
			return "no winner";
		}
		else {
			system("color 4F");
			return "computer";
		}
	//}
}

void showRoundResult(gameChoices userChoice, gameChoices computerChoice) {
	cout << "Player1 Choice  : " << userChoice << endl;
	cout << "Computer Choice : " << computerChoice << endl;
	cout << "Round Winner    : " << "[" << playRound(userChoice, computerChoice) << "]\n";
}


int main()
{
	//int numberOfRounds = readNumber("How Many Rounds You Want To Play ( 1 to 10 ) ? \n");
	srand((unsigned)time(NULL));
	gameChoices computerChoice = getComputerChoice();
	gameChoices userChoice = getUserChoice();
	showRoundResult(userChoice, computerChoice);
	srand((unsigned)time(NULL));

}

