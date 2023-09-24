#pragma once
#include <iostream>
#include "Include.h"

using namespace std;

class User_Class {
private:
	HANDLE color;
	string firstName;
	string lastName;
	int birthMonth;
	int birthDay;
	int birthYear;
	int age;

	void setAge() {
		time_t current_time;
		current_time = time(NULL);
		int currentYear;
		currentYear = 1970 + current_time / 31537970;
		//inorder to set 'age' variable
		age = currentYear - birthYear;
	}

public:
	User_Class() {
		this->color = GetStdHandle(STD_OUTPUT_HANDLE);
		this->firstName = "Bjarne";
		this->lastName = "Stroustrup";
		this->birthMonth = 12;
		this->birthDay = 30;
		this->birthYear = 1950;
		this->age = 2022;
		setAge();
	}

	~User_Class() {
		this->color = NULL;
		this->firstName = "null";
		this->lastName = "null";
		this->birthMonth = NULL;
		this->birthDay = NULL;
		this->birthYear = NULL;
		this->age = NULL;
	}

	void setUserInformation(string fName, string lName, int bmonth, int bDay, int bYear) {
		this->firstName = fName;
		this->lastName = lName;
		this->birthMonth = bmonth;
		this->birthDay = bDay;
		this->birthYear = bYear;
		setAge();
	}

	void log_in() {
		system("cls");
		SetConsoleTextAttribute(color, 3);
		cout << endl << "For the best user experience, please use true and accurate data for the following questions" << endl << endl;
		cout << "What is your first name?: ";
		cin >> firstName;
		cout << "What is your last name?: ";
		cin >> lastName;
		cout << endl << "Next I am going to ask you for your birth date.  Please use number only!" << endl;
		cout << "An example of a valid date is 12/21/2012" << endl << endl;		
		cout << "What is you birth MONTH?: ";
		cin >> birthMonth;
		cout << "What DAY where you born on?: ";
		cin >> birthDay;
		cout << "What YEAR where you born in?: ";
		cin >> birthYear;
		setAge();

	}

	void displayUserInformation() {
		system("cls");
		SetConsoleTextAttribute(color, 3);
		cout << endl << endl;
		cout << "The Current User of this program is " << firstName << " " << lastName;
		cout << endl << "You told me your Birth date was " << birthMonth << "/" << birthDay << "/" << birthYear;
		cout << endl << "That means you will turn " << age << " this year";
		cout << "\n\n";
		system("pause");
	}

	string returnUser_FirstName() {
		return firstName;
	}
	string  returnUser_FullName() {
		return firstName, lastName;
	}

	int returnUser_Birthdate() {
		return birthMonth, birthDay, birthYear;
	}

	int returnUser_Age() {
		return age;
	}
};

class ProgramDisplay {
private:
	string programName;
	string programVersion;
	HANDLE color;

	void drawHeaderMethod() {
		system("cls");
		SetConsoleTextAttribute(color, 7);
		cout << programName << " " << programVersion << endl << endl;
	}
	
public:
	ProgramDisplay() {
		this->programName = "OmniCodeProject 3";
		this->programVersion = "Version 0.13";
		this->color = GetStdHandle(STD_OUTPUT_HANDLE);
	};

	~ProgramDisplay() {
		this->programName = "null";
		this->programVersion = "null";
		this->color = NULL;
	}
	
	void mainMenuDisplay() {
		drawHeaderMethod();
		SetConsoleTextAttribute(color, 2);
		cout << "The following is a list of available commands" << endl << endl;
		cout << "Type 'i' for more information about the programs listed here" << endl;
		cout << "Type 'l' to log onto " << programName << endl;
		cout << "Type 'u' to see your user information" << endl;
		cout << "Type 'q' to Quit " << programName;
		cout << endl << endl;
	}

	void EULA() {
		system("cls");
		SetConsoleTextAttribute(color, 15);
		cout << endl << "Greetings!!!  Thank You for chosing " << programName << " " << programVersion;
		cout << endl << endl;
		cout << "My Name Is Jake and this is my C++ program.  I am learning C/C++ and I am using this program to apply" << endl;
		cout << "what I am learning as I learn it." << endl;
		cout << "The main part of this program is an interface I built to showcase to programs I have written as I advance in my studies" << endl;
		cout << "The next screen will ask you for your first and last name as well as your birth date.  I intend yo use this information" << endl;
		cout << "Within the program to make it feel more personable.  When you close the program everything you entered is deleted.";
		cout << endl << endl;
		cout << "By TYPING 'y' you give your concent for " << programName << " to collect personal data.";
		cout << endl << "If you do not concent then TYPE 'n' to quit the program immediately!" << endl;
	
	}

	void displayInformation() {
		drawHeaderMethod();
		SetConsoleTextAttribute(color, 3);
		cout << endl;
		cout << "Simple Snake is the very first game I have written in c++ code.  I followed online instructions to build the game and then I modified the code to intagrate it into THIS program" << endl;
		cout << "I have plans to modify the game to allow for different diffcaulty settings.";
		cout << "\n\n";
		system("pause");
	}
				
};

class ProgramLogic {
private:
	string commandPrompt;
	string invalidCommand;
	bool loop;
	char userInput;
	string userName;
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
		
public:
	ProgramLogic () {
		this->loop = true;
		this->userInput = ' ';
		this->userName = "User";
		this->commandPrompt = " Please a Enter Command: ";
		this->invalidCommand = " is not a valid Command!";
		this->color = GetStdHandle(STD_OUTPUT_HANDLE);

	};

	~ProgramLogic() {
		this->commandPrompt = "null";
		this->invalidCommand = "null";
		this->loop = NULL;
		this->userInput = ' ';
		this->userName = "null";
		this->color = NULL;
	}

	void setUserName(string name) {
		userName = name;
	}

	void returnInvalidCommand() {
		SetConsoleTextAttribute(color, 12);
		cout << "[" << userInput << "]" << invalidCommand << endl;
		system("pause");
	}

	bool loop_control() {
		return loop;
	}

	void loop_control_set(bool setLoop) {
		loop = setLoop;
	}

	void EULA_Accept(char input) {
		userInput = input;
		if (isalpha(userInput)) {
			userInput = tolower(userInput);
		}
		else {
			SetConsoleTextAttribute(color, 4);
			cout << "Must Enter a Single Alphabetic Character Only!" << endl;
		}

		switch (input)
		{
		case 'n': _Exit(0); break;
		case 'y': loop = false; break;
		default:
		{
			returnInvalidCommand();
			break;
		}
		}
	}

	void convertUserInput_lowercase(char input) {
		if (isalpha(input)) {
			userInput = tolower(input);
		}
	}

	void inputPrompt() {
		cout << endl;
		cout << userName << commandPrompt;		
		cin >> userInput;
	}

	char returnUserInput() {
		return userInput;
	}
};