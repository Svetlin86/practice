#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void pause();
bool isInteger(const string& input);
void setSizeOfArrayAndInsertNumbers(int K[], int& L);
double calculateMeanDivisibleBySix(const int K[], int L);
void findMaxNegative(const int K[], int L, int& maxNegative, int& index);
void printArray(const int K[], int L);

int main() {
    constexpr int MAX_SIZE = 30;
    int K[MAX_SIZE], L, choice;
    string input;
    bool arrayEntered = false;

    do {
        cout << "Menu" << endl;
        cout << "1. Vuvedi elementi ot masiva" << endl;
        cout << "2. Izchsleniq" << endl;
        cout << "3. Izhod" << endl;
        cout << "Izberi opciq: ";
        cin >> input;

        if (isInteger(input)) {
            choice = stoi(input);

            switch (choice) {
                case 1: {
                    cout << "Vuvedi razmer na masiva (1 to 30):" << endl;
                    setSizeOfArrayAndInsertNumbers(K, L);
                    arrayEntered = true;
                    break;
                }
                case 2: {
                    if (!arrayEntered) {
                        cout << "Purvo suzdai masiv." << endl;
                        pause();
                        break;
                    }

                    do {
                        cout << "Menu za izchisleniq" << endl;
                        cout << "1. Izchislete sredna stoinost na chisla, delimi na 6" << endl;
                        cout << "2. Namerete maksimalnoto otritsatelno chislo i negoviya indeks" << endl;
                        cout << "3. Izhod" << endl;
                        cout << "Izberi opciq: ";
                        cin >> input;

                        if (isInteger(input)) {
                            choice = stoi(input);

                            switch (choice) {
                                case 1: {
                                    double mean = calculateMeanDivisibleBySix(K, L);
                                    if (mean != 0) {
                                        cout << "Srednata stoĭnost na chislata, delimi na 6, e:  " << mean << endl;
                                    } else {
                                        cout << "V masiva nyama chisla, delimi na 6.";
                                    }
                                    printArray(K, L);
                                    pause();
                                    break;
                                }
                                case 2: {
                                    int maxNegative, index;
                                    findMaxNegative(K, L, maxNegative, index);
                                    if (index != -1) {
                                        cout << "Maksimalnoto otritsatelno chislo e " << maxNegative
                                             << " na index " << index << "." << endl;
                                    } else {
                                        cout << "Nyama otritsatelni chisla v masiva.";
                                    }
                                    printArray(K, L);
                                    pause();
                                    break;
                                }
                                case 3: {
                                    break;
                                }
                                default: {
                                    cout << "Nevalidna optsiya! Opitaite otnovo.";
                                    pause();
                                    break;
                                }
                            }
                        } else {
                            cout << "Nevalidna opciq";
                            pause();
                        }
                    } while (choice != 3);
                    break;
                }
                case 3: {
                    cout << "Izlizane ot programata." << endl;
                    break;
                }
                default: {
                    cout << "Nevalidna opciq";
                    pause();
                    break;
                }
            }
        } else {
            cout << "Nevalidna opciq";
            pause();
        }
    } while (choice != 3);

    return 0;
}

void setSizeOfArrayAndInsertNumbers(int K[], int& L) {
    string array_input;

    while (true) {
        cin >> array_input;

        if (isInteger(array_input)) {
            L = stoi(array_input);
            if (L > 0 && L <= 30) {
                break;
            }
            cout << "Nevaliden razmer na masiva! Vuvedete chislo mezhdu 1 i 30." << endl;
            continue;
        }
        cout << "Nevaliden razmer na masiva! Vŭvedete tsyalo chislo mezhdu 1 i 30." << endl;
    }

    for (int i = 0; i < L; ++i) {
        while (true) {
            cout << "Vuvedi K[" << i << "]: ";
            cin >> array_input;

            if (isInteger(array_input)) {
                K[i] = stoi(array_input);
                break;
            }
            cout << "nevaliden izbor" << endl;
        }
    }
}

double calculateMeanDivisibleBySix(const int K[], int L) {
    double sum = 0;
    int count = 0;

    for (int i = 0; i < L; ++i) {
        if (K[i] % 6 == 0) {
            sum += K[i];
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }
    return sum / count;
}

void findMaxNegative(const int K[], int L, int& maxNegative, int& index) {
    maxNegative = numeric_limits<int>::min();
    index = -1;

    for (int i = 0; i < L; ++i) {
        if (K[i] < 0 && K[i] > maxNegative) {
            maxNegative = K[i];
            index = i;
        }
    }
}

void printArray(const int K[], int L) {
    for (int i = 0; i < L; ++i) {
        cout << K[i] << " ";
    }
    cout << endl;
}

void pause() {
    cout << "Natisnete proizvolen buton...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool isInteger(const string& input) {
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