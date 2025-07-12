# console-application-for-doing-searching 
DSA Assignment Repository

This repository contains a C++ program implementing various Data Structures and Algorithms (DSA) techniques, including random number generation, sorting (Quick Sort and Merge Sort), and searching (Binary Search and Exponential Search). The code includes a menu-driven interface to demonstrate these algorithms with runtime measurements.
Overview
The program provides:

Generation of random integers.
Implementation of Quick Sort and Merge Sort algorithms.
Binary Search and Exponential Search for finding elements in sorted arrays.
Runtime analysis in microseconds, milliseconds, and seconds for each operation.

This project was developed as part of a DSA assignment to explore algorithm efficiency and implementation.
Features

Random Number Generation: Creates an array of random integers (0–999).
Sorting Algorithms: Implements Quick Sort and Merge Sort with time measurement.
Searching Algorithms: Provides Binary Search and Exponential Search with precise timing.
User Interface: Menu-driven system for easy interaction.
Memory Management: Proper allocation and deallocation of dynamic arrays.

Prerequisites

A C++ compiler (e.g., g++).
Basic terminal or IDE (e.g., Visual Studio Code, Code::Blocks).

Installation

Clone the repository:git clone https://github.com/SamyakUpadhyay/console-application-for-doing-searching.git


Navigate to the project directory:cd dsa-assignment


Compile the code:g++ -o dsa_assignment dsa_assignment.cpp


Run the executable:./dsa_assignment  # On Linux/Mac
dsa_assignment.exe  # On Windows



Usage

Run the program to see the menu:
--- DSA Assignment Menu ---

1. Generate random numbers
2. Quick Sort
3. Merge Sort
4. Binary Search
5. Exponential Search
6. Display Array
7. Exit
Enter choice:


Select an option by entering the corresponding number:
Option 1: Enter the number of random integers to generate.
Option 2/3: Sort the array using Quick Sort or Merge Sort (requires prior generation).
Option 4/5: Search for a number using Binary Search or Exponential Search (requires sorting).
Option 6: Display the current array.
Option 7: Exit the program.


Follow prompts to input values (e.g., number to search).
View results, including the sorted array or search index and runtime (e.g., "50 microseconds (0.05 milliseconds)").

Example Output
Enter the number of random integers to generate: 10
Generated numbers: 345 789 123 456 678 234 890 567 901 112
Binary Search Index: 5
Binary Search Time: 45 microseconds (0.045 milliseconds)

Contributing
Contributions are welcome! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Make changes and commit (git commit -m "Add new feature").
Push to the branch (git push origin feature-branch).
Open a pull request.

License
This project is licensed under the MIT License. See the LICENSE file for details.

Acknowledgments
Inspired by standard DSA curricula (e.g., Cormen et al., Introduction to Algorithms).
Thanks to the open-source community for C++ tools and libraries.

Contact
For questions or feedback, contact samyakupadhyay9@gmail.com or open an issue on this repository.
