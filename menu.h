#include <iostream>

using namespace std;

#include <iomanip>
#include <chrono>
#include "PQ1.h"
#include "PQ2.h"
#include "PQ3.h"
#include "PQ4.h"
#include "PQ5.h"

using namespace std::chrono;

const int MAX = 100; // maximum size of queues

// ANSI color codes
const string RESET = "\033[0m";
const string LIGHT_RED = "\033[91m";
const string LIGHT_GREEN = "\033[92m";
const string LIGHT_WHITE = "\033[97m";

void displayResult(const string& label, const string& pqName, float result, long long time) { // for displaing remove and front results
    cout << LIGHT_WHITE << left << setw(10) << pqName << RESET << " | "
        << LIGHT_WHITE << setw(20) << label << RESET << " | "
        << LIGHT_GREEN << "Result: " << RESET << setw(10) << result << " | "
        << LIGHT_RED << "Time: " << time << " ns" << RESET << "\n";
}

void displayResult(const string& label, const string& pqName, int result, long long time) { // for displaing length result
    cout << LIGHT_WHITE << left << setw(10) << pqName << RESET << " | "
        << LIGHT_WHITE << setw(20) << label << RESET << " | "
        << LIGHT_GREEN << "Result: " << RESET << setw(10) << result << " | "
        << LIGHT_RED << "Time: " << time << " ns" << RESET << "\n";
}

void displayResult(const string& label, const string& pqName, bool result, long long time) { // for displaying insert result
    cout << LIGHT_WHITE << left << setw(10) << pqName << RESET << " | "
        << LIGHT_WHITE << setw(20) << label << RESET << " | "
        << (result ? LIGHT_GREEN : LIGHT_RED) << "Result: " << (result ? "Success" : "Fail") << RESET << " | "
        << LIGHT_RED << "Time: " << time << " ns" << RESET << "\n";
}

void run() {
    PQ1<float, MAX> pq1;
    PQ2<float, MAX> pq2;
    PQ3<float, MAX> pq3;
    PQ4<float, MAX> pq4;
    PQ5<float, MAX> pq5;

    while (true) {
        cout << "\n" << LIGHT_WHITE << "========================================" << RESET << "\n";
        cout << LIGHT_WHITE << "              Priority Queue Menu       " << RESET << "\n";
        cout << LIGHT_WHITE << "========================================" << RESET << "\n";
        cout << LIGHT_RED << "1. Insert" << RESET << "\n";
        cout << LIGHT_RED << "2. Remove" << RESET << "\n";
        cout << LIGHT_RED << "3. Display Front" << RESET << "\n";
        cout << LIGHT_RED << "4. Display Length" << RESET << "\n";
        cout << LIGHT_RED << "5. Exit" << RESET << "\n";
        cout << LIGHT_WHITE << "========================================" << RESET << "\n";
        cout << LIGHT_WHITE << "Enter your choice: " << RESET;

        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << LIGHT_RED << "Exiting..." << RESET << "\n";
            break;
        }

        float value;
        cout << "\n" << LIGHT_WHITE << "----------------------------------------" << RESET << "\n";
        switch (choice) {
        case 1:
            cout << LIGHT_WHITE << "Enter value to insert: " << RESET;
            cin >> value;
            cout << "\n" << LIGHT_GREEN << "Results:" << RESET << "\n";
            cout << LIGHT_WHITE << "----------------------------------------" << RESET << "\n";
            {
                auto start = high_resolution_clock::now();
                bool result1 = pq1.insert(value);
                auto end = high_resolution_clock::now();
                displayResult("Insert", "PQ1", result1, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                bool result2 = pq2.insert(value);
                end = high_resolution_clock::now();
                displayResult("Insert", "PQ2", result2, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                bool result3 = pq3.insert(value);
                end = high_resolution_clock::now();
                displayResult("Insert", "PQ3", result3, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                bool result4 = pq4.insert(value);
                end = high_resolution_clock::now();
                displayResult("Insert", "PQ4", result4, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                bool result5 = pq5.insert(value);
                end = high_resolution_clock::now();
                displayResult("Insert", "PQ5", result5, duration_cast<nanoseconds>(end - start).count());
            }
            break;

        case 2:
            cout << "\n" << LIGHT_GREEN << "Results:" << RESET << "\n";
            cout << LIGHT_WHITE << "----------------------------------------" << RESET << "\n";
            {
                auto start = high_resolution_clock::now();
                float result1 = pq1.remove();
                auto end = high_resolution_clock::now();
                displayResult("Remove", "PQ1", result1, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result2 = pq2.remove();
                end = high_resolution_clock::now();
                displayResult("Remove", "PQ2", result2, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result3 = pq3.remove();
                end = high_resolution_clock::now();
                displayResult("Remove", "PQ3", result3, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result4 = pq4.remove();
                end = high_resolution_clock::now();
                displayResult("Remove", "PQ4", result4, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result5 = pq5.remove();
                end = high_resolution_clock::now();
                displayResult("Remove", "PQ5", result5, duration_cast<nanoseconds>(end - start).count());
            }
            break;

        case 3:
            cout << "\n" << LIGHT_GREEN << "Results:" << RESET << "\n";
            cout << LIGHT_WHITE << "----------------------------------------" << RESET << "\n";
            {
                auto start = high_resolution_clock::now();
                float result1 = pq1.atFront();
                auto end = high_resolution_clock::now();
                displayResult("Front", "PQ1", result1, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result2 = pq2.atFront();
                end = high_resolution_clock::now();
                displayResult("Front", "PQ2", result2, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result3 = pq3.atFront();
                end = high_resolution_clock::now();
                displayResult("Front", "PQ3", result3, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result4 = pq4.atFront();
                end = high_resolution_clock::now();
                displayResult("Front", "PQ4", result4, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                float result5 = pq5.atFront();
                end = high_resolution_clock::now();
                displayResult("Front", "PQ5", result5, duration_cast<nanoseconds>(end - start).count());
            }
            break;

        case 4:
            cout << "\n" << LIGHT_GREEN << "Results:" << RESET << "\n";
            cout << LIGHT_WHITE << "----------------------------------------" << RESET << "\n";
            {
                auto start = high_resolution_clock::now();
                int result1 = pq1.Qlen();
                auto end = high_resolution_clock::now();
                displayResult("Length", "PQ1", result1, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                int result2 = pq2.Qlen();
                end = high_resolution_clock::now();
                displayResult("Length", "PQ2", result2, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                int result3 = pq3.Qlen();
                end = high_resolution_clock::now();
                displayResult("Length", "PQ3", result3, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                int result4 = pq4.Qlen();
                end = high_resolution_clock::now();
                displayResult("Length", "PQ4", result4, duration_cast<nanoseconds>(end - start).count());

                start = high_resolution_clock::now();
                int result5 = pq5.Qlen();
                end = high_resolution_clock::now();
                displayResult("Length", "PQ5", result5, duration_cast<nanoseconds>(end - start).count());
            }
            break;

        default:
            cout << LIGHT_RED << "Invalid choice. Please try again." << RESET << "\n";
            break;
        }
    }
}
