#include <iostream>

#include <math.h>
using namespace std;

void pause();
bool isInteger(const string& input);
void setSizeOfArrayAndInsertNumbers(int Z[], int& L);
double calculateAverageNegativeInInterval(const int Z[], int L, double min, double max);
void calculateProductOfNonZeroElements(const int Z[], int L, double& product);
void countZeroElements(const int Z[], int L, int& zeroCount);
void printArray(const int Z[], int L);


int main() {

    constexpr int MAX_ARRAY_SIZE = 30;
    int Z[MAX_ARRAY_SIZE], L, choice;
    string input;
    int zeroCount;
    double product, min, max;
    bool arrayEntered = false;

    do {
        cout << "\n Menu\n" << endl;
        cout << "1. Dobavi elementi v K(L)\n" << endl;
        cout << "2. Izchsleniq\n" << endl;
        cout << "3. Izhod\n" << endl;
        cout << "Izberi opciq " << endl;
        cin >> input;

        if (isInteger(input)) {
            choice = stoi(input);

            switch (choice) {
                case 1: {
                    cout << "Izberi razmer na masiva (1 do 30):" << endl;
                    setSizeOfArrayAndInsertNumbers(Z, L);
                    arrayEntered = true;
                    break;
                }
                case 2: {
                    if (!arrayEntered) {
                        cout << "Pyrvo izberete razmer na masiva\n" << endl;
                        pause();
                        break;
                    }
                    do {
                        cout << "\nОПЕРАЦИОННО МЕНЮ\n" << endl;
                        cout << "1. Izchislyavane na srednoaritmetichnoto na otritsatelnite chisla v interval\n" << endl;
                        cout << "2. Izchislyavane na proizvedenieto na nenulevite chisla\n" << endl;
                        cout << "3. Broya na nulevite element\n" << endl;
                        cout << "4. Nazad\n" << endl;
                        cout << "Izberete operatsiya: " << endl;
                        cin >> input;

                        if (isInteger(input)) {
                            choice = stoi(input);
                            switch (choice) {
                                case 1: {
                                    cout << "Въведете минимална стойност за интервала: " << endl;
                                    cin >> min;
                                    while (cin.fail()) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cout << "Невалиден вход! Моля, въведете валидна минимална стойност: " << endl;
                                        cin >> min;
                                    }

                                    cout << "Въведете максимална стойност за интервала: " << endl;
                                    cin >> max;
                                    while (cin.fail()) {
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        cout << "Невалиден вход! Моля, въведете валидна максимална стойност: " << endl;
                                        cin >> max;
                                    }

                                    cout << "\n***********************************************************" << endl;

                                    const double avg = calculateAverageNegativeInInterval(Z, L, min, max);

                                    if (avg != 0) {
                                        cout << "Средноаритметичното на отрицателните числа в интервала [" << min <<
                                                ", " <<
                                                max
                                                <<
                                                "] е: \n" << avg << endl;
                                    } else {
                                        cout << "Няма отрицателни числа в този интервал!\n" << endl;
                                    }
                                    cout << "Елементите на масива са: " << endl;
                                    printArray(Z, L);
                                    cout << "***********************************************************\n" << endl;
                                    pause();
                                    break;
                                }
                                case 2: {
                                    calculateProductOfNonZeroElements(Z, L, product);
                                    cout << "\n***********************************************************" << endl;
                                    cout << "Произведението на ненулевите елементи е: \n" << product << endl;

                                    cout << "Елементите на масива са: " << endl;
                                    printArray(Z, L);
                                    cout << "***********************************************************\n" << endl;
                                    pause();
                                    break;
                                }
                                case 3: {
                                    countZeroElements(Z, L, zeroCount);
                                    cout << "\n***********************************************************" << endl;
                                    cout << "Броят на нулевите елементи е: \n" << zeroCount << endl;
                                    cout << "Елементите на масива са: " << endl;
                                    printArray(Z, L);
                                    cout << "***********************************************************\n" << endl;
                                    pause();
                                    break;
                                }
                                case 4: {
                                    break;
                                }
                                default: {
                                    cout << "Невалидна опция! Опитайте отново.\n" << endl;
                                    pause();
                                    break;
                                }
                            }
                        } else {
                            cout << "Невалиден вход! Oпитайте отново.\n" << endl;
                            pause();
                        }
                    } while (choice != 4);
                    break;
                }
                case 3: {
                    cout << "Изход от програмата!\n" << endl;
                    break;
                }
                default: {
                    cout << "Невалидна опция! Опитайте отново.\n" << endl;
                    pause();
                    break;
                }
            }
        } else {
            cout << "Невалиден вход! Oпитайте отново.\n" << endl;
            pause();
        }
    } while (choice != 3);

    return 0;
}

void setSizeOfArrayAndInsertNumbers(int Z[], int &L) {
    string array_input;

    while (true) {
        cin >> array_input;

        if (isInteger(array_input)) {
            L = stoi(array_input);
            if (L > 0 && L <= 30) {
                break;
            }
            cout << "Невалиден размер на масива! Моля, въведете цяло число между 1 и 30." << endl;
            continue;
        }
        cout << "Невалиден вход! Моля, въведете цяло число между 1 и 30." << endl;
    }

    for (int i = 0; i < L; ++i) {
        while (true) {
            cout << "Въведете Z[" << i << "]: "<<endl;
            cin >> array_input;

            if (isInteger(array_input)) {
                Z[i] = stoi(array_input);
                break;
            }
            cout << "Невалиден вход! Моля, въведете цяло число." << endl;
        }
    }
}

double calculateAverageNegativeInInterval(const int Z[], const int L, const double min, const double max) {
    double sum = 0.0;
    int count = 0;
    for (int i = 0; i < L; ++i) {
        if (Z[i] < 0 && Z[i] >= min && Z[i] <= max) {
            sum += Z[i];
            count++;
        }
    }
    if (count == 0) {
        return 0;
    }
    return sum / count;
}

void calculateProductOfNonZeroElements(const int Z[], const int L, double &product) {
    product = 1.0;
    bool hasNonZero = false;
    for (int i = 0; i < L; ++i) {
        if (Z[i] != 0) {
            product *= Z[i];
            hasNonZero = true;
        }
    }
    if (!hasNonZero) {
        product = 0;
    }
}

void countZeroElements(const int Z[],const int L ,int &zeroCount) {
    zeroCount = 0;
    for (int i = 0; i < L; ++i) {
        if (Z[i] == 0) {
            zeroCount++;
        }
    }
}

void printArray(const int Z[], int L) {
    for (int i = 0; i < L; ++i) {
        cout << Z[i] << " ";
    }
    cout << endl;
}

void pause() {
    cout << "Натиснете клавиш за да продължите...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool isInteger(const string &input) {
    size_t start = 0;
    if (input[0] == '-') {
        start = 1;
    }
    for (size_t i = start; i < input.size(); i++) {
        if (!isdigit(input[i])) {
            return false;
        }
    }
    return !input.empty() && (start != input.size());
}
