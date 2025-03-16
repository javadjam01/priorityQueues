#include <iostream>

using namespace std;

#include <chrono>
#include "PQ1.h"
#include "PQ2.h"
#include "PQ3.h"
#include "PQ4.h"
#include "PQ5.h"

using namespace std::chrono;

const int MAX = 100; // Define the maximum size for the queues

int main() {
    PQ1<int, MAX> pq1;
    PQ2<int, MAX> pq2;
    PQ3<int, MAX> pq3;
    PQ4<int, MAX> pq4;
    PQ5<int, MAX> pq5;

    while (true) {
        cout << "\nPriority Queue Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Display Front\n";
        cout << "4. Display Length\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting...\n";
            break;
        }

        int value;
        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;

            {
                auto start = high_resolution_clock::now();
                bool result1 = pq1.insert(value);
                auto end = high_resolution_clock::now();
                cout << "PQ1 Result: " << result1 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

                start = high_resolution_clock::now();
                bool result2 = pq2.insert(value);
                end = high_resolution_clock::now();
                cout << "PQ2 Result: " << result2 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

                start = high_resolution_clock::now();
                bool result3 = pq3.insert(value);
                end = high_resolution_clock::now();
                cout << "PQ3 Result: " << result3 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

                start = high_resolution_clock::now();
                bool result4 = pq4.insert(value);
                end = high_resolution_clock::now();
                cout << "PQ4 Result: " << result4 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

                start = high_resolution_clock::now();
                bool result5 = pq5.insert(value);
                end = high_resolution_clock::now();
                cout << "PQ5 Result: " << result5 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
            }
            break;

        case 2:
        {
            auto start = high_resolution_clock::now();
            int result1 = pq1.remove();
            auto end = high_resolution_clock::now();
            cout << "PQ1 Result: " << result1 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result2 = pq2.remove();
            end = high_resolution_clock::now();
            cout << "PQ2 Result: " << result2 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result3 = pq3.remove();
            end = high_resolution_clock::now();
            cout << "PQ3 Result: " << result3 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result4 = pq4.remove();
            end = high_resolution_clock::now();
            cout << "PQ4 Result: " << result4 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result5 = pq5.remove();
            end = high_resolution_clock::now();
            cout << "PQ5 Result: " << result5 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
        }
        break;

        case 3:
        {
            auto start = high_resolution_clock::now();
            int result1 = pq1.atFront();
            auto end = high_resolution_clock::now();
            cout << "PQ1 Front: " << result1 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result2 = pq2.atFront();
            end = high_resolution_clock::now();
            cout << "PQ2 Front: " << result2 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result3 = pq3.atFront();
            end = high_resolution_clock::now();
            cout << "PQ3 Front: " << result3 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result4 = pq4.atFront();
            end = high_resolution_clock::now();
            cout << "PQ4 Front: " << result4 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result5 = pq5.atFront();
            end = high_resolution_clock::now();
            cout << "PQ5 Front: " << result5 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
        }
        break;

        case 4:
        {
            auto start = high_resolution_clock::now();
            int result1 = pq1.Qlen();
            auto end = high_resolution_clock::now();
            cout << "PQ1 Length: " << result1 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result2 = pq2.Qlen();
            end = high_resolution_clock::now();
            cout << "PQ2 Length: " << result2 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result3 = pq3.Qlen();
            end = high_resolution_clock::now();
            cout << "PQ3 Length: " << result3 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result4 = pq4.Qlen();
            end = high_resolution_clock::now();
            cout << "PQ4 Length: " << result4 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";

            start = high_resolution_clock::now();
            int result5 = pq5.Qlen();
            end = high_resolution_clock::now();
            cout << "PQ5 Length: " << result5 << ", Time: " << duration_cast<nanoseconds>(end - start).count() << " ns\n";
        }
        break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
