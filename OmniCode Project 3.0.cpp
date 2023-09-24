// OmniCode Project 3.0.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Include.h"

int main() {
	User_Class user_object;
	ProgramLogic programLogic;
	ProgramDisplay programDisplay;

	do {
		programDisplay.EULA();
		programLogic.inputPrompt();
		programLogic.EULA_Accept(programLogic.returnUserInput());
	} while (programLogic.loop_control() == true);

	programLogic.loop_control_set(true);

	do {
		programDisplay.mainMenuDisplay();
		programLogic.inputPrompt();
		programLogic.convertUserInput_lowercase(programLogic.returnUserInput());
	
		switch (programLogic.returnUserInput()) {
		case 'i': programDisplay.displayInformation(); break;
		case 'l': user_object.log_in(); programLogic.setUserName(user_object.returnUser_FirstName()); break;
		case 'u': user_object.displayUserInformation(); break;
		case 'q': programLogic.loop_control_set(false); break;
		default: programLogic.returnInvalidCommand(); break;
		}

	} while (programLogic.loop_control() == true);

	return (0);
}