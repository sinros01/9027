#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <conio.h>

void task_5() {
	int length = 0;
	int position = 0;
	int position_1 = 0;
	int c;
	bool exit = false;
	std::cout << "How many characters would you like in your sentence(max 40): ";
	std::cin >> length;
	std::vector<char> sentence = {' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
	std::vector<char> alphabet = { ' ','A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < length; i++){
		sentence[i] = alphabet[position_1];
	}
	do {
		for (int i = 0; i < length; i++) {
			std::cout << " [" << sentence[i] << "] ";
		}
		std::cout << std::endl;
		c = _getch();
		if (c == 'W' || c == 'w') {
			if (position_1 > 0) {
				position_1--;
				sentence[position] = alphabet[position_1];
			}
		}
		if (c == 'S' || c == 's') {
			if (position_1 < 26) {
				position_1++;
				sentence[position] = alphabet[position_1];
			}
		}
		if (c == 'A' || c == 'a') {
			if (position > 0) {
				position--;
			}
		}
		if (c == 'D' || c == 'd') {
			if (position < length) {
				position++;
			}
		}
		if (c == 32) {
			sentence[position] = alphabet[0];
		}
		if (c == 13) {
			exit = true;
		}
	} while (exit == false);
	std::fstream file_task_5("Task_5_sentence.txt", std::ios::out);
	for (int i = 0; i < 40; i++) {
		file_task_5 << sentence[i];
	}
	file_task_5.close();
}
class student {
public:
	std::string name;
	std::string answers;
	int score;
};

//bool compare(student lhs, student rhs) {
//	return lhs.score > rhs.score;
//}

void task_4() {
	std::string correct_answers = "ABDCABDA";
	std::vector<student> student;
	int amount_of_students = 0;
	std::cout << "Enter amount of students: " << std::endl;
	std::cin >> amount_of_students;
	std::fstream file_task_4("Task_4_answerlist.txt", std::ios::out);
	for (int i = 0; i < amount_of_students; i++) {
		std::cout << "Student " << i << std::endl;
		std::cout << "Enter name of the student: ";
		std::getline(std::cin, student[i].name);
		std::cout << "Enter students answers(capital letters): ";
		std::getline(std::cin, student[i].answers);
		file_task_4 << student[i].name << std::endl;
		file_task_4 << student[i].answers << std::endl;
	}
	file_task_4.close();
	for (int j = 0; j < amount_of_students; j++) {
		for (int i = 0; i < 8; i++) {
			if (student[j].answers.at(i) == correct_answers.at(i)) {
				student[j].score++;
			}
		}
	}
	//std::sort(student[0], student[amount_of_students], compare);
	std::cout << "Student name     Score" << std::endl;
	for (int i = 0; i < amount_of_students; i++) {
		std::cout << student[i].name << "             " << student[i].score << std::endl;
	}
	std::cout << "number of students: " << amount_of_students << std::endl;
	int total_score = 0;
	for (int i = 0; i < amount_of_students; i++) {
		total_score = total_score + student[i].score;
	}
	std::cout << "Average score: " << total_score / amount_of_students << std::endl;
	std::cout << "max score: " << student[0].score << std::endl;                           //would have been correct if I would have been able to sort it
	std::cout << "min score: " << student[amount_of_students].score << std::endl;			//would have been correct if I would have been able to sort it


}

char ChangeToCapital(char ch) {
	return toupper(ch);
}

void task_1() {
	bool password_correct = false;
	do {
		std::string password = "ADMINPASS";
		std::string password_attempt = "";
		std::cout << "Enter password: " << std::endl;
		std::getline(std::cin, password_attempt);
		for (int i = 0; i < password_attempt.size(); i++) {
				password_attempt.at(i) = ChangeToCapital(password_attempt.at(i));
		}
		int counter = 0;
		for (int i = 0; i < password.size(); i++) {
			if (password_attempt.at(i) == password.at(i)) {
				counter++;
			}
		}
		if (counter == password.size()) {
			password_correct = true;
		}
		else {
			std::cout << "Wrong password, try again" << std::endl;
		}
	} while (password_correct == false);
}

void task_2() {
	std::vector<std::string> names{ "Jonathan", "Suzan", "Lucy", "John" };
	for (int i = 0; i < 4; i++) {
		std::cout << names[i] << " initial is: " << names[i].at(0) << std::endl;
		std::cout << names[i] << " final char is: " << names[i].at(names[i].size() - 1) << std::endl;
	}
}

void main_menu() {
	bool exit = false;
	int position = 0;
	char c = ' ';
	do {
		std::cout << "MAIN MENU" << std::endl;
		std::cout << "(use W and S to move up and down, and enter to select)" << std::endl;
		std::cout << std::endl;
		if (position == 0) {
			std::cout << "-> | 1: printed names with initials and last char (task 2)" << std::endl;
			std::cout << " | 2: students exam results (task 4)" << std::endl;
			std::cout << " | 3: typing a sentence (task 5)" << std::endl;
			std::cout << " | 4: termiate the program" << std::endl;
		}
		if (position == 1) {
			std::cout << " | 1: printed names with initials and last char (task 2)" << std::endl;
			std::cout << "-> | 2: students exam results (task 4)" << std::endl;
			std::cout << " | 3: typing a sentence (task 5)" << std::endl;
			std::cout << " | 4: termiate the program" << std::endl;
		}
		if (position == 2) {
			std::cout << " | 1: printed names with initials and last char (task 2)" << std::endl;
			std::cout << " | 2: students exam results (task 4)" << std::endl;
			std::cout << "-> | 3: typing a sentence (task 5)" << std::endl;
			std::cout << " | 4: termiate the program" << std::endl;
		}
		if (position == 3) {
			std::cout << " | 1: printed names with initials and last char (task 2)" << std::endl;
			std::cout << " | 2: students exam results (task 4)" << std::endl;
			std::cout << " | 3: typing a sentence (task 5)" << std::endl;
			std::cout << "-> | 4: termiate the program" << std::endl;
		}
		std::cout << std::endl;
		c = _getch();
		if (c == 'W' || c == 'w') {
			if (position > 0) {
				position = position - 1;
			}
		}
		if (c == 'S' || c == 's') {
			if (position < 4) {
				position = position + 1;
			}
		}
		if (c == 13) {
			if (position == 0) {
				task_2();
			}
			if (position == 1) {
				task_4();
			}
			if (position == 2) {
				task_5();
			}
			if (position == 3) {
				exit = true;
			}
		}
	} while (exit == false);
}





int main() {
	//task_1();
	/*task_2();*/
	main_menu();
}