#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

void setSizeOfArrayAndInsertNumbers(int K[], int &L);

double calculateMeanDivisibleBySix(const int K[], int L);

void findMaxNegative(const int K[], int L, int &maxNegative, int &index);

void printArray(const int K[], int L);

//new
int main() {
    constexpr int MAX_SIZE = 30;
    int K[MAX_SIZE], L, choice;
    int input;
    bool arrayEntered = false;

    do {
        cout << "Menu" << endl;
        cout << "1 Vuvedi elementi ot masiva" << endl;
        cout << "2 Izchsleniq" << endl;
        cout << "3 Izhod" << endl;
        cout << "Izberi opciq: ";
        cin >> input;

        choice = input;

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
                    break;
                }

                do {
                    cout << "Menu za izchisleniq" << endl;
                    cout << "1 Izchislete sredna stoinost na chisla, delimi na 6" << endl;
                    cout << "2 Namerete maksimalnoto otrictelno chislo i negoviya indeks" << endl;
                    cout << "3 Izhod" << endl;
                    cout << "Izberi opciq: ";
                    cin >> input;

                    choice = input;

                    switch (choice) {
                        case 1: {
                            double mean = calculateMeanDivisibleBySix(K, L);
                            if (mean != 0) {
                                cout << "Srednata stoinost na chislata, delimi na 6, e:  " << mean << endl;
                            } else {
                                cout << "V masiva nyama chisla, delimi na 6.";
                            }
                            printArray(K, L);
                            break;
                        }
                        case 2: {
                            int maxNegative, index;
                            findMaxNegative(K, L, maxNegative, index);
                            if (index != -1) {
                                cout << "Maksimalnoto otricatelno chislo e " << maxNegative
                                        << " na index " << index << "." << endl;
                            } else {
                                cout << "Nyama otricatelni chisla v masiva.";
                            }
                            printArray(K, L);
                            // pause();
                            break;
                        }
                        case 3: {
                            break;
                        }
                        default: {
                            cout << "Nevalidna opciq";
                            break;
                        }
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
                break;
            }
        }
    } while (choice != 3);

    return 0;
}

void setSizeOfArrayAndInsertNumbers(int K[], int &L) {
    string array_input;

    while (true) {
        cin >> array_input;
        L = stoi(array_input);
        if (L > 0 && L <= 30) {
            break;
        }
    }

    for (int i = 0; i < L; ++i) {
        while (true) {
            cout << "Vuvedi K[" << i << "]: ";
            cin >> array_input;
            K[i] = stoi(array_input);
            break;
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

void findMaxNegative(const int K[], int L, int &maxNegative, int &index) {
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
