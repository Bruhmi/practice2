#include <iostream>
#include <ctime>
#include <chrono>


void fillArray(int arr[], int lenArray, int min, int max) {
	srand(time(NULL));
	for (int i = 0; i < lenArray; i++) {
		arr[i] = rand() % (max - min + 1) + min;
	}
}


void printArray(int arr[], int lenArray) {
	std::cout << "[";
	for (int i = 0; i < lenArray; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]\n";
}


void validInput(int &input) {
	bool is_valid;
	do {
		is_valid = true;
		std::cin >> input;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "�������� ����. ����������, ������� ����� ����� ��� ���." << std::endl;
			is_valid = false;
		}
	} while (!is_valid);
}


void bubbleSort(int arr[], int lenArr) {
	for (int i = 0; i < 100; i++) {
		bool sorted = true;
		for (int j = 0; j < 100 - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				sorted = false;
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "ru");

	std::cout <<
		"������������� ������ �2\n"
		"���������� ����������� �������\n\n\n"

		"������������� ������ ������� 100, ����������� ���������� ������� � ��������� [-99; 99]:\n";
	int arr[100];
	int sortArr[100];
	fillArray(arr, 100, -99, 99);
	for (int i = 0; i < 100; i++) {
		sortArr[i] = arr[i];
	}
	bubbleSort(sortArr, 100);
	printArray(arr, 100);

	std::cout <<
		"��������:\n"
		"1 - ������� ����� ������ ������� 100, ����������� ���������� ������� � ��������� [-99; 99].\n"
		"2 - ������������� ������ � ������� �����������\n"
		"3 - ����� ����������� � ������������ ������� �������. ��������� ����� ������ � ��������������� � ����������������� �������.\n"
		"4 - ����� ������� �������� ������������� � ������������ �������� � ��������������� � �����������������. �������"
		"������� ���� ���������, ������� ����� ����� ��������, � �� ����������.\n"
		"5 - ������� ���������� ��������� � ��������������� �������, ������� ������ ����� �\n"
		"6 - ������� ���������� ��������� � ��������������� �������, ������� ������ ����� b\n"
		"8 - �������� ������� �������� �������, ������� ������� ������ ������������.\n"
		"9 - ��������� ������ �������� ������� ������� �� ��������� �������� n. ������ ������ ������� �������� �� ��������� �������� � ��������� [1; 9]. "
		"������� ���������� ���������, ������� ������� �� 1, 2, 3, 4, 5, 6, 7, 8, 9.\n"
		"0 - ��������� ������ ���������\n\n\n";


	for (int stop = 0; stop < 1; stop) {
		std::cout << "������� ����� ��������: ";
		int task;
		validInput(task);

		switch (task) {
		case 1:
			std::cout << "����� ������������� ������ ������� 100, ����������� ���������� ������� � ��������� [-99; 99]:\n";
			fillArray(arr, 100, -99, 99);
			printArray(arr, 100);
			for (int i = 0; i < 100; i++) {
				sortArr[i] = arr[i];
			}
			bubbleSort(sortArr, 100);
			break;

		case 2: {
			std::cout << "��������������� ������:\n";
			int sortArr2[100];
			for (int i = 0; i < 100; i++) {
				sortArr2[i] = arr[i];
			}
			auto start = std::chrono::high_resolution_clock().now();
			bubbleSort(sortArr2, 100);
			auto finish = std::chrono::high_resolution_clock().now();
			std::chrono::duration<float> duration = finish - start;
			printArray(sortArr2, 100);
			std::cout << "����� ����������: " << duration.count() << " ���.\n\n";
			break;
		}

		case 3: {
			auto start1 = std::chrono::high_resolution_clock().now();
			int min = arr[0];
			int max = arr[0];
			for (int i = 0; i < 100; i++) {
				min = (min > arr[i] ? arr[i] : min);
				max = (max < arr[i] ? arr[i] : max);
			}
			auto finish1 = std::chrono::high_resolution_clock().now();
			std::chrono::duration<float> duration1 = finish1 - start1;

			auto start2 = std::chrono::high_resolution_clock().now();
			min = sortArr[0];
			max = sortArr[99];
			auto finish2 = std::chrono::high_resolution_clock().now();
			std::chrono::duration<float> duration2 = finish2 - start2;

			std::cout <<
				"����������� ������� �������: " << min << std::endl <<
				"������������ ������� �������: " << max << std::endl <<
				"����� ������ ������������ � ������������� �������� � ����������������� �������: " << std::endl << duration1.count() << " ���.\n"
				"����� ������ ������������ � ������������� �������� � ��������������� ������� �������: " << duration2.count() << " ���.\n\n";
			break;
		}

		case 4: {
			int min = sortArr[0];
			int max = sortArr[99];
			float average = round((min + max) / 2.0);
			int numbOfAverage = 0;
			std::cout << "������� �������� ������������ � ������������� ��������: " << average << "\n\n";
			std::cout << "������� ����������, ������ �������� ��������: ";
			auto start1 = std::chrono::high_resolution_clock().now();
			for (int i = 0; i < 100; i++) {
				bool doing = true;
				if (sortArr[i] <= average) {
					if (average == sortArr[i]) {
						++numbOfAverage;
						std::cout << i << " ";
					}
				}
				else {
					if (numbOfAverage == 0) {
						std::cout << "���\n\n";
					}
					std::cout << "\n";
					doing = false;
				}
				if (!doing) {
					break;
				}
			}
			auto finish1 = std::chrono::high_resolution_clock().now();
			std::chrono::duration<float> duration1 = finish1 - start1;

			auto start2 = std::chrono::high_resolution_clock().now();
			int numbOfAverage2 = 0;
			for (int i = 0; i < 100; i++) {
				if (arr[i] == average) {
					++numbOfAverage;
				}
			}
			auto finish2 = std::chrono::high_resolution_clock().now();
			std::chrono::duration<float> duration2 = finish2 - start2;

			std::cout << "���������� ����������, ������ �������� ��������: " << numbOfAverage << "\n";
			std::cout << "����� ������ � ��������������� ������� (���): " << duration1.count() << "\n";
			std::cout << "����� ������ � ����������������� ������� (���): " << duration2.count() << "\n";
			break;
		}

		case 5: {
			int a;
			std::cout << "������� ����� a: ";
			validInput(a);
			int numbOfVarr = 0;
			for (int i = 0; i < 100; i++) {
				if (arr[i] < a) {
					++numbOfVarr;
				}
			}
			std::cout << "���������� ���������� � �������, ������� ������ " << a << ": " << numbOfVarr << "\n\n";
			break;
		}
		case 6: {
			int b;
			std::cout << "������� ����� b: ";
			validInput(b);
			int numbOfVarr = 0;
			for (int i = 0; i < 100; i++) {
				if (arr[i] < b) {
					++numbOfVarr;
				}
			}
			std::cout << "���������� ���������� � �������, ������� ������ b " << b << ": " << numbOfVarr << "\n\n";
			break;
		}

		case 8: {
			int index1 = 100;
			int index2 = 100;
			while (index1 < 0 or index1 > 99) {
				std::cout << "������� ������ ������ (�� 0 �� 99): ";
				validInput(index1);
				if (index1 < 0 or index1 > 99) {
					std::cout << "�� ����� �� �������� �������.";
				}
			}
			while (index2 < 0 or index2 > 99) {
				std::cout << "������� ������ ������ (�� 0 �� 99): ";
				validInput(index2);
				if (index2 < 0 or index2 > 99) {
					std::cout << "�� ����� �� �������� �������.";
				}
			}
			std::swap(arr[index1], arr[index2]);
			std::cout << "�� �������� ������� �������� � �������� " << index1 << " � " << index2 << ":\n";
			printArray(arr, 100);
			break;
		}

		case 9:{
			int n;
			std::cout << "������� ����� ����� n: ";
			validInput(n);
			srand(time(NULL));
			int randNumb = rand() % 9 + 1;
			int multiple1 = 100;
			int multiple2 = 0;
			int multiple3 = 0;
			int multiple4 = 0;
			int multiple5 = 0;
			int multiple6 = 0;
			int multiple7 = 0;
			int multiple8 = 0;
			int multiple9 = 0;
			for (int i = 0; i < 100; i++) {
				if (i % 2 != 0) {
					arr[i] -= n;
				}
				if (i%2 == 0) {
					arr[i] *= randNumb;
				}
				multiple2 = (arr[i]%2 == 0) ? ++multiple2: multiple2;
				multiple3 = (arr[i] % 3 == 0) ? ++multiple3 : multiple3;
				multiple4 = (arr[i] % 4 == 0) ? ++multiple4 : multiple4;
				multiple5 = (arr[i] % 5 == 0) ? ++multiple5 : multiple5;
				multiple6 = (arr[i] % 6 == 0) ? ++multiple6 : multiple6;
				multiple7 = (arr[i] % 7 == 0) ? ++multiple7 : multiple7;
				multiple8 = (arr[i] % 8 == 0) ? ++multiple8 : multiple8;
				multiple9 = (arr[i] % 9 == 0) ? ++multiple9 : multiple9;
			}
			std::cout << "�������� ������� ������� ��������� �� n. ������ - �������� �� ��������� ����� �� 1 �� 9:\n";
			printArray(arr, 100);
			std::cout <<
				"���������� ���������, ������� ������� �� 1: " << multiple1 << " \n"
				"���������� ���������, ������� ������� �� 2: " << multiple2 << " \n"
				"���������� ���������, ������� ������� �� 3: " << multiple3 << " \n"
				"���������� ���������, ������� ������� �� 4: " << multiple4 << " \n"
				"���������� ���������, ������� ������� �� 5: " << multiple5 << " \n"
				"���������� ���������, ������� ������� �� 6: " << multiple6 << " \n"
				"���������� ���������, ������� ������� �� 7: " << multiple7 << " \n"
				"���������� ���������, ������� ������� �� 8: " << multiple8 << " \n"
				"���������� ���������, ������� ������� �� 9: " << multiple9 << " \n";
			std::cout << "\n";
		}

		default:
			break;

		}

		



	}
	return 0;
}

