#include <iostream>
#include <time.h>
#include <Windows.h>

using namespace std;

void creating_examples(string*, int*, int, int);


void time_translation(int& seconds, int& minutes, int& hours);

int main() {

	bool exit = true;

	while (exit) {
		const int size = 1000;
		string examples[size];
		int answers[size];
		int number_of_examples;

		int the_number_of_errors = 0;

		cout << "Input number of examples: ";
		cin >> number_of_examples;
		if (number_of_examples < 1 || number_of_examples > size) {
			return -1;
		}

		creating_examples(examples, answers, number_of_examples, size);

		int start_time = time(NULL);

		for (int i = 0; i < number_of_examples; i++) {
			int count_errors = -1;

			int user_answer;
			while (true) {
				system("cls");
				count_errors++;
				cout << "Input answer:" << endl;
				cout << examples[i];
				cin >> user_answer;
				if (answers[i] == user_answer) {
					break;
				}
				else {
					cout << "You made a mistake.";
					Sleep(1000);
				}
			}
			if (count_errors > 0) {
				the_number_of_errors++;
			}
		}

		int end_time = time(NULL);

		int seconds = end_time - start_time;
		int minutes = 0;
		int hours = 0;

		time_translation(seconds, minutes, hours);


		cout << "Result :\n" <<
			"The number of errors = " << the_number_of_errors << ";\n" <<
			"Time = " << hours << ":" << minutes << ":" << seconds << "." << endl;

		system("pause");

		string answer_exit;
		do {
			system("cls");
			cout << "Do you want to continue? (Yes or No)";
			cin >> answer_exit;
		} while (answer_exit != "Yes" && answer_exit != "yEs" && answer_exit != "yeS" &&
			answer_exit != "yes" && answer_exit != "YES" && answer_exit != "No" &&
			answer_exit != "nO" && answer_exit != "no" && answer_exit != "NO");

		if (answer_exit == "No" || answer_exit == "nO" || answer_exit == "no" || answer_exit == "NO") {
			exit = false;
		}
	}

	return 0;
}
