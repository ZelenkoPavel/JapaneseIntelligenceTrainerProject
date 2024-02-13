#include <iostream>
#include <string>
#include <time.h>

using namespace std;

void creating_examples(string* examples, int* answers, int number_of_examples, int size) {
	if (number_of_examples < 1 || number_of_examples > size) {
		return;
	}
	srand(time(NULL));

	for (int index = 0; index < number_of_examples; index++) {
		int a, b, c;
		int answer;
		bool n = rand() % 100 + 1 > 50;

		if (n) {
			while (true) {
				a = rand() % 9 + 1;
				b = rand() % 9 + 1;
				c = rand() % 9 + 1;
				answer = a + b - c;
				if (answer > 0 && answer < 17) {
					examples[index] = to_string(a) + " + " + to_string(b) + " - " +
						to_string(c) + " = ";
					answers[index] = answer;
					break;
				}
			}
		}
		else {
			while (true) {
				a = rand() % 9 + 1;
				b = rand() % 9 + 1;
				c = rand() % 9 + 1;
				answer = a - b + c;
				if (answer > 0 && answer < 17) {
					examples[index] = to_string(a) + " - " + to_string(b) + " + " +
						to_string(c) + " = ";
					answers[index] = answer;
					break;
				}
			}
		}
	}
}

void time_translation(int& seconds, int& minutes, int& hours) {
	while (seconds > 60) {
		if (seconds > 60) {
			minutes++;
			seconds -= 60;
		}
		if (minutes > 60) {
			hours++;
			minutes -= 60;
		}
	}
}


